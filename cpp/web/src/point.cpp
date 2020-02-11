#include <SFML/Graphics.hpp>
#include <math.h>

class Point : public sf::Drawable, public sf::Transformable
{
public:
	Point(int width, int height, float minVel, float maxVel, float minSize, float maxSize) : 
	m_position(rand() % width, rand() % height),
	m_velocity(rand() % (int)(maxVel - minVel) + minVel, rand() % (int)(maxVel - minVel) + minVel),
	m_size(rand() % (int)(maxSize - minSize) + minSize),
	m_screenWidth(width),
	m_screenHeight(height),
	m_circle(m_size)
	{
		m_circle.setFillColor(sf::Color(255, 255, 255, 180));
		m_circle.setPosition(m_position);
	}

	void update(sf::Time delta)
	{
		if (m_position.x > m_screenWidth)
		{
			m_position.x = 0;
		}

		if (m_position.y > m_screenHeight)
		{
			m_position.y = 0;
		}

		m_position += m_velocity * delta.asSeconds();

		m_circle.setPosition(m_position);
	}

	sf::Vector2f getScreenPosition()
	{
		return m_position;
	}

	float findDistance(Point& other)
	{
		sf::Vector2f displacement = m_position - other.getScreenPosition();
		float squareDistance = displacement.x * displacement.x + displacement.y * displacement.y;
		return sqrt(squareDistance);
	}

	bool checkDistance(Point& other, float minDistance)
	{
		return findDistance(other) < minDistance;
	}

	float getCircleSize()
	{
		return m_size;
	}
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		states.transform *= getTransform();

		states.texture = NULL;

		target.draw(m_circle, states);
	}

private:
	sf::Vector2f m_position;
	sf::Vector2f m_velocity;
	float m_size;

	int m_screenWidth;
	int m_screenHeight;

	sf::CircleShape m_circle;
};