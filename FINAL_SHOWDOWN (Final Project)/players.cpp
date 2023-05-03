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
	if ((keys[UP] == true or keys[W] == true))
		yVel = -0.3;
	else if ((keys[DOWN] == true or keys[S] == true))
		yVel = 0.3;
	else if ((keys[LEFT] == true or keys[A] == true))
		xVel = -0.3;
	else if ((keys[RIGHT] == true or keys[D] == true))
		xVel = 0.3;
	else {
		yVel = 0;
		xVel = 0;
	}
	

	xpos += xVel;
	ypos += yVel;
}

void player::collide(float x, float y) {
	if (x > 1730)
		xpos = 1730;
	if (x < 0)
		xpos = 0;
	if (y > 830)
		ypos = 830;
	if (y < 0)
		ypos = 0;
}


