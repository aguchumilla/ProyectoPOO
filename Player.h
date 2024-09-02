#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <vector>
#include "Misil.h"
#include <SFML/System/Vector2.hpp>
using namespace std;

class Player : public sf::Sprite {
	sf::Texture playerTex;
	sf::Texture texmisil;
	sf::Vector2f velocity;
	vector<Misil> misiles;					///vector de misiles que dispara player.
	int municion=15;
public:
	Player();
	void disparo();
	void setVelocity(const sf::Vector2f &vel) {velocity = vel;};
	sf::Sprite getSpriteMisil(int pos);
	void eliminarMisil(int pos);
	void actuMisil(int pos,int elapsed);
	unsigned int tamVectorMisiles();
	sf::Vector2f posMisil(int i);
	const sf::Vector2f getVelocity() const {return velocity;};
	Misil devuelveMisil(int i);
	int cantMunicion(){return municion;};
	void actualizaMuni(int i);
};

#endif

