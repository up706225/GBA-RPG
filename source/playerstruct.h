////////////////////////////////////////////////////////////////////////////////
// Filename: playerstruct.h
////////////////////////////////////////////////////////////////////////////////
#ifndef PLAYERSTRUCT_H_
#define PLAYERSTRUCT_H_

/////////////////
// My INCLUDES //
/////////////////
#include "systemincludes.h"
//---------------------------------------------------------------------------------
// FUNCTION DECLERATIONS
//---------------------------------------------------------------------------------
void itemSetup();
void statCheck();
void calcDamDef();
//players class
// *****************
// Player 
// *****************

typedef struct Players
{
	unsigned short *xPos;
	unsigned short *yPos;
	int spriteRef; //players sprite
	int objectRef; //players object ref
	bool alive; //player alive on/off
	int frame;
	int battleSpriteRef;
	int mapSpriteRef;

	bool upPressed;
	bool downPressed;
	bool leftPressed;
	bool rightPressed;
	bool aPressed;
	bool bPressed;
	bool selectPressed;
	bool startPressed;
	bool step;
	unsigned short positionX;
	unsigned short positionY;
	unsigned short playerBattlePosX;
	unsigned short playerBattlePosY;
	int lives; //remaining lives
	int level; //current level
	int levelNumber;
	int score; //current score
	int time; //current time (not acurate)
	int enable;
	int size;
	int shape;
	int rotation_scaling_flag;
	int horFlip;
	int verFlip;
	int rotation_scaling_paramaters;
	int MaxLevel;
	int totalMaxHP;
	int totalMaxMP;

	int MaxDefence;
	int MaxDamage;

	int MaxStrength;
	int MaxAgility;
	int MaxIntelligence;
	int MaxEndurance;

	int maxHP;
	int maxMP;
	int currentHP;
	int currentMP;
	int xP;
	int nextLevel;
	int currentLevel;

	int oldXP;
	int oldLevel;

	int battleXPos;
	int battleYPos;
	int strength;
	int agility;
	int intelligence;
	int endurance;
	int baseDefence;
	bool headArmour;
	int headArmourRef;
	bool chestArmour;
	int chestArmourRef;
	bool legArmour;
	int legArmourRef;
	bool weapon;
	int weaponRef;

	int defence;
	int damage;
	int armourDefence;
	int weaponDamage;

} Player;
Player player;
enum playerCurrentState{
	idle,
	up,
	down,
	left,
	right,
	attacking,
	enemyAnimation,
	battleIdle,

}currentState;
typedef struct Items
{
	enum itemType{
		potion,
		hat,
		chest,
		legs,
		sword,
	}ItemType;
	enum itemName
	{
		HPpotion,
		MPpotion,
		leatherChest,
		leatherHat,
		leatherLegs,
		rustySword,
	}ItemName;
	char* itemsName;
	int numberOfItems;
	bool inUse;
	bool visible;
	int value;
	int defence;
	int damage;
	int itemPos;
	int currentItemPos;

}item;
item items[50];

#endif 
