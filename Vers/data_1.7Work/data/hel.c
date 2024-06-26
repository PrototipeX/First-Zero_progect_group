#include "global.h"
void helloHero(char * player->hero_name, int size) {
    int len;
    char c;
    printf("What is your name Hero? \n");
    fgets(player->hero_name, size, stdin);
    len = strlen(player->hero_name);
    if (player->hero_name[len - 1] == '\n')
        player->hero_name[len - 1] = '\0';
    else {
        while ((c = getchar()) != '\n' && c != EOF)
            ;
    }
    printf("Name2: %s\n", player->hero_name);
}