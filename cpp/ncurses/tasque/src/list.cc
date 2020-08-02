#include "list.hh"

List::List(const std::string& title) :
    m_title(title)
{
    m_tiles = {};
    m_length = 0;
}

void List::addTile(Tile &t)
{
    m_tiles.push_back(t);
    m_length++;
}

void List::delTile(unsigned int index)
{
    m_tiles.erase(m_tiles.begin() + index);
    m_length--;
}

void List::delTiles(unsigned int start, unsigned int end)
{
    m_tiles.erase(m_tiles.begin() + start, m_tiles.begin() + end);
    m_length -= end - start;
}

void List::setTitle(const std::string& title)
{
    m_title = title;
}
