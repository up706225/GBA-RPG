////////////////////////////////////////////////////////////////////////////////
// Filename: game.h
////////////////////////////////////////////////////////////////////////////////
#include "game.h"
void runGame()
{
	runAnimation(player.objectRef, player.spriteRef, currentState, player.step);
	if (gameState == splash) //---------------------------------- SPLASH SCREEN ----------------------------------
	{


		
		if (music == false)								//checks to see if music is already running
		{
			mmStart(MOD_SPLASH_SND, MM_PLAY_ONCE);	//If no music is running, it plays this on a loop
			music = true;								//Sets the bool music to be true, to indicate that music is currently running
		}
								//This function checks if keys are in use (controls.c - L63)
		int z = enemyNumberFunction();
		int e;
		//SETS UP ALL ENEMIES DEFAULT INFO
		for (e = 0; e < (NUMBER_OF_ENEMIES + z); e++)
		{
			enemy[e].alive = true;
		}
				setupFunction();								//setup function (system.c - L14)
		player.levelNumber = 1;							//sets the current levelNumber to 1, this was used in an older iteration to distinguish between different levels
		drawSplash();									//function to draw the splash screen (current - L537)
		keyUsed();		
	}

	if (gameState == menu)//---------------------------------- MENU ----------------------------------
	{
		if (music == false)
		{
			mmStart(MOD_MENU_SND, MM_PLAY_ONCE);
			music = true;
		}
		drawMenu();										//function to draw the Menu (current - L551)
		keyUsed();
	}

	if (gameState == setup) //---------------------------------- SETUP ----------------------------------
	{
		playersetup(player.levelNumber);				//Sets the players variables to their default values (playerStruct.c - L10)
		playerStart();									//Sets the player to being alive, sets the position to be on screen and enables the player (system.c - L433)
		enemySetupMap(player.levelNumber);				//sets the enemies variables to default values for positioning on the map screen
		enemyStart();									//
		gameState = playing;							//changes the current gameState to playing 
		playState = map;								//sets the current playState to the map screen
		currentState = IDLE;
	}

	if (gameState == playing) //---------------------------------- PLAYING ----------------------------------
	{
		if (playState == map)
		{
			

		//	player.spriteRef = 32;

			//drawOtherfunction(1, 1, 20, 0, 33);
			keyUsed();
			// *****************
			//PLAYER ALIVE/DEAD
			// *****************
			//switch (player.alive)						//checks if the player is alive
			//{
			//case true:									//if alive, the player will be displayed on screen
			//	myObj_function(player.objectRef, *player.yPos, player.rotation_scaling_flag, player.enable, 0, player.shape, *player.xPos, player.rotation_scaling_paramaters, player.horFlip, player.verFlip, player.size, player.spriteRef, SPRITE_PRIORITY, 0, 0);
			//	break;

			//case false:									//if dead, the screen will be cleared of characters and the gamestate switched to dead
			//	clearCharacters();
			//	gameState = dead;

			//	break;
			//}
			//runAnimation(player.objectRef, player.spriteRef, 0);
			ifAlive(&player.alive, &player.enable);
			myObj_function(player.objectRef, *player.yPos, player.rotation_scaling_flag, player.enable, 0, player.shape, *player.xPos, player.rotation_scaling_paramaters, player.horFlip, player.verFlip, player.size, player.spriteRef, SPRITE_PRIORITY, 0, 0);
			if (player.alive == false)
			{
					clearCharacters();
					gameState = dead;
			}
			int a;
			int z = enemyNumberFunction();
			for (a = 0; a < NUMBER_OF_ENEMIES + z; a++)
			{
				if (enemy[a].numberInGroup == 0 && enemy[a].enemyBattle[0].alive == false)
				{
					enemy[a].alive = false;
				}				
				

				switch (enemy[a].alive)
				{
				case true:
					
					//enemy ai, this is used for the enemy movement
					//enemyAI(enemy[a].objectRef, a);
					//enemy object function, same as the players
					myObj_function(enemy[a].objectRef, *enemy[a].yPos, enemy[a].rotation_scaling_flag, enemy[a].enable, 0, enemy[a].shape, *enemy[a].xPos, enemy[a].rotation_scaling_paramaters, enemy[a].horFlip, enemy[a].verFlip, enemy[a].size, enemy[a].spriteRef, SPRITE_PRIORITY, 0, 0);
					break;

				case false:
					//if an enemy dies, do this. Not currently used as enemies cannot die
					enemy[a].enable = 1;
					enemy[a].upMove = false;
					enemy[a].downMove = false;
					enemy[a].leftMove = false;
					enemy[a].rightMove = false;
					myObj_function(enemy[a].objectRef, 240, enemy[a].rotation_scaling_flag, enemy[a].enable, 0, enemy[a].shape, 240, enemy[a].rotation_scaling_paramaters, enemy[a].horFlip, enemy[a].verFlip, enemy[a].size, enemy[a].spriteRef, SPRITE_PRIORITY, 0, 0);
					break;
				}

			}

		}
		if (playState == battleSetup)
		{
			playersetupBattle(player.levelNumber);				//sets the players for the battle, this changes size, position
			playerStart();
			enemySetupBattle(1, Battle.enemyRef);				//sets the enemies up for battle, similarly to player
		
			playState = battle;
		}
		if (playState == battle) //---------------------------------- BATTLE (PLAYSTATE) ----------------------------------
		{
			//draw_function(3, 7, 4, 0, 18);

			battlePosFunction(enemy[Battle.enemyRef].numberInGroup);


			if (player.currentHP <= 0)
			{
				player.currentHP = 0;
				player.alive = false;
			}
			mmStop();
			if (music == false)
			{
				//mmStart(MOD_BATTLE_SND, MM_PLAY_LOOP);
				music = true;
			}
			int a;
		
			drawMenuBG(BATTLEMENUSTARTX, BATTLEMENUSTARTY, BATTLEMENUENDX, BATTLEMENUENDY,11);	//draws the battle menu background

									
			ifAlive(&player.alive, &player.enable);//ASM ALIVE FUNCTION, if the player is not alive, it disables the player
			
			if (player.alive == false)
			{
				gameState = gameOver;
			}

			myObj_function(player.objectRef, YBATTLESTART, player.rotation_scaling_flag, player.enable, 0, player.shape, XBATTLESTART, player.rotation_scaling_paramaters, player.horFlip, player.verFlip, player.size, player.spriteRef, SPRITE_PRIORITY, 0, 0);//draws the player object at current location

			for (a = 0; a < enemy[Battle.enemyRef].numberInGroup; a++)
			{
				
				if (enemy[Battle.enemyRef].enemyBattle[a].currentHP <= 0)
				{
					enemy[Battle.enemyRef].enemyBattle[a].alive = false;
				}
				ifAlive(&player.alive, &enemy[Battle.enemyRef].enemyBattle[a].enable);//ASM ALIVE FUNCTION, if the enemy is not alive, it disables the enemy
				myObj_function(enemy[Battle.enemyRef].enemyBattle[a].objectRef, *enemy[Battle.enemyRef].enemyBattle[a].yPos, enemy[Battle.enemyRef].enemyBattle[a].rotation_scaling_flag, enemy[Battle.enemyRef].enemyBattle[a].enable, 0, enemy[Battle.enemyRef].enemyBattle[a].shape, *enemy[Battle.enemyRef].enemyBattle[a].xPos, enemy[Battle.enemyRef].enemyBattle[a].rotation_scaling_paramaters, enemy[Battle.enemyRef].enemyBattle[a].horFlip, enemy[Battle.enemyRef].enemyBattle[a].verFlip, enemy[Battle.enemyRef].enemyBattle[a].size, enemy[Battle.enemyRef].enemyBattle[a].spriteRef, SPRITE_PRIORITY, 0, 0);
				if (enemy[Battle.enemyRef].enemyBattle[a].alive == false)				//checks if the enemy is alive
				{
					if (a == 0)
					{
						if (enemy[enemy[Battle.enemyRef].enemyBattle[a].refNumber].numberInGroup == 1)
						{
							enemy[Battle.enemyRef].enemyBattle[0].enable = 1;
							enemy[enemy[Battle.enemyRef].enemyBattle[a].refNumber].numberInGroup = 0;
							myObj_function(enemy[Battle.enemyRef].enemyBattle[a].objectRef, 240,enemy[Battle.enemyRef].enemyBattle[a].rotation_scaling_flag,enemy[Battle.enemyRef].enemyBattle[a].enable, 0,enemy[Battle.enemyRef].enemyBattle[a].shape, 240,enemy[Battle.enemyRef].enemyBattle[a].rotation_scaling_paramaters,enemy[Battle.enemyRef].enemyBattle[a].horFlip,enemy[Battle.enemyRef].enemyBattle[a].verFlip,enemy[Battle.enemyRef].enemyBattle[a].size,enemy[Battle.enemyRef].enemyBattle[a].spriteRef, SPRITE_PRIORITY, 0, 0);

							playState = setupEnd;
						}
						if (enemy[enemy[Battle.enemyRef].enemyBattle[a].refNumber].numberInGroup == 2)
						{
							enemy[Battle.enemyRef].enemyBattle[0] = enemy[Battle.enemyRef].enemyBattle[1];
							enemy[Battle.enemyRef].enemyBattle[1].enable = 1;
							myObj_function(enemy[Battle.enemyRef].enemyBattle[1].objectRef, 240,enemy[Battle.enemyRef].enemyBattle[1].rotation_scaling_flag,enemy[Battle.enemyRef].enemyBattle[1].enable, 0,enemy[Battle.enemyRef].enemyBattle[1].shape, 240,enemy[Battle.enemyRef].enemyBattle[1].rotation_scaling_paramaters,enemy[Battle.enemyRef].enemyBattle[1].horFlip,enemy[Battle.enemyRef].enemyBattle[1].verFlip,enemy[Battle.enemyRef].enemyBattle[1].size,enemy[Battle.enemyRef].enemyBattle[1].spriteRef, SPRITE_PRIORITY, 0, 0);
							enemy[enemy[Battle.enemyRef].enemyBattle[a].refNumber].numberInGroup = 1;
							enemySetupBattle(1, enemy[enemy[Battle.enemyRef].enemyBattle[a].refNumber].numberInGroup);
						}
						if (enemy[enemy[Battle.enemyRef].enemyBattle[a].refNumber].numberInGroup == 3)
						{
							enemy[Battle.enemyRef].enemyBattle[0] = enemy[Battle.enemyRef].enemyBattle[1];
							enemy[Battle.enemyRef].enemyBattle[1] = enemy[Battle.enemyRef].enemyBattle[2];
							enemy[Battle.enemyRef].enemyBattle[2].enable = 1;
							myObj_function(enemy[Battle.enemyRef].enemyBattle[2].objectRef, 240,enemy[Battle.enemyRef].enemyBattle[2].rotation_scaling_flag,enemy[Battle.enemyRef].enemyBattle[2].enable, 0,enemy[Battle.enemyRef].enemyBattle[2].shape, 240,enemy[Battle.enemyRef].enemyBattle[2].rotation_scaling_paramaters,enemy[Battle.enemyRef].enemyBattle[2].horFlip,enemy[Battle.enemyRef].enemyBattle[2].verFlip,enemy[Battle.enemyRef].enemyBattle[2].size,enemy[Battle.enemyRef].enemyBattle[2].spriteRef, SPRITE_PRIORITY, 0, 0);
							enemy[enemy[Battle.enemyRef].enemyBattle[a].refNumber].numberInGroup = 2;
							enemySetupBattle(1, enemy[enemy[Battle.enemyRef].enemyBattle[a].refNumber].numberInGroup);
						}


						
					}
					if (a == 1)
					{
						if (enemy[enemy[Battle.enemyRef].enemyBattle[a].refNumber].numberInGroup == 2)
						{
							enemy[Battle.enemyRef].enemyBattle[1].enable = 1;
							myObj_function(enemy[Battle.enemyRef].enemyBattle[a].objectRef, 240,enemy[Battle.enemyRef].enemyBattle[a].rotation_scaling_flag,enemy[Battle.enemyRef].enemyBattle[a].enable, 0,enemy[Battle.enemyRef].enemyBattle[a].shape, 240,enemy[Battle.enemyRef].enemyBattle[a].rotation_scaling_paramaters,enemy[Battle.enemyRef].enemyBattle[a].horFlip,enemy[Battle.enemyRef].enemyBattle[a].verFlip,enemy[Battle.enemyRef].enemyBattle[a].size,enemy[Battle.enemyRef].enemyBattle[a].spriteRef, SPRITE_PRIORITY, 0, 0);
							enemy[enemy[Battle.enemyRef].enemyBattle[a].refNumber].numberInGroup = 1;
							enemySetupBattle(1, enemy[enemy[Battle.enemyRef].enemyBattle[a].refNumber].numberInGroup);
						}
						if (enemy[enemy[Battle.enemyRef].enemyBattle[a].refNumber].numberInGroup == 3)
						{
							enemy[Battle.enemyRef].enemyBattle[1] = enemy[Battle.enemyRef].enemyBattle[2];
							enemy[Battle.enemyRef].enemyBattle[2].enable = 1;
							myObj_function(enemy[Battle.enemyRef].enemyBattle[2].objectRef, 240,enemy[Battle.enemyRef].enemyBattle[2].rotation_scaling_flag,enemy[Battle.enemyRef].enemyBattle[2].enable, 0,enemy[Battle.enemyRef].enemyBattle[2].shape, 240,enemy[Battle.enemyRef].enemyBattle[2].rotation_scaling_paramaters,enemy[Battle.enemyRef].enemyBattle[2].horFlip,enemy[Battle.enemyRef].enemyBattle[2].verFlip,enemy[Battle.enemyRef].enemyBattle[2].size,enemy[Battle.enemyRef].enemyBattle[2].spriteRef, SPRITE_PRIORITY, 0, 0);
							enemy[enemy[Battle.enemyRef].enemyBattle[a].refNumber].numberInGroup = 2;
							enemySetupBattle(1, enemy[enemy[Battle.enemyRef].enemyBattle[a].refNumber].numberInGroup);
						}
	
						
					}
					if (a == 2)
					{
						enemy[Battle.enemyRef].enemyBattle[2].enable = 1;
						enemy[enemy[Battle.enemyRef].enemyBattle[a].refNumber].numberInGroup = 2;
						enemySetupBattle(1, enemy[enemy[Battle.enemyRef].enemyBattle[a].refNumber].numberInGroup);
						myObj_function(enemy[Battle.enemyRef].enemyBattle[2].objectRef, 240,enemy[Battle.enemyRef].enemyBattle[2].rotation_scaling_flag,enemy[Battle.enemyRef].enemyBattle[2].enable, 0,enemy[Battle.enemyRef].enemyBattle[2].shape, 240,enemy[Battle.enemyRef].enemyBattle[2].rotation_scaling_paramaters,enemy[Battle.enemyRef].enemyBattle[2].horFlip,enemy[Battle.enemyRef].enemyBattle[2].verFlip,enemy[Battle.enemyRef].enemyBattle[2].size,enemy[Battle.enemyRef].enemyBattle[2].spriteRef, SPRITE_PRIORITY, 0, 0);
					}
					break;

				}
			}
			if (battleState == playerTurn)				//if the state of the battle is the players turn
			{
				if (Menu.arrow == false && battleMenuPos == attack)
				{
					draw_function(BATTLEMENUMID - 1, BATTLEMENUY, 4, 0, ARROW); //draw the arrow and set its poistion
					battleMenuPos = attack;
					Menu.arrow = true;
				}
			}
			if (battleState == playerAttack)
			{
				displayEnemyHP();
				if (enemy[Battle.enemyRef].numberInGroup == 1)
				{
					draw_function(22, 7, 4, 0, ARROW); //draw the arrow and set its poistion
					enemyBattlePos = middle;
					Menu.arrow = true;
				}
				else
				{
					
					if (Menu.arrow == false && enemyBattlePos == top)
					{
						draw_function(22, 4, 4, 0, ARROW); //draw the arrow and set its poistion
						enemyBattlePos = top;
						Menu.arrow = true;
					}
				}
			}
			if (battleState == playerAttacking)
			{
				displayEnemyHP();
				currentState = attacking;
			}
			if (battleState == enemyAttack)
			{
				int a;
				for (a = 0; a < enemy[Battle.enemyRef].numberInGroup; a++)
				{
					if (enemy[Battle.enemyRef].enemyBattle[a].alive)				//checks if the enemy is alive
					{
						enemy[Battle.enemyRef].enemyBattle[a].attacked = false;
					}
				}
				battleState = enemyAttacking;
				currentState = enemyAnimation;
			}
			if (battleState == enemyAttacking)
			{
				draw_function(9, 0, 4, 0, CHARECAPS);//E
				draw_function(10, 0, 4, 0, CHARNCAPS);//n
				draw_function(11, 0, 4, 0, CHARECAPS);//E
				draw_function(12, 0, 4, 0, CHARMCAPS);//m
				draw_function(13, 0, 4, 0, CHARYCAPS);//y

				draw_function(15, 0, 4, 0, CHARACAPS);//A
				draw_function(16, 0, 4, 0, CHARTCAPS);//T
				draw_function(17, 0, 4, 0, CHARTCAPS);//T
				draw_function(18, 0, 4, 0, CHARACAPS);//A
				draw_function(19, 0, 4, 0, CHARCCAPS);//C
				draw_function(20, 0, 4, 0, CHARKCAPS);//K
			}
			if (battleState == itemMenu)
			{
				player.enable = 1;
				myObj_function(player.objectRef, *player.yPos, player.rotation_scaling_flag, player.enable, 0, player.shape, *player.xPos, player.rotation_scaling_paramaters, player.horFlip, player.verFlip, player.size, player.spriteRef, SPRITE_PRIORITY, 0, 0);
				int a;
				for (a = 0; a < enemy[Battle.enemyRef].numberInGroup; a++)
				{
					enemy[Battle.enemyRef].enemyBattle[a].enable = 1;
					myObj_function(enemy[Battle.enemyRef].enemyBattle[a].objectRef, *enemy[Battle.enemyRef].enemyBattle[a].yPos,enemy[Battle.enemyRef].enemyBattle[a].rotation_scaling_flag,enemy[Battle.enemyRef].enemyBattle[a].enable, 0,enemy[Battle.enemyRef].enemyBattle[a].shape, *enemy[Battle.enemyRef].enemyBattle[a].xPos,enemy[Battle.enemyRef].enemyBattle[a].rotation_scaling_paramaters,enemy[Battle.enemyRef].enemyBattle[a].horFlip,enemy[Battle.enemyRef].enemyBattle[a].verFlip,enemy[Battle.enemyRef].enemyBattle[a].size,enemy[Battle.enemyRef].enemyBattle[a].spriteRef, SPRITE_PRIORITY, 0, 0);
				}
				mmPause();
				drawInventoryMenu();
				drawMenuBG(INVENTORYWINDOWSTARTX, INVENTORYWINDOWSTARTY, INVENTORYWINDOWENDX, INVENTORYWINDOWENDY-3,8);
				if (Menu.arrow == false && itemPos == item1)
				{
					draw_function(INVENTORYSTARTX, INVENTORYSTARTY, 4, 0, ARROW);
					itemPos = item1;
					Menu.arrow = true;
				}
				int i,y = 6;
				for (i = 1; i < 5; i++)
				{
					if (items[i].visible && items[i].ItemType == potion)
					{
						iprintf("\x1b[%d;6H%s", (y + items[i].itemPos), items[i].itemsName);
						iprintf("\x1b[%d;24H%d", (y + items[i].itemPos), items[i].numberOfItems);
						draw_function(y - 1, (y + items[i].itemPos), 4, 0, i);
					}
				}
			}
		
			//	drawBattleSCreen(startXPos, startYPos, endXPos, endYPos);
			//	{
			//startXPos + 2;
			draw_function(BATTLEMENUMID, BATTLEMENUSTARTY + 1, 9, 0, CHARACAPS);//A
			draw_function(BATTLEMENUMID + 1, BATTLEMENUSTARTY + 1, 9, 0, CHART);//t
			draw_function(BATTLEMENUMID + 2, BATTLEMENUSTARTY + 1, 9, 0, CHART);//t
			draw_function(BATTLEMENUMID + 3, BATTLEMENUSTARTY + 1, 9, 0, CHARA);//a
			draw_function(BATTLEMENUMID + 4, BATTLEMENUSTARTY + 1, 9, 0, CHARC);//c
			draw_function(BATTLEMENUMID + 5, BATTLEMENUSTARTY + 1, 9, 0, CHARK);//k

			draw_function(BATTLEMENUMID, BATTLEMENUSTARTY + 2, 9, 0, CHARACAPS);//A
			draw_function(BATTLEMENUMID + 1, BATTLEMENUSTARTY + 2, 9, 0, CHARB);//b
			draw_function(BATTLEMENUMID + 2, BATTLEMENUSTARTY + 2, 9, 0, CHARI);//i
			draw_function(BATTLEMENUMID + 3, BATTLEMENUSTARTY + 2, 9, 0, CHARL);//l
			draw_function(BATTLEMENUMID + 4, BATTLEMENUSTARTY + 2, 9, 0, CHART);//t
			draw_function(BATTLEMENUMID + 5, BATTLEMENUSTARTY + 2, 9, 0, CHARI);//i
			draw_function(BATTLEMENUMID + 6, BATTLEMENUSTARTY + 2, 9, 0, CHARE);//e
			draw_function(BATTLEMENUMID + 7, BATTLEMENUSTARTY + 2, 9, 0, CHARS);//s

			draw_function(BATTLEMENUMID, BATTLEMENUSTARTY + 3, 9, 0, CHARICAPS);//I
			draw_function(BATTLEMENUMID + 1, BATTLEMENUSTARTY + 3, 9, 0, CHART);//T
			draw_function(BATTLEMENUMID + 2, BATTLEMENUSTARTY + 3, 9, 0, CHARE);//E
			draw_function(BATTLEMENUMID + 3, BATTLEMENUSTARTY + 3, 9, 0, CHARM);//M
			draw_function(BATTLEMENUMID + 4, BATTLEMENUSTARTY + 3, 9, 0, CHARS);//T

			draw_function(BATTLEMENUMID, BATTLEMENUSTARTY + 4, 9, 0, CHARRCAPS);//R
			draw_function(BATTLEMENUMID + 1, BATTLEMENUSTARTY + 4, 9, 0, CHARU);//U
			draw_function(BATTLEMENUMID + 2, BATTLEMENUSTARTY + 4, 9, 0, CHARN);//N

			iprintf("\x1b[%d;%dHHP:%d/%d", BATTLEMENUSTARTY + 1, BATTLEMENULEFT, player.currentHP, player.maxHP);
			iprintf("\x1b[%d;%dHMP:%d/%d", BATTLEMENUSTARTY + 2, BATTLEMENULEFT, player.currentMP, player.maxMP);

			keyUsed();
		}

		if (playState == setupEnd)
		{
			clearCharacters();
			clearObjects();
			if (player.currentLevel < player.MaxLevel)
			{
				player.oldXP = player.xP;
				player.oldLevel = player.currentLevel;
				player.xP += (enemy[Battle.enemyRef].xP * enemy[Battle.enemyRef].preNumberInGroup);
				levelCheck();
			}
			playState = battleEnd;
		}
		if (playState == battleEnd)//---------------------------------- BATTLEEND (PLAYSTATE) ----------------------------------
		{

			int startXPos = 3,
				startYPos = 3,
				endXPos = 26,
				endYPos = 17;
			drawMenuBG(startXPos, startYPos, endXPos, endYPos, 9);
			iprintf("\x1b[4;10HLevel: %d", player.currentLevel);
			if (player.currentLevel < player.MaxLevel)
			{
				if (player.currentLevel != player.oldLevel)
				{
					iprintf("\x1b[5;9HLevel Inc: %d", (player.currentLevel - player.oldLevel));
				}

				iprintf("\x1b[9;4HOld XP: %d", player.oldXP);
				iprintf("\x1b[9;17H+ XP: %d", (player.xP - player.oldXP));

				iprintf("\x1b[11;8HCurrent XP:%d", player.xP);
				iprintf("\x1b[13;10HXP Req:%d", player.nextLevel);
			}
			keyUsed();
		}
	}

	if (gameState == gameOver)	//---------------------------------- GAMEOVER ----------------------------------
	{
		player.enable = 1;
		myObj_function(player.objectRef, *player.yPos, player.rotation_scaling_flag, player.enable, 0, player.shape, *player.xPos, player.rotation_scaling_paramaters, player.horFlip, player.verFlip, player.size, player.spriteRef, SPRITE_PRIORITY, 0, 0);
		//CLEARS THE SCREEN
		//clearObjects(); - replaced by ASM ALIVE function, when the player dies, the enemies and the player are disabled in function seperately
		clearCharacters();
		drawGameOver(player.score);
		keyUsed();
		
	}

	if (gameState == pause)//---------------------------------- PAUSED ----------------------------------
	{
		player.enable = 1;
		drawPause();
		myObj_function(player.objectRef, *player.yPos, player.rotation_scaling_flag, player.enable, 0, player.shape, *player.xPos, player.rotation_scaling_paramaters, player.horFlip, player.verFlip, player.size, player.spriteRef, SPRITE_PRIORITY, 0, 0);
		int a;
		for (a = 0; a < NUMBER_OF_ENEMIES; a++)
		{
			enemy[a].enable = 1;
			myObj_function(enemy[a].objectRef, *enemy[a].yPos, enemy[a].rotation_scaling_flag, enemy[a].enable, 0, enemy[a].shape, *enemy[a].xPos, enemy[a].rotation_scaling_paramaters, enemy[a].horFlip, enemy[a].verFlip, enemy[a].size, enemy[a].spriteRef, SPRITE_PRIORITY, 0, 0);
		}
		//stops player from moving after pause is removed
		player.upPressed = false;
		player.downPressed = false;
		player.leftPressed = false;
		player.rightPressed = false;
		keyUsed();
	}

	if (gameState == exit)//---------------------------------- EXIT ----------------------------------
	{
		drawExit();
		keyUsed();
	}

	if (gameState == options)//---------------------------------- OPTIONS ----------------------------------
	{
		drawOptions();
		
		keyUsed();
	}

	if (gameState == inGameMenu)//---------------------------------- INGAMEMENU ----------------------------------
	{
		player.enable = 1;
		myObj_function(player.objectRef, *player.yPos, player.rotation_scaling_flag, player.enable, 0, player.shape, *player.xPos, player.rotation_scaling_paramaters, player.horFlip, player.verFlip, player.size, player.spriteRef, SPRITE_PRIORITY, 0, 0);
		int a;
		for (a = 0; a < NUMBER_OF_ENEMIES; a++)
		{
			enemy[a].enable = 1;
			myObj_function(enemy[a].objectRef, *enemy[a].yPos, enemy[a].rotation_scaling_flag, enemy[a].enable, 0, enemy[a].shape, *enemy[a].xPos, enemy[a].rotation_scaling_paramaters, enemy[a].horFlip, enemy[a].verFlip, enemy[a].size, enemy[a].spriteRef, SPRITE_PRIORITY, 0, 0);
		}
		//draw menu here
		int i;
		drawMenuBG(INVENTORYWINDOWSTARTX, INVENTORYWINDOWSTARTY, INVENTORYWINDOWENDX, INVENTORYWINDOWENDY, 11);
		if (playerMenu == mainMenu)	//---------------------------------- MAIN MENU (INGAMEMENU) ----------------------------------
		{
			if (Menu.arrow == false && playerMenuPos == inventoryPos)
			{
				draw_function(PLAYERMENUSTARTX - 1, PLAYERMENUSTARTY + 1, 4, 0, ARROW);
				playerMenuPos = inventoryPos;
				Menu.arrow = true;
			}
			iprintf("\x1b[8;4HLevel: %d", player.currentLevel);
			iprintf("\x1b[9;4HHP: %d/%d", player.currentHP, player.maxHP); //for some raeson, if I have 2 more iprintf commands, the mmPause function is no longer registered when entering the main menu, this started after I removed other iprintf's from later in the menu, not entirely sure why this was happening...
			iprintf("\x1b[10;4HMP: %d/%d", player.currentMP, player.maxMP);

			iprintf("\x1b[12;4HDAM: %d", player.damage);
			iprintf("\x1b[13;4HDEF: %d", player.defence);

			iprintf("\x1b[15;4HXP Cur: %d", player.xP);
			iprintf("\x1b[16;4HXP Req: %d", player.nextLevel);
			drawMainMenu();
		}
		if (playerMenu == inventory)//---------------------------------- INVENTORY (INGAMEMENU) ----------------------------------
		{

			drawInventoryMenu();
			if (Menu.arrow == false && itemPos == item1)
			{
				draw_function(INVENTORYSTARTX, INVENTORYSTARTY, 4, 0, ARROW);
				itemPos = item1;
				Menu.arrow = true;
			}
			int y = 6;
			for (i = 1; i < 50; i++)
			{
				if (items[i].visible)
				{
					iprintf("\x1b[%d;6H%s", (y + items[i].itemPos), items[i].itemsName);
					iprintf("\x1b[%d;24H%d", (y + items[i].itemPos), items[i].numberOfItems);
				
					draw_function(y-1, (y + items[i].itemPos), 4, 0, i);
				}
			}

		}
		if (playerMenu == abilities)//---------------------------------- ABILITIES (INGAMEMENU) ----------------------------------
		{
			drawAbiliesMenu();
		}
		if (playerMenu == equipment)//---------------------------------- EQUIPMENT (INGAMEMENU) ----------------------------------
		{
			if (Menu.arrow == false && equipPos == equip1)
			{
				draw_function(INVENTORYSTARTX, INVENTORYSTARTY, 4, 0, ARROW);
				equipPos = equip1;
				Menu.arrow = true;
			}
			drawEquipmentMenu();

			for (i = 3; i < 7; i++)
			{

				if (items[i].visible)
				{
					draw_function(INVENTORYSTARTX + 1, (INVENTORYSTARTY + i - 3), 9, 0, i);
					if (items[i].inUse == true)
					{
						draw_function(INVENTORYSTARTX + 1, INVENTORYSTARTY + i - 3, 4, 0, 7);
					}
					if (items[i].inUse == false)
					{
						clear_function(INVENTORYSTARTX + 1, INVENTORYSTARTY + (i - 3), 4);
					}
					
					iprintf("\x1b[%d;6H%s", (INVENTORYSTARTY + i - 3), items[i].itemsName);
					iprintf("\x1b[%d;24H%d", (INVENTORYSTARTY + i - 3), items[i].numberOfItems);
					
					
				}
			}
		}
		if (playerMenu == status)//---------------------------------- STATUS (INGAMEMENU) ----------------------------------
		{
			drawStatusMenu();
			
			iprintf("\x1b[8;4HLevel: %d", player.currentLevel);
			iprintf("\x1b[9;4HHP: %d/%d", player.currentHP, player.maxHP); //for some raeson, if I have 2 more iprintf commands, the mmPause function is no longer registered when entering the main menu, this started after I removed other iprintf's from later in the menu, not entirely sure why this was happening...
			iprintf("\x1b[10;4HMP: %d/%d", player.currentMP, player.maxMP);

			iprintf("\x1b[12;4HDAM: %d", player.damage);
			iprintf("\x1b[13;4HDEF: %d", player.defence);

			iprintf("\x1b[15;4HXP Cur: %d", player.xP);
			iprintf("\x1b[16;4HXP Req: %d", player.nextLevel);

			iprintf("\x1b[9;20HSTR: %d", player.strength);
			iprintf("\x1b[10;20HAGI: %d", player.agility);
			iprintf("\x1b[11;20HINT: %d", player.intelligence);
			iprintf("\x1b[12;20HEND: %d", player.endurance);

		}
		if (playerMenu == party)//---------------------------------- PARTY (INGAMEMENU) ----------------------------------
		{
			drawPartyMenu();
		
		}
		if (playerMenu == optionsMenu)//---------------------------------- OPTIONSMENU (INGAMEMENU) ----------------------------------
		{
			drawOptionsMenu();
		}
		keyUsed();
	}

}
void drawSplash()//DRAWS THE SPLASH SCREEN TEXT
{
	draw_function(PLAYERMENUSTARTX - 7, PLAYERMENUSTARTY - 1, 4, 0, CHARRCAPS);//R
	draw_function(PLAYERMENUSTARTX - 6, PLAYERMENUSTARTY - 1, 4, 0, CHARPCAPS);//p
	draw_function(PLAYERMENUSTARTX - 5, PLAYERMENUSTARTY - 1, 4, 0, CHARGCAPS);//g

	draw_function(PLAYERMENUSTARTX - 3, PLAYERMENUSTARTY - 1, 4, 0, CHARGCAPS);//g
	draw_function(PLAYERMENUSTARTX - 2, PLAYERMENUSTARTY - 1, 4, 0, CHARBCAPS);//b
	draw_function(PLAYERMENUSTARTX - 1, PLAYERMENUSTARTY - 1, 4, 0, CHARACAPS);//A

	draw_function(PLAYERMENUSTARTX + 1, PLAYERMENUSTARTY - 1, 4, 0, CHARCCAPS);//C
	draw_function(PLAYERMENUSTARTX + 2, PLAYERMENUSTARTY - 1, 4, 0, CHARWCAPS);//W
	draw_function(GOSTARTX, GOSTARTY, 9, 0, CHARPCAPS);//P
	draw_function(GOSTARTX + 1, GOSTARTY, 9, 0, CHARU);//U
	draw_function(GOSTARTX + 2, GOSTARTY, 9, 0, CHARS);//S
	draw_function(GOSTARTX + 3, GOSTARTY, 9, 0, CHARH);//H

	draw_function(GOSTARTX + 5, GOSTARTY, 9, 0, CHARSCAPS);//S
	draw_function(GOSTARTX + 6, GOSTARTY, 9, 0, CHART);//T
	draw_function(GOSTARTX + 7, GOSTARTY, 9, 0, CHARA);//A
	draw_function(GOSTARTX + 8, GOSTARTY, 9, 0, CHARR);//R
	draw_function(GOSTARTX + 9, GOSTARTY, 9, 0, CHART);//T
}

