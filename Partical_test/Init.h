#pragma once

#include "Utills.h"

void init_particles(void);
void init_level_1_buttons(void);
void init_BG_Buttons(void);
void init_Tool_Buttons(void);

void init_particles()
{
	//this will set a single particle
	CircleShape r;
	r.setFillColor(Particle_color);
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

	level_1_texts[0].setString("BackGround");
	level_1_texts[1].setString("Tools");
	level_1_texts[2].setString("Clear");

	for (int i = 0; i < 3; i++)
	{
		level_1_buttons[i].setSize(Vector2f(200, 40));
		level_1_buttons[i].setPosition(i * 220 + 20, 20);
		level_1_texts[i].setFont(font);
		level_1_texts[i].setCharacterSize(28);
		level_1_texts[i].setFillColor(Color::Black);
		level_1_texts[i].setPosition(i * 220 + 35, 23);
	}

}

void init_BG_Buttons(void)
{
	// Background color buttons
	// two colors - Black and White
	for (int i = 0; i < 2; i++)
	{
		Background_col_button[i].setSize(Vector2f(30, 30));
		Background_col_button[i].setPosition(1275, i*50 + 30);
		Background_col_button[i].setOutlineThickness(5.f);
	}
}

void init_Tool_Buttons(void)
{
	int xpos = 1271;	//initial positions
	int ypos = 40;

	//brush initialization and updates are in updates.h

	//Brush Size buttons
	Brush_Size_button_text[0].setString("+");
	Brush_Size_button_text[0].setPosition(1282, 330);
	Brush_Size_button_text[1].setString("-");
	Brush_Size_button_text[1].setPosition(1289, 426);
	for (int i = 0; i < 2; i++)
	{
		Brush_Size_button[i].setOutlineThickness(3.f);
		Brush_Size_button[i].setFillColor(Color(192, 192, 192, 255));
		Brush_Size_button[i].setOutlineColor(Outline_color);
		Brush_Size_button[i].setSize(Vector2f(60, 30));
		Brush_Size_button[i].setPosition(1268, i * 100 + 350);
		Brush_Size_button_text[i].setFont(font);
		Brush_Size_button_text[i].setCharacterSize(55);
		Brush_Size_button_text[i].setFillColor(Color::Black);
	}

	//eraser button
	Eraser.setSize(Vector2f(100, 30));
	Eraser.setOutlineThickness(3.f);
	Eraser.setOutlineColor(Outline_color);
	Eraser.setFillColor(Color(192, 192, 192, 255));
	Eraser.setPosition(1245, 20);
	Eraser_text.setFont(font);
	Eraser_text.setCharacterSize(25);
	Eraser_text.setFillColor(Color::Black);
	Eraser_text.setString("ERASER");
	Eraser_text.setPosition(1249, 20);
	
	//setting all the colors 12 colors 
	// light colors first and then dark colors
	Brush_Colors[0].setFillColor(Color::White);
	Brush_Colors[1].setFillColor(Color::Black);
	Brush_Colors[2].setFillColor(Color(192, 192, 192, 255)); //silver
	Brush_Colors[3].setFillColor(Color(128, 128, 128, 255)); //Grey
	Brush_Colors[4].setFillColor(Color::Red);
	Brush_Colors[5].setFillColor(Color(128, 0, 0, 255));	//Maroon
	Brush_Colors[6].setFillColor(Color::Yellow);
	Brush_Colors[7].setFillColor(Color(128, 128, 0, 255));	//olive
	Brush_Colors[8].setFillColor(Color::Green);
	Brush_Colors[9].setFillColor(Color(0, 128, 0, 255));	//dark Green
	Brush_Colors[10].setFillColor(Color::Blue);
	Brush_Colors[11].setFillColor(Color(0, 0, 128, 255));	//navy
	Brush_Colors[12].setFillColor(Color::Magenta);
	Brush_Colors[13].setFillColor(Color(128, 0, 128, 255));	//purple
	Brush_Colors[14].setFillColor(Color(135, 206, 250, 255));	//sky blue light
	Brush_Colors[15].setFillColor(Color(65, 105, 255, 255));	//royal blue
	Brush_Colors[16].setFillColor(Color(255, 165, 0, 255)); //orange
	Brush_Colors[17].setFillColor(Color(165, 42, 42, 255)); //brown

	for (int i = 0; i < 18; i++)
	{
		Brush_Colors[i].setSize(Vector2f(23, 23));
		Brush_Colors[i].setOutlineThickness(3.f);
		if (i % 2 == 0)
		{
			xpos = 1300;
			ypos += 29;
		}
		else
			xpos = 1271;
		
		Brush_Colors[i].setPosition(xpos, ypos);
	}


}
