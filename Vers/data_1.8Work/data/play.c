#include "global.h"

void play(int* flag, struct pole* pole, struct goblin* goblin, struct player* player, int ax, int ay) {
    int game = 0, speed;
    char action = 0;
    char mass[10][21];
    int i, key;
    int x = 10, y = 5;
    int ox, oy;
    player->player_gold = 0;
    printf("(*・‿・) Пожалуйста выберите скорость игры (от 1 до 5)\n");

    do {
        printf("\33[0d\33[2J");

        gamekey(pole);  // point key
        printf("\n");
        sprintf(mass[0], "====================");

        for (i = 1; i < 9; i++) sprintf(mass[i], "#                  #");

        sprintf(mass[9], "====================");

        mass[y][x] = '@';
        mass[ay][ax] = 'o';

        for (i = 0; i < 10; i++) printf("%s\n", mass[i]);
        printf("\n");
        print_hero(player);
        // printf("Status do %d\n", *flag);
        ox = x;
        oy = y;
        key = getchar();
        if (key == 'w') y--;
        if (key == 's') y++;
        if (key == 'a') x--;
        if (key == 'd') x++;
        if (key == 'm') menu(pole, &game);
        *flag = game;
        // printf("Game do %d\n", *flag);
        if (mass[y][x] == '#' || mass[y][x] == '=') {
            x = ox;
            y = oy;
        }
        if ((x == ax && y == ay)) {
            int timerand = 0;
            ax = seedrand(timerand) * 1.0 / RAND_MAX * 18 + 1;
            ay = seedrand(timerand) * 1.0 / RAND_MAX * 8 + 1;
            battle(&game, pole, goblin, player, &action);
            *flag = game;
        }
        // printf("Game dodo %d\n", *flag);

    } while (*flag != 2);
}