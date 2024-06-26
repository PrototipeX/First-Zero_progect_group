#include "global.h"

int main() {
    int flag = -2;
    struct player* player;
    player = (struct player*)malloc(sizeof(struct player));
    struct goblin* goblin;
    goblin = (struct goblin*)malloc(sizeof(struct goblin));
    struct pole* pole;
    pole = (struct pole*)malloc(sizeof(struct pole));
    pole->h = 10;
    pole->w = 69;
    player->player_gold = 0;
    player->player_health = 10;
    player->player_attack = 1;
    player->player_defence = 1;
    player->player_experiances = 0;
    player->player_level = 1;
    while (flag != 2) {
        goblin_battle(&flag, pole, goblin, player, sizeof(&(player)->hero_name));
    }
    printf("\33[0d\33[2J");
    gameover(pole);
    free(player);
    player = NULL;
    free(goblin);
    goblin = NULL;
    free(pole);
    pole = NULL;
    return 0;
}