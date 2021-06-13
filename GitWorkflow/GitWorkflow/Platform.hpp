#pragma once

#include "GameObject.hpp"

class Platform final : public GameObject
{
public:
	Platform(const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color color = sf::Color::White);
	~Platform() = default;
};