#ifndef FINALSCENE_H
#define FINALSCENE_H
#include <SFML/System/Clock.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <vector>
#include <sstream>
#include <iostream>
#include "InputBox.h"
#include "BaseScene.h"
#include "MenuScene.h"

using namespace std;

struct hstruct{
	char name[8];
	int score;
}; 

class FinalScene : public BaseScene {
	sf::Texture tfondo;
	sf::Sprite sfondo;
	sf::Font fuente;
	sf::Text GameOver;
	sf::Text Scoretxt;
	sf::Text Hscoretxt;
	sf::Text Presstxt;
	sf::Text IngreseNombre; 
	
	sf::Text Recordstxt; 
	hstruct Actual;
	hstruct High;
	
	
public:	
	FinalScene();
	FinalScene(float score);
	void update(float elapsed) override;
	void draw(sf::RenderWindow &w);
	void processSingleEvent(const sf::Event &e);
	void scoreWriter(hstruct h);
	hstruct scorePicker();
	void OrderVect(vector<hstruct> &v, hstruct h);
	void OrderVect(vector<hstruct> &v);
	
	vector<hstruct> scorevect;
	InputText imptxt;
};

#endif

