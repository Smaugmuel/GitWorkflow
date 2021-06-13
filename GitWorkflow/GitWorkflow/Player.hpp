#pragma once

#include "Platform.hpp"

class Player final : public GameObject
{
public:
	Player(const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color color = sf::Color::Red);
	~Player() = default;

	//void collide(const Platform& platform);
	void update(const float dt) override;
	/*void move(const sf::Vector2f& offset);
	void setPosition(const sf::Vector2f& position);
	const sf::Vector2f& getPosition() const;

	void setVelocity(const sf::Vector2f& velocity);
	const sf::Vector2f& getVelocity() const;

	const sf::FloatRect getGlobalBounds() const;

	void update(const float dt = 0.0f);*/

	void resetJump();

private:
	float m_speed = 40.0f;
	bool m_hasJumped = true;
};