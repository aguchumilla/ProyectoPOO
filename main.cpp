#include "Game.h"
#include "PlayScene.h"
#include "MenuScene.h"
#include <cstdlib>
using namespace std;
using namespace sf;

int main(int argc, char *argv[]) {
	srand(time(nullptr));
	Game &game = Game::create(sf::VideoMode(720,480), new MenuScene(), "FAST 99");
	game.run();
	return 0;
}

