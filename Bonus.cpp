#include "Bonus.h"

using namespace std;

Bonus::Bonus() {
	
}
void Bonus::setTex(int i,sf::Texture &t) {
	numTex = i;
	sBonus.setTexture(t);
	position=(sf::Vector2f((rand()%720)-t.getSize().x, rand()%5));
	sBonus.setPosition(position);
	sBonus.setScale(2,2);
	/*if(numTex==2){
		sBonus.setColor(sf::Color::Red);
	}*/
	numRot=0;
}
sf::Sprite Bonus::getSprite(){
	return sBonus;
}
sf::Vector2f Bonus::devPos(){
	return position;
}
void Bonus::actuBonus(){
	position.y=position.y+3;
	sBonus.setPosition(position);
	sBonus.setRotation(numRot);
	numRot=numRot+rand()%3;
}
