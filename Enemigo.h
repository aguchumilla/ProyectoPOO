#ifndef ENEMIGO_H
#define ENEMIGO_H
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Enemigo{
private:
	sf::Sprite senemy;
	sf::Vector2f position;
	int numTex; 
	int numRot;
	
public:
	Enemigo();
	void setTex(int i,sf::Texture &t);
	void actuEnemigo();
	sf::Vector2f devPos();
	void actuEnemigo(float dificulty);
	sf::Sprite getSprite();
};

#endif

