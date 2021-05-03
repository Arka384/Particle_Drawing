
/*
	add global toggle flags for second level buttons 
*/

#include "Utills.h"
#include "Dependencies.h"

int main()
{
	RenderWindow window(VideoMode(1366, 786), "Test", Style::Close);
	init_level_1_buttons();
	init_level_2_buttons();
	font.loadFromFile("font.ttf");

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



		//draw functions

		window.clear();

		draw_particles(window);
		draw_level_1_buttons(window);
		if (BS_flag == 1)
			draw_level_2_buttons(window);

		window.display();


	}
}

