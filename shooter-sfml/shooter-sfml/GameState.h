#pragma once
#include <random>
#include <sstream>
#include <string>

#include "State.h"
#include "GameOverState.h"


class GameState :
	public State
{
private:
	Player *player;
	std::vector<Enemy*> enemies;

	sf::Clock clock;
	sf::Time enemySpawnTimer1, enemySpawnTimer2;

	sf::Font font;
	sf::Text hpText;

	float enemySpawnCooldown;
	int enemiesLimit;

	int score;

	std::random_device rd;
	typedef std::mt19937 MyRng;
	MyRng rng;
	std::uniform_int_distribution<int> dice;

	template<class Object> bool isOffScreen(Object* object);
	void updateBullets(std::vector<Bullet*>& bullets);
	void updateEnemies(std::vector<Enemy*>& enemies);

	void deleteDeadEnemies();
	void spawnEnemy();

	std::string getHitPointsString();
public:
	GameState(sf::RenderWindow* window, std::stack<State*>* states);
	~GameState();

	void endState();
	void updateKeybinds(const float& deltaTime);
	void update(const float& deltaTime);
	void render(sf::RenderTarget* target = nullptr);
};



template<class Object>
inline bool GameState::isOffScreen(Object* object)
{
	bool isAboveTopBoundary = object->getBounds().top + object->getBounds().height < 0.f;
	bool isBelowBottomBoundary = object->getBounds().top > 600;
	return isAboveTopBoundary || isBelowBottomBoundary;
}
