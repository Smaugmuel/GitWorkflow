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
	float m_speed = 40.0f;
	bool m_hasJumped = true;
};