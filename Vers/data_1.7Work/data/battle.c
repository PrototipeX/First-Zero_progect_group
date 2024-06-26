#include "global.h"

void battle(int* flag, int * player->player_gold, char* action) {
    int timerand = 0;
    printf("\33[0d\33[2J");
    printf("You attaked by goblin.'A'ttack or 'R'un\n");
    while (getchar() != '\n')
        ;  // Очистка буфера ввода
    //    printf("Action = %s\n", action);
    *action = getchar();
    while (getchar() != '\n')
        ;  // Очистка буфера ввода
           //    printf("Action = %s\n", action);
    while ((*action != 'r') && (*flag != 2)) {
        compaund(action);
        if (*action == 'a' || *action == 'A') {
            int goblin_gold = seedrand(timerand) % 15;
            for (int goblin_hp = seedrand(timerand) % 5; goblin_hp >= 0; goblin_hp--) {
                if (goblin_hp != 5) printf("You kick goblin(%d)\n", goblin_hp);
                if (goblin_hp == 0) {
                    printf("You defeat it.\n");
                    *player->player_gold += goblin_gold;
                    printf("You found %d gold\n", goblin_gold);
                    printf("You have %d gold total\n", *player->player_gold);
                    continue;
                }
            }
        }
        if (*action != 'r') {
            printf("Action = %s\n", action);
            printf("Your next action? Goblin wait.'A'ttack or 'R'un\n ");
            *action = getchar();
            while (getchar() != '\n')
                ;  // Очистка буфера ввода}
        }
        if (*action == 'm') menu(flag);
    }
    if (*action == 'r' || *action == 'R')
        printf("You've decided to run away! You Earned %ls gold\n ", player->player_gold);
}