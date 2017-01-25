#include "objProjec.h"

class objTank
{
public:
	string name;
	double x_pos;
	int y_pos;
	int angle;
	Sprite bodysprite;
	Sprite armsprite;
	bool facingleft;
	bool hasmoved = false;
	textureDeclare texDec;

	objProjec mainProj;

	objTank(textureDeclare texD)
	//objTank()
	{
		texDec = texD;
		bodysprite.setTexture(texDec.player1lefttexture);
	}

	void moveTank(bool left)
	{
		if (Keyboard::isKeyPressed(Keyboard::Left)){
			x_pos += -.1;
			bodysprite.setTexture(texDec.player1lefttexture);
		}
		if (Keyboard::isKeyPressed(Keyboard::Right)){
			x_pos += .1;
			bodysprite.setTexture(texDec.player1righttexture);
		}
	}


};