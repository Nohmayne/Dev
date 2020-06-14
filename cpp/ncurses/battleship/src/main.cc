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
    bheight = 11;
    bwidth = bheight * 2;

    WINDOW* bwin = newwin(
            bheight,
            bwidth,
            ymax / 2 - bheight / 2,
            xmax / 2 - bwidth / 2
    );

    wprintw(bwin, "%d, %d", ymax / 2 - bheight / 2, xmax / 2 - bwidth / 2);

    box(bwin, 0, 0);
    refresh();
    wrefresh(bwin);

    getch();
    endwin();
    return 0;
}
