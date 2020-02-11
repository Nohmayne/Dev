#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "point.cpp"

int main()
{
	// create and set window settings
	sf::ContextSettings settings;
	settings.antialiasingLevel = 15;

	// create a window with settings
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Web");

	// seed the random number generator
	srand(time(NULL));

	// clock to store delta time
	sf::Clock clock;

	// minimum and maximum point velocity vars
	const float minimumVelocity = -50.f;
	const float maximumVelocity = minimumVelocity * -1.f;

	// minimum and maximum point size vars
	const float minimumSize = 2.f;
	const float maximumSize = 5.f;

	// minimum distance required for points to have a line drawn between them
	const float minimumDrawDistance = 200.f;

	// number of points to generate
	const int numberOfPoints = 150;

	// point vector
	std::vector<Point> points;

	// vertex array for all lines
	sf::VertexArray lines(sf::Lines);

	// generate the points
	for (size_t index = 0; index < numberOfPoints; index++)
	{
		points.push_back(Point(window.getSize().x, window.getSize().y, minimumVelocity, maximumVelocity, minimumSize, maximumSize));
	}

	// main loop
	while (window.isOpen())
	{
		// handle events
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed: // window closed event
				window.close();
				break;
			default:
				break;
			}
		}

		// clear the window
		window.clear(sf::Color(50, 50, 50, 255));

		// calculate delta time
		sf::Time deltaTime = clock.restart();

		// update all points in the point array
		for (Point& point : points)
		{
			point.update(deltaTime);
			window.draw(point);
		}

		// clear any previous lines
		lines.clear();

		// draw all necessary lines
		for (size_t from = 0; from < points.size(); from++)
		{
			for (size_t to = from + 1; to < points.size(); to++)
			{
				Point &lineStart = points[from];
				Point &lineEnd = points[to];

				if (lineStart.checkDistance(lineEnd, minimumDrawDistance))
				{
					// get opacity of the line based on minimumDrawDistance and actual distance
					float distancePercentage = lineStart.findDistance(lineEnd) / minimumDrawDistance;
					int lineOpacity = 255 * (1 - distancePercentage);

					// append a line with that opacity
					lines.append(sf::Vertex(
						sf::Vector2f(
							lineStart.getScreenPosition().x + lineStart.getCircleSize() / 2,
							lineStart.getScreenPosition().y + lineStart.getCircleSize() / 2),
						sf::Color(255, 255, 255, lineOpacity)));
					lines.append(sf::Vertex(
						sf::Vector2f(
							lineEnd.getScreenPosition().x + lineEnd.getCircleSize() / 2,
							lineEnd.getScreenPosition().y + lineEnd.getCircleSize() / 2),
						sf::Color(255, 255, 255, lineOpacity)));
				}
			}
		}

		window.draw(lines);

		// display the current buffer
		window.display();
	}

	return 0;
}
