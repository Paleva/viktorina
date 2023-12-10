#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
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
void freeboard(struct Lenta Board[], int eilutes);

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
    float laikas = 0;    int ats = 0;
    int points = 0;
    struct timeval start, end;
    double seconds = 0.0;
    char *NewName = NULL; // "Vladislavas";
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
    
    printf("\033[2J\033[H");
    for(i=0; i < 20; i++){
        
        PrintQuestion(current, i);
        gettimeofday(&start, NULL);
        scanf("%d", &ats);
        seconds += isRight(ats, current);
        seconds += timeCounter(start);

        current = current->next;
    
        printf("\033[2J\033[H");
    }
    freelist(Head_klausimas);
    
    struct Lenta Board[10];
    struct Lenta *ptrBoard = &Board[0];

    char vardas[50];
    printf("Iveskite savo slapivardi: ");
    scanf("%s", vardas);
    NewName = (char*)malloc(strlen(vardas)+1);
    strcpy(NewName, vardas);

    int eil = 0;
    eil = Read_Current_Leaderboard(ptrBoard);
    Board[eil].time = seconds;
    Board[eil].vardas = (char*)malloc(strlen(NewName)+1);
    strcpy(Board[eil].vardas, NewName);
    free(NewName);
    

    SortLeader(Board, eil);

    Export_New_Leaderboard(Board, eil);

    freeboard(Board, eil);

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

void freeboard(struct Lenta Board[], int eilutes){

    int i=0;

    for(i=0; i < eilutes+1; i++){
        free(Board[i].vardas);
    }



}