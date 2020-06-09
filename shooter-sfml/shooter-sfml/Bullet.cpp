#include "Bullet.h"

Bullet::Bullet(float x, float y, float dirX, float dirY, float movementSpeed)
{
	this->movementSpeed = movementSpeed;
	this->x = x;
	this->y = y;
	this->direction.x = dirX;
	this->direction.y = dirY;
	this->shape.setSize(sf::Vector2f(5.f, 5.f));
	this->shape.setFillColor(sf::Color::Red);
	this->shape.setPosition(sf::Vector2f(x, y));
}

sf::FloatRect Bullet::getBounds()
{
	return this->shape.getGlobalBounds();
}

sf::RectangleShape Bullet::getShape()
{
	return this->shape;
}

void Bullet::update()
{
	this->shape.move(this->movementSpeed * this->direction);
}

void Bullet::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}

