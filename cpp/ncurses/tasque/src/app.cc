#include <iostream>
#include <ncurses.h>
#include "board.hh"
#include "list.hh"
#include "tile.hh"

int main() {
    initscr(); // start curses context
    cbreak(); // ensure that <C-c> can be used to break
    noecho(); // don't echo user-typed characters to terminal
    keypad(stdscr, true); // enable more key inputs for the stdscr

    printw("Hello, world!"); // print and display
    refresh();

    getch(); // wait for user input

    endwin(); // stop curses context

    return 0;
}
