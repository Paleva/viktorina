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
#include "lib/inputs.h"
#include "lib/inputs.c"
#include <sys/time.h>
#define MAX_LEN 256

void freeList(struct A *head);
void freeBoard(struct Lenta *Board, int eilutes);

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
    struct A *headQuestion = NULL;
    FILE *file;

    startingScreen();
    
    pasirinkimas = isSingleDigit(); 
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
        insertEnd(&headQuestion, buffer);
        i++;
    }
    fclose(file);
    char atsak;
    struct A *current = headQuestion;
    printf("\033[2J\033[H");
    for(i=0; i < 20; i++){
        
        printQuestion(current, i);
        gettimeofday(&start, NULL);
        ats = isSingleDigitAns();
        // scanf(" %c", &atsak);
        // while(isdigit(atsak) == 0){
        //     printf("Wrong input!\n");
        //     scanf(" %c", &atsak);
        // }
        seconds += isRight(ats, current);
        seconds += timeCounter(start);

        current = current->next;
    
        printf("\033[2J\033[H");
    }
    freeList(headQuestion);
    
    struct Lenta Board[10];
    struct Lenta *ptrs[10];

    char vardas[15];
    
    printf("Enter your nickname: ");
    scanf("%s", vardas);
        
    while(strlen(vardas) > 15){
        printf("Your choice of nickname is too long (over 15 character)\n Enter your nickname: ");
        scanf("%s", vardas);
    }
    
    for(i = 0; i < 10; i++){
        ptrs[i] = &Board[i];
    }

    ptrs[0]->time = seconds;
    ptrs[0]->vardas = (char*)malloc(strlen(vardas)+1);
    strcpy(ptrs[0]->vardas, vardas);


    int eilutes = readCurrentLeaderboard(ptrs, pasirinkimas);

    sortLeader(ptrs, eilutes);   
    exportNewLeaderboard(ptrs, eilutes, pasirinkimas); 
    printLeader(ptrs, eilutes, vardas, pasirinkimas);

    struct Lenta *BoardPtr = &Board[1];
    BoardPtr = &Board[0];
    freeBoard(BoardPtr, eilutes);

    printf("Your score: %.2f\n", seconds);

    return 0;
}


void freeList(struct A *head){

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

void freeBoard(struct Lenta *Board, int eilutes){

    for(int i=0; i < eilutes; i++){
        
        free(Board->vardas);
        Board++;
    }
}