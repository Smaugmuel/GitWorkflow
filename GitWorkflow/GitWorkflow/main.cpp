#include <SFML/Graphics.hpp>

#include "Player.hpp"
#include "Platform.hpp"

Platform createBottomPlatform()
{
	Platform platform;
	platform.setPos(0.0f, 190.0f);
	platform.setSize(200.0f, 10.0f);
	platform.setColor(sf::Color(0ui8, 150ui8, 0ui8));
	return platform;
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	Player player;
	Platform bottomPlatform = createBottomPlatform();

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(bottomPlatform);
		window.draw(player);
		window.display();
	}

	return 0;
}