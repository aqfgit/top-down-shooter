#include "GameOverState.h"

GameOverState::GameOverState(sf::RenderWindow* window, std::stack<State*>* states, int score) : State(window, states)
{
	if (!font.loadFromFile("./fonts/ARDESTINE.ttf")) {
		std::cout << "Blad ladowania czcionki" << std::endl;
	}

	gameOverText.setFont(font);
	gameOverText.setString("GAME OVER");
	gameOverText.setCharacterSize(44);
	gameOverText.setFillColor(sf::Color::Red);
	gameOverText.setStyle(sf::Text::Bold | sf::Text::Underlined);

	std::stringstream ss;
	ss << "SCORE: " << score;
	std::string scoreString = ss.str();

	scoreText.setFont(font);
	scoreText.setString(scoreString);
	scoreText.setCharacterSize(44);
	scoreText.setFillColor(sf::Color::Yellow);

	scoreText.setPosition(0, 150);

	playAgainText.setFont(font);
	playAgainText.setString("Press P to play again");
	playAgainText.setCharacterSize(34);
	playAgainText.setFillColor(sf::Color::Green);
	playAgainText.setStyle(sf::Text::Bold);

	playAgainText.setPosition(0, 350);
	
}

void GameOverState::endState()
{
}

void GameOverState::updateKeybinds(const float& deltaTime)
{
	this->checkForQuit();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
		this->quit = true;
		this->states->push(new GameState(this->window, this->states));
	}
}

void GameOverState::update(const float& deltaTime)
{
	this->updateKeybinds(deltaTime);
	std::cout << "KONICE HRY" << std::endl;
}

void GameOverState::render(sf::RenderTarget* target)
{
	this->window->draw(gameOverText);
	this->window->draw(playAgainText);
	this->window->draw(scoreText);
}
