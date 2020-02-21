#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/VideoMode.hpp>

int main()
{
  sf::RenderWindow window(sf::VideoMode(800, 800), "Marching Squares");

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

    window.display();
  }

  return 0;
}
