////////////////////////////////////////////////////////////////////////////////
// Filename: controls.c
////////////////////////////////////////////////////////////////////////////////
#include "controls.h"




void heldKey()//CHECKS IF KEYS ARE HELD, NOT USED AS I FOUND THIS DIDNT WORK TOO WELL
{
	scanKeys();
	u16 keyHeld = keysHeld();

	if (keyHeld == KEY_UP)
	{
		player.upPressed = true;
	}
	else if (keyHeld != KEY_UP)
	{
		player.upPressed = false;
	}
	if (keyHeld == KEY_DOWN)
	{
		player.downPressed = true;
	}
	else if (keyHeld != KEY_DOWN)
	{
		player.downPressed = false;
	}
	if (keyHeld == KEY_LEFT)
	{
		player.leftPressed = true;
	}
	else if (keyHeld != KEY_LEFT)
	{
		player.leftPressed = false;
	}
	if (keyHeld == KEY_RIGHT)
	{
		player.rightPressed = true;
	}
	else if (keyHeld != KEY_RIGHT)
	{
		player.rightPressed = false;
	}
	if (keyHeld == KEY_A)
	{
		
	}
	if (keyHeld == KEY_B)
	{

	}
	if (keyHeld == KEY_START)
	{

	}
	if (keyHeld == KEY_SELECT)
	{

	}
}
void keyUsed()//CHECKS IF KEYS ARE BEING USED
{
	//---------------------------------- SOUND EFFECTS ----------------------------------

	scanKeys();
	u16 keyDown = keysDown();
	u16 keyUp = keysUp();

	if (keyUp == KEY_UP)///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// KEY UP - UP
	{
		player.upPressed = false;
		Menu.upPressed = false;
		currentState = IDLE;
	}
	if (keyUp == KEY_DOWN)///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// KEY DOWN - UP
	{
		player.downPressed = false;
		Menu.downPressed = false;
		currentState = IDLE;

	}
	if (keyUp == KEY_LEFT)///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// KEY LEFT - UP
	{
		player.leftPressed = false;
		currentState = IDLE;
	}
	if (keyUp == KEY_RIGHT)///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// KEY RIGHT - UP
	{
		player.rightPressed = false;
		currentState = IDLE;
	}
	if (keyUp == KEY_A)///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// KEY A - UP
	{
		Menu.aPressed = false;
		player.aPressed = false;
	}
	if (keyUp == KEY_B)///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// KEY B - UP
	{
		Menu.bPressed = false;
		player.bPressed = false;
	}
	if (keyUp == KEY_START)///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// KEY START - UP
	{
		Menu.startPressed = false;
		player.startPressed = false;
	}
	if (keyUp == KEY_SELECT)///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// KEY SELECT - UP
	{
		Menu.selectPressed = false;
		player.selectPressed = false;
	}
	if (keyDown == KEY_UP)///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// KEY UP - DOWN
	{

		if (gameState == playing)//---------------------------------- PLAY SCREEN ----------------------------------
		{

			if (playState == map)
			{	
				currentState = UP;
				player.spriteRef = 40;
				player.frame = 0;
				player.upPressed = true;		//SETS THE PLAYERS UPPRESSED BOOL TO TRUE (FOR USE MOVING THE PLAYER)

			}
			if (playState == battle)
			{
				if (battleState == playerTurn)
				{
					if (battleMenuPos == attack && Menu.upPressed == false)
					{
						Menu.upPressed = true;
						clear_function(BATTLEMENUMID - 1, BATTLEMENUY, 4);
						draw_function(BATTLEMENUMID - 1, BATTLEMENUY + 3, 4, 0, ARROW);
						battleMenuPos = run;
					}
					if (battleMenuPos == abilityMenuPos && Menu.upPressed == false)
					{
						Menu.upPressed = true;
						clear_function(BATTLEMENUMID - 1, BATTLEMENUY + 1, 4);
						draw_function(BATTLEMENUMID - 1, BATTLEMENUY, 4, 0, ARROW);
						battleMenuPos = attack;
					}
					if (battleMenuPos == itemMenuPos && Menu.upPressed == false)
					{
						Menu.upPressed = true;
						clear_function(BATTLEMENUMID - 1, BATTLEMENUY + 2, 4);
						draw_function(BATTLEMENUMID - 1, BATTLEMENUY + 1, 4, 0, ARROW);
						battleMenuPos = abilityMenuPos;
					}
					if (battleMenuPos == run && Menu.upPressed == false)
					{
						Menu.upPressed = true;
						clear_function(BATTLEMENUMID - 1, BATTLEMENUY + 3, 4);
						draw_function(BATTLEMENUMID - 1, BATTLEMENUY + 2, 4, 0, ARROW);
						battleMenuPos = itemMenuPos;
					}
				}
				if (battleState == playerAttack)
				{
					if (enemyBattlePos == top && Menu.upPressed == false)
					{
						Menu.upPressed = true;
						clear_function(22, 4, 4);
						draw_function(22, 11, 4, 0, ARROW);
						enemyBattlePos = bottom;
					}
					if (enemyBattlePos == middle && Menu.upPressed == false && enemy[Battle.enemyRef].numberInGroup == 3)
					{
						Menu.upPressed = true;
						clear_function(22, 7, 4);
						draw_function(22, 4, 4, 0, ARROW);
						enemyBattlePos = top;
					}
					if (enemyBattlePos == bottom && Menu.upPressed == false)
					{
						if (enemy[Battle.enemyRef].numberInGroup == 2)
						{
							Menu.upPressed = true;
							clear_function(22, 11, 4);
							draw_function(22, 4, 4, 0, ARROW);
							enemyBattlePos = top;
						}
						if (enemy[Battle.enemyRef].numberInGroup == 3)
						{
							
							Menu.upPressed = true;
							clear_function(22, 11, 4);
							draw_function(22, 7, 4, 0, ARROW);
							enemyBattlePos = middle;
						}

					}
				}
				if (battleState == itemMenu)
				{
					if (itemPos == item1 && Menu.upPressed == false)
					{
						Menu.upPressed = true;
						clear_function(4, 6, 4);
						draw_function(4, 7, 4, 0, ARROW);
						itemPos = item2;
					}
					if (itemPos == item2 && Menu.upPressed == false)
					{
						Menu.upPressed = true;
						clear_function(4, 7, 4);
						draw_function(4, 6, 4, 0, ARROW);
						itemPos = item1;
					}
				}
			}
		}
		//----------------------------------THE UP KEY IS USED IN THE MENU FOR NAVIGATION----------------------------------
		if (gameState == menu)//---------------------------------- MENU SCREEN ----------------------------------
		{
			if (menuP == menuOptions && Menu.upPressed == false)	//CHANGES THE CURRENT MENU POSITION BASED ON ITS CURRENT POSITION AND THE MENU ITEM ABOVE IT
			{
				Menu.upPressed = true;
				clear_function(MENUX - 1, MENUY + 1, 9);
				draw_function(MENUX - 1, MENUY, 9, 0, ARROW);
				menuP = nG;
			}
			if (menuP == nG && Menu.upPressed == false)
			{
				Menu.upPressed = true;
				clear_function(MENUX - 1, MENUY, 9);
				draw_function(MENUX - 1, MENUY + 1, 9, 0, ARROW);
				menuP = menuOptions;
			}
		}
		if (gameState == exit)//---------------------------------- EXIT SCREEN ----------------------------------
		{
			if (exitM == yes && Menu.upPressed == false)
			{
				Menu.upPressed = true;
				clear_function(MENUX - 1, MENUY + 2, 9);
				draw_function(MENUX - 1, MENUY + 1, 9, 0, ARROW);
				exitM = no;
			}
			if (exitM == no && Menu.upPressed == false)
			{
				Menu.upPressed = true;
				clear_function(MENUX - 1, MENUY + 1, 9);
				draw_function(MENUX - 1, MENUY + 2, 9, 0, ARROW);
				exitM = yes;
			}
		}
		if (gameState == options)//---------------------------------- OPTIONS SCREEN ----------------------------------
		{
			if (optionP == option2 && Menu.upPressed == false)
			{
				Menu.upPressed = true;
				clear_function(MENUX - 1, MENUY + 1, 9);
				draw_function(MENUX - 1, MENUY, 9, 0, ARROW);
				optionP = option1;
			}
			if (optionP == option1 && Menu.upPressed == false)
			{
				Menu.upPressed = true;
				clear_function(MENUX - 1, MENUY, 9);
				draw_function(MENUX - 1, MENUY + 1, 9, 0, ARROW);
				optionP = option2;
			}
		}
		if (gameState == inGameMenu)//---------------------------------- INGAMEMENU SCREEN ----------------------------------
		{
			
			if (playerMenu == mainMenu)//---------------------------------- INGAMEMENU - MAIN MENU ----------------------------------
			{
				if (playerMenuPos == inventoryPos && Menu.upPressed == false)
				{
					Menu.upPressed = true;
					clear_function(PLAYERMENUSTARTX - 1, PLAYERMENUSTARTY + 1, 4);
					draw_function(PLAYERMENUSTARTX - 1, PLAYERMENUSTARTY + 6, 4, 0, ARROW);
					playerMenuPos = optionsMenuPos;
				}
				if (playerMenuPos == abilitiesPos && Menu.upPressed == false)
				{
					Menu.upPressed = true;
					clear_function(PLAYERMENUSTARTX - 1, PLAYERMENUSTARTY + 2, 4);
					draw_function(PLAYERMENUSTARTX - 1, PLAYERMENUSTARTY + 1, 4, 0, ARROW);
					playerMenuPos = inventoryPos;
				}
				if (playerMenuPos == equipmentPos && Menu.upPressed == false)
				{
					Menu.upPressed = true;
					clear_function(PLAYERMENUSTARTX - 1, PLAYERMENUSTARTY + 3, 4);
					draw_function(PLAYERMENUSTARTX - 1, PLAYERMENUSTARTY + 2, 4, 0, ARROW);
					playerMenuPos = abilitiesPos;
				}
				if (playerMenuPos == statusPos && Menu.upPressed == false)
				{
					Menu.upPressed = true;
					clear_function(PLAYERMENUSTARTX - 1, PLAYERMENUSTARTY + 4, 4);
					draw_function(PLAYERMENUSTARTX - 1, PLAYERMENUSTARTY + 3, 4, 0, ARROW);
					playerMenuPos = equipmentPos;
				}
				if (playerMenuPos == partyPos && Menu.upPressed == false)
				{
					Menu.upPressed = true;
					clear_function(PLAYERMENUSTARTX - 1, PLAYERMENUSTARTY + 5, 4);
					draw_function(PLAYERMENUSTARTX - 1, PLAYERMENUSTARTY + 4, 4, 0, ARROW);
					playerMenuPos = statusPos;
				}
				if (playerMenuPos == optionsMenuPos && Menu.upPressed == false)
				{
					Menu.upPressed = true;
					clear_function(PLAYERMENUSTARTX - 1, PLAYERMENUSTARTY + 6, 4);
					draw_function(PLAYERMENUSTARTX - 1, PLAYERMENUSTARTY + 5, 4, 0, ARROW);
					playerMenuPos = partyPos;
				}
			}
			if (playerMenu == inventory)//---------------------------------- INGAMEMENU - INVENTORY ----------------------------------
			{
				if (itemPos == item1 && Menu.upPressed == false)
				{
					Menu.upPressed = true;
					clear_function(4, 6, 4);
					draw_function(4, 11, 4, 0, ARROW);
					itemPos = item6;
				}
				if (itemPos == item2 && Menu.upPressed == false)
				{
					Menu.upPressed = true;
					clear_function(4, 7, 4);
					draw_function(4, 6, 4, 0, ARROW);
					itemPos = item1;
				}
				if (itemPos == item3 && Menu.upPressed == false)
				{
					Menu.upPressed = true;
					clear_function(4, 8, 4);
					draw_function(4, 7, 4, 0, ARROW);
					itemPos = item2;
				}
				if (itemPos == item4 && Menu.upPressed == false)
				{
					Menu.upPressed = true;
					clear_function(4, 9, 4);
					draw_function(4, 8, 4, 0, ARROW);
					itemPos = item3;
				}
				if (itemPos == item5 && Menu.upPressed == false)
				{
					Menu.upPressed = true;
					clear_function(4, 10, 4);
					draw_function(4, 9, 4, 0, ARROW);
					itemPos = item4;
				}
				if (itemPos == item6 && Menu.upPressed == false)
				{
					Menu.upPressed = true;
					clear_function(4, 11, 4);
					draw_function(4, 10, 4, 0, ARROW);
					itemPos = item5;
				}
			}
			if (playerMenu == equipment)//---------------------------------- INGAMEMENU - EQUIPMENT ----------------------------------
			{
				if (equipPos == equip1 && Menu.upPressed == false)
				{
					Menu.upPressed = true;
					clear_function(4, 6, 4);
					draw_function(4, 9, 4, 0, ARROW);
					equipPos = equip4;
				}
				if (equipPos == equip2 && Menu.upPressed == false)
				{
					Menu.upPressed = true;
					clear_function(4, 7, 4);
					draw_function(4, 6, 4, 0, ARROW);
					equipPos = equip1;
				}
				if (equipPos == equip3 && Menu.upPressed == false)
				{
					Menu.upPressed = true;
					clear_function(4, 8, 4);
					draw_function(4, 7, 4, 0, ARROW);
					equipPos = equip2;
				}
				if (equipPos == equip4 && Menu.upPressed == false)
				{
					Menu.upPressed = true;
					clear_function(4, 9, 4);
					draw_function(4, 8, 4, 0, ARROW);
					equipPos = equip3;
				}
			}
		}
	}
	if (keyDown == KEY_DOWN)///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// KEY DOWN - DOWN
	{

		if (gameState == playing)
		{
			if (playState == map)
			{
				player.spriteRef = 32;
				player.frame = 0;
				currentState = DOWN;
				player.downPressed = true;
			}
			if (playState == battle)
			{
				if (battleState == playerTurn)
				{
					if (battleMenuPos == attack && Menu.downPressed == false)
					{
						Menu.downPressed = true;
						clear_function(BATTLEMENUMID - 1, BATTLEMENUY, 4);
						draw_function(BATTLEMENUMID - 1, BATTLEMENUY + 1, 4, 0, ARROW);
						battleMenuPos = abilityMenuPos;
					}
					if (battleMenuPos == abilityMenuPos && Menu.downPressed == false)
					{
						Menu.downPressed = true;
						clear_function(BATTLEMENUMID - 1, BATTLEMENUY + 1, 4);
						draw_function(BATTLEMENUMID - 1, BATTLEMENUY + 2, 4, 0, ARROW);
						battleMenuPos = itemMenuPos;
					}
					if (battleMenuPos == itemMenuPos && Menu.downPressed == false)
					{
						Menu.downPressed = true;
						clear_function(BATTLEMENUMID - 1, BATTLEMENUY + 2, 4);
						draw_function(BATTLEMENUMID - 1, BATTLEMENUY + 3, 4, 0, ARROW);
						battleMenuPos = run;
					}
					if (battleMenuPos == run && Menu.downPressed == false)
					{
						Menu.downPressed = true;
						clear_function(BATTLEMENUMID - 1, BATTLEMENUY + 3, 4);
						draw_function(BATTLEMENUMID - 1, BATTLEMENUY, 4, 0, ARROW);
						battleMenuPos = attack;
					}
				}
				if (battleState == playerAttack)
				{
					if (enemyBattlePos == top && Menu.downPressed == false)
					{
						if (enemy[Battle.enemyRef].numberInGroup == 2)
						{
							Menu.downPressed = true;
							clear_function(22, 4, 4);
							draw_function(22, 11, 4, 0, ARROW);
							enemyBattlePos = bottom;
						}
						if (enemy[Battle.enemyRef].numberInGroup == 3)
						{
							Menu.downPressed = true;
							clear_function(22, 4, 4);
							draw_function(22, 7, 4, 0, ARROW);
							enemyBattlePos = middle;
						}
					}
					if (enemyBattlePos == middle && Menu.downPressed == false && enemy[Battle.enemyRef].numberInGroup == 3)
					{
						Menu.downPressed = true;
						clear_function(22, 7, 4);
						draw_function(22, 11, 4, 0, ARROW);
						enemyBattlePos = bottom;
					}
					if (enemyBattlePos == bottom && Menu.downPressed == false)
					{
						Menu.downPressed = true;
						clear_function(22, 11, 4);
						draw_function(22, 4, 4, 0, ARROW);
						enemyBattlePos = top;
					}
				}
				if (battleState == itemMenu)
				{
					if (itemPos == item1 && Menu.downPressed == false)
					{
						Menu.downPressed = true;
						clear_function(4, 6, 4);
						draw_function(4, 7, 4, 0, ARROW);
						itemPos = item2;
					}
					if (itemPos == item2 && Menu.downPressed == false)
					{
						Menu.downPressed = true;
						clear_function(4, 7, 4);
						draw_function(4, 6, 4, 0, ARROW);
						itemPos = item1;
					}
				}
			}
		}
		if (gameState == menu)
		{
			if (menuP == nG && Menu.downPressed == false)
			{
				Menu.downPressed = true;
				clear_function(MENUX - 1, MENUY, 9);
				draw_function(MENUX - 1, MENUY + 1, 9, 0, ARROW);
				menuP = menuOptions;
			}
			if (menuP == menuOptions && Menu.downPressed == false)
			{
				Menu.downPressed = true;
				clear_function(MENUX - 1, MENUY+1, 9);
				draw_function(MENUX - 1, MENUY, 9, 0, ARROW);
				menuP = nG;
			}
		}
		if (gameState == exit)
		{
			if (exitM == no && Menu.downPressed == false)
			{
				Menu.downPressed = true;
				clear_function(MENUX - 1, MENUY + 1, 9);
				draw_function(MENUX - 1, MENUY + 2, 9, 0, ARROW);
				exitM = yes;
			}
			if (exitM == yes && Menu.downPressed == false)
			{
				Menu.downPressed = true;
				clear_function(MENUX - 1, MENUY + 2, 9);
				draw_function(MENUX - 1, MENUY + 1, 9, 0, ARROW);
				exitM = no;
			}
		}
		if (gameState == options)
		{
			if (optionP == option1 && Menu.downPressed == false)
			{
				Menu.downPressed = true;
				clear_function(MENUX - 1, MENUY, 9);
				draw_function(MENUX - 1, MENUY + 1, 9, 0, ARROW);
				optionP = option2;
			}
			if (optionP == option2 && Menu.downPressed == false)
			{
				Menu.downPressed = true;
				clear_function(MENUX - 1, MENUY + 1, 9);
				draw_function(MENUX - 1, MENUY, 9, 0, ARROW);
				optionP = option1;
			}
		}
		if (gameState == inGameMenu)
		{
			if (playerMenu == mainMenu)
			{
				if (playerMenuPos == inventoryPos && Menu.downPressed == false)
				{
					Menu.downPressed = true;
					clear_function(PLAYERMENUSTARTX - 1, PLAYERMENUSTARTY + 1, 4);
					draw_function(PLAYERMENUSTARTX - 1, PLAYERMENUSTARTY + 2, 4, 0, ARROW);
					playerMenuPos = abilitiesPos;
				}
				if (playerMenuPos == abilitiesPos && Menu.downPressed == false)
				{
					Menu.downPressed = true;
					clear_function(PLAYERMENUSTARTX - 1, PLAYERMENUSTARTY + 2, 4);
					draw_function(PLAYERMENUSTARTX - 1, PLAYERMENUSTARTY + 3, 4, 0, ARROW);
					playerMenuPos = equipmentPos;
				}
				if (playerMenuPos == equipmentPos && Menu.downPressed == false)
				{
					Menu.downPressed = true;
					clear_function(PLAYERMENUSTARTX - 1, PLAYERMENUSTARTY + 3, 4);
					draw_function(PLAYERMENUSTARTX - 1, PLAYERMENUSTARTY + 4, 4, 0, ARROW);
					playerMenuPos = statusPos;
				}
				if (playerMenuPos == statusPos && Menu.downPressed == false)
				{
					Menu.downPressed = true;
					clear_function(PLAYERMENUSTARTX - 1, PLAYERMENUSTARTY + 4, 4);
					draw_function(PLAYERMENUSTARTX - 1, PLAYERMENUSTARTY + 5, 4, 0, ARROW);
					playerMenuPos = partyPos;
				}
				if (playerMenuPos == partyPos && Menu.downPressed == false)
				{
					Menu.downPressed = true;
					clear_function(PLAYERMENUSTARTX - 1, PLAYERMENUSTARTY + 5, 4);
					draw_function(PLAYERMENUSTARTX - 1, PLAYERMENUSTARTY + 6, 4, 0, ARROW);
					playerMenuPos = optionsMenuPos;
				}
				if (playerMenuPos == optionsMenuPos && Menu.downPressed == false)
				{
					Menu.downPressed = true;
					clear_function(PLAYERMENUSTARTX - 1, PLAYERMENUSTARTY + 6, 4);
					draw_function(PLAYERMENUSTARTX - 1, PLAYERMENUSTARTY + 1, 4, 0, ARROW);
					playerMenuPos = inventoryPos;
				}
			}
			if (playerMenu == inventory)
			{
				if (itemPos == item1 && Menu.downPressed == false)
				{
					Menu.downPressed = true;
					clear_function(4, 6, 4);
					draw_function(4, 7, 4, 0, ARROW);
					itemPos = item2;
				}
				if (itemPos == item2 && Menu.downPressed == false)
				{
					Menu.downPressed = true;
					clear_function(4, 7, 4);
					draw_function(4, 8, 4, 0, ARROW);
					itemPos = item3;
				}
				if (itemPos == item3 && Menu.downPressed == false)
				{
					Menu.downPressed = true;
					clear_function(4, 8, 4);
					draw_function(4, 9, 4, 0, ARROW);
					itemPos = item4;
				}
				if (itemPos == item4 && Menu.downPressed == false)
				{
					Menu.downPressed = true;
					clear_function(4, 9, 4);
					draw_function(4, 10, 4, 0, ARROW);
					itemPos = item5;
				}
				if (itemPos == item5 && Menu.downPressed == false)
				{
					Menu.downPressed = true;
					clear_function(4, 10, 4);
					draw_function(4, 11, 4, 0, ARROW);
					itemPos = item6;
				}
				if (itemPos == item6 && Menu.downPressed == false)
				{
					Menu.downPressed = true;
					clear_function(4, 11, 4);
					draw_function(4, 6, 4, 0, ARROW);
					itemPos = item1;
				}
			}
			if (playerMenu == equipment)
			{
				if (equipPos == equip1 && Menu.downPressed == false)
				{
					Menu.downPressed = true;
					clear_function(4, 6, 4);
					draw_function(4, 7, 4, 0, ARROW);
					equipPos = equip2;
				}
				if (equipPos == equip2 && Menu.downPressed == false)
				{
					Menu.downPressed = true;
					clear_function(4, 7, 4);
					draw_function(4, 8, 4, 0, ARROW);
					equipPos = equip3;
				}
				if (equipPos == equip3 && Menu.downPressed == false)
				{
					Menu.downPressed = true;
					clear_function(4, 8, 4);
					draw_function(4, 9, 4, 0, ARROW);
					equipPos = equip4;
				}
				if (equipPos == equip4 && Menu.downPressed == false)
				{
					Menu.downPressed = true;
					clear_function(4, 9, 4);
					draw_function(4, 6, 4, 0, ARROW);
					equipPos = equip1;
				}
			}

		}

	}
	if (keyDown == KEY_LEFT)///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// KEY LEFT - DOWN
	{
		if (gameState == playing)
		{
			if (playState == map)
			{
				player.spriteRef = 52;
				player.frame = 0;
				currentState = LEFT;
				player.leftPressed = true;
			}
			
		}
	}
	if (keyDown == KEY_RIGHT) ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// KEY RIGHT - DOWN
	{
		if (gameState == playing)
		{
			if (playState == map)
			{
				player.spriteRef = 46;
				player.frame = 0;
				currentState = RIGHT;
				player.rightPressed = true;
			}
		}
	}
	if (keyDown == KEY_A) ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// KEY A - DOWN
	{
		if (gameState == menu)
		{
			clearCharacters();//CLEARS CHARACTERS

			if (menuP == nG)
			{
				playSFX(33);
				mmStop();
				music = false;
				clearObjects();
				player.lives = PLAYER_MAX_LIVES;
				gameState = setup;
				Menu.arrow = false;
				setupLevel(player.levelNumber);
				//asm("mov r0,r0");
			}
			if (menuP == menuOptions)
			{
				playSFX(33);
				clearObjects();
				Menu.arrow = false;
				optionP = option1;
				gameState = options;
				//asm("mov r0,r0");
			}
		}
		if (gameState == dead)
		{
			if (player.lives <= 0)
			{
				mmStop();
				music = false;
				clearObjects();
				clearCharacters();
				gameState = gameOver;
			}
			else
			{
				mmStop();
				music = false;
				player.alive = true;
				clearObjects();
				clearCharacters();
				gameState = setup;
				setupLevel(player.levelNumber);
			}
		}
		if (gameState == gameOver)
		{
			playSFX(33);
			clearObjects();
			clearCharacters();
			player.lives = PLAYER_MAX_LIVES;
			player.score = 0;
			gameState = setup;
			setupLevel(player.level);
		}
		if (gameState == pause)
		{
			mmResume();
			playerStart();
			enemyStart();
			clearCharacters();
			gameState = playing;
		}
		if (gameState == exit)
		{
			if (exitM == no)
			{
				playSFX(33);
				Menu.arrow = false;
				clearCharacters();
				gameState = pause;

			}
			if (exitM == yes)
			{
				playSFX(31);
				clearCharacters();
				clearObjects();
				Menu.arrow = false;
				gameState = splash;
			}
		}
		if (gameState == options)
		{
			if (optionP == option1)
			{
				playSFX(33);
				clearObjects();
				Menu.arrow = false;
				player.levelNumber = 1;
				player.level = 1;
			}
			if (optionP == option2)
			{
				playSFX(33);
				clearObjects();
				Menu.arrow = false;
				player.levelNumber = 2;
				player.level = 2;
			}
		}
		if (gameState == inGameMenu)
		{
			if (playerMenu == mainMenu)
			{
				if (playerMenuPos == inventoryPos && Menu.aPressed == false)
				{
					clearCharacters();
					Menu.aPressed = true;
					Menu.arrow = false;
					itemPos = item1;
					playerMenu = inventory;
				}
				if (playerMenuPos == abilitiesPos && Menu.aPressed == false)
				{
					clearCharacters();
					Menu.aPressed = true;
					Menu.arrow = false;
					playerMenu = abilities;
				}
				if (playerMenuPos == equipmentPos && Menu.aPressed == false)
				{
					clearCharacters();
					Menu.aPressed = true;
					Menu.arrow = false;
					playerMenu = equipment;
				}
				if (playerMenuPos == statusPos && Menu.aPressed == false)
				{
					clearCharacters();
					Menu.aPressed = true;
					Menu.arrow = false;
					playerMenu = status;
				}
				if (playerMenuPos == partyPos && Menu.aPressed == false)
				{
					clearCharacters();
					Menu.aPressed = true;
					Menu.arrow = false;
					playerMenu = party;
				}
				if (playerMenuPos == optionsMenuPos && Menu.aPressed == false)
				{
					clearCharacters();
					Menu.aPressed = true;
					Menu.arrow = false;
					playerMenu = optionsMenu;
				}
			}
			if (playerMenu == inventory)
			{
				if (itemPos == item1 && Menu.aPressed == false)
				{
					Menu.aPressed = true;
					if (player.currentHP < player.maxHP)
					{
						int hpPOTSTR = 50;
						subNumber(&items[1].numberOfItems);
						add1Number(&player.currentHP, &hpPOTSTR);
						if (player.currentHP > player.maxHP)
						{
							player.currentHP = player.maxHP;
						}
					}

				}
				if (itemPos == item2 && Menu.aPressed == false)
				{
					Menu.aPressed = true;
					if (player.currentMP < player.maxMP)
					{
						int mpPOTSTR = 20;
						subNumber(&items[2].numberOfItems);
						add1Number(&player.currentMP, &mpPOTSTR);
						if (player.currentMP > player.maxMP)
						{
							player.currentMP = player.maxMP;
						}
					}

				}
			}
			if (playerMenu == equipment)
			{
				if (equipPos == equip1 && Menu.aPressed == false && items[3].inUse == true)
				{
					Menu.aPressed = true;
					items[3].inUse = false;
					calcStats(3);
				}
				if (equipPos == equip1 && Menu.aPressed == false && items[3].inUse == false)
				{
					Menu.aPressed = true;
					items[3].inUse = true;
					calcStats(3);
				}
				if (equipPos == equip2 && Menu.aPressed == false && items[4].inUse == true)
				{
					Menu.aPressed = true;
					items[4].inUse = false;
					calcStats(4);
				}
				if (equipPos == equip2 && Menu.aPressed == false && items[4].inUse == false)
				{
					Menu.aPressed = true;
					items[4].inUse = true;
					calcStats(4);
				}
				if (equipPos == equip3 && Menu.aPressed == false && items[5].inUse == true)
				{
					Menu.aPressed = true;
					items[5].inUse = false;
					calcStats(5);
				}
				if (equipPos == equip3 && Menu.aPressed == false && items[5].inUse == false)
				{
					Menu.aPressed = true;
					items[5].inUse = true;
					calcStats(5);
				}
				if (equipPos == equip4 && Menu.aPressed == false && items[6].inUse == true)
				{
					Menu.aPressed = true;
					items[6].inUse = false;
					calcStats(6);
				}
				if (equipPos == equip4 && Menu.aPressed == false && items[6].inUse == false)
				{
					Menu.aPressed = true;
					items[6].inUse = true;
					calcStats(6);
				}
			}
		}
		if (gameState == playing)
		{
			if (playState == battle)
			{

				if (battleMenuPos == attack && battleState == playerTurn && Menu.aPressed == false)
				{
					clear_function(BATTLEMENUMID - 1, BATTLEMENUY, 4); //draw the arrow and set its poistion
					Menu.aPressed = true;
					Menu.arrow = false;
					battleState = playerAttack;
					enemyBattlePos = top;
				}
				if (battleMenuPos == abilityMenuPos && battleState == playerTurn && Menu.aPressed == false)
				{
					Menu.aPressed = true;
					//battleState = abilityMenu;
					//itemPos = item1;
				}
				if (battleMenuPos == run && battleState == playerTurn && Menu.aPressed == false)
				{
					playSFX(31);
					Menu.aPressed = true;
					Menu.arrow = false;
					battleState = running;
					gameState = playing;							//changes the current gameState to playing 
					playState = map;
					player.spriteRef = 32;
					clearCharacters();
					clearObjects();
				

				//	playersetup(player.levelNumber);				//Sets the players variables to their default values (playerStruct.c - L10)
					playerStart();									//Sets the player to being alive, sets the position to be on screen and enables the player (system.c - L433)
					//enemySetupMap(player.levelNumber);				//sets the enemies variables to default values for positioning on the map screen
					enemyStart();
				}
				if (battleMenuPos == itemMenuPos && battleState == playerTurn && Menu.aPressed == false)
				{
					Menu.aPressed = true;
					battleState = itemMenu;
					clear_function(BATTLEMENUMID - 1, BATTLEMENUY + 2, 4);
					Menu.arrow = false;
					itemPos = item1;
				}
				if (battleState == playerAttack && Menu.aPressed == false)
				{

				
					Menu.aPressed = true;
					battleState = playerAttacking;
					currentState = attacking;
					Battle.frame = 0;
					Menu.arrow = false;
				}

				if (battleState == itemMenu)
				{
					if (itemPos == item1 && Menu.aPressed == false)
					{
						Menu.aPressed = true;
						if (player.currentHP < player.maxHP)
						{
							playSFX(33);
							int hpPOTSTR = 50;
							subNumber(&items[1].numberOfItems);
							add1Number(&player.currentHP, &hpPOTSTR);
							if (player.currentHP > player.maxHP)
							{
								player.currentHP = player.maxHP;
							}
							battleState = enemyAttack;
							clearCharacters();
							Menu.arrow = false;
							battleMenuPos = attack;

						}

					}
					if (itemPos == item2 && Menu.aPressed == false)
					{
						Menu.aPressed = true;
						if (player.currentMP < player.maxMP)
						{
							playSFX(33);
							int mpPOTSTR = 20;
							subNumber(&items[2].numberOfItems);
							add1Number(&player.currentMP, &mpPOTSTR);
							if (player.currentMP > player.maxMP)
							{
								player.currentMP = player.maxMP;
							}
							battleState = enemyAttack;
							clearCharacters();
							Menu.arrow = false;
							battleMenuPos = attack;
						}

					}
				}
			}
			if (playState == battleEnd)//---------------------------------- BATTLEEND (PLAYSTATE) ----------------------------------
			{
				if (player.aPressed == false)
				{
					playSFX(33);
					clearCharacters();
					clearObjects();
					player.aPressed = true;
					gameState = setup;
				}
			}
		}
		
	}
	if (keyDown == KEY_B)///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// KEY B - DOWN
	{
		if (gameState == gameOver)
		{
			playSFX(31);
			Menu.arrow = false;
			player.score = 0;
			clearCharacters();
			clearObjects();
			gameState = menu;
		}
		if (gameState == pause && Menu.bPressed == false)
		{
			playSFX(31);
			clearCharacters();
			Menu.bPressed = true;
			Menu.arrow = false;
			exitM = no;
			gameState = exit;
		}
		if (gameState == exit  && Menu.bPressed == false)
		{
			playSFX(31);
			clearCharacters();
			Menu.bPressed = true;
			gameState = pause;
		}
		if (gameState == options)
		{
			clearObjects();
			clearCharacters();
			Menu.arrow = false;
			menuP = nG;
			gameState = menu;
		}
		if (gameState == inGameMenu)
		{
			if (playerMenu == mainMenu)
			{
				mmResume();
				enemyStart();
				playerStart();
				clearCharacters();
				Menu.arrow = false;
				playerMenuPos = inventoryPos;
				gameState = playing;
				mmResume();
			}
			if (playerMenu != mainMenu)
			{
				clearCharacters();
				Menu.arrow = false;
				equipPos = equip1;
				itemPos = item1;
				playerMenuPos = inventoryPos;
				playerMenu = mainMenu;				
			}
		}
		if (gameState == playing)
		{
			if (playState == battle)
			{
				if (battleState == playerAttack)
				{
					playSFX(31);
					clearCharacters();
					battleState = playerTurn;
					Menu.arrow = false;
				}
				if (battleState == abilityMenu)
				{
					battleState = playerTurn;
				}
				if (battleState == running)
				{
					battleState = playerTurn;
				}
				if (battleState == itemMenu)
				{
					battleMenuPos = attack;
					Menu.arrow = false;
					clearCharacters();
					battleState = playerTurn;
				}
			}
		}
	}
	if (keyDown == KEY_START)///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// KEY START - DOWN
	{
		if (gameState == splash)
		{
			playSFX(33);
			mmStop();
			music = false;
			clearCharacters();
			Menu.arrow = false;
			menuP = nG;
			gameState = menu;
		}
		if (gameState == playing && Menu.startPressed == false && playState == map)
		{
			mmPause();
			Menu.startPressed = true;
			player.positionX = *player.xPos;
			player.positionY = *player.yPos;
			gameState = pause;
		}
		if (gameState == pause && Menu.startPressed == false)
		{
			mmResume();
			Menu.startPressed = true;
			clearCharacters();
			enemyStart();
			playerStart();
			gameState = playing;
		}
		if (gameState == dead)
		{
			if (player.lives <= 0)
			{
				clearObjects();
				clearCharacters();
				gameState = gameOver;
			}
			else
			{
				player.alive = true;
				clearObjects();
				clearCharacters();
				gameState = setup;
				setupLevel(player.levelNumber);
			}
		}
		if (gameState == gameOver)
		{
			playSFX(33);
			clearObjects();
			clearCharacters();
			player.lives = PLAYER_MAX_LIVES;
			player.score = 0;
			gameState = setup;
			setupLevel(player.level);
		}
	}
	if (keyDown == KEY_SELECT) ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// KEY SELECT - DOWN
	{
		if (gameState == gameOver)
		{
			Menu.arrow = false;
			player.score = 0;
			clearCharacters();
			clearObjects();
			gameState = menu;
		}
		if (gameState == playing && Menu.selectPressed == false && playState == map)
		{
			mmPause();
			Menu.selectPressed = true;
			player.positionX = *player.xPos;
			player.positionY = *player.yPos;
			clearCharacters();
			gameState = inGameMenu;
			playerMenu = mainMenu;
		}
		if (gameState == inGameMenu && Menu.selectPressed == false)
		{
			mmResume();
			Menu.selectPressed = true;
			playerStart();
			enemyStart();
			clearCharacters();
			Menu.arrow = false;
			playerMenuPos = inventoryPos;
			gameState = playing;
		}
	}

	moveCheck();

}