void drawMenu()//DRAWS THE MENU SCREEN TEXT
{
	if (Menu.arrow == false && menuP == nG)
	{
		draw_function(MENUX - 1, MENUY, 9, 0, ARROW);
		menuP = nG;
		Menu.arrow = true;
	}

	//DRAWS THE MENU (NEW GAME AND OPTIONS)
	draw_function(MENUX, MENUY, 9, 0, 78);//N
	draw_function(MENUX + 1, MENUY, 9, 0, 69);//E
	draw_function(MENUX + 2, MENUY, 9, 0, 87);//W

	draw_function(MENUX + 4, MENUY, 9, 0, 71);//G
	draw_function(MENUX + 5, MENUY, 9, 0, 65);//A
	draw_function(MENUX + 6, MENUY, 9, 0, 77);//M
	draw_function(MENUX + 7, MENUY, 9, 0, 69);//E


	draw_function(MENUX, MENUY + 1, 9, 0, 79);//O
	draw_function(MENUX + 1, MENUY + 1, 9, 0, 80);//P
	draw_function(MENUX + 2, MENUY + 1, 9, 0, 84);//T
	draw_function(MENUX + 3, MENUY + 1, 9, 0, 73);//I
	draw_function(MENUX + 4, MENUY + 1, 9, 0, 79);//O
	draw_function(MENUX + 5, MENUY + 1, 9, 0, 78);//N
	draw_function(MENUX + 6, MENUY + 1, 9, 0, 83);//S
}
void drawDeadScreen(int lives)//DRAWS THE DEATH SCREEN TEXT
{
	int restartX = 10;
	int restartY = 8;
	draw_function(restartX, restartY, 8, 0, 65);//A
	draw_function(restartX + 2, restartY, 8, 0, 45);//-
	draw_function(restartX + 4, restartY, 8, 0, 82);//r
	draw_function(restartX + 5, restartY, 8, 0, 101);//e
	draw_function(restartX + 6, restartY, 8, 0, 115);//s
	draw_function(restartX + 7, restartY, 8, 0, 97);//a
	draw_function(restartX + 8, restartY, 8, 0, 114);//r
	draw_function(restartX + 9, restartY, 8, 0, 116);//t

	draw_function(restartX + 3, restartY + 1, 8, 0, 21);
	draw_function(restartX + 4, restartY + 1, 8, 0, 173);
	switch (lives)
	{
	case 1:
		draw_function(restartX + 5, restartY + 1, 8, 0, 49);
		break;
	case 2:
		draw_function(restartX + 5, restartY + 1, 8, 0, 50);
		break;
	case 3:
		draw_function(restartX + 5, restartY + 1, 8, 0, 51);
		break;
	}
}
void drawGameOver(int score)//DRAWS THE GAMEOVER SCREEN TEXT
{
	//DISPLAYS GAME OVER TEXT
	draw_function(GOSTARTX, GOSTARTY, 8, 0, 71);//G
	draw_function(GOSTARTX + 1, GOSTARTY, 8, 0, 65);//A
	draw_function(GOSTARTX + 2, GOSTARTY, 8, 0, 77);//M
	draw_function(GOSTARTX + 3, GOSTARTY, 8, 0, 69);//E
	draw_function(GOSTARTX + 5, GOSTARTY, 8, 0, 79);//O
	draw_function(GOSTARTX + 6, GOSTARTY, 8, 0, 86);//V
	draw_function(GOSTARTX + 7, GOSTARTY, 8, 0, 69);//E
	draw_function(GOSTARTX + 8, GOSTARTY, 8, 0, 82);//R


	//draws the start/select text so player has some idea of what to do
	draw_function(PSTARTX, PSTARTY, 8, 0, 83);//S
	draw_function(PSTARTX + 1, PSTARTY, 8, 0, 84);//T
	draw_function(PSTARTX + 2, PSTARTY, 8, 0, 65);//A
	draw_function(PSTARTX + 3, PSTARTY, 8, 0, 82);//R
	draw_function(PSTARTX + 4, PSTARTY, 8, 0, 84);//T

	draw_function(PSTARTX + 6, PSTARTY, 8, 0, 45);//-

	draw_function(PSTARTX + 8, PSTARTY, 8, 0, CHARRCAPS);//R
	draw_function(PSTARTX + 9, PSTARTY, 8, 0, CHARECAPS);//E
	draw_function(PSTARTX + 10, PSTARTY, 8, 0, CHARSCAPS);//S
	draw_function(PSTARTX + 11, PSTARTY, 8, 0, CHARTCAPS);//T
	draw_function(PSTARTX + 12, PSTARTY, 8, 0, CHARACAPS);//A
	draw_function(PSTARTX + 13, PSTARTY, 8, 0, CHARRCAPS);//R
	draw_function(PSTARTX + 14, PSTARTY, 8, 0, CHARTCAPS);//T


	draw_function(PSELECTX, PSELECTY, 8, 0, 83);//S
	draw_function(PSELECTX + 1, PSELECTY, 8, 0, 69);//E
	draw_function(PSELECTX + 2, PSELECTY, 8, 0, 76);//L
	draw_function(PSELECTX + 3, PSELECTY, 8, 0, 69);//E
	draw_function(PSELECTX + 4, PSELECTY, 8, 0, 67);//C
	draw_function(PSELECTX + 5, PSELECTY, 8, 0, 84);//T

	draw_function(PSELECTX + 7, PSELECTY, 8, 0, 45);//-

	draw_function(PSELECTX + 9, PSELECTY, 8, 0, 77);//M
	draw_function(PSELECTX + 10, PSELECTY, 8, 0, 69);//E
	draw_function(PSELECTX + 11, PSELECTY, 8, 0, 78);//N
	draw_function(PSELECTX + 12, PSELECTY, 8, 0, 85);//U
}
void drawPause()//DRAWS THE PAUSE SCREEN TEXT
{
	draw_function(PAUSEX + 2, PAUSEY, 8, 0, 80);//P
	draw_function(PAUSEX + 3, PAUSEY, 8, 0, 97);//A
	draw_function(PAUSEX + 4, PAUSEY, 8, 0, 117);//U
	draw_function(PAUSEX + 5, PAUSEY, 8, 0, 115);//S
	draw_function(PAUSEX + 6, PAUSEY, 8, 0, 101);//E
	draw_function(PAUSEX + 7, PAUSEY, 8, 0, 100);//D

	draw_function(PAUSEX, PAUSEY + 1, 8, 0, 65);//A

	draw_function(PAUSEX + 2, PAUSEY + 1, 8, 0, 45);//-

	draw_function(PAUSEX + 4, PAUSEY + 1, 8, 0, 67);//C
	draw_function(PAUSEX + 5, PAUSEY + 1, 8, 0, 111);//O
	draw_function(PAUSEX + 6, PAUSEY + 1, 8, 0, 110);//N
	draw_function(PAUSEX + 7, PAUSEY + 1, 8, 0, 116);//T
	draw_function(PAUSEX + 8, PAUSEY + 1, 8, 0, 105);//I
	draw_function(PAUSEX + 9, PAUSEY + 1, 8, 0, 110);//N
	draw_function(PAUSEX + 10, PAUSEY + 1, 8, 0, 117);//U
	draw_function(PAUSEX + 11, PAUSEY + 1, 8, 0, 101);//E

	draw_function(PAUSEX, PAUSEY + 2, 8, 0, 66);//B

	draw_function(PAUSEX + 2, PAUSEY + 2, 8, 0, 45);//-

	draw_function(PAUSEX + 4, PAUSEY + 2, 8, 0, 69);//E
	draw_function(PAUSEX + 5, PAUSEY + 2, 8, 0, 120);//x
	draw_function(PAUSEX + 6, PAUSEY + 2, 8, 0, 105);//I
	draw_function(PAUSEX + 7, PAUSEY + 2, 8, 0, 116);//T
}
void drawExit()//DRAWS THE EXIT SCREEN TEXT
{
	if (Menu.arrow == false && exitM == no)
	{
		draw_function(MENUX - 1, MENUY + 1, 9, 0, ARROW);
		exitM = no;
		Menu.arrow = true;
	}
	player.enable = 1;
	//draw text
	draw_function(MENUX, MENUY, 8, 0, 69);//E
	draw_function(MENUX + 1, MENUY, 8, 0, 120);//x
	draw_function(MENUX + 2, MENUY, 8, 0, 105);//I
	draw_function(MENUX + 3, MENUY, 8, 0, 116);//T
	draw_function(MENUX + 4, MENUY, 8, 0, 63);//?

	draw_function(MENUX, MENUY + 1, 8, 0, 78);//no
	draw_function(MENUX + 1, MENUY + 1, 8, 0, 111);//no

	draw_function(MENUX, MENUY + 2, 8, 0, 89);//yes
	draw_function(MENUX + 1, MENUY + 2, 8, 0, 101);//yes
	draw_function(MENUX + 2, MENUY + 2, 8, 0, 115);//yes
}
void drawOptions()//DRAWS THE OPTIONS SCREEN TEXT
{
	if (Menu.arrow == false && optionP == option1)
	{
		draw_function(MENUX - 1, MENUY, 9, 0, ARROW);
		optionP = option1;
		Menu.arrow = true;
	}

	draw_function(MENUX, MENUY, 9, 0, 79);//o1
	draw_function(MENUX + 1, MENUY, 9, 0, 49);//o1

	draw_function(MENUX, MENUY + 1, 9, 0, 79);//o2
	draw_function(MENUX + 1, MENUY + 1, 9, 0, 50);//o2

	int backX = 3;
	int backY = 16;
	draw_function(backX, backY, 9, 0, 80);//P
	draw_function(backX + 1, backY, 9, 0, 85);//U
	draw_function(backX + 2, backY, 9, 0, 83);//S
	draw_function(backX + 3, backY, 9, 0, 72);//H

	draw_function(backX + 5, backY, 9, 0, 66);//B

	draw_function(backX + 7, backY, 9, 0, 84);//T
	draw_function(backX + 8, backY, 9, 0, 79);//O


	draw_function(backX, backY + 1, 9, 0, 71);//G
	draw_function(backX + 1, backY + 1, 9, 0, 79);//O

	draw_function(backX + 3, backY + 1, 9, 0, 66);//B
	draw_function(backX + 4, backY + 1, 9, 0, 65);//A
	draw_function(backX + 5, backY + 1, 9, 0, 67);//C
	draw_function(backX + 6, backY + 1, 9, 0, 75);//A
}

