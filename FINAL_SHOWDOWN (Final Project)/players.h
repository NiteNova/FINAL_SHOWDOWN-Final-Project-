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

	player(float x, float y);
	void draw(sf::RenderWindow& window);
	void move(bool* keys);
	float returnX() { return xpos; }
	float returnY() { return ypos; }
	void shoot(bool* keys, sf::RenderWindow& window);
	void collide(float x, float y, bool* keys);
	void died(int hp);
	void printInfo() { cout << "My position is " << xpos << ", " << ypos << endl; }
};