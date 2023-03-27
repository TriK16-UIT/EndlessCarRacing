#pragma once
#include"SFML\Window.hpp"
#include"SFML\System.hpp"
#include"ERCASSETS.h"
#include"ERCDefinitionsANDConsts.h"
#include <random>
#include <string>
#include"ERCRACER.h"

enum CarType {CAR1, CAR2, CAR3, CAR4, LAST};
enum LanePos {LANE1, LANE2, LANE3, LANE4, LASTPOS};

class ERCCAR
{
protected:
	float x;
	float y;
	sf::Texture* Texture;
	sf::Sprite Sprite;
public:
	ERCCAR();
	~ERCCAR();
	void updateCar(float y);
	void drawCar(sf::RenderWindow& window);
	bool checkoutWindow();
	bool checkCollision(ERCRACER* racer);
};