#include "global.h"
void helloHero(struct pole* pole, struct player* player, int size) {
    int h = pole->h;
    int w = pole->w;
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if ((y == 0 && x != -1) || (y == h - 1 && x != -1 && x != w)) {
                printf("-");
            } else if ((x == 0 && y != 0) ||
                       (x == w - 1 && x != 0 && y != h - 1 && y != 3 && y != 4 && y != 5)) {
                printf("|");
            } else if ((x == w - 10 && y != h - 1 && y == 3) || (x == w - 12 && y != h - 1 && y == 4) ||
                       (x == w - 11 && y != h - 1 && y == 5)) {
                printf("|");
            } else if ((x == (w / 2) - 5 && y == 3)) {
                printf("Hello!!!!!");
            } else if ((x == (w / 2) - 6 && y == 4)) {
                printf("What is your");
            } else if ((x == (w / 2) - 5 && y == 5)) {
                printf("name Hero? ");
            } else
                printf(" ");
        }
        printf("\n");
    }
    int len;
    char c;
    printf("\n");
    fgets(player->hero_name, size, stdin);
    len = strlen(player->hero_name);
    if (player->hero_name[len - 1] == '\n')
        player->hero_name[len - 1] = '\0';
    else {
        while ((c = getchar()) != '\n' && c != EOF)
            ;
    }

    // printf("Name2: %s\n", player->hero_name);
}