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
	Texture fireball;
	Texture hidden;

	textureDeclare(){
		if (!player1lefttexture.loadFromFile("Wizard_Red_Left.png")){  }
		if (!player2lefttexture.loadFromFile("Wizard_Blue_Left.png")){  }
		if (!player1righttexture.loadFromFile("Wizard_Red_Right.png")){  }
		if (!player2righttexture.loadFromFile("Wizard_Blue_Right.png")){  }
		if (!arm1lefttexture.loadFromFile("Wizard_Red_Arm_Left.png")){  }
		if (!arm1righttexture.loadFromFile("Wizard_Red_Arm_Right.png")){  }
		if (!arm2righttexture.loadFromFile("Wizard_Blue_Arm_Right.png")){  }
		if (!arm2lefttexture.loadFromFile("Wizard_Blue_Arm_Left.png")){  }
		if (!fireball.loadFromFile("fireBall.png")){  }
		if (!hidden.loadFromFile("Hidden.png")){  }
	}

};