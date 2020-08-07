#include "tile.hh"

Tile::Tile(const std::string &title, const std::string &desc) :
    m_title(title),
    m_desc(desc)
{}

void Tile::setTitle(const std::string &title)
{
    m_title = title;
}

void Tile::setDesc(const std::string &desc)
{
    m_desc = desc;
}
