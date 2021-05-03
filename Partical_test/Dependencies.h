#pragma once

#include "Utills.h"

//particles
void init_particles(void);
void draw_particles(RenderWindow &);
//level 1 buttons
void init_level_1_buttons(void);
void update_level_1_buttons(void);
void draw_level_1_buttons(RenderWindow &);
//level 2 buttons
void init_level_2_buttons(void);
void update_level_2_buttons(void);
void draw_level_2_buttons(RenderWindow &);


///////update functions///////

void update_level_1_buttons(void)
{
	//clear the hot[]
	for (int i = 0; i < 4; i++)
		hot[i] = 0;

	for (int i = 0; i < 4; i++)
	{
		level_1_buttons[i].setFillColor(Color(240, 230, 140, 255));

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
				h_index = 3;
				break;
			case 3:
			default:
				break;
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			sleep(milliseconds(100));
			switch (h_index)
			{
			case 3:
				h_index = 2;
				break;
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

		if (hot[i] && Keyboard::isKeyPressed(Keyboard::Enter))
		{
			// toggle second level button flags from here
			// when toggeled on they will be controlled from their update and render functions
			sleep(milliseconds(100));
			switch (i)
			{
			case 0:
				if (BS_flag == 0)
					BS_flag = 1;
				else
					BS_flag = 0;
				break;
			default:
				break;
			}
		}
	}
	
}


void update_level_2_buttons(void)
{

}


///////init functions////////////

void init_particles()
{
	//this will set a single particle
	CircleShape r;
	r.setFillColor(Color::Red);
	r.setRadius(BrushSize);
	r.setPosition(mx, my);
	r.setOrigin(BrushSize, BrushSize);
	particles.push_back(r);
}

void init_level_1_buttons(void)
{
	//this will consist all the first level buttons side-by-side on top
	//when clicked these will create another level of buttons
	//like a pop up window. Not always up....

	level_1_texts[0].setString("Brush Size");
	level_1_texts[1].setString("BackGround");
	level_1_texts[2].setString("Tools");
	level_1_texts[3].setString("Clear");

	for (int i = 0; i < 4; i++)
	{
		level_1_buttons[i].setSize(Vector2f(200, 40));
		level_1_buttons[i].setPosition(i * 220 + 20, 20);
		level_1_texts[i].setFont(font);
		level_1_texts[i].setCharacterSize(28);
		level_1_texts[i].setFillColor(Color::Black);
		level_1_texts[i].setPosition(i * 220 + 35, 23);
	}

}

void init_level_2_buttons(void)
{
	//this is for level 2 buttons which will be toggeled upon the level 1 buttons

	level_2_buttons[0].setSize(Vector2f(200, 40));
	level_2_buttons[0].setPosition(100, 100);

}



///////draw functions//////
void draw_particles(RenderWindow &thisWindow)
{
	//render all particles
	for (auto it = particles.begin(); it != particles.end(); it++)
		thisWindow.draw(*it);
}

void draw_level_1_buttons(RenderWindow &thisWindow)
{
	for (int i = 0; i < 4; i++)
	{
		thisWindow.draw(level_1_buttons[i]);
		thisWindow.draw(level_1_texts[i]);
	}
}

void draw_level_2_buttons(RenderWindow &thisWindow)
{
	thisWindow.draw(level_2_buttons[0]);
}


