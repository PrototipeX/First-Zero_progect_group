#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int get_variant(int count) {
    int variant;
    char s[100];
    scanf("%s", s);
    while (sscanf(s, "%d", &variant) != 1 || variant < 1 || variant > count) {
        printf("Incorrect input. Try again: ");
        scanf("%s", s);
    }
    return variant;
}
int printmenu(int game) {
    int h = 10;
    int w = 21;
    int variant = 0;
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
    do {
        variant = get_variant(2);
        switch (variant) {
            case 1:
                printf("\33[0d\33[2J");
                printf("you choice play\n");
                break;
        }
    } while (variant != 2);
    game = variant;
    printf("\33[0d\33[2J");
    return game;
}
int main() {
    int game = 1;
    printf("\33[0d\33[2J");
    //   int len;
    //   len = strlen(menu);
    while (game == 1) {
        printmenu(game);
        break;
    }
    return 0;
}
