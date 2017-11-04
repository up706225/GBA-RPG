////////////////////////////////////////////////////////////////////////////////
// Filename: playerstruct.h
////////////////////////////////////////////////////////////////////////////////

/////////////////
// My INCLUDES //
/////////////////
#include "playerstruct.h"

void playersetup(int levelNumber)
{
	//SETS UP PLAYERS DEFAULT INFO
	player.objectRef = 1;
	player.spriteRef = 32;
	player.frame = 0;
	player.upPressed = false;
	player.downPressed = false;
	player.leftPressed = false;
	player.rightPressed = false;
	player.startPressed = false;
	player.selectPressed = false;
	player.aPressed = false;
	player.bPressed = false;
	player.step = false;
	player.lives = player.lives;
	player.alive = true;
	player.level = levelNumber;
	player.size = 0;
	player.shape = 2;
	player.rotation_scaling_flag = 0;
	player.horFlip = 0;
	player.verFlip = 0;
	player.rotation_scaling_paramaters = 0;
	player.totalMaxHP = 9999;
	player.totalMaxMP = 999;
	player.baseDefence = 40;
	player.MaxDefence = 999;
	player.MaxDamage = 999;
	player.MaxLevel = 99;
	player.MaxStrength = 255;
	player.MaxAgility = 255;
	player.MaxIntelligence = 255;
	player.MaxEndurance = 255;
	statCheck();
	calcDamDef();
	player.currentHP = player.maxHP;
	player.currentMP = player.maxMP;
	player.headArmour = false;
	player.chestArmour = false;
	player.legArmour = false;
	player.weapon = false;
	itemSetup();
}
void playersetupBattle(int levelNumber)
{
	//SETS UP PLAYERS DEFAULT INFO for battles
	player.objectRef = 1;
	player.spriteRef = 66;
	player.battleXPos = 5;
	player.battleYPos = 10;
	player.upPressed = false;
	player.downPressed = false;
	player.leftPressed = false;
	player.rightPressed = false;
	player.startPressed = false;
	player.selectPressed = false;
	player.aPressed = false;
	player.bPressed = false;
	player.lives = player.lives;
	player.alive = true;
	player.level = levelNumber;
	player.size = 0;
	player.shape = 2;
	player.rotation_scaling_flag = 0;
	player.horFlip = 0;
	player.verFlip = 0;
	player.rotation_scaling_paramaters = 0;

}
void itemSetup()
{
	items[1].ItemName = HPpotion;
	items[1].itemsName = "HP Potion";
	items[1].ItemType = potion;
	items[1].numberOfItems = 5;
	items[1].value = 5;
	items[1].inUse = false;
	items[1].visible = true;
	items[1].itemPos = 0;
	items[2].ItemName = MPpotion;
	items[2].itemsName = "MP Potion";
	items[2].ItemType = potion;
	items[2].numberOfItems = 5;
	items[2].value = 5;
	items[2].inUse = false;
	items[2].visible = true;
	items[2].itemPos = 1;
	items[3].ItemName = leatherHat;
	items[3].itemsName = "Leather Hat";
	items[3].ItemType = hat;
	items[3].numberOfItems = 1;
	items[3].value = 50;
	items[3].inUse = false;
	items[3].visible = true;
	items[3].defence = 10;
	items[3].itemPos = 2;
	items[4].ItemName = leatherChest;
	items[4].itemsName = "Leather Chest";
	items[4].ItemType = chest;
	items[4].numberOfItems = 1;
	items[4].value = 50;
	items[4].inUse = false;
	items[4].visible = true;
	items[4].defence = 20;
	items[4].itemPos = 3;
	items[5].ItemName = leatherLegs;
	items[5].itemsName = "Leather Legs";
	items[5].ItemType = legs;
	items[5].numberOfItems = 1;
	items[5].value = 50;
	items[5].inUse = false;
	items[5].visible = true;
	items[5].defence = 10;
	items[5].itemPos = 4;
	items[6].ItemType = rustySword;
	items[6].itemsName = "Rusty Sword";
	items[6].ItemType = sword;
	items[6].numberOfItems = 1;
	items[6].value = 50;
	items[6].inUse = false;
	items[6].visible = true;
	items[6].damage = 15;
	items[6].itemPos = 5;
}