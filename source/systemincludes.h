////////////////////////////////////////////////////////////////////////////////
// Filename: systemincludes.h
////////////////////////////////////////////////////////////////////////////////
#ifndef _INCLUDES_H_
#define _INCLUDES_H_

/////////////////////
// SYSTEM INCLUDES //
/////////////////////
#include <gba_console.h>
#include <gba_video.h>
#include <gba_interrupt.h>
#include <gba_systemcalls.h>

#include <stdio.h>
#include <gba_input.h>

#include <maxmod.h>		// maxmod library
#include "soundbank.h"
#include "soundbank_bin.h"
////////////////////////
// Global definitions //
////////////////////////
#define MOVE_SPEED 1 //sets Move speed 

//sets controls to numerical value for collisions/movement
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
#define IDLE 0
#define ENEMY_OBJECT_START 20 //enemy object start number
#define ENEMY_BATTLE_START 40 //level object start number
#define FRAMETIME 20
#define MENU_OBJECT_START 100 //used for all other object placement
#define REMAINING_OBJECTS 28 // remaining objects for other
#define NUMBER_OF_PICKUPS 20 //pickup number total
#define NUMBER_OF_ENEMIES 20 //number of total object spaces the game allocates for enemies
#define NUMBER_OF_TREES 20 //total number of trees
#define XSTART 1 //players X start position
#define YSTART 75 //players Y start position

#define XBATTLESTART 16
#define YBATTLESTART 56
#define PLAYER_MAX_LIVES 1 // players start lives
#define WIDTH 232 //screen width
#define HEIGHT 153 //screen height
#define SPRITE_PRIORITY 3 //sprites priority, used to change all object sprites at once

//POSITIONS USED FOR MENUS, EITHER THE POSITIONS OF THE CORNERS OR THE POINT AT WHICH THE ARROW STARTS (ARROW IS USED FOR DIAPLYING WHICH MENU ITEM IS SELECTED)
#define PAUSEX 9
#define PAUSEY 8
#define MENUX 11
#define MENUY 7
#define GOSTARTX 10
#define GOSTARTY 8
#define PSTARTX (GOSTARTX-2)
#define PSTARTY (GOSTARTY+2)
#define PSELECTX (GOSTARTX-3)
#define PSELECTY (GOSTARTX+3)
#define PLAYERMENUX 5
#define PLAYERMENUY 5
#define PLAYERMENUSTARTX 17
#define PLAYERMENUSTARTY 5
#define INVENTORYSTARTX 4
#define INVENTORYSTARTY 6
#define INVENTORYWINDOWSTARTX 3
#define INVENTORYWINDOWSTARTY 3
#define INVENTORYWINDOWENDX 26
#define INVENTORYWINDOWENDY 17
#define BATTLEMENUMID 21	
#define BATTLEMENULEFT 1
#define BATTLEMENUY 15
#define BATTLEMENUSTARTX 0
#define BATTLEMENUSTARTY 14
#define BATTLEMENUENDX 29
#define BATTLEMENUENDY 19
//THE TEXT CHARACTERS DEFINED HERE ARE SO ITS EASIER TO USE INDIVIDUAL LETTERS LATERE
#define ARROW 8
#define TOPLEFTMEMU 9
#define TOPRIGHTMEMU 10
#define BOTTOMLEFTMEMU 12
#define BOTTOMRIGHTMEMU 11

#define TOPMENU 13
#define BOTTOMMENU 15
#define LEFTMENU 14
#define RIGHTMENU 16
#define CENTERMENU 17
//CAPS
#define CHARACAPS 65
#define CHARBCAPS 66
#define CHARCCAPS 67
#define CHARDCAPS 68
#define CHARECAPS 69
#define CHARFCAPS 70
#define CHARGCAPS 71
#define CHARHCAPS 72
#define CHARICAPS 73
#define CHARJCAPS 74
#define CHARKCAPS 75
#define CHARLCAPS 76
#define CHARMCAPS 77
#define CHARNCAPS 78
#define CHAROCAPS 79
#define CHARPCAPS 80
#define CHARQCAPS 81
#define CHARRCAPS 82
#define CHARSCAPS 83
#define CHARTCAPS 84
#define CHARUCAPS 85
#define CHARVCAPS 86
#define CHARWCAPS 87
#define CHARXCAPS 88
#define CHARYCAPS 89
#define CHARZCAPS 90
//LOWER
#define CHARA 97
#define CHARB 98
#define CHARC 99
#define CHARD 100
#define CHARE 101
#define CHARF 102
#define CHARG 103
#define CHARH 104
#define CHARI 105
#define CHARJ 106
#define CHARK 107
#define CHARL 108
#define CHARM 109
#define CHARN 110
#define CHARO 111
#define CHARP 112
#define CHARQ 113
#define CHARR 114
#define CHARS 115
#define CHART 116
#define CHARU 117
#define CHARV 118
#define CHARW 119
#define CHARX 120
#define CHARY 121
#define CHARZ 122

#endif