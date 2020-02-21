#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <iostream>

class Tile : public sf::Drawable, public sf::Transformable
{
public:
	Tile(int val, sf::Vector2i bPos, float size) : m_value(val),
																								 m_boardPosition(bPos),
																								 m_color(238, 228, 218),
																								 m_square(sf::Vector2f(size, size))
	{
		if (m_value == 2 && rand() % 2 == 1)
		{
			setValue(4);
		}

		m_square.setFillColor(m_color);
		m_square.setPosition(m_square.getSize().x * m_boardPosition.x, m_square.getSize().y * m_boardPosition.y);

		m_text.setFillColor(sf::Color(119, 110, 101));
		const char *fontLocation = "resources/Open_Sans/OpenSans-Bold.ttf";
		if (!m_font.loadFromFile(fontLocation))
		{
			fprintf(stderr, "Error: Fatal error occurred when loading font from %s\n", fontLocation);
		}

		m_text.setFont(m_font);
		m_text.setString(std::to_string(m_value));
		m_text.setCharacterSize(size / 2);

		float squareCenterX = m_square.getPosition().x + m_square.getSize().x / 2;
		float squareCenterY = m_square.getPosition().y + m_square.getSize().y / 2;

		float textPositionX = squareCenterX - ((m_text.getLocalBounds().left + m_text.getLocalBounds().width) / 2.f);
		float textPositionY = squareCenterY - ((m_text.getLocalBounds().top + m_text.getLocalBounds().height) / 2.f);

		sf::FloatRect textRect = m_text.getLocalBounds();
		m_text.setOrigin(textRect.left + textRect.width / 2.f,
										 textRect.top + textRect.height / 2.f);
		m_text.setPosition(sf::Vector2f(m_square.getPosition().x + m_square.getSize().x / 2.f, m_square.getPosition().y + m_square.getSize().y / 2.f));
	}

	int setValue(int val)
	{
		m_value = val;
		m_text.setString(std::to_string(m_value));

		if (m_value > 4)
		{
			m_text.setFillColor(sf::Color::White);
		}

		switch (m_value)
		{
		case 2:
			m_color = sf::Color(238, 228, 218);
			break;
		case 4:
			m_color = sf::Color(237, 224, 200);
			break;
		case 8:
			m_color = sf::Color(242, 177, 121);
			break;
		case 16:
			m_color = sf::Color(245, 149, 99);
			break;
		case 32:
			m_color = sf::Color(246, 124, 95);
			break;
		case 64:
			m_color = sf::Color(246, 94, 59);
			break;
		case 128:
			m_color = sf::Color(237, 207, 114);
			break;
		case 256:
			m_color = sf::Color(237, 204, 97);
			break;
		case 512:
			m_color = sf::Color(237, 200, 80);
			break;
		case 1024:
			m_color = sf::Color(237, 197, 63);
			break;
		case 2048:
			m_color = sf::Color(237, 194, 46);
			break;
		default:
			break;
		}

		m_square.setFillColor(m_color);

		return m_value;
	}

	int getValue()
	{
		return m_value;
	}

	sf::Vector2i setBoardPosition(sf::Vector2i newBoardPosition)
	{
		m_boardPosition = newBoardPosition;
		m_square.setPosition(sf::Vector2f(m_boardPosition.x * m_square.getSize().x, m_boardPosition.y * m_square.getSize().y));

		sf::FloatRect textRect = m_text.getLocalBounds();
		m_text.setOrigin(textRect.left + textRect.width / 2.f,
										 textRect.top + textRect.height / 2.f);
		m_text.setPosition(sf::Vector2f(m_square.getPosition().x + m_square.getSize().x / 2.f, m_square.getPosition().y + m_square.getSize().y / 2.f));

		return m_boardPosition;
	}

	sf::Vector2i getBoardPosition()
	{
		return m_boardPosition;
	}

private:
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const
	{
		states.transform *= getTransform();

		states.texture = NULL;

		target.draw(m_square, states);
		target.draw(m_text, states);
	}

private:
	int m_value;
	sf::Vector2i m_boardPosition;

	sf::Color m_color;
	sf::Text m_text;
	sf::RectangleShape m_square;
	sf::Font m_font;
};