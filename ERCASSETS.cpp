#include"ERCASSETS.h"

void ERCASSETS::InitTexture(std::string TextureFileName)
{
	std::cout << "assets/graphics/" + TextureFileName + ".png" << std::endl;
	if (!TextureList[TextureFileName].loadFromFile("assets/graphics/" + TextureFileName + ".png"))
		std::cout << "Unable to load " << TextureFileName << ".png";
	else std::cout << TextureFileName << " Loaded successfully" << std::endl;
}

void ERCASSETS::InitFont(std::string FontFileName)
{
	if (!FontList[FontFileName].loadFromFile("assets/fonts/" + FontFileName + ".ttf"))
		std::cout << "Unable to load " << FontFileName << ".ttf";
	else std::cout << FontFileName << " Loaded successfully" << std::endl;
}

void ERCASSETS::InitSound(std::string SoundFileName)
{
	if (!SoundList[SoundFileName].loadFromFile("assets/fonts/" + SoundFileName + ".wav"))
		std::cout << "Unable to load " << SoundFileName << ".wav" << std::endl;
	else std::cout << SoundFileName << " Loaded successfully";
}

ERCASSETS::ERCASSETS()
{
	InitTexture("MAP");
	InitTexture("RACINGCAR");
}