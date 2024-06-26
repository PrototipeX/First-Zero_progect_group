#include "global.h"

void menu() {
    int game = 0;
    printf("\33[0d\33[2J");

    while (game != 2) {
        printmenu(&game);
        break;
    }
    printf("%d\n", game);
}
