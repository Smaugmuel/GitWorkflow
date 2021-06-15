#include <vector>
#include <chrono>

#include "Level.hpp"

#define WINDOW_WIDTH  (1920)
#define WINDOW_HEIGHT (1080)
#define FRAMES_PER_SECOND (120.0f)

using Clock = std::chrono::steady_clock;
using Time = std::chrono::time_point<Clock>;

int main()
{
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML works!");
	const float windowScale = (static_cast<float>(WINDOW_WIDTH) / static_cast<float>(WINDOW_HEIGHT)) / (1080.0f / 720.0f);
	const sf::Vector2f platformSize = { 100.0f, 10.0f };
	const float timeStep = 1.0f / FRAMES_PER_SECOND;
	float accumulator = 0.0f;
	Level level;

	Time t1 = Clock::now();

	level.create<EndPoint>(sf::Vector2f(20.0f, 20.0f), sf::Vector2f(300.0f, 100.0f));
	level.create<Player>(sf::Vector2f(20.0f, 20.0f), sf::Vector2f(100.0f, 100.0f));
	level.create<Platform>(sf::Vector2f(WINDOW_WIDTH, platformSize.y), sf::Vector2f(0.0f, WINDOW_HEIGHT - platformSize.y));

	while (window.isOpen())
	{
		Time t2 = t1;
		t1 = Clock::now();
		const float dt = static_cast<float>((t1 - t2).count()) / static_cast<float>(1e9);
		accumulator += dt;

		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::MouseButtonReleased)
			{
				if(event.mouseButton.button == sf::Mouse::Left) 
					level.create<Platform>(platformSize, static_cast<sf::Vector2f>(sf::Mouse::getPosition(window) 
						- static_cast<sf::Vector2i>(platformSize / 2.0f)));
				else if (event.mouseButton.button == sf::Mouse::Right) 
					level.getPlayer()->setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
			}
		}

		while (accumulator >= timeStep)
		{
			accumulator -= timeStep;
			level.update(timeStep * windowScale);

			window.clear();
			window.draw(level);
			window.display();
		}
	}

	return 0;
}