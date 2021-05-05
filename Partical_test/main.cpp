
#include "Utills.h"
#include "Init.h"
#include "Update.h"
#include "Draw.h"


int main()
{
	RenderWindow window(VideoMode(1366, 786), "Test", Style::Close);
	font.loadFromFile("font.ttf");
	init_level_1_buttons();
	init_BG_Buttons();
	init_Tool_Buttons();

	while (window.isOpen())
	{
		Event evnt;
		while (window.pollEvent(evnt))
		{
			switch (evnt.type)
			{
			case Event::Closed:
				window.close();
			default:
				break;
			}
		}

		// update functions
		mx = Mouse::getPosition(window).x;
		my = Mouse::getPosition(window).y;

		if (Mouse::isButtonPressed(Mouse::Button::Left))
			init_particles();

		if (Keyboard::isKeyPressed(Keyboard::R))
			particles.clear();

		update_level_1_buttons();
		if(BG_flag == 1)
			update_BG_Buttons();
		if (Tool_flag == 1)
			update_Tool_Buttons();



		//draw functions

		window.clear(Background_color);

		draw_particles(window);
		draw_level_1_buttons(window);
		if (BG_flag == 1)
			draw_BG_Buttons(window);
		if (Tool_flag == 1)
			draw_Tool_Buttons(window);

		window.display();


	}
}

