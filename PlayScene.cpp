#include "PlayScene.h"
#include <SFML/Graphics/Sprite.hpp>
#include <iostream>
#include <sstream>
#include "FinalScene.h"


using namespace std;

	
PlayScene::PlayScene(){
	string ruta;
	for(int i=0;i<=7;i++) { 
		sf::Texture aux;
		ruta= "assets/img/explosion" + to_string(i)+ ".png";
		if(!aux.loadFromFile(ruta)){
			cerr<<"ERROR: no se encontro la textura "<<"assets/img/explosion"<<i<<".png"<<endl;
		}
		explosionTex.push_back(aux);
	}
	if(!recargaTex.loadFromFile("assets/img/bullets.png")){
		cerr<<"ERROR: no se encontro la textura "<<"assets/img/bullets.png"<<endl;
	}
	if(!enemyTex1.loadFromFile("assets/img/enemigo1.png")){
		cerr<<"ERROR: no se encontro la textura "<<"assets/img/enemigo1.png"<<endl;
	}
	if(!enemyTex2.loadFromFile("assets/img/enemigo2.png")){
		cerr<<"ERROR: no se encontro la textura "<<"assets/img/enemigo2.png"<<endl;
	}
	if(!enemyTex3.loadFromFile("assets/img/enemigo3.png")){
		cerr<<"ERROR: no se encontro la textura "<<"assets/img/enemigo3.png"<<endl;
	}
	if(!bonusTex1.loadFromFile("assets/img/bonus1.png")){
		cerr<<"ERROR: no se encontro la textura "<<"assets/img/enemigo1.png"<<endl;
	}
	if(!bonusTex2.loadFromFile("assets/img/bonus2.png")){
		cerr<<"ERROR: no se encontro la textura "<<"assets/img/enemigo1.png"<<endl;
	}
	if(!music.openFromFile("assets/son/music.ogg")){
		cerr<<"Error al cargar la musica de juego"<<endl;
	}
	music.play();
	music.setVolume(1.8);
	player.setPosition(sf::Vector2f((720-(player.getTexture()->getSize().x)*0.142)/2, 480-(player.getTexture()->getSize().y)/6.2));
	player.setScale(0.142,0.16);
	timeToNewEnemy.restart();
	timeToExplosion.restart();
	timeToNewrecarga.restart();
	timeToNewBonus.restart();
	if(!fontScoreText.loadFromFile("assets/font/Cave-Story.ttf")){
		cerr<<"ERROR: no se encontro la fuente "<<"assets/font/Cave-Story.ttf"<<endl;
	}
	if(!fondo.loadFromFile("assets/img/fondo.jpg")){
		cerr<<"ERROR: no se encontro la textura "<<"assets/img/fondo"<<endl;
	}
	sfondo.setTexture(fondo);
	sfondo.setScale(0.2812,0.3);
	score = 0;
	scoreText.setFont(fontScoreText);
	scoreText.setPosition(5,0);
	scoreText.setColor(sf::Color::Yellow);
	scoreText.setCharacterSize(20);
	
	municionText.setFont(fontScoreText);
	municionText.setColor(sf::Color::Yellow);
	municionText.setCharacterSize(20);
	;
}
//	Scoretxt.setPosition(sf::Vector2f((720-Scoretxt.getLocalBounds().width)/2.0, 100));
void PlayScene::processSingleEvent(const sf::Event &e){
	/// Teclas apretadas
	if(moriste==false){
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
		player.setRotation(5);
		player.setVelocity(sf::Vector2f(450, 0));
	}else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
		
		player.setRotation(-5);
		player.setVelocity(sf::Vector2f(-450, 0));
	}else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
		if (contador>0.5){
			player.disparo();
			contador=0;
		}
	}else{
		player.setRotation(0);
		player.setVelocity(sf::Vector2f(0, 0));
	}
	}
}

