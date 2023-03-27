#pragma once
#include "ERCCAR.h"
#include <vector>
#include <windows.h>
#include "ERCRACER.h"

class ERCCARFACTORY
{
private:
	float spawntimer;
	std::vector<ERCCAR*> carFactory;
	bool crash;
public:
	ERCCARFACTORY();
	~ERCCARFACTORY();
	ERCCAR* createCar();
	void draw(sf::RenderWindow& window);
	void update(ERCRACER* racer, float gameSpeed);
	bool checkCrash();
};