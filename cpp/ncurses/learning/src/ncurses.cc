#include <ncurses.h>
#include <algorithm>
#include <string>
#include "player.hh"

int main()
{
    initscr();
    noecho();
    cbreak();

    // get screen size
    int ymax, xmax;
    getmaxyx(stdscr, ymax, xmax);

    WINDOW* gamewin = newwin(20, 50, (ymax/2)-10, 10);
    box(gamewin, 0, 0);
    refresh();
    wrefresh(gamewin);
    keypad(gamewin, true);

    Player* p = new Player(gamewin, 1, 1, '@');

    do {
        p->display();
        wrefresh(gamewin);
    } while (p->getmv() != 'x');

    endwin();

    return 0;
}
