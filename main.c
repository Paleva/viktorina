#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <unistd.h>
#include "lib/questions.h"
#include "lib/questions.c"
#include "lib/gamelogic.h" 
#include "lib/gamelogic.c"
#include "lib/console.h"
#include "lib/console.c"
#include "lib/leader.h"
#include "lib/leader.c"
#include <sys/time.h>
#define MAX_LEN 256

void freelist(struct A *head);
void freeboard(struct Lenta *Board, int eilutes);

int main(){

    char *temos[5] = {
    "temos/miestai.txt",
    "temos/filmai.txt",
    "temos/muzika.txt",
    "temos/menas.txt",
    "temos/zmones.txt"
    };
    int i = 0;
    int pasirinkimas = 0;
    srand(time(NULL));
    char buffer[MAX_LEN];
    int ats = 0;
    struct timeval start, end;
    double seconds = 0.0;
    struct A *Head_klausimas = NULL;
    FILE *file;

    
    pasirinkimas = Starting_Screen(pasirinkimas);

    file = fopen(temos[pasirinkimas-1], "r");

    if(file == NULL){
        exit(1);
    }
    while(i < 20){

        fgets(buffer, MAX_LEN, file);

        int randon = rand()%10;

        if(randon%2==0){
            continue;
        }
        insertEnd(&Head_klausimas, buffer);

        i++;
    }
    fclose(file);

    struct A *current = Head_klausimas;
    char atsak;
    printf("\033[2J\033[H");
    for(i=0; i < 20; i++){
        
        PrintQuestion(current, i);
        gettimeofday(&start, NULL);
        scanf(" %c", &atsak);
        while(isdigit(atsak) == 0){
            printf("Wrong input!\n");
            scanf(" %c", &atsak);
        }
        ats = atsak - '0';
        seconds += isRight(ats, current);
        seconds += timeCounter(start);

        current = current->next;
    
        printf("\033[2J\033[H");
    }
    freelist(Head_klausimas);
    
    struct Lenta Board[10];
    struct Lenta *ptrs[10];

    char vardas[15];
    
    printf("Enter your nickname: ");
    scanf("%s", vardas);
        
    while (strlen(vardas)>15){
        printf("Your choice of nickname is too long (over 15 character)\n Enter your nickname: ");
        scanf("%s", vardas);
    }
    
    
    

    for(i = 0; i < 10; i++){
        ptrs[i] = &Board[i];
    }

    ptrs[0]->time = seconds;
    ptrs[0]->vardas = (char*)malloc(strlen(vardas)+1);
    strcpy(ptrs[0]->vardas, vardas);


    int eilutes = Read_Current_Leaderboard(ptrs);
    
    
    


    SortLeader(ptrs, eilutes);
    
    Export_New_Leaderboard(ptrs, eilutes);
    
    Print_Leader(ptrs, eilutes, vardas);

    struct Lenta *BoardPtr = &Board[1];
    BoardPtr = &Board[0];
    freeboard(BoardPtr, eilutes);

    printf("%.2f\n", seconds);

    return 0;
}


void freelist(struct A *head){

    struct A *temp = NULL;
    
    while(head != NULL){
        temp = head;
        head = head->next;
        free(temp->klausimas);
        free(temp->atsakymai[0]);
        free(temp->atsakymai[1]);
        free(temp->atsakymai[2]);
        free(temp->atsakymai[3]);
        
        free(temp);
    }

}

void freeboard(struct Lenta *Board, int eilutes){

    int i=0;

    for(i=0; i < eilutes; i++){
        
        free(Board->vardas);
        Board++;
    }



}