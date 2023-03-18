#include<iostream>
#include"SFML\Graphics.hpp"
#include"SFML\Window.hpp"
#include"SFML\System.hpp"
#include<vector>
#include"ERCASSETS.h"
#include"ERCDefinitionsANDConsts.h"
class ERCLAND
{
private:
	sf::Texture* Texture;
	sf::Sprite Sprite;
	sf::Sprite SpriteNext;
	std::vector<sf::Sprite>landfactory;
public:
	ERCLAND();
	~ERCLAND();
	void moveLand(float dt);
	void drawLand(sf::RenderWindow& window);
};