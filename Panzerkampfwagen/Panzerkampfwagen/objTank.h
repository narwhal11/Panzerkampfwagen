#include "objProjec.h"

class objTank
{
public:
	string name;
	double x_pos;
	int y_pos;
	int angle;

	RectangleShape tank;
	objProjec mainProj;

	void moveTank(bool left)
	{
		if (left == true){
			x_pos += -.01;
		}
		if (left == false){
			x_pos += .01;
		}
	}


};