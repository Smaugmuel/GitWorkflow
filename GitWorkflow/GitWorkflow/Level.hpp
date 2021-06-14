#pragma once

#include <vector>
#include <memory>

#include "Platform.hpp"
#include "EndPoint.hpp"
#include "Player.hpp"

class Level final : public sf::Drawable
{
public:
	Level();
	~Level() = default;

	template<typename T, typename... V>
	void create(const V& ...args)
	{
		if constexpr (std::is_same_v<T, Player>) m_player = std::make_unique<Player>(args...);
		else if constexpr (std::is_same_v<T, EndPoint>) m_endPoint = std::make_unique<EndPoint>(args...);
		else if constexpr (std::is_same_v<T, Platform>) m_platforms.push_back(std::make_unique<Platform>(args...));
		else m_objects.push_back(std::make_unique<T>(args...));
	}

	Player* getPlayer() const;

	void update(const float dt);

private:
	std::unique_ptr<Player> m_player;
	std::unique_ptr<EndPoint> m_endPoint;
	std::vector<std::unique_ptr<Platform>> m_platforms;
	std::vector<std::unique_ptr<GameObject>> m_objects;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};