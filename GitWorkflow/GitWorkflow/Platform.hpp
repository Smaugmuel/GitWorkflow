#pragma once
#include <SFML/Graphics/RectangleShape.hpp>

class Platform final
{
public:
	Platform() = default;
	~Platform() = default;

	void setPos(float x, float y) { rect_.setPosition(x, y); }

private:
	sf::RectangleShape rect_;
};