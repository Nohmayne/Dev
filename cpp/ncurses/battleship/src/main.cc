#include <ncurses.h>
#include <iostream>

int main()
{
    initscr();
    noecho();
    cbreak();

    int xmax, ymax;
    getmaxyx(stdscr, ymax, xmax);

    int bwidth, bheight;
    bwidth = bheight = 11;

    // WINDOW* bwin = newwin(
            // bheight,
            // bwidth,
            // ymax / 2 - bheight / 2,
            // xmax / 2 - bwidth / 2
    // );
    WINDOW* bwin = newwin(bheight, bwidth, 0, 0);

    wprintw(bwin, "%d, %d", ymax / 2 - bheight / 2, xmax / 2 - bwidth / 2);

    box(bwin, 0, 0);
    wrefresh(bwin);

    getch();
    endwin();
    return 0;
}
