#include "global.h"
char helloHero(char * player->hero_name) {
    int len;
    char c;
    char name[100];
    printf("What is your name Hero? \n");
    fgets(name, sizeof(name), stdin);
    getchar();
    printf("Name1: %.99s\n", name);
    len = strlen(name);
    *player->hero_name = name[100];
    if (player->hero_name[len - 1] == '\n')
        player->hero_name[len - 1] = '\0';
    else {
        while ((c = getchar()) != '\n' && c != EOF)
            ;
    }

    printf("Name1: %s\n", player->hero_name);
    return *player->hero_name;
}