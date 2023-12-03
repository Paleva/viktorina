#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
//#include "read.c"
#define MAX_LEN 256



struct Question{

    char *klausimas;
    char *atsakymai;
    int teisingas;
    struct Question *next;

};

void insertEnd(struct Question **head, char buffer[]);
struct Question *allocNode(char buffer[]);

int main(){

    char *temos[5] = {
    "miestai.txt",
    "filmai.txt",
    "muzika.txt",
    "menas.txt",
    "zmones.txt"
    };
    int i;
    int pasirinkimas;

    char buffer[MAX_LEN];

    for(i=0; i < sizeof(temos)/sizeof(char*); i++){
        printf("%d.%s \n",i+1, temos[i]);
    }

    printf("Pasirinkite tema ivede skaiciu: ");
    scanf("%d", &pasirinkimas);

    char *path = "\\Questions\\";

    struct Question *Head_klausimas = NULL;
    srand(time(NULL));

    //printf("%s", pasirinkimas);

    FILE *file;

    strcat(path, temos[pasirinkimas-1]);

    file = fopen(path, "r");

    if(file == NULL){
        exit(1);
    }

    char *token;

    while(fgets(buffer, MAX_LEN, file)){

        int randon = rand()%10;

        if(randon%2==0){
            continue;
        }


        insertEnd(&Head_klausimas, buffer);
    }


    return 0;
}

struct Question *allocNode(char buffer[]){

    char *token;
    struct Question *newnode = (struct Question*)malloc(sizeof(struct Question));

    if(newnode == NULL){
        exit(2);
    }

    token = strtok(buffer, ";");
    newnode->klausimas = (char*)malloc(strlen(token)+1);
    if(newnode->klausimas == NULL){
        exit(2);
    }
    strcpy(newnode->klausimas, token);
    printf("%s \n", newnode->klausimas);

    token = strtok(NULL, ";");
    newnode->atsakymai = (char*)malloc(strlen(token)+1);
    if(newnode->atsakymai == NULL){
        exit(2);
    }
    strcpy(newnode->atsakymai, token);
    printf("%s \n", newnode->atsakymai);

    token = strtok(NULL, ";");
    newnode->teisingas = atoi(token);
    printf("%d \n", newnode->teisingas);

    newnode->next = NULL;
    return newnode;
};

void insertEnd(struct Question **head, char buffer[]){

    struct Question *newnode = allocNode(buffer);

    if(*head == NULL){
        *head = newnode;
        return;
    }

    struct Question *current = *head;

    while(current->next != NULL){
        current = current->next;
    }

    current->next = newnode;

}

