#include "player.hh"

Player::Player(WINDOW* win, int y, int x, char c) :
    m_Xpos(x), m_Ypos(y), m_character(c), m_curwin(win)
{
    getmaxyx(m_curwin, m_Ymax, m_Xmax);
    keypad(m_curwin, true);
}

void Player::mvup()
{
    mvwaddch(m_curwin, m_Ypos, m_Xpos, ' ');
    m_Ypos--;

    if (m_Ypos < 1)
        m_Ypos = 1;
}

void Player::mvdn()
{
    mvwaddch(m_curwin, m_Ypos, m_Xpos, ' ');
    m_Ypos++;

    if (m_Ypos > m_Ymax - 2)
        m_Ypos = m_Ymax - 2;
}

void Player::mvlt()
{
    mvwaddch(m_curwin, m_Ypos, m_Xpos, ' ');
    m_Xpos--;

    if (m_Xpos < 1)
        m_Xpos = 1;
}

void Player::mvrt()
{
    mvwaddch(m_curwin, m_Ypos, m_Xpos, ' ');
    m_Xpos++;

    if (m_Xpos > m_Xmax - 2)
        m_Xpos = m_Xmax - 2;
}

int Player::getmv()
{
    int choice = wgetch(m_curwin);

    switch (choice)
    {
    case KEY_UP:
        mvup();
        break;
    case KEY_DOWN:
        mvdn();
        break;
    case KEY_LEFT:
        mvlt();
        break;
    case KEY_RIGHT:
        mvrt();
        break;
    default:
        break;
    }

    return choice;
}

void Player::display()
{
    mvwaddch(m_curwin, m_Ypos, m_Xpos, m_character);
}

