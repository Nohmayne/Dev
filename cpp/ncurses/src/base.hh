#ifndef BASE_HH
#define BASE_HH

#include <ncurses.h>

void start_ncurses(bool do_noecho, bool do_cbreak = true)
{
    initscr();

    if (do_noecho)
        noecho();

    if (do_cbreak)
        cbreak();
}

void end_ncurses(bool do_pause)
{
    if (do_pause)
        getch();

    endwin();
}
#endif
