#include "players.h"
#include "globals.h"
#include <SFML/Graphics.hpp>


player::player(int x, int y) {
	xpos = x;
	ypos = y;
	lives = 3;
	hp = 100;
	xVel = 0;
	yVel = 0;
}

void player::draw(sf::RenderWindow& window) {
	sf::RectangleShape P(sf::Vector2f(20, 20));
	P.setFillColor(sf::Color(0, 0, 255));
	P.setPosition(xpos, ypos);
	window.draw(P);
}

void player::move(bool* keys) {
	if (keys[UP] == true or keys[W] == true)
		yVel = -0.1;
	else if (keys[DOWN] == true or keys[S] == true)
		yVel = 0.1;
	else if (keys[LEFT] == true or keys[A] == true)
		xVel = -0.1;
	else if (keys[RIGHT] == true or keys[D] == true)
		xVel = 0.1;
	else {
		yVel = 0;
		xVel = 0;
	}

	xpos += xVel;
	ypos += yVel;
}