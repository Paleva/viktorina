#ifndef CONSOLE_H
#define CONSOLE_H
#include "leader.h"

void printLeader(struct Lenta *[], char [], int);
void printQuestion(struct A *current, int i);
void startingScreen();
void clearConsole();
void printScore(double);

#endif