#include <stdio.h>
#include <string.h>

int main() {
    int len;
    char c;
    char player->hero_name[100];
    printf("What is your name Hero? \n");
    fgets(player->hero_name, sizeof(player->hero_name), stdin);
    len = strlen(player->hero_name);
    if (player->hero_name[len - 1] == '\n')
        player->hero_name[len - 1] = '\0';
    else {
        while ((c = getchar()) != '\n' && c != EOF)
            ;
    }
    printf("Name1: %s\n", player->hero_name);
    return 0;
}
