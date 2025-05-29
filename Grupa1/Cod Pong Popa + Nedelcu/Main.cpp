#include "Networking.h"
#include "Animation.h"
#include "Colliders.h"
#include <SFML/System.hpp>
#include <iostream>
#include <SFML/Graphics.hpp>

float paddle1_x = 1, paddle1_y = 1;
float paddle2_x = 1, paddle2_y = 1;
float ball_x = 1, ball_y = 1;
float ball_speed_x = -6, ball_speed_y = 6;
sf::Uint16 score1 = 1, score2 = 1;
sf::IpAddress ip;

using namespace sf;

void setDifficulty(int& difficulty)
{
	int bufferDifficulty = 0; //un fel de set/get mai handicapat
	std::cout << "Select difficulty (1-3):";
	while (difficulty == 0)
	{
		std::cin >> bufferDifficulty;
		if (bufferDifficulty >= 1 && bufferDifficulty <= 3)
		{
			difficulty = bufferDifficulty;
			ball_speed_x *= difficulty;
			ball_speed_y *= difficulty;
		}
		else
			std::cout << "Invalid option"<<std::endl;
	}
	
}

int main()
{
	int difficulty = 0;
	bool playAnim1=0;//lazy fix
	bool playAnim2=0;//
	bool allowLeft = 0;
	bool allowRight = 0;
	int delay = 0;
	char connectionType;
	std::cout << "Pong multiplayer v1.0"<<std::endl<<"Controls: W/S Up/Down"<<std::endl;
	std::cout << "Write s for singleplayer, h for host or c for client" << std::endl;
	std::cin >> connectionType;
	if (connectionType == 'S')
		connectionType = 's';
	else if (connectionType == 'H')
		connectionType = 'h';
	else if (connectionType == 'C')
		connectionType = 'c';

	if (connectionType == 's')
	{
		setDifficulty(difficulty);
		allowLeft = 1;
		allowRight = 1;
	}
	else if (connectionType == 'h') {
		//setDifficulty(difficulty);
		difficulty = 2;
		ball_speed_x *= difficulty;
		ball_speed_y *= difficulty;
		allowLeft = 1;
		host();
	}
	else if (connectionType == 'c') {
		allowRight = 1;
		difficulty = 2;
		std::cout << "Enter IP: ";
		std::cin >> ip;
		client();
	}
	else {
		std::cout << "Invalid option.\n";
		return -1;
	}
	//Initializing Window
	RenderWindow window(VideoMode({ 1920, 1080 }), "PONG GAME", Style::Fullscreen);
	window.setFramerateLimit(120);
	Vector2u WindowSize = window.getSize();

	//Initializing Background picture
	Texture textura;
	textura.loadFromFile("background.png");
	Sprite sprite;
	sprite.setTexture(textura);
	Vector2u textureSize = textura.getSize();
	float scaleX = (float)WindowSize.x / textureSize.x;
	float scaleY = (float)WindowSize.y / textureSize.y;
	sprite.setScale(scaleX, scaleY);

	
	//Paddle1
	paddle1_x = 150;
	paddle2_x = WindowSize.x - 150;

	Texture pad1;
	pad1.loadFromFile("Paddle_Red.png");
	RectangleShape paddle1(Vector2f(100.f, 100.f));
	Animation anim1(pad1, 64, 64, 4, 0.15f);
	anim1.getSprite().setOrigin(32, 32);
	anim1.getSprite().setScale(5, -5);
	FloatRect paddlebounds = paddle1.getLocalBounds();
	paddle1.setFillColor(Color::Transparent);
	paddle1.setOrigin(paddlebounds.width / 2.f, paddlebounds.height / 2.f);
	
	//Paddle2
	paddle1_y = (WindowSize.y / 2.f);
	paddle2_y = paddle1_y;

	sf::Texture pad2;
	pad2.loadFromFile("Paddle_Blue.png");
	RectangleShape paddle2(Vector2f(100.f, 100.f));
	Animation anim2(pad2, 64, 64, 4, 0.15f);
	anim2.getSprite().setOrigin(32, 32);
	anim2.getSprite().setScale(-5, 5);
	paddle2.setFillColor(Color::Transparent);
	paddle2.setOrigin(paddlebounds.width / 2.f, paddlebounds.height / 2.f);

	//Ball
	CircleShape ball(25.f);
	FloatRect mingebounds = ball.getLocalBounds();
	ball.setOrigin(mingebounds.width / 2.f, mingebounds.height / 2.f);
	//ball.setOutlineColor(sf::Color::Black);
	//ball.setOutlineThickness(1.f);
	ball_x = WindowSize.x / 2.f;
	ball_y = WindowSize.y / 2.f;

	sf::Font font;
	font.loadFromFile("slip.ttf");
	
	//Score text
	Text text;
	std::string scoreText = std::to_string(score1) + "     :     " + std::to_string(score2);
	text.setString(scoreText);
	
	text.setFont(font); 
	text.setCharacterSize(75);   
	text.setFillColor(sf::Color::White); 
	text.setPosition(WindowSize.x / 2.f, 130);
	text.setOutlineColor(sf::Color::Black);
	text.setOutlineThickness(4.f);
	FloatRect textRect = text.getLocalBounds();
	text.setOrigin(textRect.left + textRect.width / 2.0f,
				   textRect.top + textRect.height / 2.0f);
	//CLOCK
	sf::Clock clock;
	while (window.isOpen()) 
	{
		
		Event event;
		while (window.pollEvent(event))
			if (event.type == Event::Closed || (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape))
				window.close();
		//pt animatii
		float deltaTime = clock.restart().asSeconds();
		anim1.update(deltaTime);
		anim2.update(deltaTime);

		collider_margin(WindowSize.x / 2.f, WindowSize.y / 2.f);
		collider_paddle(paddle1_x, paddle1_y, paddlebounds.width, playAnim1);
		collider_paddle(paddle2_x, paddle2_y, paddlebounds.width, playAnim2);

		//Updating text
		std::string scoreText = std::to_string(score1) + "     :     " + std::to_string(score2);
		text.setString(scoreText);

		ball_x += ball_speed_x;
		ball_y += ball_speed_y;
		ball.setPosition(ball_x, ball_y);

		//Player input
		if (Keyboard::isKeyPressed(Keyboard::W) && allowLeft && paddle1_y >= 50)
		{
			paddle1_y -= 8*difficulty;
		}
		if (Keyboard::isKeyPressed(Keyboard::S)&& allowLeft && paddle1_y <= WindowSize.y-50)
		{
			paddle1_y += 8*difficulty;
		}

		if (Keyboard::isKeyPressed(Keyboard::Up) && allowRight && paddle2_y >= 50)
		{
			paddle2_y -= 8*difficulty;
		}
		if (Keyboard::isKeyPressed(Keyboard::Down) && allowRight && paddle2_y <= WindowSize.y-50)
		{
			paddle2_y += 8*difficulty;
		}
		//animations
		if (playAnim1)
		{
			anim1.playOnce(4);
			playAnim1 = 0;
		}
		if (playAnim2)
		{
			anim2.playOnce(4);
			playAnim2 = 0;
		}

		
		paddle1.setPosition(paddle1_x, paddle1_y);
		paddle2.setPosition(paddle2_x, paddle2_y);
		//HOLY 
		anim1.getSprite().setPosition(paddle1.getPosition());
		anim2.getSprite().setPosition(paddle2.getPosition());

		if (connectionType == 'h' && delay >= 2)
		{
			host_tick();
			delay = 0;
		}
		if (connectionType == 'c' && delay >= 2)
		{
			client_tick();
			delay = 0;
		}
		delay++;

		window.clear();
		window.draw(sprite);
		window.draw(anim1.getSprite());
		window.draw(anim2.getSprite());
		window.draw(ball);
		window.draw(text);
		window.display();
	}
    return 0;
}