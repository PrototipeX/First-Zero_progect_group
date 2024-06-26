#include "global.h"

void gamekey(struct pole* pole) {
    int h = pole->h;
    int w = pole->w;
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if ((y == 0 && x != -1) || (y == h - 1 && x != -1 && x != w)) {
                printf("-");
            } else if ((x == 0 && y != 0) || (x == w - 1 && x != 0 && y != h - 1 && y != 2 && y != 3 &&
                                              y != 4 && y != 5 && y != 6)) {
                printf("|");
            } else if ((x == w - 6 && y != h - 1 && y == 2) || (x == w - 8 && y != h - 1 && y == 3) ||
                       (x == w - 8 && y != h - 1 && y == 4) || (x == w - 9 && y != h - 1 && y == 5) ||
                       (x == w - 8 && y != h - 1 && y == 6)) {
                printf("|");
            } else if ((x == (w / 2) - 5 && y == 2)) {
                printf("w - up");
            } else if ((x == (w / 2) - 5 && y == 3)) {
                printf("s - down");
            } else if ((x == (w / 2) - 5 && y == 4)) {
                printf("a - left");
            } else if ((x == (w / 2) - 5 && y == 5)) {
                printf("d - right");
            } else if ((x == (w / 2) - 5 && y == 6)) {
                printf("m - menu");
            } else
                printf(" ");
        }
        printf("\n");
    }
}