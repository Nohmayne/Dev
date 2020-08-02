#ifndef TASQUE_BOARD_HH
#define TASQUE_BOARD_HH

#include <vector>
#include <string>
#include "list.hh"

class Board
{
    public:
        // Create a board with the designated title.
        Board(const std::string& title);

        // Returns the vector containing the lists within the board.
        inline std::vector<List> getLists() { return m_lists; }
        // Returns the title of the board.
        inline std::string getTitle() { return m_title; }

        // Sets the title of the board.
        void setTitle(const std::string& title);

        // Adds a list to the board.
        void addList(List &l);
        // Removes a list from the bord at the designated index.
        void delList(unsigned int index);
        // Removes lists from the index at start to the index before end (end is not inclusive).
        void delLists(unsigned int start, unsigned int end);
    private:
        std::vector<List> m_lists;
        std::string m_title;
        unsigned int m_length;
};

#endif
