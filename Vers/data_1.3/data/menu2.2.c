#include "global.h"

int main() {
    printf("\33[0d\33[2J");
    //   int len;
    //    len = strlen(menu);
    while (1) {
        printmenu();
    }
    return 0;
}
