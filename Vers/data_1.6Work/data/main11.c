#include "global.h"

int main() {
    int flag = -2;
    char player->hero_name[50] = {};
    while (flag != 2) {
        goblin(&flag, player->hero_name, sizeof(player->hero_name));
    }
    printf("\33[0d\33[2J");
    printf("\nGame over!\n\n");
    return 0;
}