void PlayScene::update(float elapsed){	
	
	
	
	/// corrige al personaje
	player.move(player.getVelocity().x*elapsed, 0);
	if(player.getPosition().x < 0){
		player.setPosition(0, player.getPosition().y);
	}else if(player.getPosition().x > 720-(player.getTexture()->getSize().x)*0.142){
		player.setPosition(720-((player.getTexture()->getSize().x)*0.142), player.getPosition().y);
	}
	/**Actualiza misiles*/
	for(int i=0;i<player.tamVectorMisiles();i++) { 
		Misil aux;
		aux=player.devuelveMisil(i);
		if(aux.getPosition().y<0){
			player.eliminarMisil(i);
		}else{
			player.actuMisil(i,8);
		}
	}
	/** Actualiza Enemigos */
	for(int i=0;i<enemigos.size();i++) { 
		if(enemigos[i].devPos().y>480){
		eliminarEnemy(i);
		}else{
		enemigos[i].actuEnemigo(dificulty);
		}	
	}	
	/** Actualiza Bonus */
	for(int i=0;i<vBonus.size();i++) { 
		if(vBonus[i].devPos().y>480){
			eliminarBonus(i);
		}else{
			vBonus[i].actuBonus();
		}	
	}
	/** Nuevo Bonus */
	if(timeToNewBonus.getElapsedTime().asSeconds()>5){
		int numeroBonus;
		Bonus a;
		numeroBonus = rand()%2+1;
		if(numeroBonus==1){
			a.setTex(numeroBonus,bonusTex1);
		}else if(numeroBonus==2){
			a.setTex(numeroBonus,bonusTex2);
		}
		vBonus.push_back(a);
		timeToNewBonus.restart();
	}
	/**Nuevo enemigo*/
	
	if(timeToNewEnemy.getElapsedTime().asSeconds()>1-dificulty/(rand()%100+50)){
		int numeroEnemigo;
		Enemigo a;
		numeroEnemigo = rand()%4;
		if(numeroEnemigo==1){
			a.setTex(numeroEnemigo,enemyTex1);
		}else if(numeroEnemigo==2){
			a.setTex(numeroEnemigo,enemyTex2);
		}else{
			a.setTex(numeroEnemigo,enemyTex3);
		}
		
		enemigos.push_back(a);
		if(dificulty>50){
			dificulty=50;
		}
		dificulty=dificulty+rand()%2;
		timeToNewEnemy.restart();
	}
	///Nueva recarga
	if(timeToNewrecarga.getElapsedTime().asSeconds()>7){
		cargador.sacalo();
	}
	if(timeToNewrecarga.getElapsedTime().asSeconds()>15){
		if(!cargador.tieneTex()){
			cargador.texturealo(recargaTex);
		}else{
			cargador.posicionalo(recargaTex);
		}
		timeToNewrecarga.restart();
	}
	
	///Revisa colisiones 
	if(moriste==true){
		for(int i=0;i<explosiones.size();i++) {
			if(explosiones[i].yalodibuje(6)){
				eliminarExplosion(i);
				Game::getInstance().switchScene(new FinalScene(Global::highScore));
			}
		}
	}
	for(int i=0;i<enemigos.size();i++){
		if(enemigos[i].getSprite().getGlobalBounds().intersects(player.getGlobalBounds())){
			Global::highScore = score;
			music.stop();
			Explosion auxiliar;
			auxiliar.set(explosionTex,player.getPosition());
			explosiones.push_back(auxiliar);
			player.setColor(sf::Color::Transparent);
			player.setPosition(900,600);
			eliminarEnemy(i);
			moriste=true;
		}
		
	}
	if(player.getGlobalBounds().intersects(cargador.getSprite().getGlobalBounds())){
		player.actualizaMuni(15);
		cargador.sacalo();
	}
	for(int i=0;i<vBonus.size();i++){
		if(player.getGlobalBounds().intersects(vBonus[i].getSprite().getGlobalBounds())){
			score+=10;
			eliminarBonus(i);
		}
	}
	for(int i=0;i<enemigos.size();i++){
		for(int j=0;j<player.tamVectorMisiles();j++){
			Misil aux;
			aux=player.devuelveMisil(j);
			if(enemigos[i].getSprite().getGlobalBounds().intersects(aux.getSprite().getGlobalBounds())){
				sf::Vector2f auxi;
				Explosion auxiliar;
				auxi=player.devuelveMisil(j).getPosition();
				eliminarEnemy(i);
				player.eliminarMisil(j);
				score=score+5;
				auxiliar.set(explosionTex,auxi);
				explosiones.push_back(auxiliar);
			}
		}
	}
	
	/// actualiza el puntaje y municion
	score += elapsed;
	contador += elapsed;
	stringstream tmp;
	tmp<<"Puntuacion: "<<int(score);
	scoreText.setString(tmp.str());
	stringstream cant;
	cant<<"Municion: "<<(player.cantMunicion());
	municionText.setString(cant.str());
	municionText.setPosition(sf::Vector2f((720-municionText.getLocalBounds().width)-5,0));
}


void PlayScene::draw(sf::RenderWindow &w){
	
	w.clear(sf::Color::White);
	w.draw(sfondo);
	for(int i=0;i<player.tamVectorMisiles();i++) { 
		if(player.tamVectorMisiles()>0){
			Misil aux;
			aux=player.devuelveMisil(i);
			w.draw(aux.getSprite());
		}
	}
	for(int i=0;i<enemigos.size();i++){ 
		Enemigo aux;
		aux=enemigos[i];
		w.draw(aux.getSprite());
	}
	for(int i=0;i<vBonus.size();i++){ 
		Bonus aux;
		aux=vBonus[i];
		w.draw(aux.getSprite());
	}
	w.draw(player);
	w.draw(scoreText);
	w.draw(municionText);
	w.draw(cargador.getSprite());
	int j=0;
	for(int i=0;i<explosiones.size();i++) {
		
		if(explosiones[i].existe()){
			for(int j=0;j<8;j++) {
				if(!explosiones[i].yalodibuje(j)){
					if(timeToExplosion.getElapsedTime().asSeconds()>0.015){
						w.draw(explosiones[i].pum(j));
						timeToExplosion.restart();
						if(j==7){
							eliminarExplosion(i);
						}
					}
				}
			}
		}
	}
	
}
void PlayScene::eliminarEnemy(int pos){
	if(enemigos.size()>1){
		for(int i=pos;i<enemigos.size()-1;i++){ 
			enemigos[i]=enemigos[i+1];
		}
		
	enemigos.resize(enemigos.size()-1);
	}else{
		enemigos.pop_back();
	}
	
	
}
void PlayScene::eliminarExplosion(int pos){
	if(explosiones.size()>1){
		for(int i=pos;i<explosiones.size()-1;i++){ 
			enemigos[i]=enemigos[i+1];
		}
		
		explosiones.resize(enemigos.size()-1);
	}else{
		explosiones.pop_back();
	}
	
	
}
void PlayScene::eliminarBonus(int pos){
	if(vBonus.size()>1){
		for(int i=pos;i<vBonus.size()-1;i++){ 
			vBonus[i]=vBonus[i+1];
		}
		vBonus.resize(vBonus.size()-1);
	}else{
		vBonus.pop_back();
	}
}








