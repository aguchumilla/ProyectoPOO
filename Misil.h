#ifndef MISIL_H
#define MISIL_H
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>

using namespace std;

class Misil{
private:
	sf::Sprite smisil;
	sf::Vector2f posicion;
public:
	Misil();
	Misil(sf::Vector2f &pos, sf::Texture &tex);
	void actualizar(int elapsed);
	void setPosition(const sf::Vector2f &vel) {posicion = vel;};
	const sf::Vector2f getPosition() const {return posicion;};
	sf::Sprite getSprite();
};

#endif

