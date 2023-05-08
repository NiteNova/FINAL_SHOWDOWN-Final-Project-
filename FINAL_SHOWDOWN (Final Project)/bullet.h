#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "globals.h"
using namespace std;

class bullet {
public:
	float xpos;
	float ypos;
	bool isAlive = false;
	bullet(float x, float y);
	void draw(sf::RenderWindow& window);
	void move(float x, float px, float py);
	int collide(float x, float y);
	bool CheckisAlive();
	void shoot();
	void printInfo() { cout << "My xpos is" << xpos << " . My ypos is" << ypos << endl; }
};
