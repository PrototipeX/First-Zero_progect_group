#include "global.h"

void intro(struct pole* pole) {
    char* buf = (char*)malloc(sizeof(char) * 10000);
    char* text = NULL;
    FILE* file = fopen("Intro.txt", "rt");
    size_t i = 0;
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    text = (char*)malloc(10000 * sizeof(char));
    if (text == NULL) {
        printf("Error allocating memory.\n");
        fclose(file);
        return;
    }
    printf("\33[0d\33[2J");
    while (fgets(buf, 10000, file) != NULL) {
        strcat(text, buf);
        i++;
    }

    int h = pole->h;
    int w = pole->w;
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if ((y == 0 && x != -1) || (y == h - 1 && x != -1 && x != w)) {
                printf("-");
            } else if ((x == 0 && y != 0) || (x == w - 1 && x != 0 && y != h - 1)) {
                printf("|");
            } else
                printf(" ");
        }
        printf("\n");
    }
    printf("%s", text);
    getchar();
    fclose(file);
    free(text);
}