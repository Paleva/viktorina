#include "questions.h"
#include "leader.h"
#include <stdlib.h>

void freeList(struct A *head){

    struct A *temp = NULL;
    
    while(head != NULL){
        temp = head;
        head = head->next;
        free(temp->klausimas);
        
        for(int i=0; i < 4; i++){
            free(temp->atsakymai[i]);
        }
        
        free(temp);
    }

}

void freeBoard(struct Lenta *Board[]){

    for(int i=0; i < 11; i++){
        free(Board[i]->vardas);
    }
}