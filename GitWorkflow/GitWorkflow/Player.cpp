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
	if (std::roundf(m_velocity.y) == 0.0f && (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::RShift))) m_speed = m_baseSpeed * 1.5f;
	else m_speed = m_baseSpeed;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) { if (std::abs(m_velocity.x) < m_speed * (std::roundf(m_velocity.y) == 0.0f ? 1.0f : 0.5f)) m_velocity.x -= m_acceleration * dt * (std::roundf(m_velocity.y) == 0.0f ? 1.0f : 0.5f); }
	else if (m_velocity.x < 0.0f) m_velocity.x += m_acceleration * dt;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) { if (std::abs(m_velocity.x) < m_speed * (std::roundf(m_velocity.y) == 0.0f ? 1.0f : 0.5f)) m_velocity.x += m_acceleration * dt * (std::roundf(m_velocity.y) == 0.0f ? 1.0f : 0.5f); }
	else if (m_velocity.x > 0.0f) m_velocity.x -= m_acceleration * dt;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		if (!m_hasJumped)
		{
			m_velocity.y -= m_speed;
			m_hasJumped = true;
		}
	}

	else if (m_hasJumped) { m_velocity.y += m_speed * dt;  }

	move(sf::Vector2f(0.0f, 9.82f) * (dt * dt / 2.0f));
	m_velocity.y += 9.82f * 4.0f * dt; // * 4 IS FOR TESTING PURPOSES ONLY

	GameObject::update(dt);
}

