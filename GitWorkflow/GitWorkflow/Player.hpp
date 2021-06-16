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

	void setColliding(const bool colliding);
	const bool isColliding() const;
	void resetJump();

private:
	const float m_baseSpeed = 160.0f;
	const float m_acceleration = m_baseSpeed * 2.0f;
	float m_speed = m_baseSpeed;

	const float m_gravityModifier = 24.0f;
	const float m_sprintModifier = 1.5f;
	const float m_jumpModifier = 1.25f;
	const float m_airControl = 0.5f;
	bool m_colliding = false;
	bool m_hasJumped = true;

	bool m_isMoveLeftButtonDown = false;
	bool m_isMoveRightButtonDown = false;
	bool m_isSprintButtonDown = false;
	bool m_isJumpButtonDown = false;

	void accelerate(const sf::Vector2f& acceleration, const float dt);
	void updateVelocity(const float dt);
	void updateSpeed(const float dt);
	void updateInput();
};