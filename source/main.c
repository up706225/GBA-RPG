////////////////////////////////////////////////////////////////////////////////
// Filename: main.c
////////////////////////////////////////////////////////////////////////////////
/////////////////
// My INCLUDES //
/////////////////
#include "systemincludes.h"
#include "playerstruct.h"
#include "game.h"
#include "enemies.h"
void runGame();
asm("mov r0,r0");
//---------------------------------------------------------------------------------
// Program entry point
//---------------------------------------------------------------------------------
int main(void) {
//---------------------------------------------------------------------------------

	// the vblank interrupt must be enabled for VBlankIntrWait() to work
	irqInit();
	irqSet(IRQ_VBLANK, mmVBlank);
	irqEnable(IRQ_VBLANK);

	// generic setup function
	consoleDemoInit();
	mmInitDefault((mm_addr)soundbank_bin, 8);
	gameState = splash; // sets the initial gamestate

	// main loop
	while (1) 
	{
		runGame(); // runs the runGame function (game.c - L5)
		VBlankIntrWait();
		player.frame = player.frame + 1;
		Battle.frame = Battle.frame + 1;
		
		if (currentState != IDLE && player.frame >= (FRAMETIME+5))
		{
			player.frame = 0;
		}
		if (currentState != attacking && Battle.frame >= (FRAMETIME + 5))
		{
			Battle.frame = 0;
		}
		if (currentState != enemyAnimation && Battle.frame >= (FRAMETIME*2 + 5))
		{
			Battle.frame = 0;
		}
		mmFrame();
	}
}




//Marking Scheme : Deliverable 2
//(GBA artefact – 30 % of final mark – possible 100 points)

//Low - level code(total 45 points)
//0 - 6 – little / no low - level code, and / or only compiled sample code, and / or clearly very similar to other students.^
//7 - 12 – basic commands(e.g.ADD, SUB, MOV) compiling without errors, but not replacing C / C++ code, or functionality limited to basic addition / subtraction.^
//13 - 20 – intermediate commands(e.g.CMP, MUL, BNE / BEQ) replacing lines of C / C++, working fine and actually doing something useful in the game.Student has clearly attempted to do more than a bare minimum.^
//21 - 34 – complex low - level code(e.g.‘for’ loops, function calls, stack accessing) compiling fine.Student has clearly engaged well in implementing LLC for their game.
//35 - 45 – extensive use of LLC(e.g.rewriting aspects of LibGBA, optimisation tricks)

//Graphics(total 25 points)
//0 - 3 – text displayed on screen ^
//4 - 10 – text and sprites displayed using OAM and Map Memory ^
//11 - 18 – fairly advanced(e.g.BG layers, multi - tile OBJs, custom tile set, it looks good)
//19 - 25 – excellent(e.g.scrolling, animation, evidence of streamlined workflow, it looks great)

//States / logic(total 20 points)
//0 - 5 – only one game state, lack of objective or action, input unresponsive or very basic ^
//6 - 9 – more than one game state, gameplay responds to player(e.g.it could loosely be called a “game”), input responsive but badly - considered / implemented ^
//10 - 15 – fuller gameplay experience(e.g.basic AI, scoring, collisions, objectives), input working well ^
//16 - 20 – ambitious(e.g.attention to detail, complex gameplay, advanced hardware features(e.g.rotation), technically - demanding design), makes good use of complex input

//Sound(total 10 points)
//0 – no sound
//1 - 5 – basic(e.g.used example sound, or basic looping sound)
//6 - 10 – advanced(e.g.well controlled, interesting sounds, SFX as well as music)