#include <stdio.h>
#include <stdlib.h>

typedef struct good {
    char name[20];  // название-описание товара
    double price;   // цена товара
    int count;      // количество товара
} good;

void add_good(good **goods, int *size, int *capacity) {
    printf("Enter good description: ");
    scanf("%s", &(*goods)[*size].name);
    printf("Enter good price: ");
    scanf("%lf", &(*goods)[*size].price);
    printf("Enter good count: ");
    scanf("%d", &(*goods)[*size].count);

    (*size)++;

    if (*size >= *capacity) {
        *capacity *= 2;

        *goods = (good *)realloc(*goods, *capacity * sizeof(good));
    }
}

void print_goods(good *goods, int size) {
    printf("+---------------------+-------------+-------+\n");
    printf("|         good        |    Price    | Count |\n");
    printf("+---------------------+-------------+-------+\n");

    if (size == 0) printf("|            No goods was added...          |\n");

    for (int i = 0; i < size; i++)
        printf("| %19s | %11.2lf | %5d |\n", goods[i].name, goods[i].price, goods[i].count);

    printf("+---------------------+-------------+-------+\n");
}

void print_highest(good *goods, int size) {
    double max = goods[0].price;
    int imax = 0;

    for (int i = 1; i < size; i++) {
        if (goods[i].count > max) {
            max = goods[i].price;
            imax = i;
        }
    }

    printf("The highest price of goods is %.2lf (good is %s)\n", max, goods[imax].name);
}

void print_lowest(good *goods, int size) {
    double min = goods[0].price;
    int imin = 0;

    for (int i = 1; i < size; i++) {
        if (goods[i].count < min) {
            min = goods[i].price;
            imin = i;
        }
    }

    printf("The lowest price of goods is %.2lf (good is %s)\n", min, goods[imin].name);
}

void print_menu() {
    system("cls");  // очищаем экран
    printf("What do you want to do?\n");
    printf("1. Add good to list\n");
    printf("2. Print all goods in list\n");
    printf("3. Print the highest price\n");
    printf("4. Print the lowest price\n");
    printf("5. Exit\n");
    printf(">");
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
    int variant;       // выбранный пункт меню
    int size = 0;      // количество элементов массива товаров
    int capacity = 1;  // ёмкость массива товаров

    good *goods = (good *)malloc(capacity * sizeof(good));  // выделяем память под массив товаров

    do {
        print_menu();  // выводим меню на экран

        variant = get_variant(5);  // получаем номер выбранного пункта меню

        switch (variant) {
            case 1:
                add_good(&goods, &size, &capacity);
                break;

            case 2:
                print_goods(goods, size);
                break;

            case 3:
                print_highest(goods, size);
                break;

            case 4:
                print_lowest(goods, size);
                break;
        }

        if (variant != 5)
            system("pause");  // задерживаем выполнение, чтобы пользователь мог увидеть результат выполнения
                              // выбранного пункта
    } while (variant != 5);

    return 0;
}