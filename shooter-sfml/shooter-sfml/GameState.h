#pragma once
#include "State.h"

class GameState :
	public State
{
private:
	Player *player;
	std::vector<Enemy*> enemies;

	bool isBulletOffScreen(Bullet* bullet);
	void updateBullets(std::vector<Bullet*>& bullets);
	
	void deleteDeadEnemies();
	void endGame();

public:
	GameState(sf::RenderWindow* window);
	~GameState();

	void endState();
	void updateKeybinds(const float& deltaTime);
	void update(const float& deltaTime);
	void render(sf::RenderTarget* target = nullptr);
};


inline void GameState::deleteDeadEnemies()
{
	int counter = 0;

	for (auto* enemy : this->enemies) {
		if (enemy->isDead()) {

			delete this->enemies.at(counter);
			this->enemies.erase(this->enemies.begin() + counter);
			counter--;
		}
		counter++;

	}
}
