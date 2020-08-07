#include <iostream>
#include <ncurses.h>
#include "board.hh"
#include "list.hh"
#include "tile.hh"

int main() {
    initscr();
    cbreak();
    noecho();

    // get the dimensions of the standard screen
    int ymax, xmax;
    getmaxyx(stdscr, ymax, xmax);

    // window to draw the board in
    WINDOW *boardwin = newwin(ymax - 1, xmax, 0, 0);
    box(boardwin, 0, 0);
    refresh();
    wrefresh(boardwin);

    // window to draw commands and modal stuff in
    WINDOW *cmdwin = newwin(1, xmax, ymax - 1, 0);
    keypad(cmdwin, true);

    std::vector<Board*> boards;
    Board *b = new Board("Test");
    boards.push_back(b);

    b->addList(new List("List"));
    b->getList(0)->addTile(new Tile("Tile"));

    b->render(boardwin, xmax);

    for (int i = 0; i < b->getLength(); i++)
    {
        b->getList(i)->render(boardwin, 3, 1, ymax - 2, 20);
    }

    getch();
    endwin(); // stop curses context

    return 0;
}
