#include "questions.h"
#include "console.h"
#include <stdio.h>
#include <string.h>

void PrintQuestion(struct A *current){
   
    int j=0;
    int ats = 0;
    
    printf("\033[1;34m");
    printf("              +");

    for(j=0; j < strlen(current->klausimas); j++){
        printf("%s", "-");
    }
        
    printf("+\n");
    printf("              |\033[36m%s\033[34m| \n",current->klausimas);
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

    printf("Iveskite atsakyma: ");
}


//void Print_Winners();
//void Starting_Screen