#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <time.h>
#include "globals.h"
#include "players.h"
using namespace std;

int main() {
	srand(time(NULL));
	int timer = 0;
	sf::RenderWindow screen(sf::VideoMode(1000, 1000), "FINAL_SHOWDOWN!");
	bool p1keys[] = { false, false, false, false };
	bool p2keys[] = { false, false, false, false };
	player p1(100, 400);
	player p2(900, 400);

	while (screen.isOpen()) { //gameloop
		//keyboard input
		sf::Event event;
		while (screen.pollEvent(event)) { 
			if (event.type == sf::Event::Closed)
				screen.close();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				p1keys[UP] = true;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
				p1keys[DOWN] = true;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				p1keys[LEFT] = true;
				p1keys[DOWN] = false;
				p1keys[UP] = false;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
				p1keys[RIGHT] = true;
				p1keys[DOWN] = false;
				p1keys[UP] = false;
			}
			else {
				p1keys[UP] = false;
				p1keys[DOWN] = false;
				p1keys[LEFT] = false;
				p1keys[RIGHT] = false;
			}
		
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
				p2keys[W] = true;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
				p2keys[S] = true;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
				p2keys[A] = true;
				p2keys[S] = false;
				p2keys[W] = false;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				p2keys[D] = true;
				p2keys[S] = false;
				p2keys[W] = false;
			}
			else {
				p2keys[W] = false;
				p2keys[S] = false;
				p2keys[A] = false;
				p2keys[D] = false;
			}

		}

		//physics section
		p1.move(p1keys);
		p2.move(p2keys);

		//render section
		screen.clear();

		p1.draw(screen);
		p2.draw(screen);

		screen.display();
	}
	cout << "GAME OVER" << endl;
	return 0;
}