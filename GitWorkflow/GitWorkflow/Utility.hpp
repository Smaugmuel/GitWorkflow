#pragma once

#include <SFML/Graphics/Rect.hpp>

#include "Player.hpp"
#include "Platform.hpp"

namespace util
{
	const sf::Vector2f  center(const sf::FloatRect& rect);
	const bool          intersects(const sf::FloatRect& rect1, const sf::FloatRect& rect2);
	const sf::FloatRect intersection(const sf::FloatRect& rect1, const sf::FloatRect& rect2);
	void                checkAndResolveCollision(Player& player, const Platform& platform);
}