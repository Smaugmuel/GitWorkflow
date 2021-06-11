#include "Platform.hpp"

Platform::Platform(const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color color)
	: Transformable(), Drawable(), m_model(size)
{
	m_model.setPosition(position);
	m_model.setFillColor(color);

	// constexpr size_t sizeofT = sizeof(sf::FloatRect);
	// constexpr size_t sizeofTRef = sizeof(std::reference_wrapper<sf::FloatRect>);
}

void Platform::setSize(const sf::Vector2f& size)
{
	m_model.setSize(size);
}

const sf::Vector2f& Platform::getSize() const
{
	return m_model.getSize();
}

void Platform::setPosition(const sf::Vector2f& position)
{
	m_model.setPosition(position);
}

const sf::Vector2f& Platform::getPosition() const
{
	return m_model.getPosition();
}

void Platform::setColor(const sf::Color color)
{
	m_model.setFillColor(color);
}

const sf::Color Platform::getColor() const
{
	return m_model.getFillColor();
}

const sf::FloatRect& Platform::getGlobalBounds() const
{
	return m_model.getGlobalBounds();
}

void Platform::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(m_model, states);
}
