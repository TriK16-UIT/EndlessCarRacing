#include "ERCASSETS.h"

void ERCASSETS::initTexture(std::string TextureFileName)
{
	std::cout << "assets/graphics/" + TextureFileName + ".png";
	if (!TextureList[TextureFileName].loadFromFile("assets/graphics/" + TextureFileName + ".png"))
		std::cout << "Unable to load " << TextureFileName << ".png";
	else std::cout << TextureFileName << " Loaded successfully" << std::endl;
}

void ERCASSETS::initFont(std::string FontFileName)
{
	if (!FontList[FontFileName].loadFromFile("assets/fonts/" + FontFileName + ".ttf"))
		std::cout << "Unable to load " << FontFileName << ".ttf";
	else std::cout << FontFileName << " Loaded successfully" << std::endl;
}

void ERCASSETS::initSound(std::string SoundFileName)
{
	if (!SoundList[SoundFileName].loadFromFile("assets/fonts/" + SoundFileName + ".wav"))
		std::cout << "Unable to load " << SoundFileName << ".wav" << std::endl;
	else std::cout << SoundFileName << " Loaded successfully";
}

ERCASSETS::ERCASSETS()
{
	//tat ca object co width=125, height=200
	initTexture("MAP");
	initTexture("RACER");
	initTexture("CAR1");
	initTexture("CAR2");
	initTexture("CAR3");
	initTexture("CAR4");
	initFont("xirod");
}