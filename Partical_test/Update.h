#pragma once

#include "Utills.h"

void update_level_1_buttons(void);
void update_BG_Buttons(void);
void update_Tool_Buttons(void);

void update_level_1_buttons(void)
{
	//clear the hot[]
	for (int i = 0; i < 3; i++)
		hot[i] = 0;

	for (int i = 0; i < 3; i++)
	{
		level_1_buttons[i].setFillColor(Color(128, 128, 128, 255));

		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			sleep(milliseconds(100));
			switch (h_index)
			{
			case 0:
				h_index = 1;
				break;
			case 1:
				h_index = 2;
				break;
			case 2:
			default:
				break;
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			sleep(milliseconds(100));
			switch (h_index)
			{
			case 2:
				h_index = 1;
				break;
			case 1:
				h_index = 0;
				break;
			case 0:
			default:
				break;
			}
		}

		hot[h_index] = 1;

		if (hot[i] == 1)
			level_1_buttons[i].setFillColor(Color(220, 20, 60, 255));

		//std::cout << "BG = " << BG_flag << "\n";
		//std::cout << "T = " << Tool_flag << "\n";

		if (hot[i] && Keyboard::isKeyPressed(Keyboard::Enter))
		{
			// toggle second level button flags from here
			// when toggeled on they will be controlled from their update and render functions
			sleep(milliseconds(100));
			switch (i)
			{
			case 0:
				if (BG_flag == 0)
					BG_flag = 1;
				else
					BG_flag = 0;
				break;
			case 1:
				if (Tool_flag == 0)
					Tool_flag = 1;
				else
					Tool_flag = 0;
				break;
			case 2:
				particles.clear();
				break;
			default:
				break;
			}
		}

		//if buttons are not hot then toggle off
		if (hot[0] == 0)
			BG_flag = 0;
		if (hot[1] == 0)
			Tool_flag = 0;
	}

}

void update_BG_Buttons(void)
{
	//these buttons can be used only when the canvas is empty
	//when clicked these will create a border around to denote the hot condition

	Background_col_button[0].setFillColor(Color::White);
	Background_col_button[0].setOutlineColor(Color(128, 128, 128, 255));
	Background_col_button[1].setFillColor(Color::Black);
	Background_col_button[1].setOutlineColor(Color(128, 128, 128, 255));

	for (int i = 0; i < 2; i++)
	{
		Background_col_button[i].setSize(Vector2f(30, 30));
		Background_col_button[i].setPosition(1275, i * 50 + 30);

		int hot = mx > Background_col_button[i].getPosition().x && mx < Background_col_button[i].getPosition().x + 30 &&
			my > Background_col_button[i].getPosition().y && my < Background_col_button[i].getPosition().y + 30;

		if (hot)
		{
			Background_col_button[i].setPosition(1270, i * 50 + 25);
			Background_col_button[i].setSize(Vector2f(40, 40));
		}
			

		if (hot && Mouse::isButtonPressed(Mouse::Button::Left))
		{
			sleep(milliseconds(50));
			//if (particles.empty())
				particles.pop_back();
			if (particles.empty())
			{
				if (i == 0)
				{
					Outline_color = Color::Black;
					Particle_color = Outline_color;
					Background_color = Color::White;
				}
				if (i == 1)
				{
					Outline_color = Color::White;
					Particle_color = Outline_color;
					Background_color = Color::Black;
				}
			}
		}
	}

}

void update_Tool_Buttons(void)
{
	//this will change the pen color 
	// the outline will be changed to complement of the background color 
	// to denote the hot condition

	for (int i = 0; i < 18; i++)
	{
		Brush_Colors[i].setOutlineColor(Outline_color);

		int hot = mx > Brush_Colors[i].getPosition().x && mx < Brush_Colors[i].getPosition().x + 23 &&
			my > Brush_Colors[i].getPosition().y && my < Brush_Colors[i].getPosition().y + 23;

		if (hot)
			Brush_Colors[i].setOutlineColor(Background_color);

		if (hot && Mouse::isButtonPressed(Mouse::Button::Left))
		{
			sleep(milliseconds(50));
			particles.pop_back();
			switch (i)
			{
			case 0:
				Particle_color = Color::White;
				break;
			case 1:
				Particle_color = Color::Black;
				break;
			case 2:
				Particle_color = Color(192, 192, 192, 255);
				break;
			case 3:
				Particle_color = Color(128, 128, 128, 255);
				break;
			case 4:
				Particle_color = Color::Red;
				break;
			case 5:
				Particle_color = Color(128, 0, 0, 255);
				break;
			case 6:
				Particle_color = Color::Yellow;
				break;
			case 7:
				Particle_color = Color(128, 128, 0, 255);
				break;
			case 8:
				Particle_color = Color::Green;
				break;
			case 9:
				Particle_color = Color(0, 128, 0, 255);
				break;
			case 10:
				Particle_color = Color::Blue;
				break;
			case 11:
				Particle_color = Color(0, 0, 128, 255);
				break;
			case 12:
				Particle_color = Color::Magenta;
				break;
			case 13:
				Particle_color = Color(128, 0, 128, 255);
				break;
			case 14:
				Particle_color = Color(135, 206, 250, 255);
				break;
			case 15:
				Particle_color = Color(65, 105, 255, 255);
				break;
			case 16:
				Particle_color = Color(255, 165, 0, 255);
				break;
			case 17:
				Particle_color = Color(165, 42, 42, 255);
				break;
			default:
				break;
			}
			
		}
	}

	//update for Eraser button
	Eraser.setSize(Vector2f(100, 30));
	Eraser.setPosition(1245, 20);
	Eraser.setOutlineColor(Outline_color);

	int hot = mx > Eraser.getPosition().x && mx < Eraser.getPosition().x + 100 &&
		my > Eraser.getPosition().y && my < Eraser.getPosition().y + 30;

	if (hot)
	{
		Eraser.setPosition(1240, 15);
		Eraser.setSize(Vector2f(110, 40));
	}

	if (hot && Mouse::isButtonPressed(Mouse::Button::Left))
	{
		sleep(milliseconds(50));
		particles.pop_back();
		Particle_color = Background_color;
	}

	//updating the Brush Size button
	for (int i = 0; i < 2; i++)
	{
		Brush_Size_button[i].setSize(Vector2f(60, 30));
		Brush_Size_button[i].setPosition(1268, i * 50 + 350);
		Brush_Size_button[i].setOutlineColor(Outline_color);

		int hot = mx > Brush_Size_button[i].getPosition().x && mx < Brush_Size_button[i].getPosition().x + 60 &&
			my > Brush_Size_button[i].getPosition().y && my < Brush_Size_button[i].getPosition().y + 30;

		if (hot)
		{
			Brush_Size_button[i].setPosition(1265, i * 50 + 347);
			Brush_Size_button[i].setSize(Vector2f(65, 35));
		}

		if (hot && Mouse::isButtonPressed(Mouse::Button::Left))
		{
			sleep(milliseconds(50));
			particles.pop_back();
			if (i == 0)
				BrushSize++;
			if (i == 1)
				BrushSize--;
		}
	}
}
