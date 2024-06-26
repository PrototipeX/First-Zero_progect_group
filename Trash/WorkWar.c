#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int seedrand(int timerand) {
    srand(time(NULL));  // seed rng 0-2kkk
    timerand = rand();
    return timerand;
}

char compaund(char *symbol) {
    printf("symbol1 = %c\n", *symbol);
    if ((*symbol != 'a') && (*symbol != 'A') && (*symbol != 'r') && (*symbol != 'R')) {
        do {
            printf("Некорректный символ. Введите 'a' или 'r': ");
            *symbol = getchar();
            while (getchar() != '\n')
                ;  // Очистка буфера ввода
            printf("symbol2 = %c\n", *symbol);

        } while ((*symbol != 'a') && (*symbol != 'A') && (*symbol != 'r') && (*symbol != 'R'));
    }
    return *symbol;
}
int main() {
    int player->player_gold;
    char buffer = '0';
    int timerand = 0;
    char action = '0';
    printf("\33[0d\33[2J");
    printf("You attaked by goblin.'A'ttack or 'R'un\n");
    buffer = getchar();
    action = buffer;
    while (getchar() != '\n')
        ;  // Очистка буфера ввода
    printf("Action = %c\n", action);
    while (action != 'r') {
        action = compaund(&action);
        if (action == 'a' || action == 'A') {
            int goblin_gold = seedrand(timerand) % 15;
            for (int goblin_hp = seedrand(timerand) % 5; goblin_hp >= 0; goblin_hp--) {
                if (goblin_hp != 5) printf("You kick goblin(%d)\n", goblin_hp);
                if (goblin_hp == 0) {
                    printf("You defeat it.\n");
                    player->player_gold += goblin_gold;
                    printf("You found %d gold\n", goblin_gold);
                    printf("You have %d gold total\n", player->player_gold);
                    continue;
                }
            }
        }
        if (action != 'r') {
            printf("Action = %c\n", action);
            printf("Your action? Goblin wait.'A'ttack or 'R'un\n ");
            buffer = getchar();
            action = buffer;
            while (getchar() != '\n')
                ;  // Очистка буфера ввода}
        }
    }
    if (action == 'r' || action == 'R')
        printf("You've decided to run away! You Earned %d gold\n ", player->player_gold);
    return player->player_gold;
}