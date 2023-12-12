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

    printf("Enter the answer: "); 
}


//void Print_Winners();
int startingScreen(int ats){
    char input;
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
    printf("There are 20 questions. There are 4 different options for each question and only one is correct.\n");
    printf("Your goal is to get as many correct answers as possible as quickly as possible.\n");
    printf("If you make a mistake, the system adds five seconds to the final time.\n");
    printf("\033[0;34m");
    printf("Subject list:\n");
    printf("\033[1;37m"); // balta
    printf("%d - Cities\n",1);
    printf("%d - Cinema\n",2);
    printf("%d - Music\n",3);
    printf("%d - Art\n",4);
    printf("%d - People\n",5);
    printf("\033[0;34m");
    printf("Select a subject by entering a number:\033[1;37m ");
    scanf(" %c", &input);
    while(isdigit(input) == 0){
        printf("\033[0;36mPick a topic from the list by entering the number besides it:\033[1;37m ");
        scanf(" %c", &input);
    }
    ats = input - '0';
    printf("\033[0;36m");
    return ats;

}


void printLeader(struct Lenta *ptrs[], int eilutes, char vardas[], int pasirinkimas){
    char *filename[5] = {
    "Cities",
    "Cinema",
    "Music",
    "Art",
    "People"
    };
    printf("\033[2J\033[H");
    printf("┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
    printf("┃               %7s                 ┃\n", filename[pasirinkimas-1]);
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
