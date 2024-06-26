#include "global.h"

void slee(int s) {
    if (s == 5) {
        usleep(1000);
    } else if (s == 4) {
        usleep(7000);
    } else if (s == 3) {
        usleep(20000);
    } else if (s == 2) {
        usleep(50000);
    } else {
        usleep(100000);
    }
}