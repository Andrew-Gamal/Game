// SFML_Template.cpp : This file contains the 'main' function. Program execution begins and ends there
#include <sfml/graphics.hpp>
#include <iostream>
#include <math.h>
using namespace sf;
using namespace std;

#define x 10
#define y 10
#define up  72
#define down  80
#define right 77
#define left 75

using namespace sf;
using namespace std;

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 800;
const int margin = 50;
int main()
{
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Day(2)",Style::Default);
	
	int positionX = 0, positionY = 5, q, w, targetX = 0, targetY = 0;
	
	char number[x][y] =
	{
		{'X','.','.','.','|','0','.','.','|','.'},
		{'.','.','.','|','.','.','.','|','.','.'},
		{'|','.','.','.','.','|','.','.','.','.'},
		{'.','.','.','.','.','.','.','.','.','.'},
		{'.','.','.','.','|','.','.','.','.','.'},
		{'|','.','.','.','.','.','.','.','.','.'},
		{'.','.','.','|','.','.','.','.','.','.'},
		{'|','.','.','.','.','.','.','|','.','.'},
		{'.','.','.','.','.','|','.','.','.','.'},
		{'.','.','.','.','|','.','.','.','.','|'}
	};

	sf::RectangleShape rectangle(sf::Vector2f(50.f, 50.f));
	rectangle.setFillColor(sf::Color::Yellow);
	sf::CircleShape shape2(20.f);
	shape2.setFillColor(sf::Color::Red);
	sf::CircleShape player(20.f);
	player.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		Event event;
		window.clear();
		for (w = 0; w < y; w++)
		{
			for (q = 0; q < x; q++)
			{
				if (number[q][w] == '|') {
					rectangle.setPosition(50.f * q, 50.f * w);
					window.draw(rectangle);
				}

				 if (number[q][w] == 'X')
				{
					shape2.setPosition(50.f * q, 50.f * w);
					window.draw(shape2);

				}
				 if (number[q][w] == '0')
				{
					player.setPosition(50.f * q, 50.f * w);
					window.draw(player);
				}
			}
		}
		if (positionX == targetX && positionY == targetY)
		{
			puts("You Win :D");
		}
		while (window.pollEvent(event)){
			
			switch (event.type)
			{ 
			case (sf::Event::Closed):
					window.close();
					break;
			case(sf::Event::KeyPressed):
					switch (event.key.code)
					{
					case Keyboard::Up:
						while (positionY > 0 && number[positionX][positionY - 1] != '|')
						{
							number[positionX][positionY] = '.';
							positionY--;
							number[positionX][positionY] = '0';
						}
						break;
					case Keyboard::Down:
						while (positionY < 9 && number[positionX][positionY + 1] != '|')
						{
							cout << "hi";
							number[positionX][positionY] = '.';
							positionY++;
							number[positionX][positionY] = '0';
						}
						break;
					case Keyboard::Right:
						while (positionX < 9 && number[positionX + 1][positionY] != '|')
						{
							number[positionX][positionY] = '.';
							positionX++;
							number[positionX][positionY] = '0';
						}
						break;
					case Keyboard::Left:
						while (positionX > 0 && number[positionX - 1][positionY] != '|')
						{
							number[positionX][positionY] = '.';
							positionX--;
							number[positionX][positionY] = '0';
						}
						break;
					}		
			}
		}
		window.display();
	}
		return 0;
}