#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

class player {
private:
	int lives;
	float xVel;
	float yVel;
public:
	float xpos;
	float ypos;
	int hp;

	player(int x, int y);
	void draw(sf::RenderWindow& window);
	void move(bool* keys);
	float returnX() { return xpos; }
	float returnY() { return ypos; }
	void died(int hp);
	void printInfo() { cout << "My position is " << xpos << ", " << ypos << endl; }
};