void drawMenuBG(int startXPos, int startYPos, int endXPos, int endYPos,int baseblock)//DRAWS THE THE BACKGROUND USED IN THE INGAME MENU
{
	int i, t;
	draw_function(startXPos, startYPos, baseblock, 0, TOPLEFTMEMU);
	draw_function(endXPos, startYPos, baseblock, 0, TOPRIGHTMEMU);
	draw_function(startXPos, endYPos, baseblock, 0, BOTTOMLEFTMEMU);
	draw_function(endXPos, endYPos, baseblock, 0, BOTTOMRIGHTMEMU);
	//top
	for (i = startXPos + 1; i < endXPos; i++)
	{
		draw_function(i, startYPos, baseblock, 0, TOPMENU);
	}
	//right
	for (i = startYPos + 1; i < endYPos; i++)
	{
		draw_function(endXPos, i, baseblock, 0, LEFTMENU);
	}
	//bottom
	for (i = startXPos + 1; i < endXPos; i++)
	{
		draw_function(i, endYPos, baseblock, 0, BOTTOMMENU);
	}
	//left
	for (i = startYPos + 1; i < endYPos; i++)
	{
		draw_function(startXPos, i, baseblock, 0, RIGHTMENU);
	}
	//center
	//top
	for (t = startYPos + 1; t < endYPos; t++)
	{
		for (i = startXPos + 1; i < endXPos; i++)
		{
			draw_function(i, t, baseblock, 0, CENTERMENU);
		}
	}
}
void drawMainMenu()//DRAWS THE IN GAME MAIN MENU SCREEN TEXT
{
	draw_function(PLAYERMENUSTARTX - 8, PLAYERMENUSTARTY - 1, 4, 0, CHARPCAPS);//P
	draw_function(PLAYERMENUSTARTX - 7, PLAYERMENUSTARTY - 1, 4, 0, CHARLCAPS);//L
	draw_function(PLAYERMENUSTARTX - 6, PLAYERMENUSTARTY - 1, 4, 0, CHARACAPS);//A
	draw_function(PLAYERMENUSTARTX - 5, PLAYERMENUSTARTY - 1, 4, 0, CHARYCAPS);//Y
	draw_function(PLAYERMENUSTARTX - 4, PLAYERMENUSTARTY - 1, 4, 0, CHARECAPS);//E
	draw_function(PLAYERMENUSTARTX - 3, PLAYERMENUSTARTY - 1, 4, 0, CHARRCAPS);//R

	draw_function(PLAYERMENUSTARTX - 1, PLAYERMENUSTARTY - 1, 4, 0, CHARMCAPS);//M
	draw_function(PLAYERMENUSTARTX, PLAYERMENUSTARTY - 1, 4, 0, CHARECAPS);//e
	draw_function(PLAYERMENUSTARTX + 1, PLAYERMENUSTARTY - 1, 4, 0, CHARNCAPS);//n
	draw_function(PLAYERMENUSTARTX + 2, PLAYERMENUSTARTY - 1, 4, 0, CHARUCAPS);//u

	draw_function(PLAYERMENUSTARTX, PLAYERMENUSTARTY + 1, 4, 0, CHARICAPS);//I
	draw_function(PLAYERMENUSTARTX + 1, PLAYERMENUSTARTY + 1, 4, 0, CHARN);//N
	draw_function(PLAYERMENUSTARTX + 2, PLAYERMENUSTARTY + 1, 4, 0, CHARV);//V
	draw_function(PLAYERMENUSTARTX + 3, PLAYERMENUSTARTY + 1, 4, 0, CHARE);//E
	draw_function(PLAYERMENUSTARTX + 4, PLAYERMENUSTARTY + 1, 4, 0, CHARN);//N
	draw_function(PLAYERMENUSTARTX + 5, PLAYERMENUSTARTY + 1, 4, 0, CHART);//T
	draw_function(PLAYERMENUSTARTX + 6, PLAYERMENUSTARTY + 1, 4, 0, CHARO);//O
	draw_function(PLAYERMENUSTARTX + 7, PLAYERMENUSTARTY + 1, 4, 0, CHARR);//R
	draw_function(PLAYERMENUSTARTX + 8, PLAYERMENUSTARTY + 1, 4, 0, CHARY);//Y

	draw_function(PLAYERMENUSTARTX, PLAYERMENUSTARTY + 2, 4, 0, CHARACAPS);//A
	draw_function(PLAYERMENUSTARTX + 1, PLAYERMENUSTARTY + 2, 4, 0, CHARB);//B
	draw_function(PLAYERMENUSTARTX + 2, PLAYERMENUSTARTY + 2, 4, 0, CHARI);//I
	draw_function(PLAYERMENUSTARTX + 3, PLAYERMENUSTARTY + 2, 4, 0, CHARL);//L
	draw_function(PLAYERMENUSTARTX + 4, PLAYERMENUSTARTY + 2, 4, 0, CHARI);//I
	draw_function(PLAYERMENUSTARTX + 5, PLAYERMENUSTARTY + 2, 4, 0, CHART);//T
	draw_function(PLAYERMENUSTARTX + 6, PLAYERMENUSTARTY + 2, 4, 0, CHARI);//I
	draw_function(PLAYERMENUSTARTX + 7, PLAYERMENUSTARTY + 2, 4, 0, CHARE);//E
	draw_function(PLAYERMENUSTARTX + 8, PLAYERMENUSTARTY + 2, 4, 0, CHARS);//S

	draw_function(PLAYERMENUSTARTX, PLAYERMENUSTARTY + 3, 4, 0, CHARECAPS);//E
	draw_function(PLAYERMENUSTARTX + 1, PLAYERMENUSTARTY + 3, 4, 0, CHARQ);//Q
	draw_function(PLAYERMENUSTARTX + 2, PLAYERMENUSTARTY + 3, 4, 0, CHARU);//U
	draw_function(PLAYERMENUSTARTX + 3, PLAYERMENUSTARTY + 3, 4, 0, CHARI);//I
	draw_function(PLAYERMENUSTARTX + 4, PLAYERMENUSTARTY + 3, 4, 0, CHARP);//P
	draw_function(PLAYERMENUSTARTX + 5, PLAYERMENUSTARTY + 3, 4, 0, CHARM);//M
	draw_function(PLAYERMENUSTARTX + 6, PLAYERMENUSTARTY + 3, 4, 0, CHARE);//E
	draw_function(PLAYERMENUSTARTX + 7, PLAYERMENUSTARTY + 3, 4, 0, CHARN);//N
	draw_function(PLAYERMENUSTARTX + 8, PLAYERMENUSTARTY + 3, 4, 0, CHART);//T

	draw_function(PLAYERMENUSTARTX, PLAYERMENUSTARTY + 4, 4, 0, CHARSCAPS);//S
	draw_function(PLAYERMENUSTARTX + 1, PLAYERMENUSTARTY + 4, 4, 0, CHART);//T
	draw_function(PLAYERMENUSTARTX + 2, PLAYERMENUSTARTY + 4, 4, 0, CHARA);//A
	draw_function(PLAYERMENUSTARTX + 3, PLAYERMENUSTARTY + 4, 4, 0, CHART);//T
	draw_function(PLAYERMENUSTARTX + 4, PLAYERMENUSTARTY + 4, 4, 0, CHARU);//U
	draw_function(PLAYERMENUSTARTX + 5, PLAYERMENUSTARTY + 4, 4, 0, CHARS);//S

	draw_function(PLAYERMENUSTARTX, PLAYERMENUSTARTY + 5, 4, 0, CHARPCAPS);//P
	draw_function(PLAYERMENUSTARTX + 1, PLAYERMENUSTARTY + 5, 4, 0, CHARA);//A
	draw_function(PLAYERMENUSTARTX + 2, PLAYERMENUSTARTY + 5, 4, 0, CHARR);//R
	draw_function(PLAYERMENUSTARTX + 3, PLAYERMENUSTARTY + 5, 4, 0, CHART);//T
	draw_function(PLAYERMENUSTARTX + 4, PLAYERMENUSTARTY + 5, 4, 0, CHARY);//Y

	draw_function(PLAYERMENUSTARTX, PLAYERMENUSTARTY + 6, 4, 0, CHAROCAPS);//O
	draw_function(PLAYERMENUSTARTX + 1, PLAYERMENUSTARTY + 6, 4, 0, CHARP);//P
	draw_function(PLAYERMENUSTARTX + 2, PLAYERMENUSTARTY + 6, 4, 0, CHART);//T
	draw_function(PLAYERMENUSTARTX + 3, PLAYERMENUSTARTY + 6, 4, 0, CHARI);//I
	draw_function(PLAYERMENUSTARTX + 4, PLAYERMENUSTARTY + 6, 4, 0, CHARO);//O
	draw_function(PLAYERMENUSTARTX + 5, PLAYERMENUSTARTY + 6, 4, 0, CHARN);//N
	draw_function(PLAYERMENUSTARTX + 6, PLAYERMENUSTARTY + 6, 4, 0, CHARS);//S


	draw_function(INVENTORYSTARTX + 2, INVENTORYSTARTY + 0, 4, 0, 21);
	draw_function(INVENTORYSTARTX + 3, INVENTORYSTARTY + 0, 4, 0, 22);
	draw_function(INVENTORYSTARTX + 2, INVENTORYSTARTY + 1, 4, 0, 23);
	draw_function(INVENTORYSTARTX + 3, INVENTORYSTARTY + 1, 4, 0, 24);

}
void drawInventoryMenu()//DRAWS THE INVENTORY MENU SCREEN TEXT
{
	draw_function(PLAYERMENUSTARTX - 7, PLAYERMENUSTARTY - 1, 4, 0, CHARICAPS);//I
	draw_function(PLAYERMENUSTARTX - 6, PLAYERMENUSTARTY - 1, 4, 0, CHARNCAPS);//N
	draw_function(PLAYERMENUSTARTX - 5, PLAYERMENUSTARTY - 1, 4, 0, CHARVCAPS);//V
	draw_function(PLAYERMENUSTARTX - 4, PLAYERMENUSTARTY - 1, 4, 0, CHARECAPS);//E
	draw_function(PLAYERMENUSTARTX - 3, PLAYERMENUSTARTY - 1, 4, 0, CHARNCAPS);//N
	draw_function(PLAYERMENUSTARTX - 2, PLAYERMENUSTARTY - 1, 4, 0, CHARTCAPS);//T
	draw_function(PLAYERMENUSTARTX - 1, PLAYERMENUSTARTY - 1, 4, 0, CHAROCAPS);//O
	draw_function(PLAYERMENUSTARTX + 0, PLAYERMENUSTARTY - 1, 4, 0, CHARRCAPS);//R
	draw_function(PLAYERMENUSTARTX + 1, PLAYERMENUSTARTY - 1, 4, 0, CHARYCAPS);//Y

}
void drawAbiliesMenu()//DRAWS THE ABILITIES SCREEN TEXT
{
	draw_function(PLAYERMENUSTARTX - 7, PLAYERMENUSTARTY - 1, 4, 0, CHARACAPS);//A
	draw_function(PLAYERMENUSTARTX - 6, PLAYERMENUSTARTY - 1, 4, 0, CHARBCAPS);//B
	draw_function(PLAYERMENUSTARTX - 5, PLAYERMENUSTARTY - 1, 4, 0, CHARICAPS);//I
	draw_function(PLAYERMENUSTARTX - 4, PLAYERMENUSTARTY - 1, 4, 0, CHARLCAPS);//L
	draw_function(PLAYERMENUSTARTX - 3, PLAYERMENUSTARTY - 1, 4, 0, CHARICAPS);//I
	draw_function(PLAYERMENUSTARTX - 2, PLAYERMENUSTARTY - 1, 4, 0, CHARTCAPS);//T
	draw_function(PLAYERMENUSTARTX - 1, PLAYERMENUSTARTY - 1, 4, 0, CHARICAPS);//I
	draw_function(PLAYERMENUSTARTX + 0, PLAYERMENUSTARTY - 1, 4, 0, CHARECAPS);//E
	draw_function(PLAYERMENUSTARTX + 1, PLAYERMENUSTARTY - 1, 4, 0, CHARSCAPS);//S
}
void drawEquipmentMenu()//DRAWS THE EQUIPMENT SCREEN TEXT
{
	draw_function(PLAYERMENUSTARTX - 7, PLAYERMENUSTARTY - 1, 4, 0, CHARECAPS);//E
	draw_function(PLAYERMENUSTARTX - 6, PLAYERMENUSTARTY - 1, 4, 0, CHARQCAPS);//Q
	draw_function(PLAYERMENUSTARTX - 5, PLAYERMENUSTARTY - 1, 4, 0, CHARUCAPS);//U
	draw_function(PLAYERMENUSTARTX - 4, PLAYERMENUSTARTY - 1, 4, 0, CHARICAPS);//I
	draw_function(PLAYERMENUSTARTX - 3, PLAYERMENUSTARTY - 1, 4, 0, CHARPCAPS);//P
	draw_function(PLAYERMENUSTARTX - 2, PLAYERMENUSTARTY - 1, 4, 0, CHARMCAPS);//M
	draw_function(PLAYERMENUSTARTX - 1, PLAYERMENUSTARTY - 1, 4, 0, CHARECAPS);//E
	draw_function(PLAYERMENUSTARTX + 0, PLAYERMENUSTARTY - 1, 4, 0, CHARNCAPS);//N
	draw_function(PLAYERMENUSTARTX + 1, PLAYERMENUSTARTY - 1, 4, 0, CHARTCAPS);//T
	
}
void drawStatusMenu()//DRAWS THE STATUS SCREEN TEXT
{
	draw_function(PLAYERMENUSTARTX - 5, PLAYERMENUSTARTY - 1, 4, 0, CHARSCAPS);//S
	draw_function(PLAYERMENUSTARTX - 4, PLAYERMENUSTARTY - 1, 4, 0, CHARTCAPS);//T
	draw_function(PLAYERMENUSTARTX - 3, PLAYERMENUSTARTY - 1, 4, 0, CHARACAPS);//A
	draw_function(PLAYERMENUSTARTX - 2, PLAYERMENUSTARTY - 1, 4, 0, CHARTCAPS);//T
	draw_function(PLAYERMENUSTARTX - 1, PLAYERMENUSTARTY - 1, 4, 0, CHARUCAPS);//U
	draw_function(PLAYERMENUSTARTX - 0, PLAYERMENUSTARTY - 1, 4, 0, CHARSCAPS);//S

	draw_function(INVENTORYSTARTX + 2, INVENTORYSTARTY + 0, 4, 0, 21);
	draw_function(INVENTORYSTARTX + 3, INVENTORYSTARTY + 0, 4, 0, 22);
	draw_function(INVENTORYSTARTX + 2, INVENTORYSTARTY + 1, 4, 0, 23);
	draw_function(INVENTORYSTARTX + 3, INVENTORYSTARTY + 1, 4, 0, 24);
}
void drawPartyMenu()//DRAWS THE PARTY SCREEN TEXT
{
	draw_function(PLAYERMENUSTARTX - 5, PLAYERMENUSTARTY - 1, 4, 0, CHARPCAPS);//P
	draw_function(PLAYERMENUSTARTX - 4, PLAYERMENUSTARTY - 1, 4, 0, CHARACAPS);//A
	draw_function(PLAYERMENUSTARTX - 3, PLAYERMENUSTARTY - 1, 4, 0, CHARRCAPS);//R
	draw_function(PLAYERMENUSTARTX - 2, PLAYERMENUSTARTY - 1, 4, 0, CHARTCAPS);//T
	draw_function(PLAYERMENUSTARTX - 1, PLAYERMENUSTARTY - 1, 4, 0, CHARYCAPS);//Y
}
void drawOptionsMenu()//DRAWS THE OPTIONS SCREEN TEXT
{
	draw_function(PLAYERMENUSTARTX - 6, PLAYERMENUSTARTY - 1, 4, 0, CHAROCAPS);//O
	draw_function(PLAYERMENUSTARTX - 5, PLAYERMENUSTARTY - 1, 4, 0, CHARPCAPS);//P
	draw_function(PLAYERMENUSTARTX - 4, PLAYERMENUSTARTY - 1, 4, 0, CHARTCAPS);//T
	draw_function(PLAYERMENUSTARTX - 3, PLAYERMENUSTARTY - 1, 4, 0, CHARICAPS);//I
	draw_function(PLAYERMENUSTARTX - 2, PLAYERMENUSTARTY - 1, 4, 0, CHAROCAPS);//O
	draw_function(PLAYERMENUSTARTX - 1, PLAYERMENUSTARTY - 1, 4, 0, CHARNCAPS);//N
	draw_function(PLAYERMENUSTARTX - 0, PLAYERMENUSTARTY - 1, 4, 0, CHARSCAPS);//S
}
