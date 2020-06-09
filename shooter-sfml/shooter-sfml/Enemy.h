#pragma once
#include "Unit.h"
class Enemy :
	public Unit
{
private:
	sf::Clock clock;
	sf::Time time1, time2;

public:
	Enemy(float x);

	void update(const float& deltaTime);
	void render(sf::RenderTarget* target = nullptr);
	
};

