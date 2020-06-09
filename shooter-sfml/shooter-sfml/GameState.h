#pragma once
#include "State.h"

class GameState :
	public State
{
private:
	Player player;
	Enemy enemy;

	bool isBulletOffScreen(Bullet* bullet);
	void updateBullets(std::vector<Bullet*>& bullets);
	template<class Object1, class Object2> void checkForCollision(Object1 o1, Object2 o2);

public:
	GameState(sf::RenderWindow* window);
	~GameState();

	void endState();
	void updateKeybinds(const float& deltaTime);
	void update(const float& deltaTime);
	void render(sf::RenderTarget* target = nullptr);
};

template<class Object1, class Object2>
inline void GameState::checkForCollision(Object1 o1, Object2 o2)
{
	if (o1.getGlobalBounds().intersects(o2.getGlobalBounds())) {
		std::cout << "kolizja" << std::endl;
	}
}
