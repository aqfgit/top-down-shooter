#pragma once
#include "State.h"
#include "GameState.h"

class GameOverState :public State
{
private:
	sf::Font font;
	sf::Text gameOverText;
	sf::Text playAgainText;
	sf::Text scoreText;

public:
	GameOverState(sf::RenderWindow* window, std::stack<State*>* states, int score);

	void endState();
	void updateKeybinds(const float& deltaTime);
	void update(const float& deltaTime);
	void render(sf::RenderTarget* target = nullptr);
};

