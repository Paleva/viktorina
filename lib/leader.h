#ifndef LEADER_H
#define LEADER_H

struct Lenta{
    float time;
    char *vardas;
    // struct Lenta *next;
};

void SortLeader(struct Lenta *[], int );
int Read_Current_Leaderboard(struct Lenta *[], int);
void Export_New_Leaderboard(struct Lenta *[], int, int);

#endif