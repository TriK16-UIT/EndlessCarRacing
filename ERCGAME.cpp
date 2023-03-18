#include"ERCGAME.h"

void ERCGAME::initWindow()
{
	VideoMode.width = 1920;
	VideoMode.height = 1080;
	Window = new sf::RenderWindow(VideoMode, "Racing Car");
	Window->setFramerateLimit(60);
}

ERCGAME::ERCGAME()
{
	initWindow();
	delete land;
	land = new ERCLAND;
}

ERCGAME::~ERCGAME()
{

}
void ERCGAME::update()
{
	land->moveLand(dt);
}

void ERCGAME::render()
{
	Window->clear();
	land->drawLand(*this->Window);
	Window->display();
}

void ERCGAME::pollEvent()
{
	while (Window->isOpen())
	{
		while (Window->pollEvent(Event))
			if (Event.type = sf::Event::Closed)
				Window->close();
		update();
		render();
	}
}

void ERCGAME::run()
{
	pollEvent();
}