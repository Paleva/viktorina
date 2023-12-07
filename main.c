#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "lib/questions.h"
#include "lib/questions.c"
#include "lib/gamelogic.h"
#include "lib/gamelogic.c"
#include "lib/console.h"
#include "lib/console.c"
#define MAX_LEN 256

void freelist(struct A *head);

int main(){

    char *temos[5] = {
    "temos/miestai.txt",
    "temos/filmai.txt",
    "temos/muzika.txt",
    "temos/menas.txt",
    "temos/zmones.txt"
    };
    int i = 0;
    int pasirinkimas = 0;

    char buffer[MAX_LEN];
    
    for(i=0; i < sizeof(temos)/sizeof(char*); i++){
        printf("%d. %s \n",i+1, temos[i]);
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

        i++;
    }
    fclose(file);
    struct A *current = Head_klausimas;
    
    

    printf("\033[2J\033[H");
    for(i=0; i < 20; i++){
        
        print(current);
        //reik padaryt cia ivedima atskirtai nuo print 
        //ir patikrinima arba labai jobnutai daryt 
        //kad printas returnina ka iveda zmogus i kita funkcija 
        //kuri patikrina ar teisingas ats nors cia labai bad design man rodos butu nes funkcija "du darbus daro" 
        current=current->next;
    
        printf("\033[2J\033[H");
    }
    
    freelist(Head_klausimas);
    return 0;
}

void freelist(struct A *head){

    struct A *temp = NULL;
    
    while(head != NULL){
        temp = head;
        head = head->next;
        free(temp->klausimas);
        free(temp->atsakymai[0]);
        free(temp->atsakymai[1]);
        free(temp->atsakymai[2]);
        free(temp->atsakymai[3]);
        
        free(temp);
    }

}
