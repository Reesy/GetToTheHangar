#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Game.h"

void update(float dt);
void render();
void handleInput();

int main()
{
	Game myGame;
	myGame.init();
	myGame.loop();
}

