#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Определяем размер рамки
#define FRAME_WIDTH 40
#define FRAME_HEIGHT 10

// Определяем символы для рисования рамки
#define TOP_LEFT '+'
#define TOP_RIGHT '+'
#define BOTTOM_LEFT '+'
#define BOTTOM_RIGHT '+'
#define HORIZONTAL_LINE '-'
#define VERTICAL_LINE '|'

// Определяем опции меню
#define OPTION1 "Опция 1"
#define OPTION2 "Опция 2"
#define OPTION3 "Опция 3"
#define QUIT "Выход"

// Рисуем рамку с заголовком
void draw_frame(char *title) {
    // Рисуем верхнюю линию
    for (int i = 0; i < FRAME_WIDTH; i++) {
        printf("%c", HORIZONTAL_LINE);
    }
    printf("\n");

    // Рисуем левую и правую вертикальные линии
    for (int i = 0; i < FRAME_HEIGHT - 2; i++) {
        printf("%c", VERTICAL_LINE);
        for (int j = 0; j < FRAME_WIDTH - 2; j++) {
            printf(" ");
        }
        printf("%c\n", VERTICAL_LINE);
    }

    // Рисуем нижнюю линию
    for (int i = 0; i < FRAME_WIDTH; i++) {
        printf("%c", HORIZONTAL_LINE);
    }
    printf("\n");

    // Рисуем заголовок
    int title_length = strlen(title);
    int padding = (FRAME_WIDTH - title_length) / 2;
    for (int i = 0; i < padding; i++) {
        printf(" ");
    }
    printf("%s", title);
    for (int i = padding + title_length; i < FRAME_WIDTH; i++) {
        printf(" ");
    }
    printf("\n");
}

// Рисуем меню
void draw_menu() {
    // Рисуем рамку
    char title[20];
    draw_frame(title);

    // Добавляем опции меню
    printf("%c %2d. %s\n", VERTICAL_LINE, 1, OPTION1);
    printf("%c %2d. %s\n", VERTICAL_LINE, 2, OPTION2);
    printf("%c %2d. %s\n", VERTICAL_LINE, 3, OPTION3);
    printf("%c %2d. %s\n", VERTICAL_LINE, 4, QUIT);
}

// Получаем ввод пользователя
int get_user_input() {
    // Считываем ввод пользователя
    int choice;
    printf("%d Выберите пункт меню (1-4): ", VERTICAL_LINE);
    scanf("%d", &choice);

    // Возвращаем выбор пользователя
    return choice;
}

// Запускаем программу
int main() {
    // Рисуем меню
    draw_menu();

    // Получаем ввод пользователя
    int choice = get_user_input();

    // Обрабатываем выбор пользователя
    switch (choice) {
        case 1:
            printf("%d Вы выбрали %s\n", VERTICAL_LINE, OPTION1);
            break;
        case 2:
            printf("%d Вы выбрали %s\n", VERTICAL_LINE, OPTION2);
            break;
        case 3:
            printf("%d Вы выбрали %s\n", VERTICAL_LINE, OPTION3);
            break;
        case 4:
            printf("%d Вы вышли из программы\n", VERTICAL_LINE);
            return 0;
        default:
            printf("%d Неверный выбор\n", VERTICAL_LINE);
    }

    return 0;
}
