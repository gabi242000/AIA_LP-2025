#pragma once
#include <SFML/System.hpp>
extern float paddle1_x, paddle1_y;
extern float paddle2_x, paddle2_y;
extern float ball_x, ball_y;
extern float ball_speed_x, ball_speed_y;
extern sf::Uint16 score1, score2;
void collider_paddle(float x, float y, float offset, bool& playAnim) {
	float animOffset = 50;
	if (ball_x >= x - offset/1.5 &&
		ball_x <= x + offset/1.5 &&
		ball_y >= y - offset &&
		ball_y <= y + offset)
	{
		//sketchy fix afla in care jum a ecranului se afla mingea
		if (ball_x < 960)
		{
			ball_x = x + offset / 1.5 + 3;
			ball_y = y;
		}
		else
		{
			ball_x = x - offset / 1.5 - 3;
			ball_y = y;
		}

		ball_speed_x *= -1;
		//ball_speed_y *= -1;
	}
	//Anim trigger, hardcoded, doare lenea
	if (ball_x < 960 && ball_speed_x < 0)
	{
		if (ball_x >= x + offset +animOffset*1.5 -6 &&
			ball_x <= x + offset +animOffset*1.5 +12&&
			ball_y >= y - offset - animOffset* 8 &&
			ball_y <= y + offset + animOffset* 8)
		{
				playAnim = 1;
		}
	}	
	else if (ball_speed_x > 0 && ball_x > 960)
	{
		if (ball_x >= x - offset - animOffset * 1.5 -12&&
			ball_x <= x - offset - animOffset * 1.5 +6&&
			ball_y >= y - offset - animOffset * 8 &&
			ball_y <= y + offset + animOffset * 8)
		{
			playAnim = 1;
		}
	}
		
}
void collider_margin(float x, float y)
{
	if (ball_y <= 80)//sus
	{
		ball_y = 81;
		ball_speed_y *= -1;
	}
	if (ball_y >= 1080 - 80)//jos
	{
		ball_y = 999;
		ball_speed_y *= -1;
	}
	if (ball_x < -200)
	{
		ball_x = x;
		ball_y = y;
		score2++;
		ball_speed_x *= -1;
	}
	if (ball_x > 1920 + 200)
	{
		ball_x = x;
		ball_y = y;
		score1++;
		ball_speed_x *= -1;
	}

}