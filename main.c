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
#include "lib/leader.h"
#include "lib/leader.c"
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
    srand(time(NULL));
    char buffer[MAX_LEN];

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
//    for(i=0; i < sizeof(temos)/sizeof(char*); i++){
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
// cia pabaiga

    struct A *Head_klausimas = NULL;
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
        
        PrintQuestion(current,i);
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
