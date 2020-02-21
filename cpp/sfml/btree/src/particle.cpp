#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <math.h>

class Particle : public sf::Drawable, public sf::Transformable
{
public:
  Particle(sf::Vector2f pos, sf::Vector2f gridSize, sf::Vector2f gridDimensions) : m_movementDirection(0, 0), m_position(pos), m_gridSize(gridSize), m_gridDimensions(gridDimensions), m_frozen(false), m_square(gridSize)
  {
    m_square.setPosition(sf::Vector2f(m_position.x * m_gridSize.x, m_position.y * m_gridSize.y));
    m_square.setFillColor(sf::Color::White);

    randomizeDirection();
  }

  void update()
  {
    if (!m_frozen)
    {
      m_position += m_movementDirection;

      if (m_position.x < 0)
      {
        m_position.x = m_gridDimensions.x - 1;
      }
      else if (m_position.x > m_gridDimensions.x - 1)
      {
        m_position.x = 0;
      }

      if (m_position.y < 0)
      {
        m_position.y = m_gridDimensions.y - 1;
      }
      else if (m_position.y > m_gridDimensions.y - 1)
      {
        m_position.y = 0;
      }

      m_square.setPosition(sf::Vector2f(m_position.x * m_gridSize.x, m_position.y * m_gridSize.y));
    }
  }

  void stepBack()
  {
    m_position -= m_movementDirection;

    if (m_position.x < 0)
    {
      m_position.x = m_gridDimensions.x - 1;
    }
    else if (m_position.x > m_gridDimensions.x - 1)
    {
      m_position.x = 0;
    }

    if (m_position.y < 0)
    {
      m_position.y = m_gridDimensions.y - 1;
    }
    else if (m_position.y > m_gridDimensions.y - 1)
    {
      m_position.y = 0;
    }

    m_square.setPosition(sf::Vector2f(m_position.x * m_gridSize.x, m_position.y * m_gridSize.y));
  }

  void randomizeDirection()
  {
    switch (rand() % 2)
    {
    case 0:
      m_movementDirection = sf::Vector2f(rand() % 3 - 1, 0);
      break;
    case 1:
      m_movementDirection = sf::Vector2f(0, rand() % 3 - 1);
      break;
    default:
      break;
    }
  }

  void freeze()
  {
    m_frozen = true;
  }

  bool getFrozen()
  {
    return m_frozen;
  }

  sf::Vector2f getGridPosition()
  {
    return m_position;
  }

private:
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const
  {
    states.transform *= getTransform();
    states.texture = NULL;
    target.draw(m_square, states);
  }

private:
  sf::Vector2f m_movementDirection;
  sf::Vector2f m_position;
  sf::Vector2f m_gridSize;
  sf::Vector2f m_gridDimensions;
  bool m_frozen;
  sf::RectangleShape m_square;
};