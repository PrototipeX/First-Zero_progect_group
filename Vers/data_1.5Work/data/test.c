#include <stdio.h>
#include <string.h>

int main() {
    int k = 777;
    int *p;
    p = &k;
    *p = 888;
    printf("%d\n", k);
    int **p2;
    p2 = &p;
    **p2 = 999;
    printf("%d\n", k);
    int ***p3;
    p3 = &p2;
    ***p3 = 1000;
    printf("%d\n", k);
    return 0;
}
