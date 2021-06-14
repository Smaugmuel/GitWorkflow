#include "Player.hpp"

Player::Player(const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color color)
	: GameObject(size, position, color)
{
}

void Player::collide(const Platform& platform)
{
	const auto intersection = util::intersection(getGlobalBounds(), platform.getGlobalBounds());
	const bool verticalCollision = abs(intersection.width) > abs(intersection.height);

	move(verticalCollision ? sf::Vector2f(0.0f, intersection.height) : sf::Vector2f(intersection.width, 0.0f));

	if (verticalCollision)
	{
		if(m_velocity.y > 0.0f) m_hasJumped = false;
		setVelocity({ m_velocity.x, 0.0f });
	}
}

void Player::update(const float dt)
{
	if (m_collidedLastFrame && 
		(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::RShift))) 
		m_speed = m_baseSpeed * m_sprintModifier;
	else m_speed = m_baseSpeed;

	const float control = m_collidedLastFrame ? 1.0f : m_airControl;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) 
	{ 
		if (std::abs(m_velocity.x) < m_speed * control) 
			m_velocity.x -= m_acceleration * control * dt;
	}
	else if (m_velocity.x < 0.0f) m_velocity.x += m_acceleration * dt;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) 
	{
		if (std::abs(m_velocity.x) < m_speed * control)
			m_velocity.x += m_acceleration * dt * control;
	}
	else if (m_velocity.x > 0.0f) m_velocity.x -= m_acceleration * control * dt;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		if (!m_hasJumped)
		{
			m_velocity.y = -m_baseSpeed * m_jumpModifier;
			m_hasJumped = true;
		}
	}
	else if (m_hasJumped && m_velocity.y < 0.0f) m_velocity.y += m_speed * dt;

	move(m_velocity * dt + sf::Vector2f(0.0f, 9.82f) * 24.0f * (dt * dt * 0.5f));
	m_velocity.y += 9.82f * 24.0f * dt;
}

void Player::setCollidedLastFrame(const bool collidedLastFrame)
{
	m_collidedLastFrame = collidedLastFrame;
}

