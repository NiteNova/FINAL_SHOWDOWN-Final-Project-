#include "wall.h"

wall::wall(int x, int y, int h) {
	xpos = x;
	ypos = y;
	hp = h;
	isAlive = true;
}

void wall::draw(sf::RenderWindow& window, int x, int y) {
	if (isAlive == true) {
		sf::RectangleShape wall(sf::Vector2f(x, y));
		wall.setFillColor(sf::Color(255, 0, 0));
		wall.setPosition(xpos, ypos);
		window.draw(wall);
	}
}

bool wall::collide(int x, int y) {
	if (isAlive == true) {
		if (xpos <= x and xpos+20 >= x and ypos+200 >= y and ypos <= y and hp > 0) {
			cout << "Bullet hit a wall" << endl;
			hp -= 3;
			return false;
		}
	}
	else {
		return true;
	}
}

bool wall::CheckisAlive() {
	return isAlive;
}