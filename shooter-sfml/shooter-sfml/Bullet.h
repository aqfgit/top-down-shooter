#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Bullet
{
private:

	sf::Vector2f direction;
	float movementSpeed;
	float x, y;
	sf::RectangleShape shape;

public:

	Bullet(float x, float y, float dirX, float dirY, float movementSpeed);

	sf::FloatRect getBounds();
	sf::RectangleShape getShape();

	void update();
	void render(sf::RenderTarget* target);
};

