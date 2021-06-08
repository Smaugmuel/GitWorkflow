#pragma once

#include <SFML/Graphics.hpp>

class Player final : public sf::Drawable
{
public:
	Player(const sf::Vector2f& position = { 0.f, 0.f }, const sf::Vector2f& size = { 100.f, 100.f }, const sf::Color & color = sf::Color::Red)
		: m_model(size)
	{
		m_model.setFillColor(color);
		m_model.setPosition(position);
	}
	~Player() = default;

	void setPosition(sf::Vector2f position) { m_model.setPosition(position); }

	void move(sf::Vector2f offset) { m_model.setPosition(m_model.getPosition() + offset); }

	sf::Vector2f getPosition() const { return m_model.getPosition(); }

	void update() 
	{ 
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) move({ -0.01f, 0.f }); 
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) move({  0.01f, 0.f });
	}
private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override
	{
		target.draw(m_model, states);
	}

	sf::RectangleShape m_model;
};