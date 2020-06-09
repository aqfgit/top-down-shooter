#include "Enemy.h"

Enemy::Enemy(float x) {
	this->x = x;
	this->y = 0.f;
	this->attackDamage = 1;
	this->hitPoints = 4;
	this->shootingCooldown = 2.f;
	this->movementSpeed = 60.f;
	this->shape.setSize(sf::Vector2f(30.f, 30.f));
	this->shape.setFillColor(sf::Color::Magenta);
	this->shape.setPosition(sf::Vector2f(this->x, this->y));
}

sf::FloatRect Enemy::getBounds()
{
	return this->shape.getGlobalBounds();
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
