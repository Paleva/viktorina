#include "console.h"
#include "questions.h"

void print(struct A *current){
   
    int j=0;
    
    
    printf("\033[1;34m");
    printf("              +");

    for(j=0; j < strlen(current->klausimas); j++){
        printf("%c", *ch);
    }
        
    printf("+\n");
    printf("              |\033[36m%s\033[34m| \n",current->klausimas);
    printf("              +");

    for(j=0; j < strlen(current->klausimas); j++){
        printf("%c", *ch);
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
    scanf("%d", &ats); // sita perkelti kitur
    // is_right(ats, current);
    // sleep(1);
        

    
}