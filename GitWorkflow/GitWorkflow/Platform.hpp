#pragma once

#include <SFML/Graphics.hpp>

class Platform final : public sf::Drawable
{
public:
	Platform(const sf::Vector2f& size, const sf::Vector2f& position = { 0.0f, 0.0f }, const sf::Color color = sf::Color::White);
	~Platform() = default;

	void setSize(const sf::Vector2f& size);
	const sf::Vector2f& getSize() const;

	void setPosition(const sf::Vector2f& position);
	const sf::Vector2f& getPosition() const;

	void setColor(const sf::Color color);
	const sf::Color getColor() const;

	const sf::FloatRect& getGlobalBounds() const;

private:
	sf::RectangleShape m_model;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};