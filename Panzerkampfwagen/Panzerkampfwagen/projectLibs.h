#include <SFML/Graphics.hpp>

#include <stdlib.h>
#include <math.h>
#include <time.h>

using namespace std;
using namespace sf;

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
	Clock clock;
	Time time;

	void projecReset()
	{
		x_pos = x_posC;
		y_pos = y_posC;
		x_velocity = x_velocityC;
		y_velocity = y_velocityC;
		y_accel = y_accelC;
		projectile.setPosition(x_pos, y_pos);
	}

	void moveProj(Time time1)
	{
		x_pos += (x_velocity * time1.asSeconds());
		y_velocity += (y_accel * time1.asSeconds());
		y_pos += (y_velocity * time1.asSeconds());
		projectile.setPosition(x_pos, y_pos);
	}

	RectangleShape projectile;
};

class objTank
{
public:
	string name;
	int x_pos;
	int y_pos;

	RectangleShape tank;
	objProjec mainProj;

	void moveTank()
	{

	}
};