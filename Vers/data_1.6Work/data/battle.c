#include "global.h"

int battle(int player->player_gold) {
    char action;
    int timerand = 0;
    printf("\33[0d\33[2J");
    printf("You attaked by goblin.'A'ttack or 'R'un\n");
    getchar();
    action = getchar();
    while (action != 'r') {
        if (action == 'a' || action == 'A') {
            int goblin_gold = seedrand(timerand) % 15;
            for (int goblin_hp = seedrand(timerand) % 5; goblin_hp >= 0; goblin_hp--) {
                if (goblin_hp != 5) printf("You kick goblin(%d)\n", goblin_hp);
                if (goblin_hp == 0) {
                    printf("You defeat it.\n");
                    player->player_gold += goblin_gold;
                    printf("You found %d gold\n", goblin_gold);
                    printf("You have %d gold total\n", player->player_gold);
                    break;
                }
            }
        }
        printf("Next action? Goblin.'A'ttack or 'R'un\n ");
        getchar();
        action = getchar();
    }
    if (action == 'r' || action == 'R')
        printf("You've decided to run away! You Earned %d gold\n ", player->player_gold);
    return player->player_gold;
}