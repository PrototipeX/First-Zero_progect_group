#include <stdio.h>
#include <stdlib.h>

void foo(int *p) {
    printf("Foo x=%d\n", *p);
    *p += 10;
    printf("Foo +10 x=%d\n", *p);
}

int *bar() {
    int y = 888;
    printf("Bar y=%d\n", y);
    return &y;
}

int main() {
    int x = 7;
    printf("x = %d\n", x);
    foo(&x);
    printf("x = %d\n", x);

    int *py = bar();
    printf("*py = %d\n", *py);
    return 0;
}