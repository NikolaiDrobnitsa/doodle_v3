#pragma once
#include "C_Doodle.h"
class C_Platform
{
private:
	struct Pos
	{
		int x;
		int y;
	};
	vector<Pos> vecPlat;
	Sprite* imgPlat;
	Texture platform_texture;
	int imgWidth;
public:
	C_Platform()
	{
		srand(static_cast<unsigned int>(time(nullptr)));

		platform_texture.loadFromFile("platform.png");
		imgPlat = new Sprite(platform_texture);

		imgWidth = imgPlat->getTexture()->getSize().x;

		for (int i = 0; i < Platform_count; ++i)
		{
			Pos p;
			p.x = rand() % WIDTH - imgWidth / 2;
			p.y = rand() % HEIGHT;
			vecPlat.push_back(p);
		}

		vecPlat[0].y = HEIGHT - 200;
	}
	~C_Platform()
	{
		delete(imgPlat);
	}

	void Draw(RenderWindow& window)
	{
		for (int i = 0; i < Platform_count; ++i)
		{
			imgPlat->setPosition(vecPlat[i].x, vecPlat[i].y);
			window.draw(*imgPlat);
		}
	}
	bool CheckCollision(C_Doodle* doodle)
	{
		//null check.
		if (doodle == nullptr)
		{
			return false;
		}

		for (int i = 0; i < Platform_count; ++i)
		{
			if (doodle->GetDy() > 0
				&& doodle->GetX() + doodle->GetWidth() > vecPlat[i].x
				&& doodle->GetX() < vecPlat[i].x + imgWidth
				&& doodle->GetY() + doodle->GetHeight() > vecPlat[i].y
				&& doodle->GetY() + doodle->GetHeight() < vecPlat[i].y + 10)
			{
				doodle->Jump();
				return true;
			}
		}
		return false;
	}
	void MoveAndReset(C_Doodle* doodle)
	{
		static const int limit = HEIGHT / 3;
		if (doodle->GetY() < limit)
		{
			for (int i = 0; i < Platform_count; ++i)
			{
				doodle->SetY(limit);
				vecPlat[i].y -= static_cast<int>(doodle->GetDy());
				if (vecPlat[i].y > HEIGHT + 10)
				{
					vecPlat[i].y = rand() % HEIGHT / 3 + 100;
					vecPlat[i].x = rand() % WIDTH;
				}
			}
		}
	}

};

