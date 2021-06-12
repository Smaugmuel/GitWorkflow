#pragma once

#include <SFML/Graphics.hpp>
#include "Platform.hpp"
#include "Utility.hpp"

class Player final : public sf::Drawable
{
public:
	Player(const sf::Vector2f& position = { 0.0f, 0.0f }, const sf::Vector2f& size = { 100.0f, 100.0f }, const sf::Color& color = sf::Color::Red);
	~Player() = default;

	void move(const sf::Vector2f& offset);
	void setPosition(const sf::Vector2f& position);
	const sf::Vector2f& getPosition() const;

	void setVelocity(const sf::Vector2f& velocity);
	const sf::Vector2f& getVelocity() const;

	const sf::FloatRect getGlobalBounds() const;
	void collide(const Platform& platform);

	void update(const float dt = 0.0f);

private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	sf::RectangleShape m_model;
	sf::Vector2f m_velocity = { 0.0f, 0.0f };

	float m_speed = 40.0f;
	bool m_hasJumped = true;
};