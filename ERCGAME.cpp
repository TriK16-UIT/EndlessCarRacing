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
	delete racer;
	delete carFactory;
	land = new ERCLAND;
	racer = new ERCRACER;
	carFactory = new ERCCARFACTORY;
	Font = &ERCASSETS::getInstance().FontList["xirod"];
	Score = 0;
	gameSpeed = 10.f;
}

ERCGAME::~ERCGAME()
{

}
void ERCGAME::updateScore()
{
	Score += 1;
	if (Score % 10000 == 0) gameSpeed += 10.f;
}
void ERCGAME::gameover()
{
	while (Window->isOpen())
	{
		while (Window->pollEvent(Event))
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			Window->close();
		Window->clear();
		std::string stringscore = "SCORE: " + std::to_string(Score);
		sf::Text text(stringscore, *Font, 100);
		text.setPosition(SCREEN_WIDTH/2 - text.getGlobalBounds().width/2, SCREEN_HEIGHT / 2 - text.getGlobalBounds().height/2);
		Window->draw(text);
		Window->display();
	}
}
void ERCGAME::drawScore()
{
	std::string stringscore = "SCORE: " + std::to_string(Score);
	sf::Text text(stringscore, *Font, 15);
	text.setPosition(5, 0);
	Window->draw(text);
}
void ERCGAME::update()
{
	int direct;
	land->moveLand(dt);
	racer->moveRacer();
	carFactory->update(racer, gameSpeed);
	if (carFactory->checkCrash()) gameover();
	updateScore();
}

void ERCGAME::render()
{
	Window->clear();
	land->drawLand(*this->Window);
	racer->drawRacer(*this->Window);
	carFactory->draw(*this->Window);
	drawScore();
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