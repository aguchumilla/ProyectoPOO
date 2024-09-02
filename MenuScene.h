#ifndef MENUSCENE_H
#define MENUSCENE_H
#include "BaseScene.h"
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Audio/Music.hpp>

class MenuScene : public BaseScene {
	sf::Text titleText;
	sf::Text pressStartText;
	sf::Font titleFont;
	sf::Texture fondo;
	sf::Sprite sfondo;
	sf::Music music;
public:
	MenuScene();
	
	void processEvents(sf::Window &w);
	void processSingleEvent(const sf::Event &e);
	void update(float elapsed);
	void draw(sf::RenderWindow &w);
};

#endif

