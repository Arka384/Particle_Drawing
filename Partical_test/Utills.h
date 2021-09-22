#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <sstream>
#include <list>
#include <time.h>
#define SIZE 1	//draws this muh particles at once
using namespace sf;

bool BG_flag = 0;
bool Tool_flag = 0;

int hot[3] = { 0 };
int h_index = 0;

float mx, my;
float BrushSize = 5.f;	//by default 5
std::list <CircleShape> particles; //Global list for particles
Font font;

Color Background_color = Color::White;
Color Outline_color = Color::Black;
Color Particle_color = Outline_color;

RectangleShape level_1_buttons[3];
Text level_1_texts[6];

RectangleShape Brush_Size_button[2];
Text Brush_Size_button_text[2];

RectangleShape Background_col_button[2];
RectangleShape Brush_Colors[20]; //for tools tab
RectangleShape Eraser;
Text Eraser_text;
