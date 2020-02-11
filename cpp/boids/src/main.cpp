#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/ContextSettings.hpp>

int main()
{
  sf::ContextSettings settings;
  settings.antialiasingLevel = 15;

  sf::RenderWindow window(sf::VideoMode(800, 800), "Boids",sf::Style::Default, settings);

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
}
