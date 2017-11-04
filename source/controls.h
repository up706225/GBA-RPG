////////////////////////////////////////////////////////////////////////////////
// Filename: controls.h
////////////////////////////////////////////////////////////////////////////////
#ifndef CONTROLS_H_
#define CONTROLS_H_
#include "systemincludes.h"
#include "playerstruct.h"
#include "game.h"
#include "enemies.h"



extern bool music;
void clearCharacters();
//---------------------------------------------------------------------------------
// FUNCTION DECLERATIONS
//---------------------------------------------------------------------------------
	void moveCheck();
	void heldKey();
	void keyUsed();
	void menuClear();
#endif