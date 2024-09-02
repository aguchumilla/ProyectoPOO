#include "Player.h"
#include <iostream>

using namespace std;
Player::Player() {
	/**Cargo la textura del jugador.*/
	if(!playerTex.loadFromFile("assets/img/player.png")){
		cerr<<"ERROR: no se encontro la textura: "<<"assets/img/player.png"<<endl;
	}
	setTexture(playerTex);
	/**Cargo la textura del misil para todos los misiles del jugador.*/
	if(!texmisil.loadFromFile("assets/img/misil.png")){
		cerr<<"ERROR: no se encontro la textura "<<"assets/img/misil.png"<<endl;
	}
}
 

void Player::disparo(){
	if(municion>0){
	float auxx=velocity.x+(playerTex.getSize().x)*0.142;
	float auxy=velocity.y+(playerTex.getSize().y)*0.16;
	sf::Vector2f aux = getPosition();
	aux.x=aux.x+((playerTex.getSize().x)*0.142)/5;	
	//aux.y=aux.y+(playerTex.getSize().y)*0.16;
	Misil misil(aux, texmisil);
	misiles.push_back(misil);
	municion--;
	}
	
	
}
void Player::eliminarMisil(int pos){
	if(misiles.size()>1){
		for(int i=pos;i<misiles.size()-1;i++){  
			misiles[i]=misiles[i+1];
		}
		misiles.resize(misiles.size()-1);
	}else{
		misiles.pop_back();
	}
}

void Player::actuMisil(int pos,int elapsed){
	misiles[pos].actualizar(elapsed);
}

sf::Sprite Player::getSpriteMisil(int pos){
	misiles[pos].getSprite();
}

Misil Player::devuelveMisil(int i){
	return misiles[i];
}

void Player::actualizaMuni(int i){
	municion=municion+i;
}

sf::Vector2f Player::posMisil(int i){
	return misiles[i].getSprite().getPosition();
}

unsigned int Player::tamVectorMisiles(){
	return misiles.size();
}
