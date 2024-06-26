#ifndef GLOBAL_H
#define GLOBAL_H

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int battle(int player->player_gold);
char helloHero(char *player->hero_name);
int seedrand(int timerand);
int menu(int *game);
int get_variant(int count);
int goblin(int *mode);
void printmenu();
void gamekey();

#endif