#pragma once

#include <SFML/Graphics.hpp>

class Player final : public sf::Drawable
{
public:
	Player(const sf::Vector2f& size = sf::Vector2f(100.f, 100.f), const sf::Color& color = sf::Color::Red)
		: m_shape(size)
	{
		m_shape.setFillColor(color);
	}

	~Player() = default;

private:
	sf::RectangleShape m_shape;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override 
	{
		target.draw(m_shape, states);
	}
};