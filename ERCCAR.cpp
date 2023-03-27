#include "ERCCAR.h"

ERCCAR::ERCCAR()
{
	//467
	CarType type = CarType(rand() % LAST);
	switch (type)
	{
	case CAR1:
		Texture = &ERCASSETS::getInstance().TextureList["CAR1"];
		break;
	case CAR2:
		Texture = &ERCASSETS::getInstance().TextureList["CAR2"];
		break;
	case CAR3:
		Texture = &ERCASSETS::getInstance().TextureList["CAR3"];
		break;
	case CAR4:
		Texture = &ERCASSETS::getInstance().TextureList["CAR4"];
		break;
	}
	LanePos lane = LanePos(rand() % LAST);
	switch (lane)
	{
	case LANE1:
		x = 467;
		break;
	case LANE2:
		x = 750;
		break;
	case LANE3:
		x = 1050;
		break;
	case LANE4:
		x = 1350;
		break;
	}
	y = -50.f;
	Sprite.setTexture(*Texture);
	Sprite.setScale(2.5, 2.5);
}
ERCCAR::~ERCCAR()
{

}
void ERCCAR::updateCar(float speed)
{
	y += speed;
}
void ERCCAR::drawCar(sf::RenderWindow& window)
{
	Sprite.setPosition(x, y);
	window.draw(Sprite);
}
bool ERCCAR::checkoutWindow()
{
	return (Sprite.getPosition().y > SCREEN_HEIGHT);
}
bool ERCCAR::checkCollision(ERCRACER* racer)
{
	if (Sprite.getGlobalBounds().intersects(racer->getSprite().getGlobalBounds())) return true;
	return false;
}