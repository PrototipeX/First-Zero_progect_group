#include "global.h"
;
int main(void) {
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