#include "ERCRACER.h"

ERCRACER::ERCRACER()
{
	Texture = &ERCASSETS::getInstance().TextureList["RACER"];
	Sprite.setTexture(*Texture);
	Sprite.setScale(2.5, 2.5);
	x = SCREEN_WIDTH / 2 - Sprite.getGlobalBounds().width / 2 + 3;
	y = SCREEN_HEIGHT - Sprite.getGlobalBounds().height - 200;
	Sprite.setPosition(0, 0);
}
ERCRACER::~ERCRACER()
{

}
void ERCRACER::updateInput()
{	
	Sprite.setRotation(0);
	bool up = 0, down = 0, left = 0, right = 0;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) up = 1;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) left = 1;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) down = 1;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) right = 1;

	if (right)
	{
		x += 10.f;
		Sprite.setRotation(15);
		
	}
	if (left)
	{
		x -= 10.f;
		Sprite.setRotation(-15);
	}
	if (up) y -= 10.f;
	if (down) y += 10.f;
}

void ERCRACER::updateWindowBoundsCollision()
{
	if (x < 310.f) x = 310.f;
	if (y < 0.f) y = 0.f;
	if (x + Sprite.getGlobalBounds().width > SCREEN_WIDTH - 250.f) x = SCREEN_WIDTH - Sprite.getGlobalBounds().width - 250.f;
	if (y + Sprite.getGlobalBounds().height > SCREEN_HEIGHT) y = SCREEN_HEIGHT - Sprite.getGlobalBounds().height;
}
void ERCRACER::moveRacer()
{
	updateInput();
	updateWindowBoundsCollision();
}
void ERCRACER::drawRacer(sf::RenderWindow& window)
{
	Sprite.setPosition(x, y);
	window.draw(Sprite);
}
sf::Sprite ERCRACER::getSprite()
{
	return Sprite;
}