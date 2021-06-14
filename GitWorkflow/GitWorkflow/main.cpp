#include <vector>
#include <chrono>

#include "Level.hpp"

#define WINDOW_WIDTH  (1080)
#define WINDOW_HEIGHT (720)

using Clock = std::chrono::steady_clock;
using Time = std::chrono::time_point<Clock>;

int main()
{
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML works!");
	const float windowScale = (WINDOW_WIDTH / WINDOW_HEIGHT) / (1080 / 720);
	const sf::Vector2f platformSize = { 100.0f, 10.0f };
	Level level;

	Time t1 = Clock::now();

	level.create<EndPoint>(sf::Vector2f(20.0f, 20.0f), sf::Vector2f(300.0f, 100.0f));
	level.create<Player>(sf::Vector2f(20.0f, 20.0f), sf::Vector2f(100.0f, 100.0f));
	level.create<Platform>(sf::Vector2f(WINDOW_WIDTH, 10.0f), sf::Vector2f(0.0f, WINDOW_HEIGHT));

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

			if (event.type == sf::Event::MouseButtonReleased)
			{
				if(event.mouseButton.button == sf::Mouse::Left) level.create<Platform>(platformSize, static_cast<sf::Vector2f>(sf::Mouse::getPosition(window) - static_cast<sf::Vector2i>(platformSize / 2.0f)));
				else if (event.mouseButton.button == sf::Mouse::Right) { level.getPlayer().setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window))); }
			}
		}

		level.update(dt * windowScale);

		window.clear();
		window.draw(level);
		window.display();
	}

	return 0;
}