#include "Player.hpp"

Player::Player(const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color color)
	: GameObject(size, position, color)
{
}

void Player::update(const float dt)
{
	updateInput();
	updateSpeed(dt);
	updateMovement(dt);

	move(m_velocity * dt + sf::Vector2f(0.0f, 9.82f) * m_gravityModifier * (dt * dt * 0.5f));
	m_velocity.y += 9.82f * m_gravityModifier * dt;
}

void Player::setColliding(const bool colliding)
{
	m_colliding = colliding;
}

const bool Player::isColliding() const
{
	return m_colliding;
}

void Player::resetJump()
{
	m_hasJumped = false;
}

void Player::accelerate(const sf::Vector2f& acceleration, const float dt)
{
	sf::Vector2f velocity = m_velocity + acceleration * dt;

	if (m_velocity.x > 0.0f)
	{
		if (acceleration.x > 0.0f && velocity.x > m_speed)
			velocity.x = m_speed;
		else if (acceleration.x < 0.0f && velocity.x < 0.0f)
			velocity.x = 0.0f;
	}

	if (m_velocity.x < 0.0f)
	{
		if (acceleration.x < 0.0f && velocity.x < -m_speed)
			velocity.x = -m_speed;
		else if (acceleration.x > 0.0f && velocity.x > 0.0f)
			velocity.x = 0.0f;
	}

	m_velocity = velocity;
}

void Player::updateMovement(const float dt)
{
	if (!m_movingLeft)
	{
		if (m_velocity.x < 0.0f)
			accelerate({ isColliding() ? m_acceleration : m_acceleration * m_airControl, 0.0f }, dt);
	}
	else if (m_velocity.x > -m_speed)
		accelerate({ -m_acceleration, 0.0f }, dt);
	else if(m_velocity.x < -m_speed && !m_sprinting && isColliding()) 
		accelerate({  m_acceleration, 0.0f }, dt);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) m_velocity.x -= m_speed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) m_velocity.x += m_speed;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !m_hasJumped)
	{
		m_velocity.y -= m_speed;
		m_hasJumped = true;
	}

	move(sf::Vector2f(0.0f, 9.82f) * (dt * dt / 2.0f));
	m_velocity.y += 9.82f * dt;

	GameObject::update(dt);
}



