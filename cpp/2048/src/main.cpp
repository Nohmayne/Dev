#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <time.h>
#include "board.cpp"
#include "../include/2048.h"

int main()
{
	// create a window
	sf::RenderWindow window(sf::VideoMode(720, 720), "2048", sf::Style::Close | sf::Style::Titlebar);

	// seed the random number generator
	srand(time(NULL));

	// divide board into 4x4
	int boardSize = window.getSize().x / 4;

	// make a board object
	Board b(4, 4, window.getSize().x, window.getSize().y, boardSize);

	// main loop
	while (window.isOpen())
	{
		// handle events
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyReleased:
				// move the board based on direction
				if (event.key.code == sf::Keyboard::Up)
				{
					b.move(UP);
				}
				else if (event.key.code == sf::Keyboard::Right)
				{
					b.move(RIGHT);
				}
				else if (event.key.code == sf::Keyboard::Down)
				{
					b.move(DOWN);
				}
				else if (event.key.code == sf::Keyboard::Left)
				{
					b.move(LEFT);
				}

				// check if the board is full and end the game if necessary
				if (b.checkFull())
				{
					printf("Game Ended: You lost!");
				}
			default:
				break;
			}
		}

		// clear the window for drawing
		window.clear(sf::Color(206, 194, 182));

		// draw the board
		window.draw(b);

		// display the current buffer
		window.display();
	}

	return 0;
}