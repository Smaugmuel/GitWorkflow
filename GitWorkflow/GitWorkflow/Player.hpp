#pragma once

#include "Platform.hpp"
#include "Utility.hpp"

class Player final : public GameObject
{
public:
	Player(const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color color = sf::Color::Red);
	~Player() = default;

	void collide(const Platform& platform);
	void update(const float dt) override;

private:
	const float m_baseSpeed = 160.0f;
	const float m_acceleration = m_baseSpeed * 2.0f;
	float m_speed = m_baseSpeed;

	bool m_hasJumped = true;
};