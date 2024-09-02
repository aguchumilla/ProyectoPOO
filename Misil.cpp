#include "Misil.h"
#include <iostream>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Texture.hpp>
using namespace std;

/**Constructor por defecto. No es utilizado.*/
	Misil::Misil() {

	};
/**A este constructor le paso la posición inicial con la que llamo a ubicar.*/
	Misil::Misil(sf::Vector2f &pos, sf::Texture &tex){
		posicion=pos;
		smisil.setTexture(tex);
		smisil.setScale(0.06,0.06);
		smisil.setPosition(posicion);
	};
	
	void Misil::actualizar(int elapsed){
		posicion.y= posicion.y-elapsed-10;
		smisil.setPosition(posicion);
	};
	
	sf::Sprite Misil::getSprite(){
		return smisil;
	}



