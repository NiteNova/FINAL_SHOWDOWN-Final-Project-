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

void player::draw(sf::RenderWindow& window, int healthx, int healthy) {
	if (hp > 0) {
		sf::RectangleShape P(sf::Vector2f(70, 70));
		P.setFillColor(sf::Color(0, 0, 255));
		P.setPosition(xpos, ypos);
		window.draw(P);
	}

	//health bar outline
	sf::RectangleShape rectangle2(sf::Vector2f(100, 20));
	rectangle2.setFillColor(sf::Color::Black);
	rectangle2.setOutlineThickness(3);
	rectangle2.setOutlineColor(sf::Color::Red);
	rectangle2.setPosition(healthx, healthy);
	window.draw(rectangle2);

	//health bar
	if (hp > 0) {
		sf::RectangleShape rectangle(sf::Vector2f(hp, 20));
		rectangle.setFillColor(sf::Color::Yellow);
		rectangle.setPosition(healthx, healthy);
		window.draw(rectangle);
	}
}

void player::move(bool* keys) {
	if ((keys[0] == true))
		yVel = -0.3;
	else if ((keys[1] == true))
		yVel = 0.3;
	else if ((keys[2] == true))
		xVel = -0.3;
	else if ((keys[3] == true))
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
