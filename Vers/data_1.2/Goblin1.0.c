
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
    printf("\33[0d\33[2J");
    printf("You attaked by goblin.'A'ttack or 'R'un\n");
    getchar();
    action = getchar();
    while (action != 'r') {
        if (action == 'a' || action == 'A') {
            int goblin_gold = 15;
            printf("1\n");
            for (int goblin_hp = 3; goblin_hp >= 0; goblin_hp--) {
                printf("2\n");
                if (goblin_hp != 3) printf("You kick goblin(%d)\n", goblin_hp);
                printf("3\n");
                if (goblin_hp == 0) {
                    printf("4\n");
                    printf("\33[0d\33[2J");
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

int main() {
    char mass[10][21];
    char player->hero_name[8];
    int i, key;
    int x = 10, y = 5;
    int ox, oy;
    int ax = 2, ay = 3;
    int stage = 1;
    int player->player_gold = 0;

    helloHero(player->hero_name);

    do {
        printf("\33[0d\33[2J");
        sprintf(mass[0], "====================");

        for (i = 1; i < 9; i++) sprintf(mass[i], "#                  #");

        sprintf(mass[9], "====================");

        mass[y][x] = '@';
        mass[ay][ax] = '*';

        for (i = 0; i < 10; i++) printf("%s\n", mass[i]);
        printf("\n");
        printf("Hero \n");
        printf("Name: %s\n", player->hero_name);
        printf("Stage: %d\n", stage);
        printf("Golds: %d\n", player->player_gold);
        ox = x;
        oy = y;
        key = getchar();
        if (key == 'w') y--;
        if (key == 's') y++;
        if (key == 'a') x--;
        if (key == 'd') x++;
        if (mass[y][x] == '#' || mass[y][x] == '=') {
            x = ox;
            y = oy;
        }
        if ((x == ax && y == ay)) {
            ax = rand() * 1.0 / RAND_MAX * 18 + 1;
            ay = rand() * 1.0 / RAND_MAX * 8 + 1;
            player->player_gold = battle(player->player_gold);
        }
    } while (key != 'e');

    return 0;
}