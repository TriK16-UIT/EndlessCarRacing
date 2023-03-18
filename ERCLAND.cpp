#include"ERCLAND.h"

ERCLAND::ERCLAND()
{
	Texture = &ERCASSETS::GetInstance().TextureList["MAP"];
	Sprite.setTexture(*Texture);
	Sprite.setScale(2.3, 2);
	Sprite.setPosition(0, 0);
	SpriteNext.setTexture(*Texture);
	SpriteNext.setScale(2.3, 2);
	SpriteNext.setPosition(0, 0 - Sprite.getGlobalBounds().height);
	landfactory.push_back(Sprite);
	landfactory.push_back(SpriteNext);
}
ERCLAND::~ERCLAND()
{

}
void ERCLAND::moveLand(float dt)
{
	for (unsigned short i = 0; i < landfactory.size(); i++)
	{
		float movement = MOVEMENT_SPEED * dt;
		landfactory.at(i).move(0.0f, movement);
		if (landfactory.at(i).getPosition().y > SCREEN_HEIGHT)
		{
			sf::Vector2f position(0, 0 - landfactory.at(i).getGlobalBounds().height);
			landfactory.at(i).setPosition(position);
		}
	}
}

void ERCLAND::drawLand(sf::RenderWindow& window)
{
	for (unsigned short i = 0; i < landfactory.size(); i++)
	{
		window.draw(landfactory.at(i));
	}
}