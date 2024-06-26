#include "global.h"
;
int goblin_battle(int* flag, struct pole* pole, struct goblin* goblin, struct player* player, int size) {
    int game = 0;
    menu(pole, &game);  // cont menu
    // printf("game goblin = %d\n", game);
    *flag = game;
    int timerand = 0;
    if (game == 1) {
        int ax = 0, ay = 0;
        ax = seedrand(timerand) * 1.0 / RAND_MAX * 18 + 1;
        ay = seedrand(timerand) * 1.0 / RAND_MAX * 8 + 1;
        helloHero(pole, player, size);  // inter hero name
        // printf("Name3: %s\n", player->hero_name);
        intro();
        play(&game, pole, goblin, player, ax, ay);
    }
    // printf("Game dododo %d\n", *flag);
    return 0;
}