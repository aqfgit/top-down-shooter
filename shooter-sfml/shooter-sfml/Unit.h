#pragma once
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stack>
#include <map>
#include <vector>

#include "Bullet.h"

class Unit
{
protected:
	float movementSpeed;
	float x, y;
	float shootingCooldown;
	float attackDamage;
	float hitPoints;

	bool dead;


	std::vector<Bullet*> bullets;
	sf::RectangleShape shape;

public:

	virtual void update(const float& deltaTime) = 0;
	virtual void render(sf::RenderTarget* target = nullptr) = 0;
	virtual void takeDamage(float damage);


	template<class Object> void checkForBulletsCollision(Object& object);
	bool isDead();

	std::vector <Bullet*>& getBullets();
	sf::RectangleShape getShape();

};

template<class Object>
inline void Unit::checkForBulletsCollision(Object& object)
{
	int counter = 0;

	for (auto* bullet : bullets) {
		
		if (bullet->getShape().getGlobalBounds().intersects(object->getShape().getGlobalBounds())) {
			std::cout << "BULLET" << std::endl;
			object->takeDamage(this->attackDamage);
			delete bullets.at(counter);
			bullets.erase(bullets.begin() + counter);
			counter--;
		}
		counter++;
	}
	
}

