#include "Explosion.h"
using namespace std;


Explosion::Explosion() {
	
}

void Explosion::set(vector<sf::Texture> &texs,sf::Vector2f p){
	position=p;
	exist=true;
	for(int i=0;i<8;i++) { 
		sf::Sprite aux;
		aux.setTexture(texs[i]);
		aux.setPosition(position);
		sprites.push_back(aux);
		dibujado.push_back(false);
	}
}

sf::Sprite Explosion::pum(int i){
	dibujado[i]=true;
	return sprites[i];
	
}
bool Explosion::existe(){
	return exist;
}
bool Explosion::yalodibuje(int i){
	return dibujado[i];
}
