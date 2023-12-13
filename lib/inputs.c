#include "inputs.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void clearInputBuffer(){
    while ((getchar()) != '\n');
}

int isSingleDigit(){
    char input[3]; // Buffer size 3: one for the digit, one for the newline, and one for the null terminator
    int valid = 0;
    do {
        printf("\033[0;34mSelect a subject by entering a number:\033[1;37m ");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            continue; 
        }

        // Check if the input is exactly 2 characters long and the first character is a digit
        if (isdigit(input[0]) && input[1] == '\n') {
            valid = 1;
            clearInputBuffer();
        } else {
            printf("Invalid input. Please enter a single digit from the given topics.\n"); 
            clearInputBuffer();
            
        }
    } while (valid == 0);

    return input[0]-'0';
}

int isSingleDigitAns(){
    char input[3]; // Buffer size 3: one for the digit, one for the newline, and one for the null terminator
    int valid = 0;

    do {
        
        printf("Enter the answer: "); 
        if (fgets(input, sizeof(input), stdin) == NULL) {
            // Handle input error or EOF
            clearInputBuffer();
            continue; 
        }

        // Check if the input is exactly 2 characters long and the first character is a digit
        if (strlen(input) == 2 && isdigit(input[0])) {
            valid = 1;
            clearInputBuffer();
        } else {
            clearInputBuffer();
            printf("Invalid input.\n");
        }
    } while (valid == 0);

    return input[0]-'0';
}

