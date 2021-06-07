#include <SFML/Graphics.hpp>
#include "Player.hpp"

#define WINDOW_WIDTH (1080)
#define WINDOW_HEIGHT (720)

int main()
{
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML works!");
	Player player;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		player.update();
		window.draw(player);
		window.display();
	}

	return 0;
}