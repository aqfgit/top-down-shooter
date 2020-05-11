#include "Game.h"

void Game::initWindow() {
	this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "Shooter");
	this->window->setFramerateLimit(120);
}

void Game::initStates()
{
	this->states.push(new GameState(this->window));
}

Game::Game() {
	this->initWindow();
	this->initStates();
}

Game::~Game() {
	delete this->window;

	while (!this->states.empty()) {
		delete this->states.top();
		this->states.pop();
	}
}

void Game::update() {
	this->updateSFMLEvents();

	if (!this->states.empty()) {
		this->states.top()->update(this->deltaTime);

		if (this->states.top()->getQuit()) {
			this->states.top()->endState();
			delete this->states.top();
			this->states.pop();
		}
	}
	else {
		this->endApplication();
		this->window->close();
	}
}

void Game::endApplication()
{
	std::cout << "ending the app" << std::endl;
}

void Game::updateDeltaTime() {
	this->deltaTime = this->deltaTimeClock.getElapsedTime().asSeconds();
}

void Game::updateSFMLEvents() {
	while (this->window->pollEvent(this->sfEvent))
	{
		if (this->sfEvent.type == sf::Event::Closed) {
			this->window->close();
		}
	}

}

void Game::render() {
	this->window->clear();

	if (!this->states.empty()) {
		this->states.top()->render(this->window);
	}

	this->window->display();
}

void Game::run() {

	while (this->window->isOpen())
	{
		this->updateDeltaTime();
		this->update();
		this->render();
	}
}