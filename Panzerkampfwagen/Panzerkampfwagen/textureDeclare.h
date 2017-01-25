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


	textureDeclare(){
		cout << "Got Here";
		if (!player1lefttexture.loadFromFile("Wizard_Red_Left.png"))
		{
			// error...
			cout << "Got Here1";
		}
		if (!player2lefttexture.loadFromFile("Wizard_Blue_Left.png"))
		{
			// error...
			cout << "Got Here2";
		}
		if (!player1righttexture.loadFromFile("Wizard_Red_Right.png"))
		{
			// error...
			cout << "Got Here3";
		}
		if (!player2righttexture.loadFromFile("Wizard_Blue_Right.png"))
		{
			// error...
			cout << "Got Here4";
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

		//player1lefttexture.loadFromFile("Wizard_Red_Left.png");
		//player2lefttexture.loadFromFile("Wizard_Blue_Left.png");
		//player1righttexture.loadFromFile("Wizard_Red_Right.png");
		//player2righttexture.loadFromFile("Wizard_Blue_Right.png");
		//arm1lefttexture.loadFromFile("Wizard_Red_Arm_Left.png");
		//arm1righttexture.loadFromFile("Wizard_Red_Arm_Right.png");
		//arm2righttexture.loadFromFile("Wizard_Blue_Arm_Right.png");
		//arm2lefttexture.loadFromFile("Wizard_Blue_Arm_Left.png");

	}
};