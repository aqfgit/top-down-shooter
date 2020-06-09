#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Bullet
{
private:
	sf::RectangleShape shape;

	sf::Vector2f direction;
	float movementSpeed;
	float x, y;

public:
	Bullet(float x, float y, float dirX, float dirY, float movementSpeed);

	sf::FloatRect getBounds();

	void update();
	void render(sf::RenderTarget* target);
};

