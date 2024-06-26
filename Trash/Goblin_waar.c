
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int helloHero(char * player->hero_name) {
    int len;
    char c;
    printf("What is your name Hero? \n");
    fgets(player->hero_name, sizeof(player->hero_name), stdin);
    len = strlen(player->hero_name);
    if (player->hero_name[len - 1] == '\n')
        player->hero_name[len - 1] = '\0';
    else {
        while ((c = getchar()) != '\n' && c != EOF)
            ;
    }
    return 0;
}

int battle(int player->player_gold) {
    char action;
    printf("You attaked by goblin.'A'ttack or 'R'un\n");
    action = getchar();
    while (action != 'r') {
        if (action == 'a' || action == 'A') {
            int goblin_gold = 15;
            for (int goblin_hp = 3; goblin_hp >= 0; goblin_hp--) {
                if (goblin_hp != 3) printf("You kick goblin(%d)\n", goblin_hp);
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
    if (action == 'r') printf("You've decided to run away! You Earned %d gold\n ", player->player_gold);
    return player->player_gold;
}

int main() {
    char player->hero_name[8];

    helloHero(player->hero_name);

    //   printf("\33[0d\33[2J");

    int player->player_gold = 0;

    player->player_gold = battle(player->player_gold);

    return 0;
}