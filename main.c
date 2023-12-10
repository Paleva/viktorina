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
#include <sys/time.h>
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
    float laikas = 0;    int ats = 0;
    int points = 0;
    struct timeval start, end;
    double seconds = 0.0;

    char *NewName; // "Vladislavas";

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
//    for(i = 0; i < sizeof(temos)/sizeof(char*); i++){
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
    
    
    int tsk;
    
    printf("\033[2J\033[H");
    for(i=0; i < 20; i++){
        
        PrintQuestion(current, i);
        gettimeofday(&start, NULL);
        scanf("%d", &ats);
        seconds += isRight(ats, current);
        seconds += timeCounter(start);

        current = current->next;
    
        printf("\033[2J\033[H");
    }
    freelist(Head_klausimas);
    

    struct Lenta Board[11];

    struct Lenta *ptrBoard = &Board[0];
    int eilutes = 1;
    eilutes = Read_Current_Leaderboard(ptrBoard);

    ptrBoard = &Board[0];
    Board[eilutes].time = seconds;
    NewName = "Agurkelis";
    Board[eilutes].vardas = (char*)malloc(strlen(NewName)+1);
    strcpy(Board[eilutes].vardas, NewName);
    ptrBoard = &Board[0];
    SortLeader(Board, eilutes);
    Export_New_Leaderboard(Board);

    printf("%.2f\n", seconds);

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
