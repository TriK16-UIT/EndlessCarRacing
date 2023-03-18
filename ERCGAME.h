#pragma once
#include<iostream>
#include"SFML\Graphics.hpp"
#include"SFML\Window.hpp"
#include"SFML\System.hpp"
#include"ERCLAND.h"
#include"ERCDefinitionsANDConsts.h"
const float dt = 1.0f / 60.0f;

class ERCGAME
{
private:
	sf::VideoMode VideoMode;
	sf::RenderWindow* Window;
	sf::Event Event;
	ERCLAND* land;
public:
	ERCGAME();
	~ERCGAME();
	void render();
	void update();
	void initWindow();
	void run();
	void pollEvent();
};