#pragma once

#include "Utills.h"

void draw_particles(RenderWindow &);
void draw_level_1_buttons(RenderWindow &);
void draw_BS_Buttons(RenderWindow &);
void draw_BG_Buttons(RenderWindow &);
void draw_Tool_Buttons(RenderWindow &);


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

void draw_BS_Buttons(RenderWindow &thisWindow)
{
	for (int i = 0; i < 2; i++)
	{
		thisWindow.draw(Brush_Size_button[i]);
		thisWindow.draw(Brush_Size_button_text[i]);
	}
}

void draw_BG_Buttons(RenderWindow &thisWindow)
{
	for (int i = 0; i < 2; i++)
		thisWindow.draw(Background_col_button[i]);
}

void draw_Tool_Buttons(RenderWindow &thisWindow)
{
	for (int i = 0; i < 18; i++)
		thisWindow.draw(Brush_Colors[i]);
}