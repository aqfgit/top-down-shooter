#pragma once

#include "GameState.h"
#include "GameOverState.h"

class Game {
private:
	sf::RenderWindow* window;
	sf::Event sfEvent;

	sf::Clock deltaTimeClock;
	float deltaTime;

	std::stack<State*> states;

	void initWindow();
	void initStates();

public:
	Game();
	virtual ~Game();

	void endApplication();
	void updateDeltaTime();
	void update();
	void updateSFMLEvents();
	void render();
	void run();
};