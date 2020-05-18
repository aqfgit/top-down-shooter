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

class Unit
{
protected:
	float movementSpeed;
	float x, y;


public:
	virtual void update(const float& deltaTime) = 0;
	virtual void render(sf::RenderTarget* target = nullptr) = 0;
	virtual void move(float dirX, float dirY, float deltaTime) = 0;
};

