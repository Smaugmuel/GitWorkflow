#include "Utility.hpp"
#include <iostream>

const sf::FloatRect util::intersection(const sf::FloatRect& rect1, const sf::FloatRect& rect2)
{
	const float x1 = std::max(rect1.left, rect2.left);
	const float y1 = std::max(rect1.top, rect2.top);

	const float x2 = std::min(rect1.left + rect1.width, rect2.left + rect2.width);
	const float y2 = std::min(rect1.top + rect1.height, rect2.top + rect2.height);

	return sf::FloatRect(x1, y1, x1 > (rect1.left + rect1.width / 2.0f) ? x1 - x2 : x2 - x1, y1 > (rect1.top + rect1.height / 2.0f) ? y1 - y2 : y2 - y1);
}

