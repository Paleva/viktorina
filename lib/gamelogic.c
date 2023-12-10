
#include "questions.h"
#include "gamelogic.h"
#include <stdio.h>
#include <time.h>
#include <sys/time.h>


double isRight(int ats, struct A *current){

    if(ats == current->teisingas){
        printf("%d\n", current->teisingas);
        return 0;
    }
    else{
        printf("%d\n", current->teisingas);
        return 2.0;
    }
}
double timeCounter(struct timeval start){

    struct timeval end;

    gettimeofday(&end, NULL);
    double startTime = start.tv_sec * 1000 + start.tv_usec / 1000.0;
    double endTime = end.tv_sec * 1000 + end.tv_usec / 1000.0;
    double seconds = (endTime - startTime)/1000;
    
    return seconds;
}

//void Points_Counter(){}