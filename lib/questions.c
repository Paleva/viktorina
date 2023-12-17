
#include "questions.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

struct A *allocNode(char buffer[]){

    char *token;
    char *delim = ";";
    char *delim_2 = ",";
    char *answers = NULL;
    int i = 0;
    struct A *newnode = (struct A*)malloc(sizeof(struct A));

    
    if(newnode == NULL){
        exit(2);
    }
    
    token = strtok(buffer, delim);
    newnode->klausimas = (char*)malloc(strlen(token)+1);
    if(newnode->klausimas == NULL){
        exit(2);
    }
    strcpy(newnode->klausimas, token);
    //printf("%s \n", newnode->klausimas);


    token = strtok(NULL, delim);
    answers = (char*)malloc(strlen(token)+2); //fix naxui segmentation
    strcpy(answers, token);
    // printf("%s \n", answers);



    token = strtok(NULL, delim);
    newnode->teisingas = atoi(token);
    //printf("%d \n", newnode->teisingas);

    token = strtok(answers, delim_2);
    for(i=0; i < 4; i++){

            newnode->atsakymai[i] = (char *)malloc(strlen(token)+1);

            if(newnode->atsakymai[i] == NULL){
                exit(2);
            }

            strcpy(newnode->atsakymai[i], token);
            token = strtok(NULL, delim_2);

            //printf("%s ", newnode->atsakymai[i]);


    }
    
    newnode->next = NULL;
    free(answers);
    
    return newnode;
}

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

