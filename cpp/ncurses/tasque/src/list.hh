#ifndef TASQUE_LIST_HH
#define TASQUE_LIST_HH

#include <vector>
#include <string>
#include "tile.hh"

class List
{
    public:
        // Creates a list with the designated title.
        List(const std::string& title);

        // Returns the vector of all tiles within the list
        inline std::vector<Tile>& getTiles() { return m_tiles; }
        // Returns the title of the list.
        inline std::string& getTitle() { return m_title; }
        // Returns the number of tiles in the list, counting from 1.
        inline unsigned int& getLength() { return m_length; }

        // Adds a tile to the list.
        void addTile(Tile &t);
        // Removes a tile from the list at the designated index.
        void delTile(unsigned int index);
        // Removes tiles from the index at start to the index before end (end is not inclusive).
        void delTiles(unsigned int start, unsigned int end);

        // Sets the title of the list.
        void setTitle(const std::string& title);
    private:
        std::vector<Tile> m_tiles;
        std::string m_title;
        unsigned int m_length;
};

#endif
