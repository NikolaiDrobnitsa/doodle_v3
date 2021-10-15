#pragma once

class C_Doodle
{
private:
	int x;
	int y;
	int imgWidth;
	int imgHeight;
	float dy;
	Sprite* imgJump;
	Sprite* imgReady;
	Texture doodle_texture;
	Texture fire_doodle;
	
	IntRect IntRect;
	bool jumpFlag;
private:
	const Sprite& GetImg()
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) == false) {

			return *imgJump;
		}
		else
		{
			return *imgReady;
		}
	}

public:
	C_Doodle() : dy(0), jumpFlag(true)
	{
		x = static_cast<int>(WIDTH / 2);
		y = static_cast<int>(HEIGHT / 2);

		
		doodle_texture.loadFromFile("doodle.png");
		fire_doodle.loadFromFile("fire_doodle.png");
		imgJump = new Sprite(doodle_texture);
		imgReady = new Sprite(fire_doodle);

		imgWidth = static_cast<int>(imgReady->getTexture()->getSize().x);
		imgHeight = static_cast<int>(imgReady->getTexture()->getSize().y);
		
	}
	
	
	void SetPosition()
	{
		imgReady->setPosition(x, y);
		imgJump->setPosition(x, y);
	}
	void Move()
	{
		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			x += 4;
		}
		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			x -= 4;
		}
		if (x <= 0)
		{
			x = 0;
		}
		if (x >= WIDTH - imgWidth)
		{
			x = WIDTH - imgWidth;
		}

		jumpFlag = true;
		dy += GRAVITY;
		y += static_cast<int>(dy);

		if (y > HEIGHT - imgHeight)
		{
			jumpFlag = false;
			dy = -10;

		}

	}

	void Draw(RenderWindow& window)
	{
		window.draw(GetImg());
	}

	float GetDy() const
	{
		return dy;
	}
	int GetY() const
	{
		return y;
	}
	int GetX() const
	{
		return x;
	}
	int GetWidth() const
	{
		return imgWidth;
	}
	int GetHeight() const
	{
		return imgHeight;
	}
	void SetY(int _y)
	{
		y = _y;
	}
	void Jump()
	{
		//jumpFlag = false;
		dy = -15;
	}
	
	~C_Doodle()
	{
		delete(imgJump);
		delete(imgReady);
	}
};