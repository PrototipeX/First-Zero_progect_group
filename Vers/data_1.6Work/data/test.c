#include <stdio.h>

void get_name(char *name, int size) {
    printf("Введите имя: ");
    fgets(name, size, stdin);

    // Удаляем символ новой строки, который добавляется fgets
    name[strcspn(name, "\n")] = '\0';
}

int main() {
    char name[50];  // Максимальная длина имени 50 символов
    get_name(name, sizeof(name));
    printf("Ваше имя: %s\n", name);

    return 0;
}