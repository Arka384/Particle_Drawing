#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>
#include <time.h>
#define SIZE 1	//draws this muh particles at once
using namespace sf;

bool BS_flag = 0;

int hot[4] = { 0 };
int h_index = 0;

float mx, my;
float BrushSize = 5.f;	//by default 5
std::list <CircleShape> particles; //Global list for particles
Font font;

RectangleShape level_1_buttons[4];
RectangleShape level_2_buttons[4];

Text level_1_texts[6];
Text level_2_texts[2];