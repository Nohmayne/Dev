#include <ncurses.h>
#include <algorithm>
#include <string>

int main()
{
    initscr();
    noecho();
    cbreak();

    // get screen size
    int ymax, xmax;
    getmaxyx(stdscr, ymax, xmax);

    WINDOW* menuwin = newwin(7, xmax-12, ymax-10, 5);
    box(menuwin, 0, 0);
    refresh();
    wrefresh(menuwin);
    keypad(menuwin, true);

    // make a menu
    std::array<std::string, 3> choices = {
        "Walk",
        "Jog",
        "Run"
    };

    int choice;
    int highlight = 0;

    while (true)
    {
        for (auto itr = choices.begin(); itr < choices.end(); itr++)
        {
            if (itr == choices.begin() + highlight)
                wattron(menuwin, A_REVERSE);
            mvwprintw(menuwin, itr-choices.begin()+1, 1, "%d) %s", itr-choices.begin(), itr->c_str());
            wattroff(menuwin, A_REVERSE);
        }

        choice = wgetch(menuwin);

        switch (choice)
        {
            case KEY_UP:
                highlight--;
                break;
            case KEY_DOWN:
                highlight++;
                break;
            default:
                break;
        }

        highlight = std::clamp(highlight, 0, 2);

        if (choice == 10)
            break;
    }

    printw("You chose: %s", choices.at(highlight).c_str());

    getch();
    endwin();

    return 0;
}
