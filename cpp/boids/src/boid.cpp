#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/System/Vector2.hpp>
#include <math.h>
#include <stdlib.h>

class Boid : public sf::Drawable, public sf::Transformable
{
public:
  Boid(sf::Vector2f pos, float maxVel, float radius) :
    m_position (pos),
    m_velocity (sf::Vector2f(0, 0)),
    m_acceleration (sf::Vector2f(0, 0)),
    m_shape (radius)
  {
    // set the velocity to a point on circle with radius maxVel
    float randomAngle = 2.f *  M_PI * (rand() % 100 / 100);

    m_velocity = maxVel * sf::Vector2f(cos(randomAngle), sin(randomAngle));

    // set the base values of the shape
    m_shape.setPosition(m_position);
    m_shape.setFillColor(sf::Color::White);
  }

  sf::Vector2f getPosition()
  {
    return m_position;
  }

  void update()
  {
    m_velocity += m_acceleration;
    m_position += m_velocity;

    m_shape.setPosition(m_position);
  }
private:
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const
  {
    states.transform *= getTransform();
    states.texture = NULL;
    target.draw(m_shape);
  }
private:
  sf::Vector2f m_position;
  sf::Vector2f m_velocity;
  sf::Vector2f m_acceleration;
  sf::CircleShape m_shape;
};
