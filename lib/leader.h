#ifndef LEADER_H
#define LEADER_H

struct Lenta{
    float time;
    char *vardas;
    // struct Lenta *next;
};

void sortLeader(struct Lenta *[], int );
int readCurrentLeaderboard(struct Lenta *[], int);
void exportNewLeaderboard(struct Lenta *[], int, int);

#endif