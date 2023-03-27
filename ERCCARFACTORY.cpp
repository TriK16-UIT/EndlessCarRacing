
#include "ERCCARFACTORY.h"

ERCCARFACTORY::ERCCARFACTORY()
{
	crash = false;
	spawntimer = 0.0f;
}

ERCCARFACTORY::~ERCCARFACTORY()
{

}

ERCCAR* ERCCARFACTORY::createCar()
{
	return new ERCCAR;
}
bool ERCCARFACTORY::checkCrash()
{
	return crash;
}
void ERCCARFACTORY::update(ERCRACER* racer, float gameSpeed)
{
	if (carFactory.size() < MAX_CAR)
		if (spawntimer >= ENEMY_SPAWN_TIMER_MAX)
		{
			carFactory.push_back(createCar());
			spawntimer = 0.f;
		}
		else
			spawntimer += 0.5f;
	for (int i = 0; i < carFactory.size(); i++)
	{
		carFactory[i]->updateCar(gameSpeed);
		if (carFactory[i]->checkCollision(racer))
		{
			std::cout << "COLLISION!";
			crash = true;
		}
		if (carFactory[i]->checkoutWindow())
			carFactory.erase(carFactory.begin() + i);
	}
}

void ERCCARFACTORY::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < carFactory.size(); i++)
		carFactory[i]->drawCar(window);
}