#ifndef GLOBAL_H
#define GLOBAL_H

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int battle(int player->player_gold);
int helloHero(char *player->hero_name);
int seedrand(int timerand);
void printmenu();
int get_variant(int count);
void menu();

#endif