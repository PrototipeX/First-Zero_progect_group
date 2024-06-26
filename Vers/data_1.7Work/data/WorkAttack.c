#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

void battle(int * player->player_gold, char* action);
int goblin(int* flag, char * player->hero_name, int size);
void helloHero(char * player->hero_name, int size);
int seedrand(int timerand);
int menu(int* game);
int get_variant(int count);
void printmenu();
void gamekey();
void compaund(char* symbol);

int seedrand(int timerand) {
    srand(time(NULL));  // seed rng 0-2kkk
    timerand = rand();
    return timerand;
}
void gamekey() {
    int h = 10;
    int w = 21;
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
void compaund(char* sp) {
    printf("symbol1 = %c\n", *sp);
    while ((*sp != 'a') && (*sp != 'A') && (*sp != 'r') && (*sp != 'R')) {
        printf("Некорректный символ. Введите 'A'ttack or 'R'un:\n ");
        printf("symbol2 = %c\n", *sp);
        *sp = getchar();
        while (getchar() != '\n')
            ;  // Очистка буфера ввода
    }
}
void battle(int * player->player_gold, char* action) {
    int timerand = 0;
    printf("\33[0d\33[2J");
    printf("You attaked by goblin.'A'ttack or 'R'un\n");
    while (getchar() != '\n')
        ;  // Очистка буфера ввода
    //    printf("Action = %s\n", action);
    *action = getchar();
    while (getchar() != '\n')
        ;  // Очистка буфера ввода
           //    printf("Action = %s\n", action);
    while (*action != 'r') {
        compaund(action);
        if (*action == 'a' || *action == 'A') {
            int goblin_gold = seedrand(timerand) % 15;
            for (int goblin_hp = seedrand(timerand) % 5; goblin_hp >= 0; goblin_hp--) {
                if (goblin_hp != 5) printf("You kick goblin(%d)\n", goblin_hp);
                if (goblin_hp == 0) {
                    printf("You defeat it.\n");
                    *player->player_gold += goblin_gold;
                    printf("You found %d gold\n", goblin_gold);
                    printf("You have %d gold total\n", *player->player_gold);
                    continue;
                }
            }
        }
        if (*action != 'r') {
            printf("Action = %s\n", action);
            printf("Your next action? Goblin wait.'A'ttack or 'R'un\n ");
            *action = getchar();
            while (getchar() != '\n')
                ;  // Очистка буфера ввода}
        }
    }
    if (*action == 'r' || *action == 'R')
        printf("You've decided to run away! You Earned %ls gold\n ", player->player_gold);
}
int goblin(int* flag, char * player->hero_name, int size) {
    int game = 0;
    menu(&game);  // cont menu
    printf("game goblin = %d\n", game);
    *flag = game;
    if (game == 1) {
        int i, key;
        int x = 10, y = 5;
        int ox, oy;
        int stage = 1;
        char action = '0';
        int player->player_gold = 0;
        int timerand = 0;
        char mass[10][21];
        int ax = 0, ay = 0;
        ax = seedrand(timerand) * 1.0 / RAND_MAX * 18 + 1;
        ay = seedrand(timerand) * 1.0 / RAND_MAX * 8 + 1;
        helloHero(player->hero_name, size);  // inter hero name
        printf("Name3: %s\n", player->hero_name);
        do {
            printf("\33[0d\33[2J");
            gamekey();  // point key
            sprintf(mass[0], "====================");

            for (i = 1; i < 9; i++) sprintf(mass[i], "#                  #");

            sprintf(mass[9], "====================");

            mass[y][x] = '@';
            mass[ay][ax] = 'o';

            for (i = 0; i < 10; i++) printf("%s\n", mass[i]);
            printf("\n");
            printf("Hero \n");
            printf("Name: %s\n", player->hero_name);
            printf("Stage: %d\n", stage);
            printf("Golds: %d\n", player->player_gold);
            // printf("Status do %d\n", *flag);
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
                battle(&player->player_gold, &action);
            }
            printf("Game dodo %d\n", *flag);
        } while (*flag != 2);
    }
    printf("Game dododo %d\n", *flag);
    return 0;
}
int get_variant(int count) {
    int variant;
    char s[100];
    scanf("%s", s);
    while (sscanf(s, "%d", &variant) != 1 || variant < 1 || variant > count) {
        printf("Incorrect input. Try again: ");
        scanf("%s", s);
    }
    printf("Variant working\n");
    return variant;
}
void printmenu() {
    int h = 10;
    int w = 21;
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
void helloHero(char * player->hero_name, int size) {
    int len;
    char c;
    printf("What is your name Hero? \n");
    fgets(player->hero_name, size, stdin);
    len = strlen(player->hero_name);
    if (player->hero_name[len - 1] == '\n')
        player->hero_name[len - 1] = '\0';
    else {
        while ((c = getchar()) != '\n' && c != EOF)
            ;
    }
    printf("Name2: %s\n", player->hero_name);
}
int menu(int* game) {
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