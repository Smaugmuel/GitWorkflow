#pragma once
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

class Platform final : sf::Drawable
{
public:
	Platform() = default;
	~Platform() = default;

	void setPos(float x, float y) { rect_.setPosition(x, y); }
	void setWidth(float x, float y) { rect_.setSize({ x, y }); }
	void setColor(sf::Color color) { rect_.setFillColor(color); }

	sf::Vector2f getPos() const { return rect_.getPosition(); }
	sf::Vector2f getWidth() const { return rect_.getSize(); }
	sf::Color getColor() const { return rect_.getFillColor(); }

private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) { target.draw(rect_, states); }

	sf::RectangleShape rect_;
};