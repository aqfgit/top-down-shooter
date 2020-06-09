#include "GameState.h"

bool GameState::isBulletOffScreen(Bullet* bullet)
{
	bool isAboveTopBoundry = bullet->getBounds().top + bullet->getBounds().height < 0.f;
	bool isAboveBottomBoundry = bullet->getBounds().top > 600;
	return bullet->getBounds().top + bullet->getBounds().height < 0.f;
}

void GameState::updateBullets(std::vector<Bullet*>& bullets)
{
	int counter = 0;

	for (auto* bullet : bullets) {
		bullet->update();
		if (this->isBulletOffScreen(bullet)) {
			std::cout << bullets.size() << std::endl;

			delete bullets.at(counter);
			bullets.erase(bullets.begin() + counter);
			counter--;
		}
		counter++;
	}
}

GameState::GameState(sf::RenderWindow* window) : State(window)
{
}

GameState::~GameState()
{
}

void GameState::endState()
{
	std::cout << "Ending GameState..." << std::endl;
}

void GameState::updateKeybinds(const float& deltaTime)
{
	this->checkForQuit();
}

void GameState::update(const float& deltaTime)
{
	this->updateKeybinds(deltaTime);
	this->updateBullets(this->player.getBullets());
	 
	
	this->player.update(deltaTime);

}


void GameState::render(sf::RenderTarget* target)
{
	this->player.render(this->window);
	for (auto *bullet : this->player.getBullets()) {
		bullet->render(this->window);
	}
}


