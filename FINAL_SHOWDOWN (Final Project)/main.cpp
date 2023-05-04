#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <time.h>
#include "globals.h"
#include "players.h"
#include "bullet.h"
using namespace std;

int main() {
	srand(time(NULL));
	int timer = 0;
	sf::RenderWindow screen(sf::VideoMode(1800, 900), "FINAL_SHOWDOWN!");
	bool p1keys[] = { false, false, false, false, false };
	bool p2keys[] = { false, false, false, false, false };
	player p1(1630, 400);
	player p2(100, 400);
	bullet b1(p1.xpos - 10, p1.ypos + 40);


	while (screen.isOpen()) { //gameloop
		//keyboard input
		sf::Event event;
		while (screen.pollEvent(event)) { 
			if (event.type == sf::Event::Closed)
				screen.close();
		//player 1 (Arrow keys)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				p1keys[UP] = true;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
				p1keys[DOWN] = true;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				p1keys[LEFT] = true;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
				p1keys[RIGHT] = true;
			}
			else {
				p1keys[UP] = false;
				p1keys[DOWN] = false;
				p1keys[LEFT] = false;
				p1keys[RIGHT] = false;
			}
		//player 2 (WASD)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
				p2keys[W] = true;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
				p2keys[S] = true;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
				p2keys[A] = true;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				p2keys[D] = true;
			}
			else {
				p2keys[W] = false;
				p2keys[S] = false;
				p2keys[A] = false;
				p2keys[D] = false;
			}

		//shooting inputs
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)) {
				//p1keys[SHIFT] = true;
				b1.isAlive = true;
			}
			

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
				p2keys[SPACE] = true;
			}
			

		}

		//physics section
		
			//player movement
		p1.move(p1keys);
		p2.move(p2keys);
			//bullet movement
		b1.move(-0.3, p1.xpos - 10, p1.ypos + 30);

			//bullet collision
		p2.hp += (b1.collide(p2.xpos, p2.ypos));

			//player collision with the walls
		p1.collide(p1.xpos, p1.ypos);
		p2.collide(p2.xpos, p2.ypos);

		//render section
		screen.clear();
		b1.draw(screen);
			
			//player drawings 
		p1.draw(screen);
		p2.draw(screen);
		//end of render section 

		screen.display();
	}
	cout << "GAME OVER" << endl;
	return 0;
}