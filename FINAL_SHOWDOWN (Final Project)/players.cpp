#include "players.h"
#include "globals.h"
#include <SFML/Graphics.hpp>


player::player(float x, float y) {
	xpos = x;
	ypos = y;
	lives = 3;
	hp = 100;
	xVel = 0;
	yVel = 0;
}

void player::draw(sf::RenderWindow& window) {
	sf::RectangleShape P(sf::Vector2f(70, 70));
	P.setFillColor(sf::Color(0, 0, 255));
	P.setPosition(xpos, ypos);
	window.draw(P);
}

void player::move(bool* keys) {
	if ((keys[UP] == true or keys[W] == true) and ypos > 0 and xpos < 1820 and xpos > 0)
		yVel = -0.1;
	else if ((keys[DOWN] == true or keys[S] == true) and ypos < 1020 and xpos < 1820 and xpos > 0)
		yVel = 0.1;
	else if ((keys[LEFT] == true or keys[A] == true) and xpos > 0)
		xVel = -0.1;
	else if ((keys[RIGHT] == true or keys[D] == true) and xpos < 1820)
		xVel = 0.1;
	else {
		yVel = 0;
		xVel = 0;
	}
	

	xpos += xVel;
	ypos += yVel;
}


void player::shoot(bool* keys, sf::RenderWindow& window) {
	if (keys[SPACE] == true or keys[SHIFT] == true) {
		sf::RectangleShape bullet(sf::Vector2f(10, 10));
		bullet.setFillColor(sf::Color(255, 0, 0));
		bullet.setPosition(xpos, ypos);
		window.draw(bullet);
	}
}