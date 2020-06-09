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


	std::vector<Bullet*> bullets;


public:
	sf::RectangleShape shape;

	virtual void update(const float& deltaTime) = 0;
	virtual void render(sf::RenderTarget* target = nullptr) = 0;

	std::vector <Bullet*>& getBullets();

};

