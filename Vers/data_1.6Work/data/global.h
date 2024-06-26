#ifndef GLOBAL_H
#define GLOBAL_H

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int battle(int player->player_gold);
int goblin(int *flag, char *player->hero_name, int size);
void helloHero(char *player->hero_name, int size);
int seedrand(int timerand);
int menu(int *game);
int get_variant(int count);
void printmenu();
void gamekey();
char compaund(char action);

#endif