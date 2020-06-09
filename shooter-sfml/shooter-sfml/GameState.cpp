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

GameState::GameState(sf::RenderWindow* window, std::stack<State*>* states) : State(window, states)
{
	player = new Player();
	for (int i = 0; i < 3; i++) {
		this->enemies.push_back(new Enemy(i*30 + i*100));
	}
}

GameState::~GameState()
{
}

void GameState::endState()
{
}

void GameState::updateKeybinds(const float& deltaTime)
{
	this->checkForQuit();
	
}

void GameState::update(const float& deltaTime)
{
	if (this->player->isDead()) {
		this->quit = true;
		this->states->push(new GameOverState(this->window, this->states));
	}

	if (this->enemies.size() == 0) {
		this->states->push(new GameOverState(this->window, this->states));
	}
	this->deleteDeadEnemies();
	for (auto* enemy : this->enemies) {
		enemy->render(this->window);
		this->updateBullets(enemy->getBullets());
		this->player->checkForBulletsCollision(enemy);
		enemy->checkForBulletsCollision(this->player);
		enemy->update(deltaTime);
	}
	
	this->updateKeybinds(deltaTime);
	this->updateBullets(this->player->getBullets());


	this->player->update(deltaTime);

}


void GameState::render(sf::RenderTarget* target)
{
	this->player->render(this->window);
	this->deleteDeadEnemies();
	for (auto* enemy : this->enemies) {
		enemy->render(this->window);
		for (auto* bullet : enemy->getBullets()) {
			bullet->render(this->window);
		}
	}
	for (auto *bullet : this->player->getBullets()) {
		bullet->render(this->window);
	}
	
}


