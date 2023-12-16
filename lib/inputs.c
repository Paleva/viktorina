#include "inputs.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_LEN 256

int isSingleDigitChoice(){
    char input[MAX_LEN];
    int valid = 0;
    do {
        printf("\033[0;34mSelect a subject by entering a number:\033[1;37m ");
        if (fgets(input, MAX_LEN, stdin) == NULL) {
            continue; 
        }

        if ((input[0]-'0' >= 1 && input[0]-'0' <= 5)) {
            valid = 1;
        } else {
            printf("Invalid input. Please enter a single digit from the given topics.\n");           
        }
    } while (valid == 0);

    return input[0]-'0';
}

int isSingleDigitAns(){
    char input[MAX_LEN]; 
    int valid = 0;

    do {
        
        printf("Enter the answer: "); 
        if (fgets(input, MAX_LEN, stdin) == NULL) {
            continue; 
        }
        if ((input[0]-'0' >= 1 && input[0]-'0' <= 4)) {
            valid = 1;
        } else {
            printf("Invalid input.\n");
        }
    } while (valid == 0);

    return input[0]-'0';
}