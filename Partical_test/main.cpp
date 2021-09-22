
#include "Utills.h"
#include "Init.h"
#include "Update.h"
#include "Draw.h"

void takeScreenShot(RenderWindow &window, Time t);

int main()
{
	std::cout << "Press S to save drawing\n\n";
	RenderWindow window(VideoMode(1366, 786), "Test", Style::Close);
	Clock clk;
	clk.restart();
	Time time;
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
			case Event::KeyPressed:
				if(evnt.key.code == Keyboard::R)
					particles.clear();
				if (evnt.key.code == Keyboard::S) {
					time = clk.getElapsedTime();
					takeScreenShot(window, time);
				}
				break;
			default:
				break;
			}
		}

		// update functions
		mx = Mouse::getPosition(window).x;
		my = Mouse::getPosition(window).y;

		if (Mouse::isButtonPressed(Mouse::Button::Left))
			init_particles();

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

void takeScreenShot(RenderWindow & window, Time t)
{
	sf::Texture texture;
	texture.create(window.getSize().x, window.getSize().y);
	texture.update(window);
	float x = t.asSeconds();
	float time = t.asSeconds() / 10;
	std::string fileName = "Drawings/";
	std::stringstream uniqueFactor;
	uniqueFactor << time;
	fileName.append(uniqueFactor.str());
	fileName.append(".png");

	if (texture.copyToImage().saveToFile(fileName)) {
		std::cout << "Drawing saved in 'Drawings' folder at " << x << " seconds\n\n";
	}
}
