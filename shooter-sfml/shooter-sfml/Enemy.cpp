#include "Enemy.h"

Enemy::Enemy() {
	this->x = 50.f;
	this->y = 0.f;
	this->shootingCooldown = 2.f;
	this->movementSpeed = 10.f;
	this->shape.setSize(sf::Vector2f(30.f, 30.f));
	this->shape.setFillColor(sf::Color::Magenta);
	this->shape.setPosition(sf::Vector2f(this->x, this->y));
}


void Enemy::update(const float& deltaTime) {

	this->shape.move(this->movementSpeed * sf::Vector2f(0, 1) * deltaTime);
	
	time2 = clock.getElapsedTime();
	float dt = time2.asSeconds() - time1.asSeconds();
	if (dt < this->shootingCooldown) return;
	this->bullets.push_back(new Bullet(this->shape.getPosition().x + 15, this->shape.getPosition().y - 5, 0.f, 1.f, 5));
	time1 = clock.getElapsedTime();
}

void Enemy::render(sf::RenderTarget* target) {
	target->draw(this->shape);
}
