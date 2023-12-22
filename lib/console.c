#include "questions.h"
#include "console.h"
#include "leader.h"
#include <stdio.h>
#include <string.h>

void printQuestion(struct A *current, int i){
    
    int j=0;
    int ats = 0;
    
    printf("\033[1;34m");
    printf("               +");

    for(j = 0; j < strlen(current->klausimas); j++){
        printf("%s", "-");
    }
        
    printf("+\n");
    printf(" Question %2d:  |\033[36m%s\033[34m| \n",i+1,current->klausimas);
    printf("               +");

    for(j = 0; j < strlen(current->klausimas); j++){
        printf("%s", "-");
    }
    printf("+\n");

    j = 0;
    while(j < 4){
        printf("               ");
        printf("\033[1;34m%d. \033[36m %s \n", j+1, current->atsakymai[j]);
        j++;
    }
    printf("\n");
}


//void Print_Winners();
void startingScreen(){

    printf("\033[2J\033[H");
    printf("\033[0;36m");
    printf("████████╗██████╗░██╗██╗░░░██╗██╗░█████╗░    ░██████╗░██╗░░░██╗██╗███████╗\n");
    printf("╚══██╔══╝██╔══██╗██║██║░░░██║██║██╔══██╗    ██╔═══██╗██║░░░██║██║╚════██║\n");
    printf("░░░██║░░░██████╔╝██║╚██╗░██╔╝██║███████║    ██║██╗██║██║░░░██║██║░░███╔═╝\n");
    printf("░░░██║░░░██╔══██╗██║░╚████╔╝░██║██╔══██║    ╚██████╔╝██║░░░██║██║██╔══╝░░\n");
    printf("░░░██║░░░██║░░██║██║░░╚██╔╝░░██║██║░░██║    ░╚═██╔═╝░╚██████╔╝██║███████╗\n");
    printf("░░░╚═╝░░░╚═╝░░╚═╝╚═╝░░░╚═╝░░░╚═╝╚═╝░░╚═╝    ░░░╚═╝░░░░╚═════╝░╚═╝╚══════╝\n");
    printf("\033[0m"); // Reset
    printf("\033[0;34m");
    printf("\nRULES:\n");
    printf("\033[1;37m");
    printf("\033[0;36m");
    printf("There are 20 questions. There are 4 different answers for each question and only one is correct.\n");
    printf("Your goal is to answer as many questions correct as quickly as possible.\n");
    printf("If you answer a question incorrectly, the system adds ten seconds to the final time (score).\nThe lower the score the better!\n");
    printf("\033[0;34m");
    printf("Subject list:\n");
    printf("\033[1;37m"); // balta
    printf("1 - Cities\n");
    printf("2 - Cinema\n");
    printf("3 - Music\n");
    printf("4 - Art\n");
    printf("5 - People\n");
    printf("\033[0;34m");
    // printf("Select a subject by entering a number:\033[1;37m ");
    printf("\033[0;36m");
    

}


void printLeader(struct Lenta *ptrs[], int eilutes, char vardas[], int pasirinkimas){
    char *topic[5] = {
    "Cities",
    "Cinema",
    "Music",
    "Art",
    "People"
    };
    printf("\033[2J\033[H");
    printf("┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
    printf("┃               %7s                 ┃\n", topic[pasirinkimas-1]);
    printf("┃               LEADERBOARD             ┃\n");
    printf("┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
    for(int i = 0; i < eilutes; i++)
    {
        if(strcmp(vardas, ptrs[i]->vardas) == 0 ){
            printf("┃->%2d.  %15s    \033[34mScore:\033[36m %6.2f┃\n",i+1, ptrs[i]->vardas, ptrs[i]->time);
        }   
        else {
            printf("┃%4d.  %15s    \033[34mScore:\033[36m %6.2f┃\n",i+1, ptrs[i]->vardas, ptrs[i]->time);
        }
        
    }
    printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");

}

void printScore(double seconds){
    // printf("\033[2J\033[H");
    printf("\033[0;36m");
    printf("Your score: %.2f\n", seconds);
    printf("\033[0m");
}

void clearConsole(){
    printf("\033[2J\033[H");
}