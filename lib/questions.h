#ifndef QUESTIONS_H
#define QUESTIONS_H

struct A{

    char *klausimas;
    char *atsakymai[4];
    int teisingas;
    struct A *next;

};

void insertEnd(struct A **, char []);
struct A *allocNode(char []);

// #include "questions.c"


#endif // QUESTIONS_H_INCLUDED
