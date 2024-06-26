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

int get_variant(int count) {
    int variant;
    char s[100];     // строка для считывания введённых данных
    scanf("%s", s);  // считываем строку

    // пока ввод некорректен, сообщаем об этом и просим повторить его
    while (sscanf(s, "%d", &variant) != 1 || variant < 1 || variant > count) {
        printf("Incorrect input. Try again: ");  // выводим сообщение об ошибке
        scanf("%s", s);                          // считываем строку повторно
    }

    return variant;
}

int main() {
    int h = 10;
    int w = 20;
    int timerand = 0;
    int rx = seedrand(timerand) * 1.0 / RAND_MAX * 18 + 1;
    int ry = seedrand(timerand) * 1.0 / RAND_MAX * 8 + 1;
    int ax = seedrand(timerand) * 1.0 / RAND_MAX * 15 + 1;
    int ay = seedrand(timerand) * 1.0 / RAND_MAX * 5 + 1;
    int variant = 0;
    //   int len;
    //    len = strlen(menu);
    while (1) {
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                if (x == rx && y == ry) {
                    printf("@");  // player position
                } else if (x == ax && y == ay) {
                    printf("*");  // enemy position
                } else if ((y == 0 && x != 0) || (y == h - 1 && x != 0 && x != w - 1)) {
                    printf("-");  // отрисовывается нижняя и верхняя грань
                } else if ((x == 0 && y != 0) || (x == w - 1 && x != 0 && y != h - 1 && y != 3) ||
                           (x == w - 1 && y == 3)) {
                    printf("|");  // отрисовывается левая и правая грань
                } else if ((x == (w / 2) - 7 && y == 3)) {
                    printf("1. PlayGame");  // point menu
                } else if ((x == (w / 2) - 7 && y == 4)) {
                    printf("2. Exit");  // point menu
                } else
                    printf(" ");  // всё остальное заполняем пробелами
            }
            printf("\n");  // завершаем строку и переходим на следующую по оси y
        }
        do {
            variant = get_variant(2);  // получаем номер выбранного пункта меню
                                       //       printf("\33[0d\33[2J");    // очищаем экран
            switch (variant) {
                case 1:
                    printf("you choice play");
                    break;
            }
        } while (variant != 2);
        printf("\33[0d\33[2J");
    }
    return 0;
}
