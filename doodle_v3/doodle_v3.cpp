#include "pch.h"
#include "C_Doodle.h"
#include "C_Platform.h"




int main(void)
{
	RenderWindow window(VideoMode(WIDTH, HEIGHT), "Doodle Jump");
	window.setFramerateLimit(60);

	//setting
	C_Doodle* doodle = new C_Doodle();
	C_Platform* Platform = new C_Platform();
	
	while (window.isOpen())
	{
		Event e;
		if (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
			{
				window.close();
			}
		}
		//logic
		doodle->Move();
		Platform->MoveAndReset(doodle);
		Platform->CheckCollision(doodle);
		doodle->SetPosition();

		//draw
		window.clear(Color::White);
		doodle->Draw(window);
		Platform->Draw(window);
		window.display();
	}

	delete(Platform);
	delete(doodle);
	return 0;
}