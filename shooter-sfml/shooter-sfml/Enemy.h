#pragma once
#include "Unit.h"
class Enemy :
	public Unit
{
private:
	sf::Clock clock;
	sf::Time time1, time2;

public:
	Enemy();

	void update(const float& deltaTime);
	void render(sf::RenderTarget* target = nullptr);
	void move(float dirX, float dirY, float deltaTime);
};

