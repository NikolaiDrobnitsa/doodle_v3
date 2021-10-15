#pragma once
#include "pch.h"
#include "C_Platform.h"
class C_MainWindow : public sf::RenderWindow {
	Texture texture_background;
	Sprite* sprite_background;
	sf::IntRect IntRect;
	sf::Font Font;
	sf::Text text;
	sf::Color Color;


public:
	C_MainWindow() {
		if (!Font.loadFromFile("arial.ttf"))
		{
			throw;
		}
		
		texture_background.loadFromFile("background.png");
		sprite_background = new sf::Sprite(texture_background);
		int score = 228;
		ostringstream Score;
		Score << score;

		text.setFont(Font);
		text.setString("Score : " + Score.str());
		text.setCharacterSize(40);
		text.setFillColor(sf::Color::Red);
		text.setStyle(sf::Text::Bold | sf::Text::Underlined);
		text.setPosition(30, 30);
		
	}
	
	void Draw(RenderWindow& windowBackground) { 
		windowBackground.draw(*sprite_background); 
		windowBackground.draw(text);
	}
};

