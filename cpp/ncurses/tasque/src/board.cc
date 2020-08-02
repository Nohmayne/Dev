#include "board.hh"

Board::Board(const std::string& title) :
    m_title(title)
{
    m_lists = {};
    m_length = 0;
}

void Board::setTitle(const std::string &title)
{
    m_title = title;
}

void Board::addList(List &l)
{
    m_lists.push_back(l);
    m_length++;
}

void Board::delList(unsigned int index)
{
    m_lists.erase(m_lists.begin() + index);
    m_length--;
}

void Board::delLists(unsigned int start, unsigned int end)
{
    m_lists.erase(m_lists.begin()+start, m_lists.begin()+end);
    m_length -= end - start;
}
