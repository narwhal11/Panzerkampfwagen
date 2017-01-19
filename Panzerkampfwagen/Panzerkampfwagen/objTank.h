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
	int angle;
	bool hasmoved = false;

	RectangleShape tank;
	objProjec mainProj;

	void moveTank(bool left)
	{
		if (left == true){
			x_pos += -.1;
		}
		if (left == false){
			x_pos += .1;
		}
	}


};