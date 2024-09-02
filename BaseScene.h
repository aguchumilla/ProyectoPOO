#ifndef BASESCENE_H
#define BASESCENE_H
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>


/***
* Representa una escena del juego.
* Para crear una nueva clase de escena, heredar de �sta clase
* y redefinir el comportamiento de los m�todos
*/ 
class BaseScene {
public:
	/// constructor
	BaseScene();
	
	/// funci�n que ser� invocada para procesar eventos en general
	void processEvents(sf::Window &w);
	
	/// funci�n que ser� invocada para procesar un evento
	virtual void processSingleEvent(const sf::Event &e);
	
	/// funci�n que ser� invocada para actualizar la escena
	virtual void update(float elapsed);
	
	/// funci�n que ser� invocada para dibujar la escena
	virtual void draw(sf::RenderWindow &w);
};

#endif

