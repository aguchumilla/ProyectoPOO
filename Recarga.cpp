#include "Recarga.h"
#include <iostream>
using namespace std;

Recarga::Recarga() {
	
}

void Recarga::texturealo(sf::Texture &tex) {
	
	srecarga.setTexture(tex);
	position=(sf::Vector2f((rand()%720-tex.getSize().x*0.05),476-tex.getSize().y*0.05));
	srecarga.setScale(0.04,0.04);
	srecarga.setPosition(position);
	texturaCargada=true;
}
sf::Sprite Recarga::getSprite(){
	return srecarga;
}
void Recarga::posicionalo(sf::Texture &tex){
	position=(sf::Vector2f((rand()%720-tex.getSize().x*0.05),476-tex.getSize().y*0.05));
	if(position.x<0){
		position.x=0;
	}
	srecarga.setPosition(position);
}

void Recarga::sacalo(){
	srecarga.setPosition(800,500);
}
bool Recarga::tieneTex(){
	return texturaCargada;
}
