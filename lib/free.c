#include "questions.h"
#include "leader.h"
#include <stdlib.h>

void freeList(struct A *head){

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

void freeBoard(struct Lenta *Board, int eilutes){

    for(int i=0; i < eilutes; i++){
        
        free(Board->vardas);
        Board++;
    }
}