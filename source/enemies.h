////////////////////////////////////////////////////////////////////////////////
// Filename: enemies.h
////////////////////////////////////////////////////////////////////////////////
#ifndef ENEMIES_H_
#define ENEMIES_H_

/////////////////
// My INCLUDES //
/////////////////
#include "systemincludes.h"
void battlePosFunction(int numberInGroup);
void levelSelectFunction();
int enemyNumberFunction();

typedef struct EnemiesBattle
{
	unsigned short *xPos;
	unsigned short *yPos;
	int spriteRef; //players sprite
	int objectRef; //players object ref
	bool alive; //player alive on/off

	bool upMove;
	bool downMove;
	bool leftMove;
	bool rightMove;
	int xStart;
	int yStart;
	int battleXPos;
	int battleYPos;
	int direction;
	short lastX;
	short lastY;
	int nextMove;
	
	int numberInGroup;
	int battleSpriteRef;
	int mapSpriteRef;

	unsigned short positionX;
	unsigned short positionY;
	int lives; //remaining lives
	int level; //current level
	int levelNumber;
	int time; //current time (not acurate)
	int enable;
	int size;
	int shape;
	int rotation_scaling_flag;
	int horFlip;
	int verFlip;
	int rotation_scaling_paramaters;
	bool attacked;
	int maxHP;
	int maxMP;
	int currentHP;
	int currentMP;
	int xPGive;
	int xP;
	int currentLevel;
	int refNumber;
	int defence;
	int damage;

}enemiesBattle;
typedef struct Enemies
{
	unsigned short *xPos;
	unsigned short *yPos;
	int spriteRef; //players sprite
	int objectRef; //players object ref
	bool alive; //player alive on/off

	bool upMove;
	bool downMove;
	bool leftMove;
	bool rightMove;
	int xStart;
	int yStart;
	int battleXPos;
	int battleYPos;
	int direction;
	short lastX;
	short lastY;
	int nextMove;

	int preNumberInGroup;
	int numberInGroup;
	int battleSpriteRef;
	int mapSpriteRef;

	unsigned short positionX;
	unsigned short positionY;
	int lives; //remaining lives
	int level; //current level
	int levelNumber;
	int time; //current time (not acurate)
	int enable;
	int size;
	int shape;
	int rotation_scaling_flag;
	int horFlip;
	int verFlip;
	int rotation_scaling_paramaters;

	int maxHP;
	int maxMP;
	int currentHP;
	int currentMP;
	int xPGive;
	int xP;
	int currentLevel;
	int refNumber;
	int defence;
	int damage;
	enemiesBattle enemyBattle[3];
}enemies;
enemies enemy[NUMBER_OF_ENEMIES];
#endif