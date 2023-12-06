#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "lib/questions.h"
#include "lib/questions.c"
#define MAX_LEN 256



int main(){

    char *temos[5] = {
    "temos/miestai.txt",
    "temos/filmai.txt",
    "temos/muzika.txt",
    "temos/menas.txt",
    "temos/zmones.txt"
    };
    int i;
    int pasirinkimas;
    int ats;

    char buffer[MAX_LEN];

    for(i=0; i < sizeof(temos)/sizeof(char*); i++){
        printf("%d.%s \n",i+1, temos[i]);
    }

    printf("Pasirinkite tema ivede skaiciu: ");
    scanf("%d", &pasirinkimas);

    struct A *Head_klausimas = NULL;
    srand(time(NULL));

    //printf("%s", pasirinkimas);

    FILE *file;

    file = fopen(temos[pasirinkimas-1], "r");

    if(file == NULL){
        exit(1);
    }

    i = 0;
    while(i < 20){

        fgets(buffer, MAX_LEN, file);

        int randon = rand()%10;

        if(randon%2==0){
            continue;
        }


        insertEnd(&Head_klausimas, buffer);
        //printf("\n");

        i++;
    }
    int j;
    struct A *current = Head_klausimas;
    char *eilute; 
    char *ch = malloc(1);
    ch = "-";

    printf("\033[2J\033[H");
    for(i=0; i < 20; i++){
        printf("\033[1;34m");
        printf("\033[1m");
        printf("              +");

        eilute = (char*)malloc(strlen(current->klausimas));

        for(j=0; j < strlen(current->klausimas); j++){
            printf("%c", *ch);
            strcat(eilute, ch);
        }
        
        printf("+\n");
        printf("              |\033[36m%s\033[34m| \n",current->klausimas);
        printf("              +");
        // for(j=0; j < strlen(current->klausimas); j++){
        //     printf("-");

        // }
        printf("%s", eilute);
        printf("+\n");

        j = 0;
        while(j < 4){
            printf("              ");
            printf("\033[1;34m%d. \033[36m %s \n", j+1, current->atsakymai[j]);
            j++;
        }
        printf("\n");

        printf("Iveskite atsakyma: ");
        scanf("%d", &ats);
        // char c = getchar();
        // sleep(1);
        // putchar(c);

        current=current->next;
        char *nx = "";
        strcpy(eilute, nx);
        printf("\033[2J\033[H");
    }



    return 0;
}

