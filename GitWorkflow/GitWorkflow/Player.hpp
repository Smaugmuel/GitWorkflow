#pragma once

#include <SFML/Graphics.hpp>

class Player final : public sf::Drawable
{
public:
	Player(const sf::Vector2f& size = sf::Vector2f(100.f, 100.f), const sf::Color& color = sf::Color::Red)
		: m_model(size)
	{
		m_model.setFillColor(color);
	}
	~Player() = default;

	void setPosition(sf::Vector2f position) { m_model.setPosition(position); }

	void move(sf::Vector2f offset) { m_model.setPosition(m_model.getPosition() + offset); }

	sf::Vector2f getPosition() const { return m_model.getPosition(); }

private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override
	{
		target.draw(m_model, states);
	}

	sf::RectangleShape m_model;
};