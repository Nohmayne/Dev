#include "tile.hh"

Tile::Tile(std::string title, std::string desc) :
    m_title(title),
    m_desc(desc)
{}

void Tile::setTitle(std::string title)
{
    m_title = title;
}

void Tile::setDesc(std::string desc)
{
    m_desc = desc;
}
