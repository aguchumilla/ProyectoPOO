#ifndef EXPLOSION_H
#define EXPLOSION_H
#include <SFML/System/Vector2.hpp>
#include <vector>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

using namespace std;

class Explosion{
	sf::Vector2f position;
	vector<sf::Sprite> sprites;
	bool exist=false;
	vector<bool> dibujado;
public:
	Explosion();											///Constructor por defecto.
	void set(vector<sf::Texture> &texs,sf::Vector2f pos);	///Constructor con texturas y pos.
	sf::Sprite pum(int i);									///Devuelve sprite i.
	bool existe();
	bool yalodibuje(int i);
private:
};

#endif








