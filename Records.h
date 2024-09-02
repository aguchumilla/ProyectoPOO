#ifndef RECORDS_H
#define RECORDS_H
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "BaseScene.h"
#include <vector>
#include "FinalScene.h"
using namespace std;


class Records : public BaseScene {
	sf::Texture fondo;
	sf::Sprite sfondo;
	sf::Font fuente;
	sf::Text Title;
	sf::Text First;
	sf::Text Second;
	sf::Text Third;
	sf::Text Fourth;
	sf::Text Fifth;
	sf::Text Volver;
	vector<hstruct> scores;
public:
	Records();
	void draw(sf::RenderWindow &w);
	void processSingleEvent(const sf::Event &e);
	void ScorePicker();
	void OrderVect(vector<hstruct> &v);
};

#endif

