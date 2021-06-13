#pragma once

#include "GameObject.hpp"

class EndPoint final : public GameObject
{
public:
	EndPoint(const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color color = sf::Color::Green);
	~EndPoint() = default;
};