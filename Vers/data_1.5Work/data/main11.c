#include "global.h"

int main() {
    int flag = -2;

    while (flag != 2) {
        goblin(&flag);
    }
    printf("\33[0d\33[2J");
    printf("\nGame over1!\n\n");
    return 0;
}