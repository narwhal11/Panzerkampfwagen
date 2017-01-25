#include "objTank.h"

int main()
{
	srand(time(NULL));

	textureDeclare texDec;

	RectangleShape background(Vector2f(1400, 800));
	background.setPosition(0, 0);
	background.setFillColor(Color(204, 51, 77));

	RectangleShape ground(Vector2f(1400, 200));
	ground.setPosition(0, 600);
	ground.setFillColor(Color(51, 153, 204));

	objTank tank[1] = { objTank(texDec) };

	tank[0].bodysprite.setScale(Vector2f(50, 10));
	tank[0].x_pos = 40;
	tank[0].y_pos = 790;
	tank[0].bodysprite.setPosition(tank[0].x_pos,tank[0].y_pos);

	//tank[0].mainProj.x_posC = tank[0].x_pos;
	//tank[0].mainProj.y_posC = tank[0].y_pos;
	//tank[0].mainProj.x_velocityC = 300;
	//tank[0].mainProj.y_velocityC = 300 * -1;
	//tank[0].mainProj.y_accelC = 100;
	//tank[0].mainProj.projecReset();
	//tank[0].mainProj.projectile.setSize(Vector2f(10, 10));
	//tank[0].mainProj.projectile.setFillColor(Color(51, 153, 204));

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
		
		for (int a = 0; a < 1; a++)
		{
			tank[a].bodysprite.setPosition(tank[a].x_pos, tank[a].y_pos);
			window.draw(tank[a].bodysprite);
			//window.draw(tank[a].mainProj.projectile);
		}

		window.display();

		if (Keyboard::isKeyPressed(Keyboard::Space)){
			for (int a = 0; a < 1; a++)
			{
				tank[a].mainProj.counter1 = 1;
				tank[a].mainProj.clock.restart();
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::Left) | Keyboard::isKeyPressed(Keyboard::Right)){
			tank[0].moveTank(true);
		}

		for (int a = 0; a < 1; a++)
		{
			if (tank[a].mainProj.counter1 == 1){
				tank[a].mainProj.time = tank[a].mainProj.clock.getElapsedTime();
				tank[a].mainProj.clock.restart();
			}
		}

		for (int a = 0; a < 1; a++)
		{
			if (tank[a].mainProj.y_pos > 790){
				tank[a].mainProj.projecReset();
				tank[a].mainProj.counter1 = 0;
			}
		}

	}
	return 10;
}