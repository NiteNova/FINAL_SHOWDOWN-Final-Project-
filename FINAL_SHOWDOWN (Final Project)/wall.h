#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

class wall {
public:
	int xpos;
	int ypos;
	int hp;
	bool isAlive;
	wall(int x, int y, int h);
	void draw(sf::RenderWindow& window, int x, int y);
	void collide(int x, int y);
	bool CheckisAlive();
	void printInfo() { cout << "My xpos is" << xpos << " . My ypos is" << ypos << endl; }
};

