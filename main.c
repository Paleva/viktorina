#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/time.h>
#include "lib/questions.h"
#include "lib/gamelogic.h" 
#include "lib/console.h"
#include "lib/leader.h"
#include "lib/inputs.h"
#include "lib/free.h"
#define MAX_LEN 255
#define KLAUSIMU_SKAICIUS 20

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
    //print starting screen
    startingScreen();
    
    int pasirinkimas = isSingleDigitChoice(); 
    file = fopen(temos[pasirinkimas-1], "r");
    //open topic file
    if(file == NULL){
        printf("Failed to open topic file\n");
        exit(1);
    }
    //read questions from file
    while(i < KLAUSIMU_SKAICIUS){
        fgets(buffer, MAX_LEN, file);
        int randon = rand()%10; // 0-9
        if(randon%2==0){ // 50% chance to skip question (astronomical chances to skip all questions)
            continue;
        }
        insertEnd(&headQuestion, buffer);
        i++;
    }
    fclose(file);
    //main game loop prints questions and checks answers and counts the time (score)
    struct A *current = headQuestion;
    printf("\033[2J\033[H");
    for(i=0; i < KLAUSIMU_SKAICIUS; i++){
        
        printQuestion(current, i);
        gettimeofday(&start, NULL);
        ats = isSingleDigitAns();
        seconds += isRight(ats, current);
        seconds += timeCounter(start);
        current = current->next;
        printf("\033[2J\033[H");
    
    }
    //free memory for the questions
    freeList(headQuestion);
    
    //leaderboard
    struct Lenta Board[10];
    struct Lenta *boardPtrs[10];
    for(i = 0; i < 10; i++){
        boardPtrs[i] = &Board[i];
    }
    boardPtrs[0]->time = seconds;
    //get nickname  
    char *nick = Nickname();
    boardPtrs[0]->vardas = (char*)malloc(strlen(nick)+1);
    if(boardPtrs[0]->vardas == NULL){
        printf("Failed to allocate memory for nickname\n");
        exit(2);
    }
    strcpy(boardPtrs[0]->vardas, nick);

    int eilutes = readCurrentLeaderboard(boardPtrs, pasirinkimas);
    // printf("%d", eilutes);
    sortLeader(boardPtrs, eilutes);   
    exportNewLeaderboard(boardPtrs, eilutes, pasirinkimas); 
    printLeader(boardPtrs, eilutes, nick, pasirinkimas);
    free(nick);

    //free memory for the leaderboard
    struct Lenta *BoardPtr = &Board[0];
    freeBoard(BoardPtr, eilutes);

    printScore(seconds);
    waitForInput();
    clearConsole();
    return 0;
}
