#pragma once
#include"SFML/System.hpp"
#include"SFML/Graphics.hpp"
#include"SFML/Window.hpp"
#include"SFML/Audio.hpp"
#include<unordered_map>
#include<iostream>

class ERCASSETS
{
private:
	ERCASSETS();
	ERCASSETS(const ERCASSETS&) {};
	ERCASSETS& operator=(const ERCASSETS&) {};
	void initTexture(std::string TextureFileName);
	void initFont(std::string FontFileName);
	void initSound(std::string SoundFileName);
public:
	static ERCASSETS& getInstance()
	{
		static ERCASSETS instance;
		return instance;
	}
	std::unordered_map <std::string, sf::Texture> TextureList;
	std::unordered_map <std::string, sf::Font> FontList;
	std::unordered_map <std::string, sf::SoundBuffer> SoundList;
};