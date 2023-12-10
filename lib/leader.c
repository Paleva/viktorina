#include "leader.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int Read_Current_Leaderboard(struct Lenta *ptr){
    int eilutes = 0;
    FILE *leaderboard;
    char *filename = "leaderboard.txt";
    leaderboard = fopen(filename, "r");
    // struct Lenta *bPtr = ptr;
    char buffer[255];

    if(leaderboard == NULL){
        exit(3);
    }

    char *token;
    for(int i=0; i < 10; i++){
        if(fgets(buffer, 255, leaderboard) == NULL){
            break;
        }
        eilutes++;
        printf("%s", buffer);
        token = strtok(buffer, ";");
        ptr->vardas = (char*)malloc(strlen(token)+1);
        strcpy(ptr->vardas, token);
        token = strtok(NULL, ";");
        ptr->time=atof(token);
        ptr++;
    }
    fclose(leaderboard);
    return eilutes;
    
}   

void SortLeader(struct Lenta Board[], int eilutes){

    for(int i=0; i < eilutes+1; i++){
        for(int j=0; j < eilutes; j++)
            if(Board[j].time > Board[j+1].time){
                struct Lenta temp = Board[j];
                Board[j] = Board[j+1];
                Board[j+1] = temp;
            }
        
    }
}

void Export_New_Leaderboard(struct Lenta Board[], int eilutes){

    char *filename = "leaderboard.txt";
    FILE *leaderboard = fopen(filename, "w");
   
    for(int i=0; i < eilutes+1; i++){
        if(Board[i].vardas == NULL){
            continue;
        }
        else{
            fprintf(leaderboard,"%s;%.2f \n",Board[i].vardas, Board[i].time);
        }
    }
    fclose(leaderboard);
}
