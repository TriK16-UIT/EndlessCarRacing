#pragma once
#include<iostream>
#include"SFML\Graphics.hpp"
#include"SFML\Window.hpp"
#include"SFML\System.hpp"
#include"ERCLAND.h"
#include"ERCDefinitionsANDConsts.h"
#include"ERCRACER.h"
#include"ERCCARFACTORY.h"
#include<conio.h>
#include<Windows.h>
#include<string>
const float dt = 1.0f / 60.0f;

class ERCGAME
{
private:
	sf::VideoMode VideoMode;
	sf::RenderWindow* Window;
	sf::Event Event;
	ERCLAND* land;
	ERCRACER* racer;
	ERCCARFACTORY* carFactory;
	int Score;
	sf::Font* Font;
	float gameSpeed;
public:
	ERCGAME();
	~ERCGAME();
	void render();
	void update();
	void initWindow();
	void run();
	void pollEvent();
	void drawScore();
	void updateScore();
	void gameover();
};