#ifndef PLAYSCENE_H
#define PLAYSCENE_H
#include <string>
#include <vector>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include "BaseScene.h"
#include "Player.h"
#include "Global.h"
#include "MenuScene.h"
#include "Game.h"
#include "Misil.h"
#include "Enemigo.h"
#include "Explosion.h"
#include <SFML/System/Clock.hpp>
#include "Recarga.h"
#include <SFML/Audio/Music.hpp>
#include "Bonus.h"
#include "FinalScene.h"

using namespace std;

class PlayScene: public BaseScene{
private:
	float contador=5;
	float dificulty=0;
	Player player;						/// el jugador
	vector<Enemigo> enemigos;			/// arreglo con los enemigos
	vector<Bonus> vBonus;				/// arreglo con los bonus
	sf::Clock timeToNewEnemy;			/// reloj para medir cuándo crear un nuevo enemigo
	sf::Clock timeToExplosion;
	sf::Clock timeToNewrecarga;
	sf::Clock timeToNewBonus;
	float score;						/// puntaje
	sf::Text scoreText;					/// texto para mostrar el puntaje
	sf::Font fontScoreText;				/// fuente del texto
	sf::Text municionText;
	vector<sf::Texture> explosionTex;
	sf::Music music;
	sf::Texture fondo;
	sf::Sprite sfondo;
	sf::Texture misil;
	sf::Texture enemyTex1;
	sf::Texture enemyTex2;
	sf::Texture enemyTex3;
	sf::Texture bonusTex1;
	sf::Texture bonusTex2;
	bool moriste=false;
	int numEnemigo;
	vector<Explosion> explosiones;
	sf::Texture recargaTex;
	Recarga cargador;

	
public:
	PlayScene();
	void processEvents(sf::Window &w);
	void processSingleEvent(const sf::Event &e);
	void update(float elapsed);
	void draw(sf::RenderWindow &w);
	void eliminarEnemy(int pos);
	void eliminarExplosion(int pos);
	void eliminarBonus(int pos);
	
};

#endif

