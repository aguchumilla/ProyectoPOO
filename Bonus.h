#ifndef BONUS_H
#define BONUS_H
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <cstdlib>

class Bonus{
	int numTex;
	sf::Sprite sBonus;
	sf::Vector2f position;
	int numRot;
	
	
public:
	Bonus();
	void setTex(int i,sf::Texture &t);
	sf::Vector2f devPos();
	sf::Sprite getSprite();
	void actuBonus();
private:
};

#endif

