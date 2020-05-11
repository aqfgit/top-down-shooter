#pragma once
#include "State.h"
class GameState :
	public State
{
public:
	GameState(sf::RenderWindow* window);
	~GameState();

	void endState();
	void updateKeybinds(const float& deltaTime);
	void update(const float& deltaTime);
	void render(sf::RenderTarget* target = nullptr);
};

