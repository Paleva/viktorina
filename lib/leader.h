#ifndef LEADER_H
#define LEADER_H

struct Lenta{
    float time;
    char *vardas;
    // struct Lenta *next;
};

void sortLeader(struct Lenta *[]);
void readCurrentLeaderboard(struct Lenta *[], int);
void exportNewLeaderboard(struct Lenta *[], int);

#endif