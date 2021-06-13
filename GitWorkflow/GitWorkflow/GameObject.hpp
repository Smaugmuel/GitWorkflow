#pragma once

#include <SFML/Graphics.hpp>

class GameObject : public sf::Drawable
{
public:
	GameObject(const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color color);
	virtual ~GameObject();

	void setSize(const sf::Vector2f& size);
	const sf::Vector2f& getSize() const;

	void setPosition(const sf::Vector2f& position);
	const sf::Vector2f& getPosition() const;

	void setVelocity(const sf::Vector2f& velocity);
	const sf::Vector2f& getVelocity() const;

	void move(const sf::Vector2f& offset);

	void setColor(const sf::Color color);
	const sf::Color getColor() const;

	const sf::FloatRect getGlobalBounds() const;

	virtual void update(const float dt);

protected:
	sf::RectangleShape m_model;
	sf::Vector2f m_velocity = { 0.0f, 0.0f };

private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};