#include <ctype.h>
#include <stdio.h>

// Функция 1: Печать символа
void print_char(char symbol) { printf("Введенный символ: %c\n", symbol); }

// Функция 2: Проверка ввода
char validate_input(char symbol) {
    while (symbol != 'a' && symbol != 'r') {
        printf("Некорректный символ. Введите 'a' или 'r': ");
        symbol = getchar();
        while (getchar() != '\n')
            ;  // Очистка буфера ввода
    }
    return symbol;
}

// Функция main: Получение символа и его обработка
int main() {
    char symbol;
    printf("Введите 'a' или 'r': ");
    symbol = getchar();
    while (getchar() != '\n')
        ;  // Очистка буфера ввода

    symbol = validate_input(symbol);  // Проверка ввода

    print_char(symbol);  // Печать символа

    return 0;
}