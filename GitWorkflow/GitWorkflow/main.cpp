#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include <chrono>

#define WINDOW_WIDTH  (1080)
#define WINDOW_HEIGHT (720)

using Clock = std::chrono::steady_clock;
using Time = std::chrono::time_point<Clock>;

int main()
{
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML works!");
	sf::RectangleShape endPoint({ 100.0f, 100.0f });

	endPoint.setPosition({ 300.0f, 0.0f });
	endPoint.setFillColor(sf::Color::Green);

	Player player;
	Time t1 = Clock::now();

	while (window.isOpen())
	{
		Time t2 = t1;
		t1 = Clock::now();
		const float dt = static_cast<float>((t1 - t2).count()) / 1e9;

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		player.update(dt);
		if (player.getGlobalBounds().intersects(endPoint.getGlobalBounds())) { window.close(); }

		window.clear();
		window.draw(player);
		window.draw(endPoint);
		window.display();
	}

	return 0;
}