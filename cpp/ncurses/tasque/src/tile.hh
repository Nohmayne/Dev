#ifndef TASQUE_TILE_HH
#define TASQUE_TILE_HH

#include <string>
#include <vector>

class Tile
{
    public:
        // Creates a tile with the designated title. Description is optional.
        Tile(const std::string &title, const std::string &desc = "");

        // Returns the title of the tile.
        inline std::string getTitle() { return m_title; }
        // Returns the description of the tile.
        inline std::string getDesc() { return m_desc; }

        // Sets the title of the tile.
        void setTitle(const std::string &title);
        // Sets the description of the tile.
        void setDesc(const std::string &desc);
    private:
        std::string m_title;
        std::string m_desc;
};

#endif
