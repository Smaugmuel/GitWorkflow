#include "Player.hpp"

Player::Player(const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color color)
	: GameObject(size, position, color)
{
}

void Player::update(const float dt)
{
	m_velocity.x = 0.0f;

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

void Player::resetJump()
{
	m_hasJumped = false;
}

