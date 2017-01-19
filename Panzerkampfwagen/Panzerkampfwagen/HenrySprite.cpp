#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

class wizard
{
public:
};
int main(){
	sf::RenderWindow window(sf::VideoMode(1400, 800), "SFML Application");

	int turn = 1;
	wizard player1;
	wizard player2;
	player1.facingleft = true;
	player1.bodysprite.setTexture(player1lefttexture);
	player1.xposition = 1000;
	player1.yposition = 556;
	//player1.bodysprite.scale(sf::Vector2f(4.f, 4.f));
	//player1.bodysprite.setOrigin(64, 108);
	//player1.armsprite.scale(sf::Vector2f(4.f, 4.f));
	player2.facingleft = false;
	player2.bodysprite.setTexture(player2righttexture);
	player2.xposition = 300;
	player2.yposition = 556;
	//player2.bodysprite.scale(sf::Vector2f(4.f, 4.f));
	//player2.armsprite.scale(sf::Vector2f(4.f, 4.f));
	sf::RectangleShape sky(sf::Vector2f(1400, 600));
	sky.setFillColor(sf::Color(135, 206, 250));
	//sky.setFillColor(sf::Color(0, 0, 0)); //Space Background
	sky.setPosition(0, 0);
	sf::RectangleShape ground(sf::Vector2f(1400, 200));
	ground.setFillColor(sf::Color(34, 139, 34));
	//ground.setFillColor(sf::Color(155, 155, 155)); //Space Background
	ground.setPosition(0, 600);
	window.setFramerateLimit(480);
	while (window.isOpen()){

		sf::Event event;
		while (window.pollEvent(event)){

			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			if (turn == 1)
			{
				player1.xposition = player1.xposition - 1;
				if (player1.facingleft == false)
				{
					player1.armsprite.setRotation(180 - (player1.armsprite.getRotation() - 180));
				}
				player1.facingleft = true;
				player1.hasmoved = true;
			}
			if (turn == 2)
			{
				player2.xposition = player2.xposition - 1;
				if (player2.facingleft == false)
				{
					player2.armsprite.setRotation(180 - (player2.armsprite.getRotation() - 180));
				}
				player2.facingleft = true;
				player2.hasmoved = true;
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			if (turn == 1)
			{
				player1.xposition = player1.xposition + 1;
				if (player1.facingleft == true)
				{
					player1.armsprite.setRotation(180 - (player1.armsprite.getRotation() - 180));
				}
				player1.facingleft = false;
				player1.hasmoved = true;
			}
			if (turn == 2)
			{
				player2.xposition = player2.xposition + 1;
				if (player2.facingleft == true)
				{
					player2.armsprite.setRotation(180 - (player2.armsprite.getRotation() - 180));
				}
				player2.facingleft = false;
				player2.hasmoved = true;
			}
		}
		player1.bodysprite.setPosition(player1.xposition, player1.yposition);
		player2.bodysprite.setPosition(player2.xposition, player2.yposition);
		if (player1.facingleft == true)
		{
			if (turn == 1)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				{
					if (player1.armsprite.getRotation() != 90)
					{
						player1.armsprite.rotate(1);
					}
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				{
					if (player1.armsprite.getRotation() != 270)
					{
						player1.armsprite.rotate(-1);
					}

				}
			}
			player1.bodysprite.setTexture(player1lefttexture);
			player1.armsprite.setTexture(arm1lefttexture);
			player1.armsprite.setOrigin(23, 2);
			player1.armsprite.setPosition(player1.xposition + 16, player1.yposition + 27);
		}
		if (player2.facingleft == true)
		{
			if (turn == 2)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				{
					if (player2.armsprite.getRotation() != 90)
					{
						player2.armsprite.rotate(1);
					}
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				{
					if (player2.armsprite.getRotation() != 270)
					{
						player2.armsprite.rotate(-1);
					}
				}
			}
			player2.bodysprite.setTexture(player2lefttexture);
			player2.armsprite.setTexture(arm2lefttexture);
			player2.armsprite.setOrigin(23, 2);
			player2.armsprite.setPosition(player2.xposition + 16, player2.yposition + 27);
		}
		if (player1.facingleft == false)
		{
			if (turn == 1)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				{
					if (player1.armsprite.getRotation() != 270)
					{
						player1.armsprite.rotate(-1);
					}
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				{
					if (player1.armsprite.getRotation() != 90)
					{
						player1.armsprite.rotate(1);
					}
				}
			}
			player1.bodysprite.setTexture(player1righttexture);
			player1.armsprite.setTexture(arm1righttexture);
			player1.armsprite.setOrigin(0, 2);
			player1.armsprite.setPosition(player1.xposition + 12, player1.yposition + 27);
		}
		if (player2.facingleft == false)
		{
			if (turn == 2)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				{
					if (player2.armsprite.getRotation() != 270)
					{
						player2.armsprite.rotate(-1);
					}
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				{
					if (player2.armsprite.getRotation() != 90)
					{
						player2.armsprite.rotate(1);
					}
				}
			}
			player2.bodysprite.setTexture(player2righttexture);
			player2.armsprite.setTexture(arm2righttexture);
			player2.armsprite.setOrigin(0, 2);
			player2.armsprite.setPosition(player2.xposition + 12, player2.yposition + 27);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			//cout << player1.armsprite.getRotation() << endl;
			if (turn == 1)
			{
				if (player1.hasmoved == true)
				{
					turn = 2;
					player2.hasmoved = false;
				}

			}
			if (turn == 2)
			{
				if (player2.hasmoved == true)
				{
					turn = 1;
					player1.hasmoved = false;
				}

			}
		}

		window.draw(sky);
		window.draw(ground);
		window.draw(player1.bodysprite);
		window.draw(player1.armsprite);
		window.draw(player2.bodysprite);
		window.draw(player2.armsprite);
		window.display();
	}

}