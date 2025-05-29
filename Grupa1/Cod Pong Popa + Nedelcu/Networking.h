#pragma once
#include <SFML/Network.hpp>

extern float paddle1_x, paddle1_y;
extern float paddle2_x, paddle2_y;
extern float ball_x, ball_y;
extern float ball_speed_x, ball_speed_y;
extern sf::Uint16 score1, score2;
extern sf::IpAddress ip;
void host();
void client();
void host_tick();
void client_tick();
