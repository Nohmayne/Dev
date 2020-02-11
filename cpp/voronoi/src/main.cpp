#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Voronoi", sf::Style::Close | sf::Style::Titlebar);

    srand(time(NULL));

    sf::Vector2f grid(4.f, 4.f);

    std::vector<sf::Vector2f> voronoiPoints;

    sf::VertexArray texture(sf::Points);

    float maximumDistance = sqrt(window.getSize().x * window.getSize().x + window.getSize().y * window.getSize().y) / 2.f;

    for (size_t height = 0; height < window.getSize().y; height++)
    {
        for (size_t width = 0; width < window.getSize().x; width++)
        {
            texture.append(sf::Vertex(sf::Vector2f((int)width, (int)height)));
        }
    }

    for (size_t gridHeight = 0; gridHeight < grid.y; gridHeight++)
    {
        for (size_t gridWidth = 0; gridWidth < grid.x; gridWidth++)
        {
            voronoiPoints.push_back(sf::Vector2f(
                rand() % (int)((gridWidth + 1) * (window.getSize().x / grid.x)) + (gridWidth * (window.getSize().x / grid.x)),
                rand() % (int)((gridHeight + 1) * (window.getSize().y / grid.y)) + (gridHeight * (window.getSize().y / grid.y))
            ));
        }
    }

    for (size_t height = 0; height < window.getSize().y; height++)
    {
        for (size_t width = 0; width < window.getSize().x; width++)
        {
            int currentIndex = (height * window.getSize().x) + width;

            float deltaX = texture[currentIndex].position.x - voronoiPoints[0].x;
            float deltaY = texture[currentIndex].position.y - voronoiPoints[0].y;
            float minimumDistance = sqrt(deltaX * deltaX + deltaY * deltaY);

            for (sf::Vector2f& point : voronoiPoints)
            {
                deltaX = texture[currentIndex].position.x - point.x;
                deltaY = texture[currentIndex].position.y - point.y;

                float newDistance = sqrt(deltaX * deltaX + deltaY * deltaY);
                if (newDistance < minimumDistance)
                {
                    minimumDistance = newDistance;
                }
            }

            int pointAlpha = (int)(255 * (minimumDistance / maximumDistance));
            texture[currentIndex].color = sf::Color(255, 255, 255, pointAlpha);
        }
    }
    

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch(event.type)
            {
            case sf::Event::Closed:
                window.close();
            default:
                break;
            }
        }

        window.clear();

        window.draw(texture);

        window.display();
    }

    return 0;
}