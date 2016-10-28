#include <SFML/Graphics.hpp>

#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>

using namespace std;
using namespace sf;

class objTank
{
public:
	string name;
	int x_pos;
	int y_pos;

	Sprite sprite1;
};

class objProjec
{
public:
	string name;
	double x_pos;
	double y_pos;
	double x_velocity;
	double y_velocity;
	double y_accel;
	double x_posC;
	double y_posC;
	double x_velocityC;
	double y_velocityC;
	double y_accelC;
	int type = 0;
	int counter1 = 0;

	void projecReset()
	{
		x_pos = x_posC;
		y_pos = y_posC;
		x_velocity = x_velocityC;
		y_velocity = y_velocityC;
		y_accel = y_accelC;
		projectile.setPosition(x_posC, y_posC);
	}

	void moveProj(Time time1)
	{
		x_pos += (x_velocity * time1.asSeconds());
		y_velocity += (y_accel * time1.asSeconds());
		y_pos += (y_velocity * time1.asSeconds());
		projectile.setPosition(x_pos,y_pos);
	}

	RectangleShape projectile;
};

int main()
{

	Clock clock;
	Time time1 = clock.getElapsedTime();

	RectangleShape background(Vector2f(1400, 800));
	background.setPosition(0, 0);
	background.setFillColor(Color(204, 51, 77));

	RectangleShape ground(Vector2f(1400, 200));
	ground.setPosition(0, 600);
	ground.setFillColor(Color(51, 153, 204));

	//int amtProj = 5;

	objProjec projVec[5];
	for (int a = 0; a < 5; a++)
	{
		projVec[a].x_posC = 10;
		projVec[a].y_posC = 790;
		projVec[a].x_velocityC = 150 + (a * 5);
		projVec[a].y_velocityC = -300;
		projVec[a].y_accelC = 100;
		projVec[a].projecReset();
		projVec[a].projectile.setSize(Vector2f(10, 10));
		projVec[a].projectile.setFillColor(Color(51, 153, 204));
	}

	RenderWindow window(VideoMode(1400, 800), "Panzerkampfwagen");

	while (window.isOpen()){

		Event event1;
		while (window.pollEvent(event1))
		{
			if (event1.type == Event::Closed){
				window.close();
			}
		}

		window.clear();

		window.draw(background);
		//window.draw(ground);
		for (int a = 0; a < 5; a++)
		{
			window.draw(projVec[a].projectile);
		}


		window.display();

		if (Keyboard::isKeyPressed(Keyboard::Space)){
			for (int a = 0; a < 5; a++)
			{
				projVec[a].counter1 = 1;
			}

			clock.restart();
		}


		for (int a = 0; a < 5; a++)
		{
			if (projVec[a].counter1 == 1){
				time1 = clock.getElapsedTime();
				clock.restart();
				projVec[a].moveProj(time1);
			}
		}

		for (int a = 0; a < 5; a++)
		{
			if (projVec[a].y_pos > 790){
				projVec[a].projecReset();
				projVec[a].counter1 = 0;
			}
		}

	}
	return 10;
}