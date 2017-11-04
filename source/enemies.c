////////////////////////////////////////////////////////////////////////////////
// Filename: enemies.c
////////////////////////////////////////////////////////////////////////////////

/////////////////
// My INCLUDES //
/////////////////
#include "enemies.h"

void enemySetupMap(int levelNumber)
{
	int z = enemyNumberFunction();
	int e;
	//SETS UP ALL ENEMIES DEFAULT INFO
	for (e = 0; e < (NUMBER_OF_ENEMIES + z); e++)
	{
		enemy[e].objectRef = (ENEMY_OBJECT_START + e);
		enemy[e].mapSpriteRef = 79;
		enemy[e].preNumberInGroup = enemy[e].numberInGroup;

		enemy[e].upMove = false;
		enemy[e].downMove = false;
		enemy[e].leftMove = false;
		enemy[e].rightMove = false;
		//enemy[e].direction = random(0);
		enemy[e].lastX = *enemy[e].xPos;
		enemy[e].lastY = *enemy[e].yPos;
		enemy[e].nextMove = 50;
		//enemy[e].alive = true;
		enemy[e].spriteRef = enemy[e].mapSpriteRef;
		enemy[e].size = 0;
		enemy[e].shape = 0;
		enemy[e].rotation_scaling_flag = 0;
		enemy[e].horFlip = 0;
		enemy[e].verFlip = 0;
		enemy[e].rotation_scaling_paramaters = 0;
		enemy[e].xP = 100;
		
	}
}
void enemySetupBattle(int levelNumber,int groupNumber)
{
	int e;
	//SETS UP ALL ENEMIES DEFAULT INFO
	for (e = 0; e < (enemy[groupNumber].numberInGroup); e++)
	{
		enemy[groupNumber].enemyBattle[e].objectRef = (ENEMY_BATTLE_START + e);
		enemy[groupNumber].enemyBattle[e].battleSpriteRef = 83;
		enemy[groupNumber].enemyBattle[e].spriteRef = enemy[groupNumber].enemyBattle[e].battleSpriteRef;
		enemy[groupNumber].enemyBattle[e].refNumber = enemy[groupNumber].refNumber;
		enemy[groupNumber].enemyBattle[e].attacked = false;
		enemy[groupNumber].enemyBattle[e].upMove = false;
		enemy[groupNumber].enemyBattle[e].downMove = false;
		enemy[groupNumber].enemyBattle[e].leftMove = false;
		enemy[groupNumber].enemyBattle[e].rightMove = false;
		enemy[groupNumber].enemyBattle[e].maxHP = enemy[groupNumber].maxHP;
		enemy[groupNumber].enemyBattle[e].damage = enemy[groupNumber].damage = 10;
		enemy[groupNumber].enemyBattle[e].defence = enemy[groupNumber].defence = 40;
		//enemy[groupNumber].enemyBattle[e].currentHP = enemy[groupNumber].currentHP;
		enemy[groupNumber].enemyBattle[e].xPGive = enemy[groupNumber].xP * enemy[groupNumber].numberInGroup;
		//enemy[groupNumber].enemy[e].direction = random(0);
		enemy[groupNumber].enemyBattle[e].lastX = *enemy[groupNumber].enemyBattle[e].xPos;
		enemy[groupNumber].enemyBattle[e].lastY = *enemy[groupNumber].enemyBattle[e].yPos;
		enemy[groupNumber].enemyBattle[e].nextMove = 50;
		enemy[groupNumber].enemyBattle[e].alive = true;
		enemy[groupNumber].enemyBattle[e].lives = enemy[groupNumber].enemyBattle[e].numberInGroup;
		enemy[groupNumber].enemyBattle[e].enable = 0;
		enemy[groupNumber].enemyBattle[e].size = 1;
		enemy[groupNumber].enemyBattle[e].shape = 0;
		enemy[groupNumber].enemyBattle[e].rotation_scaling_flag = 0;
		enemy[groupNumber].enemyBattle[e].horFlip = 0;
		enemy[groupNumber].enemyBattle[e].verFlip = 0;
		enemy[groupNumber].enemyBattle[e].rotation_scaling_paramaters = 0;

	}
}