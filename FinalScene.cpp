#include "FinalScene.h"
#include <sstream>
#include "Game.h"
#include "PlayScene.h"

#include <cstring>
#include <fstream>
#include "Records.h"
using namespace std;

FinalScene::FinalScene(float score) {
	imptxt.setEditable(false);
	scorevect.resize(5);
	High = scorePicker();
	Actual.score=score;
	if(!tfondo.loadFromFile("assets/img/fondo.jpg")){
		cerr<<"ERROR: no se encontro la textura "<<"assets/img/fondo"<<endl;
	}
	sfondo.setColor(sf::Color::Red);
	sfondo.setTexture(tfondo);
	sfondo.setScale(0.2812,0.3);
	
	fuente.loadFromFile("assets/font/Cave-Story.ttf");
	imptxt.setFont(fuente);
	imptxt.setPosition(500,270);
	imptxt.setColor(sf::Color::Yellow);
	imptxt.setMaxChars(7);
	
	imptxt.setCharacterSize(30);
	
	GameOver.setFont(fuente);
	GameOver.setString("GAME OVER!");
	GameOver.setColor(sf::Color::Red);
	GameOver.setCharacterSize(60);
	GameOver.setPosition(sf::Vector2f((720-GameOver.getLocalBounds().width)/2.0, 0));
	
	Scoretxt.setFont(fuente);
	stringstream aux;
	aux<<"Puntuacion: "<<score;
	Scoretxt.setString(aux.str());
	Scoretxt.setCharacterSize(30);
	Scoretxt.setColor(sf::Color::Yellow);
	Scoretxt.setPosition(sf::Vector2f((720-Scoretxt.getLocalBounds().width)/2.0, 100));
	
	Presstxt.setFont(fuente);
	Presstxt.setCharacterSize(17);
	Presstxt.setString("Espacio para volver a jugar");
	Presstxt.setPosition(5,455);
	
	
	
	
	if(Actual.score<=scorevect[4].score){
		//cout<<Actual.score<<" -- "<<scorevect[4].score;
		Hscoretxt.setFont(fuente);
		stringstream auxi;
		
		auxi<<"Mejor puntuacion: "<<High.name<<"-"<<High.score;
		Hscoretxt.setString(auxi.str());
		Hscoretxt.setCharacterSize(30);
		Hscoretxt.setPosition(sf::Vector2f((720-Hscoretxt.getLocalBounds().width)/2.0, 300));
	}else if(Actual.score>scorevect[4].score){
		Hscoretxt.setFont(fuente);
		stringstream asd;
		asd<<"NUEVO RECORD!";
		imptxt.setEditable(true);
		Hscoretxt.setString(asd.str());
		Hscoretxt.setCharacterSize(40);
		Hscoretxt.setPosition(sf::Vector2f((720-Hscoretxt.getLocalBounds().width)/2.0, 190));
		
		
		IngreseNombre.setFont(fuente);
		IngreseNombre.setString("Ingrese su nombre: \n(Enter para confirmar)");
		IngreseNombre.setCharacterSize(30);
		IngreseNombre.setColor(sf::Color::Yellow);
		IngreseNombre.setPosition(sf::Vector2f((720-IngreseNombre.getLocalBounds().width)/2.0, 270));
		
	}
	
	Recordstxt.setFont(fuente);
	Recordstxt.setString("Presiona R para ver records");
	Recordstxt.setCharacterSize(20);
	Recordstxt.setPosition(sf::Vector2f((720-Recordstxt.getLocalBounds().width)/2,380));
	
	
	
};

void FinalScene :: update(float elapsed){
	GameOver.setColor(sf::Color::Red);
	imptxt.update();
};

void FinalScene :: draw(sf::RenderWindow &w){
	w.draw(sfondo);
	w.draw(Scoretxt);
	w.draw(GameOver);
	w.draw(Hscoretxt);
	w.draw(Presstxt);
	for(int i=0;i<scorevect.size();i++) { 
		if(Actual.score>scorevect[i].score){
			w.draw(IngreseNombre);
		}
	}
	
	w.draw(imptxt);
	w.draw(Recordstxt);
	
};


void FinalScene::processSingleEvent(const sf::Event &e){
	imptxt.processEvent(e);
	
	if(e.type == sf::Event::KeyPressed){
		if(e.key.code == sf::Keyboard::Space){
			Game::getInstance().switchScene(new PlayScene());
		}
		if(e.key.code == sf::Keyboard::Return){
			if(imptxt.isEditable()){
				strcpy(Actual.name,imptxt.getValue().c_str());
				scoreWriter(Actual);
				imptxt.setEditable(false);
			}
		}
		if(e.key.code == sf::Keyboard::R && imptxt.isEditable()==false){
			Game::getInstance().switchScene(new Records());
		}
	}
	
};

void FinalScene::scoreWriter(hstruct k){
	ofstream esc("assets/other/scores.dat",ios::binary|ios::trunc);
	OrderVect(scorevect,k);
	for(int i=0;i<scorevect.size();i++) { 
		esc.write(reinterpret_cast<char*>(&scorevect[i]),sizeof(k));
	}
	esc.close();
	
}

hstruct FinalScene :: scorePicker(){
	ifstream lec("assets/other/scores.dat",ios::binary|ios::ate);
	
	hstruct h;
	int cant=lec.tellg()/sizeof(h);
	lec.seekg(0);
	
	if(cant>0){
		for(int i=0;i<scorevect.size();i++) { 
			lec.read(reinterpret_cast<char*>(&h), sizeof(h));
			scorevect[i]=h;
		}
		OrderVect(scorevect);
		return scorevect[0];
	}
	string aux="non";
	strcpy(h.name,aux.c_str());
	h.score=0;
	return h;
};

bool  esMayor(hstruct &a, hstruct &b){
	return a.score>b.score;
};

void FinalScene :: OrderVect(vector<hstruct> &v,hstruct h){
	v.push_back(h);
	sort(v.begin(),v.end(),esMayor);
	v.pop_back();
}

void FinalScene :: OrderVect(vector<hstruct> &v){
	
	sort(v.begin(),v.end(),esMayor);

	
}




