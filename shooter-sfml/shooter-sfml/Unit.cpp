#include "Unit.h"

void Unit::takeDamage(float damage)
{
	this->hitPoints -= damage;
	if (hitPoints <= 0) {
		this->dead = true;
	}
}

bool Unit::isDead()
{
	return this->dead;
}

std::vector<Bullet*>& Unit::getBullets()
{
	return this->bullets;
}

sf::RectangleShape Unit::getShape()
{
	return this->shape;
}
