#include <vector>
#include <chrono>

#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "Utility.hpp"

#define WINDOW_WIDTH  (1080)
#define WINDOW_HEIGHT (720)

using Clock = std::chrono::steady_clock;
using Time = std::chrono::time_point<Clock>;

std::vector<Platform> platforms;
sf::Vector2f platformSize = { 100.0f, 20.0f };

void createPlatform(const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color color = sf::Color::White) 
{
	platforms.push_back({ size, position, color });
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML works!");
	sf::RectangleShape endPoint({ 100.0f, 100.0f });

	endPoint.setPosition({ 300.0f, 0.0f });
	endPoint.setFillColor(sf::Color::Green);

	createPlatform({ WINDOW_WIDTH, 10.0f }, { 0.0f, WINDOW_HEIGHT });

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

			if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
			{
				createPlatform(platformSize, static_cast<sf::Vector2f>(sf::Mouse::getPosition(window) - static_cast<sf::Vector2i>(platformSize / 2.0f)));
			}
		}

		player.update(dt);

		for (const auto& platform : platforms) 
		{
			if (player.getGlobalBounds().intersects(platform.getGlobalBounds())) player.collide(platform);
		}

		if(player.getGlobalBounds().intersects(endPoint.getGlobalBounds())) window.close();

		window.clear();
		window.draw(player);
		window.draw(endPoint);
		
		for (const auto& platform : platforms)
		{
			window.draw(platform);
		}

		window.display();
	}

	return 0;
}