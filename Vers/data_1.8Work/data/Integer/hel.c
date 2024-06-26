#include "global.h"
int helloHero(char * player->hero_name) {
    int len;
    char c;
    printf("What is your name Hero? \n");
    fgets(player->hero_name, sizeof(player->hero_name), stdin);
    len = strlen(player->hero_name);
    if (player->hero_name[len - 1] == '\n')
        player->hero_name[len - 1] = '\0';
    else {
        while ((c = getchar()) != '\n' && c != EOF)
            ;
    }
    return 0;
}