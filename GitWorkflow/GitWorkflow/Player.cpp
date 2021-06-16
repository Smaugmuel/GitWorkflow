#include "Player.hpp"

Player::Player(const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color color)
	: GameObject(size, position, color)
{
}

void Player::update(const float dt)
{
	updateInput();
	updateSpeed(dt);
	updateVelocity(dt);

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
	const float lastDirection = (m_velocity.x > 0.0f ? 1.0f : (m_velocity.x < 0.0f ? -1.0f : 0.0f));

	if ((m_velocity.x > 0.0f && acceleration.x > 0.0f && velocity.x > m_speed) 
	 || (m_velocity.x < 0.0f && acceleration.x < 0.0f && velocity.x < -m_speed))
		velocity.x = lastDirection * m_speed;
	else if ((m_velocity.x < 0.0f && acceleration.x > 0.0f && velocity.x > 0.0f) 
		  || (m_velocity.x > 0.0f && acceleration.x < 0.0f && velocity.x < 0.0f))
		velocity.x = 0.0f;

	m_velocity = velocity;
}

void Player::updateVelocity(const float dt)
{
	const float absVelocity   = std::abs(m_velocity.x);
	const float nextDirection = (m_isMoveLeftButtonDown ? -1.0f : (m_isMoveRightButtonDown ? 1.0f : 0.0f));
	const float lastDirection = (m_velocity.x > 0.0f ? -1.0f : (m_velocity.x < 0.0f ? 1.0f : 0.0f));

	if (nextDirection == 0.0f)
	{
		if(absVelocity > 0.0f)
			accelerate(lastDirection * sf::Vector2f(isColliding() ? m_acceleration : m_acceleration * m_airControl, 0.0f), dt);
	}
	else if(absVelocity < m_speed)
		accelerate(nextDirection * sf::Vector2f( m_acceleration, 0.0f), dt);
	else if(absVelocity > m_speed && !m_isSprintButtonDown && isColliding())
		accelerate(nextDirection * sf::Vector2f(-m_acceleration, 0.0f), dt);

	if (m_isJumpButtonDown)
	{
		if (!m_hasJumped && isColliding())
		{
			m_velocity.y = -m_baseSpeed * m_jumpModifier;
			m_hasJumped = true;
		}
	}
	else if (m_hasJumped && m_velocity.y < 0.0f)
		m_velocity.y += m_baseSpeed * dt;
}

void Player::updateSpeed(const float dt)
{
	m_speed = m_baseSpeed;

	if (isColliding())
	{
		if (m_isSprintButtonDown)
			m_speed *= m_sprintModifier;
	}
	else
		m_speed *= m_airControl;
}

void Player::updateInput()
{
	m_isMoveLeftButtonDown  = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
	m_isMoveRightButtonDown = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
	m_isSprintButtonDown    = sf::Keyboard::isKeyPressed(sf::Keyboard::LShift);
	m_isJumpButtonDown      = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);
}

