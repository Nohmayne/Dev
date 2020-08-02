#ifndef TASQUE_TILE_HH
#define TASQUE_TILE_HH

#include <string>
#include <vector>

class Tile
{
    public:
        // Creates a tile with the designated title. Description is optional.
        Tile(std::string title, std::string desc = "");

        inline std::string& getTitle() { return m_title; }
        inline std::string& getDesc() { return m_desc; }

        // Sets the title of the tile.
        void setTitle(std::string title);
        // Sets the description of the tile.
        void setDesc(std::string desc);
    private:
        std::string m_title;
        std::string m_desc;
};

#endif
