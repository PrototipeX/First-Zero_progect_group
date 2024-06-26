#include "global.h"

void battle(int* flag, struct pole* pole, struct goblin* goblin, struct player* player, char* action) {
    int timerand = 0;
    goblin->goblin_count = 0;
    goblin->goblin_experiances = 0;
    printf("\33[0d\33[2J");
    goblin->goblin_count = seedrand(timerand) % 3 + 1;
    printf("There are %d goblins in the squad\n\n", goblin->goblin_count);
    printf("You attaked.'A'ttack or 'R'un: ");
    while (getchar() != '\n')
        ;  // Очистка буфера ввода
    *action = getchar();
    while (getchar() != '\n')
        ;  // Очистка буфера ввода
    do {
        compaund(action);
        if ((*action == 'a' || *action == 'A')) {
            goblin->goblin_gold = seedrand(timerand) % 15;
            int goblin_exp = seedrand(timerand) % 5 + 1;
            for (int goblin_hp = seedrand(timerand) % 5 + 1; goblin_hp >= 0; goblin_hp--) {
                if (goblin_hp != 5) printf("You kick goblin(%d)\n", goblin_hp);
                if (goblin_hp == 0) {
                    printf("You defeat it.\n");
                    player->player_gold += goblin->goblin_gold;
                    player->player_experiances += goblin_exp;
                    goblin->goblin_experiances += goblin_exp;
                    printf("You found %d gold, and received %d experiances\n", goblin->goblin_gold,
                           goblin->goblin_experiances);
                    printf("You have %d gold total\n", player->player_gold);
                    goblin->goblin_count = goblin->goblin_count - 1;
                    continue;
                }
            }
        }
        if ((*action != 'r') && (*action != 'm') && (goblin->goblin_count != 0)) {
            // printf("Action = %s\n", action);
            printf("\nThere are still %d goblins in the squad\n", goblin->goblin_count);
            printf("\nYour next action? Goblin wait.'A'ttack or 'R'un: ");
            *action = getchar();
            while (getchar() != '\n')
                ;  // Очистка буфера ввода}
        }

        if (*action == 'm') menu(pole, flag);
    } while ((*action != 'r') && (*action != 'm') && (*flag != 2) && (goblin->goblin_count != 0));
    if ((*action == 'r' || *action == 'R') && (goblin->goblin_count != 0))
        printf("You've decided to run away! You Earned %d gold\n ", player->player_gold);
    if ((*action != 'r' || *action != 'R') && (goblin->goblin_count == 0))
        printf("\n\nYou've kill ALL goblins! You have %d gold and %d exp\n ", player->player_gold,
               goblin->goblin_experiances);
    printf("\nPress any key for continue\n ");

    while (getchar() != '\n')
        ;  // Очистка буфера ввода}
}