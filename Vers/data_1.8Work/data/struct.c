
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct player {
    char player->hero_name[50];
    int player->player_gold;
    int count;
} player;

int main() {
    struct player player = {"Kod19", 0, 0};
    printf("%s\n", player->player->hero_name);
    printf("%d\n", player->player->player_gold);
    printf("%d\n", player->count);
    return 0;
}

/*typedef struct player {
    char player->hero_name[name_length];
    int player->player_gold;
    int count;
} player;
  player pt;
    pt.player->hero_name[50] = '11';
    pt.count = 1;
    pt.player->player_gold = 1000;

    printf("%s\n", pt.player->hero_name);
    printf("%d\n", pt.count);
    printf("%d\n", pt.player->player_gold);*/