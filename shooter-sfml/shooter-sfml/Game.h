#pragma once

#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <cstdlib>

class Game {
private:
	sf::RenderWindow* window;
	sf::Event sfEvent;

	void initWindow();

public:
	Game();
	virtual ~Game();

	void update();
	void updateSFMLEvents();
	void render();
	void run()
		;
};