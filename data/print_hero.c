#include "global.h"

void print_hero(struct player* player) {
    printf("+--------+---------+-------+\n");
    printf("| Status |  Count  | Modif |\n");
    printf("+--------+---------+-------+\n");
    player->count = 6;
    printf("| Name   | %7s | ----- |\n", player->hero_name);
    printf("| Gold   | %7d | ----- |\n", player->player_gold);
    printf("| Health | %7d | ----- |\n", player->player_health);
    printf("| Attack | %7d | ----- |\n", player->player_attack);
    printf("| Defense| %7d | ----- |\n", player->player_defence);
    printf("| Exp    | %7d | ----- |\n", player->player_experiances);
    printf("| Level  | %7d | ----- |\n", player->player_level);
    printf("+--------+---------+-------+\n");
}