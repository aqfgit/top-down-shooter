#include "Player.h"

Player::Player() {
	this->x = 200.f;
	this->y = 150.f;
	this->movementSpeed = 100.f;
	this->shape.setSize(sf::Vector2f(50.f, 50.f));
	this->shape.setFillColor(sf::Color::Yellow);
	this->shape.setPosition(sf::Vector2f(this->x, this->y));
}

void Player::move(float dirX, float dirY, float deltaTime) {
	float xAxisMovement = dirX * this->movementSpeed * deltaTime;
	float yAxisMovement = dirY * this->movementSpeed * deltaTime;
	this->shape.move(xAxisMovement, yAxisMovement);
	this->x += xAxisMovement;
	this->y += yAxisMovement;
}

void Player::update(const float& deltaTime) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		this->move(-1.f, 0.f, deltaTime);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		this->move(1.f, 0.f, deltaTime);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		this->move(0.f, 1.f, deltaTime);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		this->move(0.f, -1.f, deltaTime);
	}
	std::cout << "X: " << this->x << "Y: " << this->y << std::endl;
}

void Player::render(sf::RenderTarget* target) {
	target->draw(this->shape);
}