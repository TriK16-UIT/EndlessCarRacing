#include<iostream>
#include"SFML\Graphics.hpp"
#include"SFML\Window.hpp"
#include"SFML\System.hpp"
#include"SFML\Audio.hpp"
#include<cstdlib>
#include<string>
//Dung de luu ten file va kieu du lieu cua file
#include <unordered_map>
class ERCASSETS
{
private:
	ERCASSETS();
	ERCASSETS(const ERCASSETS&) {};
	ERCASSETS& operator=(const ERCASSETS&) {};

	void InitTexture(std::string TextureFileName);
	void InitFont(std::string FontFileName);
	void InitSound(std::string SoundFileName);
public:
	static ERCASSETS& GetInstance()
	{
		static ERCASSETS instance;
		return instance;
	}
	std::unordered_map<std::string, sf::Texture> TextureList;
	std::unordered_map<std::string, sf::SoundBuffer> SoundList;
	std::unordered_map<std::string, sf::Font> FontList;
};