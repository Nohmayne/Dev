#ifndef PLAYER_H
#define PLAYER_H

#include <ncurses.h>

class Player
{
public:
    Player(WINDOW* win, int y, int x, char c);

    void mvup();
    void mvdn();
    void mvlt();
    void mvrt();

    int getmv();

    void display();

private:
    int m_Xpos, m_Ypos, m_Xmax, m_Ymax;
    char m_character;
    WINDOW* m_curwin;
};

#endif
