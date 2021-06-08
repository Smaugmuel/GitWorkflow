#include <SFML/Graphics.hpp>
#include "Player.hpp"

#define WINDOW_WIDTH (1080)
#define WINDOW_HEIGHT (720)

int main()
{
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML works!");
	sf::RectangleShape endPoint({ 100.f, 100.f });

	endPoint.setPosition({ 300.f, 0.f });
	endPoint.setFillColor(sf::Color::Green);

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
		if (player.getGlobalBounds().intersects(endPoint.getGlobalBounds())) { window.close(); }

		window.draw(player);
		window.draw(endPoint);
		window.display();
	}

	return 0;
}