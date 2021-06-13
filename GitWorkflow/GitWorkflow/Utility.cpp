#include "Utility.hpp"

const sf::Vector2f util::center(const sf::FloatRect& rect)
{
	return sf::Vector2f(rect.left + rect.width * 0.5f, rect.top + rect.height * 0.5f);
}

const bool util::intersects(const sf::FloatRect& rect1, const sf::FloatRect& rect2)
{
	const sf::Vector2f center1 = center(rect1), center2 = center(rect2);
	return (std::fabsf(center1.x - center2.x) < (rect1.width  + rect2.width ) * 0.5f
		&&  std::fabsf(center1.y - center2.y) < (rect1.height + rect2.height) * 0.5f);
}

const sf::FloatRect util::intersection(const sf::FloatRect& rect1, const sf::FloatRect& rect2)
{
	const float left   = std::max(rect1.left, rect2.left);
	const float top    = std::max(rect1.top,  rect2.top);
	const float right  = std::min(rect1.left + rect1.width,  rect2.left + rect2.width);
	const float bottom = std::min(rect1.top  + rect1.height, rect2.top  + rect2.height);
	return sf::FloatRect(left, top, right - left, bottom - top);
}

void util::checkAndResolveCollision(Player& player, const Platform& platform)
{
	const sf::FloatRect playerRect     = player.getGlobalBounds();
	const sf::FloatRect platformRect   = platform.getGlobalBounds();

	if (!intersects(playerRect, platformRect))
		return;

	const sf::FloatRect intersection   = util::intersection(playerRect, platformRect);
	const sf::Vector2f  playerCenter   = {   playerRect.left +   playerRect.width * 0.5f,   playerRect.top +   playerRect.height * 0.5f };
	const sf::Vector2f  platformCenter = { platformRect.left + platformRect.width * 0.5f, platformRect.top + platformRect.height * 0.5f };

	float sign = 1.0f;
	const sf::Vector2f& velocity = player.getVelocity();

	if (intersection.width > intersection.height)
	{
		if (playerCenter.y < platformCenter.y)
		{
			sign = -1.0f;
			player.resetJump();
			player.setVelocity({ velocity.x, 0.0f });
		}
		else if (velocity.y < 0.0f)
			player.setVelocity({ velocity.x, 0.0f });
		player.move({ 0.0f, intersection.height * sign });
	}
	else
	{
		if (playerCenter.x < platformCenter.x)
			sign = -1.0f;
		player.move({ intersection.width * sign, 0.0f });
		player.setVelocity({ 0.0f, velocity.y });
	}
}
