/*
Caroline Pattillo (cbp53)
Fractal Tree Assignment 
*/

#include <iostream>
#include <iomanip>
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <math.h>

using namespace std;

const float scalar = 2./3; //scalar for the length 
const float valLength = 150.0; //intial length of starting line
const float Xvalue = 300.0;//inital x value of tree
const float Yvalue = 0.0; //inital y value of tree
const float degree = 90; //inital angle of rotation
const float rad = 3.14/180; //pi constant
const float base = 2.0; //minimum branch length 
const float thetaVal = 50.0;  //normal angle of rotation

//Recursive Draw Function which draws the tree
void drawTree(float L, float T, float X, float Y, sf::RenderWindow &window);

int main(int argc, const char* argv[])
{
	//Declaring window variable 
	sf::RenderWindow window(sf::VideoMode(600, 600), "Moving Asteroids"); 

	//Calling drawTree function 
	drawTree(valLength, degree, Xvalue, Yvalue, window);

	//While window is open, display tree  
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

		}

		window.display();
	}


	system("pause"); //keeps window open
	return 0;
}

void drawTree(float L, float T, float X, float Y,sf::RenderWindow &window)
{
	//Base Case
	//Montgomery wanted us to change base case so can actually see a tree
	if (L < base)
	{
		return;
	}

		//Creating new X and Y
		float x2 = X + (L * cos(T * rad));
		float y2 = Y + (L *sin(T* rad));


		//Vector of line points  
		sf::Vertex line[] =
		{
			sf::Vertex(sf::Vector2f(X, Y)),
			sf::Vertex(sf::Vector2f(x2, y2))
		};

		//Draw line 
		window.draw(line, 2, sf::Lines);

		//Fist recursive call, draw one side 
		drawTree(L*scalar, T - thetaVal, x2, y2, window);

		//Drawning other side of tree 
		drawTree(L *scalar, T + thetaVal, x2, y2, window);
	
}