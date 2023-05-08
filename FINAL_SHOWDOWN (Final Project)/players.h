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
	void draw(sf::RenderWindow& window, int healthx, int healthy);
	void move(bool* keys);
	float returnX() { return xpos; }
	float returnY() { return ypos; }
	void collide(float x, float y);
	void died();
	void printInfo() { cout << "My position is " << xpos << ", " << ypos << endl; }
};