#include "objProjec.h"

class objTank
{
public:
	string name;
	int x_pos;
	int y_pos;
	int angle;

	RectangleShape tank;
	objProjec mainProj;

	void moveTank()
	{
		x_pos += 100;
	}


};