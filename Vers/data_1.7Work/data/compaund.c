#include "global.h"

void compaund(char* sp) {
    printf("symbol1 = %c\n", *sp);
    while ((*sp != 'a') && (*sp != 'A') && (*sp != 'r') && (*sp != 'R') && (*sp != 'm')) {
        printf("Некорректный символ. Введите 'A'ttack or 'R'un:\n ");
        printf("symbol2 = %c\n", *sp);
        *sp = getchar();
        while (getchar() != '\n')
            ;  // Очистка буфера ввода
    }
}