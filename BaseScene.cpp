#include "BaseScene.h"

BaseScene::BaseScene() {
	
}

/// el comportamiento por defecto deber�a ser vaciar la cola de eventos de la ventana
/// �sto deber�a hacerse siempre
void BaseScene::processEvents(sf::Window &w) {
	sf::Event e;
	while(w.pollEvent(e)) {
		if(e.type == e.Closed) w.close();
		else{
			processSingleEvent(e);
		}
	}
}

void BaseScene::update(float elapsed) {
	
}

void BaseScene::draw(sf::RenderWindow &w){
	
}

void BaseScene::processSingleEvent(const sf::Event &e){
	
}
