#ifndef READ_H_INCLUDED
#define READ_H_INCLUDED

struct A{

    char *klausimas;
    char *atsakymai[4];
    int teisingas;
    struct A *next;

};

void insertEnd(struct A **, char []);
struct A *allocNode(char []);




#endif // READ_H_INCLUDED
