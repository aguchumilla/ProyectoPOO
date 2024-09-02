#ifndef BASESCENE_H
#define BASESCENE_H
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>


/***
* Representa una escena del juego.
* Para crear una nueva clase de escena, heredar de ésta clase
* y redefinir el comportamiento de los métodos
*/ 
class BaseScene {
public:
	/// constructor
	BaseScene();
	
	/// función que será invocada para procesar eventos en general
	void processEvents(sf::Window &w);
	
	/// función que será invocada para procesar un evento
	virtual void processSingleEvent(const sf::Event &e);
	
	/// función que será invocada para actualizar la escena
	virtual void update(float elapsed);
	
	/// función que será invocada para dibujar la escena
	virtual void draw(sf::RenderWindow &w);
};

#endif

