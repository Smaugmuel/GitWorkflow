#include "Level.hpp"
#include <assert.h>

Level::Level()
	: m_player(), m_endPoint(), m_objects()
{
}

Player* Level::getPlayer() const
{
	return m_player.get();
}

void Level::update(const float dt)
{
	if (m_player) m_player->update(dt);
	if (m_endPoint)
	{
		m_endPoint->update(dt);

		if (m_player && m_player->getGlobalBounds().intersects(m_endPoint->getGlobalBounds())) std::printf("LEVEL CLEARED!\n");
	}

	for (const auto& platform : m_platforms)
	{
		platform->update(dt);

		if (m_player && m_player->getGlobalBounds().intersects(platform->getGlobalBounds())) m_player->collide(*platform);
	}

	for (auto& object : m_objects)
	{
		object->update(dt);
	}
}

void Level::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (m_player) target.draw(*m_player);
	if (m_endPoint) target.draw(*m_endPoint);

	for (const auto& platform : m_platforms)
	{
		target.draw(*platform, states);
	}

	for (const auto& object : m_objects)
	{
		target.draw(*object, states);
	}
}
