#include <SFML/Graphics.hpp>
#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Window/ContextSettings.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/WindowStyle.hpp>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <math.h>

#define SQRT_TWO 1.41421356237

int main()
{
  sf::ContextSettings settings;
  settings.antialiasingLevel = 15;

  sf::RenderWindow window(sf::VideoMode(1000, 1000), "10PRINT", sf::Style::Default, settings);
  
  int rows = 50;
  int cols = 50;

  sf::Vector2f gridSize(window.getSize().x * 1.f / rows, window.getSize().y * 1.f / cols);
  sf::VertexArray vertices(sf::Lines);

  srand(time(NULL));
  
  for (size_t row = 0; row < rows; row++)
  {
    for (size_t col = 0; col < cols; col++)
    {
      if (rand() % 2 == 1)
      {
        vertices.append(sf::Vertex(sf::Vector2f(gridSize.x * col + gridSize.x, gridSize.y * row)));
        vertices.append(sf::Vertex(sf::Vector2f(gridSize.x * col, gridSize.y * row + gridSize.y)));
      }
      else
      {
        vertices.append(sf::Vertex(sf::Vector2f(gridSize.x * col + gridSize.x, gridSize.y * row + gridSize.y)));
        vertices.append(sf::Vertex(sf::Vector2f(gridSize.x * col, gridSize.y * row)));
      }
    }
  }

  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      switch (event.type)
      {
      case sf::Event::Closed:
        window.close();
        break;
      default:
        break;
      }
    }

    window.clear();
    
    window.draw(vertices);

    window.display();
  }

  return 0;
}
