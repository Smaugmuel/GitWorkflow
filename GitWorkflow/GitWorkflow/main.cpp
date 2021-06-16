#include <vector>
#include <chrono>

#include "Level.hpp"

#define WINDOW_WIDTH  (1080)
#define WINDOW_HEIGHT (720)

using Clock = std::chrono::steady_clock;
using Time = std::chrono::time_point<Clock>;

constexpr float nanoSecondsToSeconds = 1.0f / static_cast<float>(1e9);

int main()
{
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML works!");
	const sf::Vector2f platformSize = { 100.0f, 10.0f };
	Level level;

	Time t1 = Clock::now();

	level.create<EndPoint>(sf::Vector2f(20.0f, 20.0f), sf::Vector2f(300.0f, 100.0f));
	level.create<Player>(sf::Vector2f(20.0f, 20.0f), sf::Vector2f(100.0f, 100.0f));

	while (window.isOpen())
	{
		Time t2 = t1;
		t1 = Clock::now();
		const float dt = static_cast<float>((t1 - t2).count()) * nanoSecondsToSeconds;

		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
			{
				level.create<Platform>(platformSize, static_cast<sf::Vector2f>(sf::Mouse::getPosition(window) - static_cast<sf::Vector2i>(platformSize / 2.0f)));
			}
		}

		level.update(dt);

		window.clear();
		window.draw(level);
		window.display();
	}

	return 0;
}