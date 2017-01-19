#ifndef textureDeclare_HEADER
#define textureDeclare_HEADER

#include "includeLibs.h"

class textureDeclare
{
public:
	Texture player1lefttexture;
	Texture player2lefttexture;
	Texture player1righttexture;
	Texture player2righttexture;
	Texture arm1lefttexture;
	Texture arm1righttexture;
	Texture arm2righttexture;
	Texture arm2lefttexture;


	void getTextures(){

		if (!player1lefttexture.loadFromFile("Wizard_Red_Left.png"))
		{
			// error...
		}
		if (!player2lefttexture.loadFromFile("Wizard_Blue_Left.png"))
		{
			// error...
		}
		if (!player1righttexture.loadFromFile("Wizard_Red_Right.png"))
		{
			// error...
		}
		if (!player2righttexture.loadFromFile("Wizard_Blue_Right.png"))
		{
			// error...
		}
		if (!arm1lefttexture.loadFromFile("Wizard_Red_Arm_Left.png"))
		{
			// error...
		}
		if (!arm1righttexture.loadFromFile("Wizard_Red_Arm_Right.png"))
		{
			// error...
		}
		if (!arm2righttexture.loadFromFile("Wizard_Blue_Arm_Right.png"))
		{
			// error...
		}
		if (!arm2lefttexture.loadFromFile("Wizard_Blue_Arm_Left.png"))
		{
			//error...
		}
	}
};


#endif