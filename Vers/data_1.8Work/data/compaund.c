#include "global.h"

void compaund(char* sp) {
    // printf("symbol1 = %c\n", *sp);
    while ((*sp != 'm') && (*sp != 'a') && (*sp != 'A') && (*sp != 'r') && (*sp != 'R')) {
        printf("Некорректный символ. Введите 'A'ttack or 'R'un:\n ");
        // printf("symbol2 = %c\n", *sp);
        *sp = getchar();
        while (getchar() != '\n')
            ;  // Очистка буфера ввода
    }
}