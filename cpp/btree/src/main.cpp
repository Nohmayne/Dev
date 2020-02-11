#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <time.h>
#include "particle.cpp"

int main()
{
  sf::RenderWindow window(sf::VideoMode(1000, 1000), "Brownian Tree");

  //window.setFramerateLimit(2);

  srand(time(NULL));

  float gridSize = 200.f;
  int spareParticles = 100;
  bool showSpares = false;

  std::vector<Particle *> particles;
  particles.push_back(new Particle(sf::Vector2f((int)(gridSize / 2), (int)(gridSize / 2)), sf::Vector2f(window.getSize().x / gridSize, window.getSize().y / gridSize), sf::Vector2f(gridSize, gridSize)));
  particles.at(0)->freeze();
  for (size_t i = 0; i < spareParticles; i++)
  {
    particles.push_back(new Particle(sf::Vector2f(rand() % (int)gridSize, rand() % (int)gridSize), sf::Vector2f(window.getSize().x / gridSize, window.getSize().y / gridSize), sf::Vector2f(gridSize, gridSize)));
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
      case sf::Event::KeyReleased:
        if (event.key.code == sf::Keyboard::Space)
        {
          showSpares = !showSpares;
        }
      default:
        break;
      }
    }

    window.clear();

    for (size_t i = 0; i < particles.size(); i++)
    {
      if (!particles.at(i)->getFrozen())
      {
        particles.at(i)->update();

        for (size_t j = 0; j < particles.size(); j++)
        {
          if (i != j && particles.at(i)->getGridPosition() == particles.at(j)->getGridPosition() && particles.at(j)->getFrozen())
          {
            particles.at(i)->stepBack();
            particles.at(i)->freeze();
            particles.push_back(new Particle(sf::Vector2f(rand() % (int)gridSize, rand() % (int)gridSize), sf::Vector2f(window.getSize().x / gridSize, window.getSize().y / gridSize), sf::Vector2f(gridSize, gridSize)));
          }
        }

        if (showSpares)
        {
          window.draw(*particles.at(i));
        }

        particles.at(i)->randomizeDirection();
      }
      else
      {
        window.draw(*particles.at(i));
      }
    }

    window.display();
  }

  return 0;
}