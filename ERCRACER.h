#pragma once
#include<iostream>
#include"SFML\Graphics.hpp"
#include"SFML\Window.hpp"
#include"SFML\System.hpp"
#include"ERCASSETS.h"
#include"ERCDefinitionsANDConsts.h"
#include<Windows.h>

class ERCRACER
{
private:
	sf::Texture* Texture;
	sf::Sprite Sprite;
	float x;
	float y;
public:
	ERCRACER();
	~ERCRACER();
	void updateInput();
	void updateWindowBoundsCollision();
	void moveRacer();
	void drawRacer(sf::RenderWindow& window);
	sf::Sprite getSprite();
};
