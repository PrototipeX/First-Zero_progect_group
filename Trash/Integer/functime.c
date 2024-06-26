#include "global.h"

int seedrand(int timerand) {
    srand(time(NULL));  // seed rng 0-2kkk
    timerand = rand();
    return timerand;
}