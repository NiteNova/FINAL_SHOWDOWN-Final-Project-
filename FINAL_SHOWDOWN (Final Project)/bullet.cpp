#include <SFML/Graphics.hpp>
#include <iostream>
#include "bullet.h"
#include "globals.h"

bullet::bullet(float x, float y) {
	xpos = x;
	ypos = y;
	isAlive = false;
}
void bullet::draw(sf::RenderWindow& window) {
	if (isAlive == true) {
		sf::RectangleShape bul(sf::Vector2f(10, 10));
		bul.setFillColor(sf::Color(255, 0, 0));
		bul.setPosition(xpos, ypos);
		window.draw(bul);
	}
}

void bullet::shoot() {
	isAlive = true;
}

void bullet::move(float x, float px, float py) {
	if (isAlive == true) {
		xpos += x;
	}
	if (isAlive == false) {
		xpos = px;
		ypos = py;
	}
}

int bullet::collide(float x, float y) {
	if (isAlive == true) {
		if (xpos < 0 or xpos > 1890 or ypos < 0 or ypos > 890) {
			isAlive = false;
			cout << "Bullet died" << endl;
		}
		if (xpos <= x + 70 and xpos >= x and ypos >= y and ypos <= y + 70) {
			isAlive = false;
			cout << "Bullet hit player" << endl;
			return -20;
		}
	}
	return 0;
}

bool bullet::CheckisAlive() {
	return isAlive;
}