#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/time.h>
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
#include "lib/free.h"
#include "lib/free.c"
#define MAX_LEN 255

int main(){

    srand(time(NULL));
    char *temos[5] = {
    "temos/miestai.txt",
    "temos/filmai.txt",
    "temos/muzika.txt",
    "temos/menas.txt",
    "temos/zmones.txt"
    };
    int i = 0;
    char buffer[MAX_LEN];
    int ats = 0;
    struct timeval start, end;
    double seconds = 0.0;
    struct A *headQuestion = NULL;
    FILE *file;

    startingScreen();
    
    int pasirinkimas = isSingleDigitChoice(); 
    file = fopen(temos[pasirinkimas-1], "r");

    if(file == NULL){
        printf("Failed to open file\n");
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

    struct A *current = headQuestion;

    printf("\033[2J\033[H");
    for(i=0; i < 20; i++){
        
        printQuestion(current, i);
        gettimeofday(&start, NULL);
        ats = isSingleDigitAns();
        seconds += isRight(ats, current);
        seconds += timeCounter(start);
        current = current->next;
        printf("\033[2J\033[H");
    
    }
    freeList(headQuestion);
    
    struct Lenta Board[10];
    struct Lenta *ptrs[10];

    for(i = 0; i < 10; i++){
        ptrs[i] = &Board[i];
    }

    ptrs[0]->time = seconds;

    char *nick = Nickname();

    ptrs[0]->vardas = (char*)malloc(strlen(nick)+1);
    if(ptrs[0]->vardas == NULL){
        printf("Failed to allocate memory\n");
        exit(2);
    }
    strcpy(ptrs[0]->vardas, nick);

    int eilutes = readCurrentLeaderboard(ptrs, pasirinkimas);
    printf("%d", eilutes);

    sortLeader(ptrs, eilutes);   
    exportNewLeaderboard(ptrs, eilutes, pasirinkimas); 
    printLeader(ptrs, eilutes, nick, pasirinkimas);
    free(nick);

    struct Lenta *BoardPtr = &Board[0];
    freeBoard(BoardPtr, eilutes);

    printf("Your score: %.2f\n", seconds);

    return 0;
}

