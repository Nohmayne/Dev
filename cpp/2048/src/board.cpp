#include <SFML/Graphics.hpp>
#include "tile.cpp"
#include <iostream>
#include <math.h>

class Board : public sf::Drawable, public sf::Transformable
{
public:
	Board(int bw, int bh, int width, int height, float size) :
	m_border((bw + 1) + (bh + 1)),
	m_slotSize(size),
	m_boardSize(sf::Vector2i(bw, bh)),
	m_width(width),
	m_height(height)
	{
		spawnTiles();
	}

	~Board()
	{
		for (Tile* t : m_tiles)
		{
			delete t;
		}
	}

	void addTile()
	{
		std::vector<sf::Vector2i> possiblePositions;

		for (size_t row = 0; row < m_boardSize.y; row++)
		{
			for (size_t col = 0; col < m_boardSize.x; col++)
			{
				sf::Vector2i newPosition(col, row);
				bool goodPosition = true;

				for (Tile* t : m_tiles)
				{
					if (t->getBoardPosition() == newPosition)
					{
						goodPosition = false;
						break;
					}
				}

				if (goodPosition)
					possiblePositions.push_back(newPosition);
			}
		}

		if (possiblePositions.size() != 0)
		{
			sf::Vector2i tilePosition = possiblePositions[rand() % possiblePositions.size()];

			Tile *newTile = new Tile(2, tilePosition, m_slotSize);
			m_tiles.push_back(newTile);
		}
	}

	Tile* findTileWithOffset(sf::Vector2i tilePos, sf::Vector2i offset)
	{
		sf::Vector2i checkPos = tilePos + offset;

		if (checkPos.x < 0 || checkPos.y < 0 || checkPos.x > m_boardSize.x || checkPos.y > m_boardSize.y)
		{
			size_t outOfBoundsTileIndex = findIndexOfTile(sf::Vector2i(-1000, -1000), m_tiles);
			if (outOfBoundsTileIndex != -1)
				m_tiles.erase(m_tiles.begin() + outOfBoundsTileIndex);

			Tile* outOfBoundsTile = new Tile(2, sf::Vector2i(-1000, -1000), m_slotSize);
			return outOfBoundsTile;
		}

		for (Tile* t : m_tiles)
		{
			if (t->getBoardPosition() == checkPos)
			{
				return t;
			}
		}

		return nullptr;
	}

	size_t findIndexOfTile(sf::Vector2i tilePos, std::vector<Tile*>& tiles)
	{
		for (size_t index = 0; index < tiles.size(); index++)
		{
			if (tiles[index]->getBoardPosition() == tilePos)
			{
				return index;
			}
		}

		return -1;
	}

	bool checkFull()
	{
		for (Tile* t : m_tiles)
		{
			std::vector<Tile*> adjacentTiles;
			adjacentTiles.push_back(findTileWithOffset(t->getBoardPosition(), sf::Vector2i(0, -1)));
			adjacentTiles.push_back(findTileWithOffset(t->getBoardPosition(), sf::Vector2i(1, 0)));
			adjacentTiles.push_back(findTileWithOffset(t->getBoardPosition(), sf::Vector2i(0, 1)));
			adjacentTiles.push_back(findTileWithOffset(t->getBoardPosition(), sf::Vector2i(-1, 0)));

			for (size_t i = 0; i < adjacentTiles.size(); i++)
			{
				Tile* adjacent = adjacentTiles[i];
				if (adjacent == nullptr)
				{
					// std::cout << "No Tile: " << std::endl;
					// std::cout << t->getBoardPosition().x << ", " << t->getBoardPosition().y << std::endl;
					// std::cout << i << std::endl;
					return false;
				}
				else if (adjacent->getValue() == t->getValue() && adjacent->getBoardPosition() != sf::Vector2i(-1000, -1000))
				{
					// std::cout << "Value Equal: " << std::endl;
					// std::cout << t->getBoardPosition().x << ", " << t->getBoardPosition().y;
					// std::cout << adjacent->getBoardPosition().x << ", " << adjacent->getBoardPosition().y << std::endl;
					return false;
				}
			}
		}

		return true;
	}

	void move(sf::Vector2i unitDirection)
	{
		std::vector<Tile*> moveableTiles;

		sf::Vector2i borderPosition;

		if (unitDirection.x != 0)
		{
			borderPosition.x = (int)((1 + unitDirection.x) * ((m_boardSize.x - 1) / 2.f));
		}
		else
		{
			borderPosition.x = -1;
		}

		if (unitDirection.y != 0)
		{
			borderPosition.y = (int)((1 + unitDirection.y) * ((m_boardSize.y - 1) / 2.f));
		}
		else
		{
			borderPosition.y = -1;
		}

		for (Tile* t : m_tiles)
		{
			if (t->getBoardPosition().x != borderPosition.x && t->getBoardPosition().y != borderPosition.y)
			{
				moveableTiles.push_back(t);
			}
		}

		while (moveableTiles.size() > 0)
		{
			for (size_t index = 0; index < moveableTiles.size(); index++)
			{
				Tile* moveable = moveableTiles[index];
				Tile* adjacentTile = findTileWithOffset(moveable->getBoardPosition(), unitDirection);
				if (adjacentTile != nullptr)
				{
					if (moveable->getValue() == adjacentTile->getValue())
					{
						adjacentTile->setValue(moveable->getValue() + adjacentTile->getValue());
						m_tiles.erase(m_tiles.begin() + findIndexOfTile(moveableTiles[index]->getBoardPosition(), m_tiles));
						moveableTiles.erase(moveableTiles.begin() + index);
						continue;
					}
					else
					{
						if (findIndexOfTile(adjacentTile->getBoardPosition(), moveableTiles) == -1)
						{
							moveableTiles.erase(moveableTiles.begin() + index);
							continue;
						}
					}
				}
				else
				{
					moveableTiles[index]->setBoardPosition(moveableTiles[index]->getBoardPosition() + unitDirection);

					if (moveableTiles[index]->getBoardPosition().x == borderPosition.x || moveableTiles[index]->getBoardPosition().y == borderPosition.y)
					{
						moveableTiles.erase(moveableTiles.begin() + index);
					}
				}
			}
		}

		addTile();
	}
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		states.transform *= getTransform();

		states.texture = NULL;
		
		for (Tile* t : m_tiles)
		{
			target.draw(*t);
		}
	}

	void spawnTiles()
	{
		for (size_t i = 0; i < 2; i++)
		{
			addTile();
		}
	}
private:
	std::vector<Tile*> m_tiles;
	std::vector<sf::RectangleShape> m_border;
	float m_slotSize;
	sf::Vector2i m_boardSize;
	float m_width;
	float m_height;
};