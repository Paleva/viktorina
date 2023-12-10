#ifndef LEADER_H
#define LEADER_H

struct Lenta{
    float time;
    char *vardas;
    // struct Lenta *next;
};

void SortLeader(struct Lenta Board[], int eilutes);
int Read_Current_Leaderboard(struct Lenta *ptr);
void Export_New_Leaderboard(struct Lenta Board[]);

#endif