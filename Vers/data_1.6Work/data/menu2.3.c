#include "global.h"

int menu(int *game) {
    printf("\33[0d\33[2J");

    printmenu();
    int variant = 0;
    variant = get_variant(2);
    *game = variant;
    getchar();
    printf("\33[0d\33[2J");

    printf("game menu = %d\n", *game);
    return 0;
}
