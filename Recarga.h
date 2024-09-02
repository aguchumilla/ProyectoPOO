#ifndef RECARGA_H
#define RECARGA_H
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Texture.hpp>

using namespace std;

class Recarga{
	sf::Sprite srecarga;
	sf::Vector2f position;
	bool texturaCargada=false;
	
public:
	Recarga();
	void texturealo(sf::Texture &tex);
	sf::Sprite getSprite();
	void posicionalo(sf::Texture &tex);
	void sacalo();
	bool tieneTex();
	
private:
};

#endif

