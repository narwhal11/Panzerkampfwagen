#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>

using namespace std;
using namespace sf;

class wizard
{
public:
	sf::Sprite bodysprite;
	sf::Sprite armsprite;
	bool facingright;
	int xxposition;
	int yyposition;
	int angle;
	bool hasmoved = false;
};

int main()
{
	sf::Texture player1righttexture;
	sf::Texture arm1righttexture;
	sf::Texture player1lefttexture;
	sf::Texture arm1lefttexture;
	if (!player1righttexture.loadFromFile("Wizard_Red_right.png"))
	{
		// error...
	}
	if (!arm1righttexture.loadFromFile("Wizard_Red_arm_right.png"))
	{
		// error...
	}
	if (!player1lefttexture.loadFromFile("Wizard_Red_left.png"))
	{
		// error...
	}
	if (!arm1lefttexture.loadFromFile("Wizard_Red_arm_left.png"))
	{
		// error...
	}
	wizard player1;
	player1.facingright = true;
	player1.bodysprite.setTexture(player1righttexture);
	player1.xxposition = 10;
	player1.yyposition = 653;
	player1.bodysprite.scale(sf::Vector2f(1.f, 1.f));
	//player1.bodysprite.setOrigin(64, 108);
	player1.armsprite.scale(sf::Vector2f(1.f, 1.f));


	Clock clock;
	Time time1 = clock.getElapsedTime();
	int counter1 = 0;
	bool turn = true;


	RectangleShape background(Vector2f(1400, 800));
	background.setPosition(0, 0);
	background.setFillColor(Color(51, 255, 255));

	RectangleShape ground(Vector2f(1400, 100));
	ground.setPosition(0, 700);
	ground.setFillColor(Color(12, 139, 12));

	double x_position = 0;
	double y_position = 690;
	double x_velocity = 180;
	double y_velocity = -400;
	double y_accel = 120;
	double a_position = 1380;

	RectangleShape projectile(Vector2f(10, 10));
	projectile.setFillColor(Color(255 ,255 ,255));

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
		window.draw(projectile);
		player1.armsprite.setTexture(arm1righttexture);
		player1.armsprite.setOrigin(0, 2);
		player1.bodysprite.setPosition(player1.xxposition, player1.yyposition);
		player1.armsprite.setPosition(player1.xxposition +17, player1.yyposition + 27);

		window.draw(ground);
		window.draw(player1.bodysprite);
		window.draw(player1.armsprite);
		window.display();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::PageDown) & x_velocity > 0 & counter1 == 0)
		{
			x_velocity = x_velocity - 5;
			while (sf::Keyboard::isKeyPressed(sf::Keyboard::PageDown)){}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::PageUp) & x_velocity < 2000 & counter1 == 0)
		{
			x_velocity = x_velocity + 5;
			while (sf::Keyboard::isKeyPressed(sf::Keyboard::PageUp)){}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) & y_accel < 10000 & counter1 == 0)
		{
			y_accel = y_accel + 5;
			while (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) & y_accel > 0 & counter1 == 0)
		{
			y_accel = y_accel - 5;
			while (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){}
		}
		cout << "x:" << x_velocity << "   y:" << y_accel << endl;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) & counter1 == 0)
		{
			if (turn == true)
			{
				counter1 = 1;
			}
			else
			{
				counter1 = 2;
			}
			clock.restart();
		}
		time1 = clock.getElapsedTime();
		if (counter1 == 1)
		{
			clock.restart();
			x_position += (x_velocity * time1.asSeconds());
			y_velocity += (y_accel * time1.asSeconds());
			y_position += (y_velocity * time1.asSeconds());
			projectile.setPosition(x_position, y_position);
		}
		if (counter1 == 2)
		{
			clock.restart();
			a_position += (-x_velocity * time1.asSeconds());
			y_velocity += (y_accel * time1.asSeconds());
			y_position += (y_velocity * time1.asSeconds());
			projectile.setPosition(a_position, y_position);
		}
		if (y_position > 810 || x_position > 1410 || a_position < -10)
		{
			x_position = 0;
			y_position = 690;
			x_velocity = 180;
			y_accel = 120;
			y_velocity = -400;
			a_position = 1390;
			counter1 = 0;
			turn = !turn;
		}
	}
}