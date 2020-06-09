#include "GameState.h"


void GameState::updateBullets(std::vector<Bullet*>& bullets)
{
	int counter = 0;

	for (auto* bullet : bullets) {
		bullet->update();
		if (this->isOffScreen(bullet)) {
			std::cout << bullets.size() << std::endl;

			delete bullets.at(counter);
			bullets.erase(bullets.begin() + counter);
			counter--;
		}
		counter++;
	}
}

void GameState::updateEnemies(std::vector<Enemy*>& enemies)
{
	int counter = 0;

	for (auto* enemy : enemies) {
		if (this->isOffScreen(enemy)) {
			delete enemies.at(counter);
			enemies.erase(enemies.begin() + counter);
			counter--;
		}
		else if (enemy->getShape().getGlobalBounds().intersects(this->player->getShape().getGlobalBounds())) {
			this->player->takeDamage(15);
		}
		counter++;
	}
}

void GameState::deleteDeadEnemies()
{
	int counter = 0;

	for (auto* enemy : this->enemies) {
		if (enemy->isDead()) {
			this->score += 100;
			delete this->enemies.at(counter);
			this->enemies.erase(this->enemies.begin() + counter);
			counter--;
		}
		counter++;

	}
}

GameState::GameState(sf::RenderWindow* window, std::stack<State*>* states) : State(window, states)
{	
	this->enemySpawnCooldown = 4;
	this->enemiesLimit = 8;
	player = new Player();
	for (int i = 0; i < 3; i++) {
		this->enemies.push_back(new Enemy(i * 30 + i * 300));
	}

	if (!font.loadFromFile("./fonts/ARDESTINE.ttf")) {
		std::cout << "Blad ladowania czcionki" << std::endl;
	}

	hpText.setFont(font);
	hpText.setString(this->getHitPointsString());
	hpText.setCharacterSize(24);
	hpText.setFillColor(sf::Color::Red);
	hpText.setStyle(sf::Text::Bold | sf::Text::Underlined);

	hpText.setPosition(700, 20);

	dice = std::uniform_int_distribution<>(0, 800);
	rng.seed(::time(NULL));
	
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
		this->states->push(new GameOverState(this->window, this->states, this->score));
	}

	if (this->enemies.size() == 0) {
		this->states->push(new GameOverState(this->window, this->states, this->score));
	}
	this->deleteDeadEnemies();
	if (this->enemies.size() < this->enemiesLimit)
	this->spawnEnemy();
	for (auto* enemy : this->enemies) {
		enemy->render(this->window);
		this->updateBullets(enemy->getBullets());
		this->player->checkForBulletsCollision(enemy);
		enemy->checkForBulletsCollision(this->player);
		enemy->update(deltaTime);
	}
	
	this->updateKeybinds(deltaTime);
	this->updateBullets(this->player->getBullets());
	this->updateEnemies(this->enemies);


	this->player->update(deltaTime);

}


void GameState::spawnEnemy() {
	enemySpawnTimer2 = clock.getElapsedTime();
	float dt = enemySpawnTimer2.asSeconds() - enemySpawnTimer1.asSeconds();

	if (dt < this->enemySpawnCooldown) return;
	this->enemies.push_back(new Enemy(this->dice(rng)));
	std::cout << this->enemies.size() << std::endl;
	enemySpawnTimer1 = clock.getElapsedTime();
}

std::string GameState::getHitPointsString()
{
	
	std::stringstream ss;
	ss << "HP: " << this->player->getHitPoints();
	std::string hpString = ss.str();
	return hpString;
	
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
	
	hpText.setString(this->getHitPointsString());
	this->window->draw(hpText);
}


