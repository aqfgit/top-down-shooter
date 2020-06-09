#pragma once
#include "Unit.h"
#include "Bullet.h"

class Player :
	public Unit
{
private:
	sf::RectangleShape shape;
	sf::Clock clock;
	sf::Time time1, time2;

public:
	Player();
	std::vector<Bullet*> bullets;

	std::vector <Bullet*>& getBullets();
	void update(const float& deltaTime);
	void render(sf::RenderTarget* target = nullptr);
	void move(float dirX, float dirY, float deltaTime);
};

