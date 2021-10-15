#pragma once
#include "pch.h"
class C_MainWindow : public sf::RenderWindow {
	sf::Color _bgColor;

	sf::Texture texture_background;
	sf::Sprite* sprite_background;
	sf::IntRect IntRect;

	sf::Font myFont;
	sf::Text myText;


	sf::Font font;


public:
	C_MainWindow() : RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "") {
		

	}
};

