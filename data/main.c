#include "global.h"

int main() {
    int mode = -2;

    while (mode != -1) {
        if (scanf("%d", &mode) == 1) {
            if (mode == 1) {
                for (int i = 0; i < count; i++) print_door(readDoorn(doors_file, i));
            } else if (mode == 1) {
                sort_door_file(doors_file);
                for (int i = 0; i < count; i++) print_door(readDoorn(doors_file, i));
            } else if (mode == 2) {
                t_door td;
                if (inputDoor(&td)) {
                    insertDoor(doors_file, td);
                    count++;
                    sort_door_file(doors_file);
                    for (int i = 0; i < count; i++) print_door(readDoorn(doors_file, i));
                }

            } else {
                mode = -1;
                printf("n/a");
            }

            goblin(mode);
        } else {
            mode = -1;
            printf("n/a");
        }
    }

    return 0;
}