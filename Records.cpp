#include "Records.h"
#include "Game.h"
#include <sstream>
#include <fstream>
#include <iostream>
#include <cstring>
using namespace std;
bool  es_mayor(hstruct &a, hstruct &b){
	return a.score>b.score;

}
Records::Records() {
	if(!fondo.loadFromFile("assets/img/fondo.jpg")){
		cerr<<"ERROR: no se encontro la textura "<<"assets/img/fondo"<<endl;
	}
	sfondo.setTexture(fondo);
	sfondo.setScale(0.2812,0.3);
	
	fuente.loadFromFile("assets/font/Cave-Story.ttf");
	
	Title.setFont(fuente);
	Title.setString("Maximas puntuaciones");
	Title.setCharacterSize(50);
	scores.resize(5);
	Title.setPosition(sf::Vector2f((720-Title.getLocalBounds().width)/2,100));
	Title.setColor(sf::Color::Yellow);
	
	ScorePicker();
	
	stringstream p;
	p<<scores[0].name<<" - "<<scores[0].score;
	First.setFont(fuente);
	First.setString(p.str());
	First.setCharacterSize(25);
	First.setPosition(sf::Vector2f((720-First.getLocalBounds().width)/2.0-10, 200));
	
	First.setColor(sf::Color::Red);
	
	stringstream s;
	s<<scores[1].name<<" - "<<scores[1].score;
	Second.setFont(fuente);
	Second.setString(s.str());
	Second.setCharacterSize(25);
	Second.setPosition(sf::Vector2f((720-Second.getLocalBounds().width)/2-10,250));
	
	
	stringstream t;
	t<<scores[2].name<<" - "<<scores[2].score;
	Third.setFont(fuente);
	Third.setString(t.str());
	Third.setCharacterSize(25);
	Third.setPosition(sf::Vector2f((720-Third.getLocalBounds().width)/2-10,300));
	
	
	stringstream f;
	f<<scores[3].name<<" - "<<scores[3].score;
	Fourth.setFont(fuente);
	Fourth.setString(f.str());	
	Fourth.setCharacterSize(25);
	Fourth.setPosition(sf::Vector2f((720-Fourth.getLocalBounds().width)/2-10,350));

	
	stringstream fi;
	fi<<scores[4].name<<" - "<<scores[4].score;
	Fifth.setFont(fuente);
	Fifth.setString(fi.str());
	Fifth.setCharacterSize(25);
	Fifth.setPosition(sf::Vector2f((720-Fifth.getLocalBounds().width)/2-10,400));

	
	Volver.setFont(fuente);
	Volver.setString("Presiona ENTER para volver");
	Volver.setCharacterSize(15);
	Volver.setPosition(sf::Vector2f(5,460));
	
}

void Records :: draw(sf::RenderWindow &w){
	w.draw(sfondo);
	w.draw(Title);
	w.draw(Volver);
	w.draw(First);
	w.draw(Second);
	w.draw(Third);
	w.draw(Fourth);
	w.draw(Fifth);
	
}
void Records::processSingleEvent(const sf::Event &e){
	
	
	if(e.type == sf::Event::KeyPressed){
		if(e.key.code == sf::Keyboard::Return){
			Game::getInstance().switchScene(new MenuScene());
		}
	}
}
void Records::ScorePicker(){
	ifstream lec("assets/other/scores.dat",ios::binary|ios::ate);
	hstruct h;
	int cant= lec.tellg()/sizeof(h);
	lec.seekg(0);	
	
	
	if(cant>0){
		for(int i=0;i<scores.size();i++) {
			lec.read(reinterpret_cast<char*>(&h), sizeof(h));
			
			scores[i] = h;
			
			
		}
	}
	else{
		string aux = "---";
		for(int i=0;i<scores.size();i++) { 
			strcpy(h.name,aux.c_str());
			h.score= 0;
		}
	}
	OrderVect(scores);
}
void Records::OrderVect(vector<hstruct> &v){
	sort(v.begin(),v.end(),es_mayor);
}
