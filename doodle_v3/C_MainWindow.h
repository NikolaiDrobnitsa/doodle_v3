#pragma once
#include "pch.h"
#include "C_Platform.h"
class C_MainWindow : public sf::RenderWindow, public C_Platform, public C_Doodle {
	Texture texture_background;
	Sprite* sprite_background;
	sf::IntRect IntRect;
	sf::Font Font;
	sf::Text text;
	sf::Color Color;

	
public:
		
	C_MainWindow() {

		int score;
		if (!Font.loadFromFile("arial.ttf"))
		{
			throw;
		}
		int test = 0;
		//score = Testscore;
		
		//score = GetScore();
		
		
		cout << test;
		//score++;
		
		ostringstream Score;
		Score << test;
		text.setFont(Font);
		text.setString("Score : " + Score.str());
		text.setCharacterSize(40);
		text.setFillColor(sf::Color::Red);
		text.setStyle(sf::Text::Bold | sf::Text::Underlined);
		text.setPosition(30, 30);
		


		texture_background.loadFromFile("background.png");
		sprite_background = new sf::Sprite(texture_background);
		//int score = 228;
		
		
	}
	void Draw(RenderWindow& windowBackground) { 
		windowBackground.draw(*sprite_background); 
	}
	void Draws(RenderWindow& windowScore) {
		windowScore.draw(text);
		
	}

};

