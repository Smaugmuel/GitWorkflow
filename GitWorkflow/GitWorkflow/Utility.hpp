#pragma once

#include <SFML/Graphics/Rect.hpp>

namespace util
{
	const sf::FloatRect intersection(const sf::FloatRect& rect1, const sf::FloatRect& rect2);
}