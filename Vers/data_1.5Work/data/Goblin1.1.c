#include "global.h"
;
int goblin(int *flag) {
    char mass[10][21];
    char player->hero_name[8] = {};
    int i, key;
    int x = 10, y = 5;
    int ox, oy;
    int ax = 0, ay = 0;
    int stage = 1;
    int player->player_gold = 0;
    int game = 0;
    menu(&game);  // cont menu
    printf("game goblin = %d\n", game);
    *flag = game;
    if (game == 1) {
        helloHero(&player->hero_name[8]);  // inter hero name
        printf("Name2: %s\n", player->hero_name);
        int timerand = 0;
        ax = seedrand(timerand) * 1.0 / RAND_MAX * 18 + 1;
        ay = seedrand(timerand) * 1.0 / RAND_MAX * 8 + 1;
        do {
            printf("\33[0d\33[2J");
            gamekey();  // point key
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
            printf("Status do %d\n", *flag);
            ox = x;
            oy = y;
            key = getchar();
            if (key == 'w') y--;
            if (key == 's') y++;
            if (key == 'a') x--;
            if (key == 'd') x++;
            if (key == 'm') menu(&game);
            *flag = game;
            printf("Game do %d\n", *flag);
            if (mass[y][x] == '#' || mass[y][x] == '=') {
                x = ox;
                y = oy;
            }
            if ((x == ax && y == ay)) {
                int timerand = 0;
                ax = seedrand(timerand) * 1.0 / RAND_MAX * 18 + 1;
                ay = seedrand(timerand) * 1.0 / RAND_MAX * 8 + 1;
                player->player_gold = battle(player->player_gold);
            }
            printf("Game dodo %d\n", *flag);
        } while (*flag != 2);
    }
    printf("Game dododo %d\n", *flag);
    return 0;
}
/*int timerand;
            ax = rand() * 1.0 / seedrand(int timerand) * 18 + 1;
            ay = rand() * 1.0 / seedrand(int timerand) * 8 + 1;

            ax = rand() * 1.0 / RAND_MAX * 18 + 1;
            ay = rand() * 1.0 / RAND_MAX * 8 + 1;


*/