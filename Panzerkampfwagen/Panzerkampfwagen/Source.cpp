#include <SFML/Graphics.hpp>

#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>

using namespace std;
using namespace sf;

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

	double x_position = 10;
	double y_position = 790;

	RectangleShape projectile(Vector2f(10, 10));
	projectile.setPosition(x_position, y_position);
	projectile.setFillColor(Color(51, 153, 204));

	double x_velocity = 180;
	double y_velocity = -400;
	double y_accel = 100;

	RenderWindow window(VideoMode(1400, 800), "Panzerkampfwagen");
	//window.setFramerateLimit(30);

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
		window.draw(projectile);

		window.display();

		time1 = clock.getElapsedTime();
		clock.restart();
		x_position += (x_velocity * time1.asSeconds());
		y_velocity += (y_accel * time1.asSeconds());
		y_position += (y_velocity * time1.asSeconds());

		projectile.setPosition(x_position, y_position);
		//cout << x_position << " " << y_position << endl;

	}

	return 10;
}