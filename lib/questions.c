#include <stdlib.h>
#include "questions.h"

struct A *allocNode(char buffer[]){

    char *token;
    char *answers;
    struct A *newnode = (struct A*)malloc(sizeof(struct A));

    if(newnode == NULL){
        exit(2);
    }

    token = strtok(buffer, ";");
    newnode->klausimas = (char*)malloc(strlen(token)+1);
    if(newnode->klausimas == NULL){
        exit(2);
    }
    strcpy(newnode->klausimas, token);
    //printf("%s \n", newnode->klausimas);


    token = strtok(NULL, ";");
    strcpy(answers, token);



    token = strtok(NULL, ";");
    newnode->teisingas = atoi(token);
    //printf("%d \n", newnode->teisingas);

    token = strtok(answers, " ");
    for(int i=0; i < 4; i++){

            if(token == NULL){
                newnode->atsakymai[i] = NULL;
                break;
            }

            newnode->atsakymai[i] = (char *)malloc(strlen(token)+1);

            if(newnode->atsakymai[i] == NULL){
                exit(2);
            }

            strcpy(newnode->atsakymai[i], token);

            //printf("%s ", newnode->atsakymai[i]);

            token = strtok(NULL, " ");

    }
    newnode->next = NULL;
    return newnode;
};

void insertEnd(struct A **head, char buffer[]){

    struct A *newnode = allocNode(buffer);

    if(*head == NULL){
        *head = newnode;
        return;
    }

    struct A *current = *head;

    while(current->next != NULL){
        current = current->next;
    }

    current->next = newnode;

}

