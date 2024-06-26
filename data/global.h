#ifndef GLOBAL_H
#define GLOBAL_H

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

struct player {
    char hero_name[50];
    int player_gold;
    int player_health;
    int player_attack;
    int player_defence;
    int player_experiances;
    int player_level;
    int count;
};
struct goblin {
    int goblin_gold;
    int goblin_health;
    int goblin_attack;
    int goblin_defence;
    int goblin_experiances;
    int goblin_count;
};
struct pole {
    int h;
    int w;
};

void helloHero(struct pole* pole, struct player* player, int size);
int seedrand(int timerand);
void print_hero(struct player* player);
void gamekey(struct pole* pole);
void gameover(struct pole* pole);
void compaund(char* symbol);
int goblin_battle(int* flag, struct pole* pole, struct goblin* goblin, struct player* player, int size);
void play(int* flag, struct pole* pole, struct goblin* goblin, struct player* player, int ax, int ay);
void battle(int* flag, struct pole* pole, struct goblin* goblin, struct player* player, char* action);
int get_variant(int count);
int menu(struct pole* pole, int* game);
void printmenu();
void intro();

#endif