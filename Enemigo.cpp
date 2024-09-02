#include "Enemigo.h"

using namespace std;
Enemigo::Enemigo(){
	
}
void Enemigo::setTex(int i,sf::Texture &t) {
	numTex = i;
	senemy.setTexture(t);
	position=(sf::Vector2f((rand()%720)-t.getSize().x, rand()%5));
	senemy.setPosition(position);
	if(numTex==1){
		senemy.setScale(0.2,0.2);
	}else if(numTex==2){
		senemy.setScale(0.3,0.3);
	}else{
		senemy.setScale(0.4,0.4);
	}
	numRot=0;
}
sf::Sprite Enemigo::getSprite(){
	return senemy;
}
sf::Vector2f Enemigo::devPos(){
	return position;
}

void Enemigo::actuEnemigo(float dificulty){
	position.y=position.y+2.3+dificulty/14;
	senemy.setPosition(position);
	numRot=numRot+rand()%2;
	senemy.setRotation(numRot);
	

}
