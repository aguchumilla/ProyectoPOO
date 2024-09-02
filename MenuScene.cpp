#include "MenuScene.h"
#include <iostream>
#include "Game.h"
#include "PlayScene.h"
#include <sstream>
#include "Global.h"
#include "Records.h"
using namespace std;

MenuScene::MenuScene(){
	if(!titleFont.loadFromFile("assets/font/Cave-Story.ttf")){
		cerr<<"ERROR: no se encontro la fuente "<<"assets/font/Cave-Story.ttf"<<endl;
	}
	if(!fondo.loadFromFile("assets/img/fondo.jpg")){
		cerr<<"ERROR: no se encontro la imagen "<<"assets/img/fondo.jpg"<<endl;
	}
	if(!music.openFromFile("assets/son/musicmenu.ogg")){
		cerr<<"Error al cargar la musica de menu"<<endl;
	}
	sfondo.setTexture(fondo);
	sfondo.setScale(0.2812,0.3);
	
	titleText.setFont(titleFont);
	titleText.setColor(sf::Color::White);
	titleText.setString("FAST 99");
	titleText.setCharacterSize(150);
	// centra el texto
	titleText.setPosition(sf::Vector2f((720-titleText.getLocalBounds().width)/2.0, 0));
	


	
	pressStartText.setFont(titleFont);
	pressStartText.setColor(sf::Color::White);
	pressStartText.setString("Presione ENTER para comenzar\nR para ver Records");
	pressStartText.setColor(sf::Color::Yellow);
	pressStartText.setCharacterSize(30);
	pressStartText.setPosition(sf::Vector2f((720-pressStartText.getLocalBounds().width)/2.0, 300));
	
	music.play();
	music.setVolume(3);
}

void MenuScene::update(float elapsed){
	
}

void MenuScene::processSingleEvent(const sf::Event &e){
	if(e.type == sf::Event::KeyPressed){
		if(e.key.code == sf::Keyboard::Return){
			music.stop();
			Game::getInstance().switchScene(new PlayScene());
		}
		if(e.key.code == sf::Keyboard::R){
			music.stop();
			Game::getInstance().switchScene(new Records());
		}
	}
}

void MenuScene::draw(sf::RenderWindow &w){
	w.draw(sfondo);
	w.draw(titleText);
	w.draw(pressStartText);
}
