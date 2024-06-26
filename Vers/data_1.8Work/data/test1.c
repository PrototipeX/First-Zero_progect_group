
#include <ncurses.h>

int main(void) {
    initscr();
    printw("Press");
    getch();
    endwin();
    return 0;
}