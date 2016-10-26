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

	void projecReset(double x_posU, double y_posU, double x_velocityU, double y_velocityU, double y_accelU)
	{
		x_pos = x_posU;
		y_pos = y_posU;
		x_velocity = x_velocityU;
		y_velocity = y_velocityU;
		y_accel = y_accelU;
	}

	RectangleShape projectile;
};

int main()
{
	Clock clock;
	Time time1 = clock.getElapsedTime();

	int counter1 = 0;

	RectangleShape background(Vector2f(1400, 800));
	background.setPosition(0, 0);
	background.setFillColor(Color(204, 51, 77));

	RectangleShape ground(Vector2f(1400, 200));
	ground.setPosition(0, 600);
	ground.setFillColor(Color(51, 153, 204));

	objProjec mainProj;
	mainProj.x_posC = 10;
	mainProj.y_posC = 790;
	mainProj.x_velocityC = 150;
	mainProj.y_velocityC = -300;
	mainProj.y_accelC = 100;
	mainProj.x_pos = mainProj.x_posC;
	mainProj.y_pos = mainProj.y_posC;
	mainProj.x_velocity = mainProj.x_velocityC;
	mainProj.y_velocity = mainProj.y_velocityC;
	mainProj.y_accel = mainProj.y_accelC;
	mainProj.projectile.setSize(Vector2f(10, 10));
	mainProj.projectile.setPosition(mainProj.x_posC, mainProj.y_posC);
	mainProj.projectile.setFillColor(Color(51, 153, 204));

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
		window.draw(mainProj.projectile);

		window.display();

		if (Keyboard::isKeyPressed(Keyboard::Space)){
			counter1 = 1;
			clock.restart();
		}

		if (counter1 == 1){
			time1 = clock.getElapsedTime();
			clock.restart();
			mainProj.x_pos += (mainProj.x_velocity * time1.asSeconds());
			mainProj.y_velocity += (mainProj.y_accel * time1.asSeconds());
			mainProj.y_pos += (mainProj.y_velocity * time1.asSeconds());
		}

		if (mainProj.y_pos > 790){
			mainProj.projecReset(mainProj.x_posC, mainProj.y_posC, mainProj.x_velocityC, mainProj.y_velocityC, mainProj.y_accelC);
			counter1 = 0;
		}

		mainProj.projectile.setPosition(mainProj.x_pos, mainProj.y_pos);

	}
	return 10;
}