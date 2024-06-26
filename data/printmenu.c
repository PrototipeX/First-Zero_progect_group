#include "global.h"

void printmenu(struct pole* pole) {
    int h = pole->h;
    int w = pole->w;
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if ((y == 0 && x != -1) || (y == h - 1 && x != -1 && x != w)) {
                printf("-");
            } else if ((x == 0 && y != 0) ||
                       (x == w - 1 && x != 0 && y != h - 1 && y != 3 && y != 4 && y != 5) ||
                       (x == w - 1 && y == 3)) {
                printf("|");
            } else if ((x == w - 11 && y != h - 1 && y == 4) || (x == w - 7 && y != h - 1 && y == 5)) {
                printf("|");
            } else if ((x == (w / 2) - 5 && y == 4)) {
                printf("1. PlayGame");
            } else if ((x == (w / 2) - 5 && y == 5)) {
                printf("2. Exit");
            } else
                printf(" ");
        }
        printf("\n");
    }
}