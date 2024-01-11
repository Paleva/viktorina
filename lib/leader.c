#include "leader.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX_LEN 255
void readCurrentLeaderboard(struct Lenta *ptr[], int pasirinkimas){
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
        printf("Failed to open leaderboard file\n");
        exit(3);
    }

    char buffer[MAX_LEN];
    int i = 0;

    char *token;
    for(i = 0; i < 10; i++){

        if(fgets(buffer, MAX_LEN, leaderboard) == NULL){
            break;
        }
        token = strtok(buffer, ";");
        ptr[i]->vardas = (char*)malloc(strlen(token)+1);
        if(ptr[i]->vardas == NULL){
            printf("Failed to allocate memory\n");
            exit(2);
        }
        strcpy(ptr[i]->vardas, token);
        token = strtok(NULL, "");
        if(token == NULL){
            // printf("lmao\n");
            continue;
        }
        ptr[i]->time=atof(token);
        // printf("%s, %.2f \n", ptr[i]->vardas, ptr[i]->time);
    
    }
    fclose(leaderboard);
}   

void sortLeader(struct Lenta *ptrs[]){

    int i, j;
    for(i = 0; i < 11 - 1; i++){
        if(ptrs[i]->time == 0){
            break;
        }
        for(j = 0; j < 11-i-1; j++){
            if(ptrs[j]->time > ptrs[j+1]->time){    
                struct Lenta *temp = ptrs[j];
                ptrs[j] = ptrs[j+1];
                ptrs[j+1] = temp;
            }
        }
    }
}

void exportNewLeaderboard(struct Lenta *ptrs[], int pasirinkimas){

    char *filename[5] = {
    "leaderboards/miestaiLeader.txt",
    "leaderboards/filmaiLeader.txt",
    "leaderboards/muzikaLeader.txt",
    "leaderboards/menasLeader.txt",
    "leaderboards/zmonesLeader.txt"
    };
    FILE *leaderboard = fopen(filename[pasirinkimas-1], "w");
    
    if(leaderboard == NULL){
        printf("Failed to open leaderboard file\n");
        exit(3);
    }

    for(int i = 0; i < 10; i++){
        if(ptrs[i]->time == 0xFFFFFFFF){
            break;
        }
        fprintf(leaderboard,"%s;%.2f \n",ptrs[i]->vardas, ptrs[i]->time);
        
    }

    fclose(leaderboard);
}
