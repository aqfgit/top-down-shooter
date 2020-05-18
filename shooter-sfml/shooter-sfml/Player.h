#pragma once
#include "Unit.h"

class Player :
	public Unit
{
private:
	sf::RectangleShape shape;
public:
	Player();
	void update(const float& deltaTime);
	void render(sf::RenderTarget* target = nullptr);
	void move(float dirX, float dirY, float deltaTime);
};

