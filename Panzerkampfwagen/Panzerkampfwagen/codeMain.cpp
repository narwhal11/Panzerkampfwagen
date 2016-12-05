#include <SFML/Graphics.hpp>

#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <projectLibs.h>

using namespace std;
using namespace sf;

int main()
{
	srand(time(NULL));

	RectangleShape background(Vector2f(1400, 800));
	background.setPosition(0, 0);
	background.setFillColor(Color(0, 0, 0));

	RectangleShape ground(Vector2f(1400, 200));
	ground.setPosition(0, 600);
	ground.setFillColor(Color(0, 0, 0));

	objTank tank[2];

	tank[0].tank.setSize(Vector2f(50, 10));
	tank[0].x_pos = 40;
	tank[0].y_pos = 790;
	tank[0].tank.setPosition(tank[0].x_pos,tank[0].y_pos);
	tank[0].tank.setFillColor(Color(244,86,66));

	tank[0].mainProj.x_posC = tank[0].x_pos;
	tank[0].mainProj.y_posC = tank[0].y_pos;
	tank[0].mainProj.x_velocityC = 300;
	tank[0].mainProj.y_velocityC = 300 * -1;
	tank[0].mainProj.y_accelC = 100;
	tank[0].mainProj.projecReset();
	tank[0].mainProj.projectile.setSize(Vector2f(10, 10));
	tank[0].mainProj.projectile.setFillColor(Color(51, 153, 204));

	tank[1].tank.setSize(Vector2f(50, 10));
	tank[1].x_pos = 1320;
	tank[1].y_pos = 790;
	tank[1].tank.setPosition(tank[1].x_pos, tank[1].y_pos);
	tank[1].tank.setFillColor(Color(244, 66, 232));

	tank[1].mainProj.x_posC = tank[1].x_pos;
	tank[1].mainProj.y_posC = tank[1].y_pos;
	tank[1].mainProj.x_velocityC = -300;
	tank[1].mainProj.y_velocityC = 300 * -1;
	tank[1].mainProj.y_accelC = 100;
	tank[1].mainProj.projecReset();
	tank[1].mainProj.projectile.setSize(Vector2f(10, 10));
	tank[1].mainProj.projectile.setFillColor(Color(51, 153, 204));


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
		
		for (int a = 0; a < 2; a++)
		{
			window.draw(tank[a].tank);
			window.draw(tank[a].mainProj.projectile);
		}

		window.display();

		if (Keyboard::isKeyPressed(Keyboard::Space)){
			for (int a = 0; a < 2; a++)
			{
				tank[a].mainProj.counter1 = 1;
				tank[a].mainProj.clock.restart();
			}
		}


		for (int a = 0; a < 2; a++)
		{
			if (tank[a].mainProj.counter1 == 1){
				tank[a].mainProj.time = tank[a].mainProj.clock.getElapsedTime();
				tank[a].mainProj.clock.restart();
				tank[a].mainProj.moveProj(tank[a].mainProj.time);
			}
		}

		for (int a = 0; a < 2; a++)
		{
			if (tank[a].mainProj.y_pos > 790){
				tank[a].mainProj.projecReset();
				tank[a].mainProj.counter1 = 0;
			}
		}

	}
	return 10;
}