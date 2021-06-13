#include "GameObject.hpp"

GameObject::GameObject(const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color color)
	: Drawable(), m_model(size)
{
	setPosition(position);
	setColor(color);
}

GameObject::~GameObject()
{
}

void GameObject::setSize(const sf::Vector2f& size)
{
	m_model.setSize(size);
}

const sf::Vector2f& GameObject::getSize() const
{
	return m_model.getSize();
}

void GameObject::setPosition(const sf::Vector2f& position)
{
	m_model.setPosition(position);
}

const sf::Vector2f& GameObject::getPosition() const
{
	return m_model.getPosition();
}

void GameObject::setVelocity(const sf::Vector2f& velocity)
{
	m_velocity = velocity;
}

const sf::Vector2f& GameObject::getVelocity() const
{
	return m_velocity;
}

void GameObject::move(const sf::Vector2f& offset)
{
	m_model.move(offset);
}

void GameObject::setColor(const sf::Color color)
{
	m_model.setFillColor(color);
}

const sf::Color GameObject::getColor() const
{
	return m_model.getFillColor();
}

const sf::FloatRect GameObject::getGlobalBounds() const
{
	return m_model.getGlobalBounds();
}

void GameObject::update(const float dt)
{
	move(m_velocity * dt);
}

void GameObject::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_model, states);
}
