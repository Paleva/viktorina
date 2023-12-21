#include "leader.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX_LEN 255
int readCurrentLeaderboard(struct Lenta *ptr[], int pasirinkimas){
    int eilutes = 1;
    FILE *leaderboard;
    char *filename[5] = {
    "leaderboards/miestaiLeader.txt",
    "leaderboards/filmaiLeader.txt",
    "leaderboards/muzikaLeader.txt",
    "leaderboards/menasLeader.txt",
    "leaderboards/zmonesLeader.txt"
    };
    leaderboard = fopen(filename[pasirinkimas-1], "r");
    
    if(leaderboard == NULL){
        printf("Failed to open file\n");
        exit(3);
    }

    char buffer[MAX_LEN];
    int i = 0;

    char *token;
    for(i = 1; i < 10; i++){

        if(fgets(buffer, MAX_LEN, leaderboard) == NULL){
            break;
        }
        
        eilutes++;
        token = strtok(buffer, ";");
        ptr[i]->vardas = (char*)malloc(strlen(token)+1);
        strcpy(ptr[i]->vardas, token);
        token = strtok(NULL, ";");
        ptr[i]->time=atof(token);
        // printf("%s, %.2f \n", ptr[i]->vardas, ptr[i]->time);
    
    }
    fclose(leaderboard);
    return eilutes;
    
}   

void sortLeader(struct Lenta *ptrs[], int eilutes){
    if(eilutes == 1){
        return;
    }
    int i, j;
    for(i = 0; i < eilutes - 1; i++){
        for(j = 0; j < eilutes-i-1; j++){
            if(ptrs[j]->time > ptrs[j+1]->time){    
                struct Lenta *temp = ptrs[j];
                ptrs[j] = ptrs[j+1];
                ptrs[j+1] = temp;
            }
        }
    }
}

void exportNewLeaderboard(struct Lenta *ptrs[], int eilutes, int pasirinkimas){

    char *filename[5] = {
    "leaderboards/miestaiLeader.txt",
    "leaderboards/filmaiLeader.txt",
    "leaderboards/muzikaLeader.txt",
    "leaderboards/menasLeader.txt",
    "leaderboards/zmonesLeader.txt"
    };
    FILE *leaderboard = fopen(filename[pasirinkimas-1], "w");
    
    if(leaderboard == NULL){
        printf("Failed to open file\n");
        exit(3);
    }

    for(int i = 0; i < eilutes; i++){
        
        fprintf(leaderboard,"%s;%.2f \n",ptrs[i]->vardas, ptrs[i]->time);
        
    }

    fclose(leaderboard);
}
