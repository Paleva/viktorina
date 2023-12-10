#include "questions.h"
#include "console.h"
#include <stdio.h>
#include <string.h>

void PrintQuestion(struct A *current, int i){
    
    int j=0;
    int ats = 0;
    
    printf("\033[1;34m");
    printf("              +");

    for(j=0; j < strlen(current->klausimas); j++){
        printf("%s", "-");
    }
        
    printf("+\n");
    printf(" Question %d:  |\033[36m%s\033[34m| \n",i+1,current->klausimas);
    printf("              +");

    for(j=0; j < strlen(current->klausimas); j++){
        printf("%s", "-");
    }
    printf("+\n");

    j = 0;
    while(j < 4){
        printf("              ");
        printf("\033[1;34m%d. \033[36m %s \n", j+1, current->atsakymai[j]);
        j++;
    }
    printf("\n");

    printf("Enter the answer: "); 
}


//void Print_Winners();
int Starting_Screen(int pasirinkimas){
    //ce krc perkelt i console.h
    printf("\033[2J\033[H");
    printf("\033[0;36m");
    printf("████████╗██████╗░██╗██╗░░░██╗██╗░█████╗░    ░██████╗░██╗░░░██╗██╗███████╗\n");
    printf("╚══██╔══╝██╔══██╗██║██║░░░██║██║██╔══██╗    ██╔═══██╗██║░░░██║██║╚════██║\n");
    printf("░░░██║░░░██████╔╝██║╚██╗░██╔╝██║███████║    ██║██╗██║██║░░░██║██║░░███╔═╝\n");
    printf("░░░██║░░░██╔══██╗██║░╚████╔╝░██║██╔══██║    ╚██████╔╝██║░░░██║██║██╔══╝░░\n");
    printf("░░░██║░░░██║░░██║██║░░╚██╔╝░░██║██║░░██║    ░╚═██╔═╝░╚██████╔╝██║███████╗\n");
    printf("░░░╚═╝░░░╚═╝░░╚═╝╚═╝░░░╚═╝░░░╚═╝╚═╝░░╚═╝    ░░░╚═╝░░░░╚═════╝░╚═╝╚══════╝\n");
    printf("\033[0m"); // Reset colors
    printf("\033[0;34m");
    printf("Subject list:\n");
    printf("\033[1;37m"); // Set text color to white (bright)
    printf("%d - Cities\n",1);
    printf("%d - Cinema\n",2);
    printf("%d - Music\n",3);
    printf("%d - Art\n",4);
    printf("%d - People\n",5);
    
    printf("\033[0;34m");
    printf("Select a subject by entering a number: ");
    printf("\033[0;36m");
    scanf("%d", &pasirinkimas);
    return pasirinkimas;
}