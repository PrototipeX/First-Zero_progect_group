#include "global.h"

void intro() {
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
    printf("%s", text);
    getchar();
    fclose(file);
    free(text);
}