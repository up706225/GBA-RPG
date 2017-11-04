////////////////////////////////////////////////////////////////////////////////
// Filename: pointerstruct.c
////////////////////////////////////////////////////////////////////////////////

/////////////////
// My INCLUDES //
/////////////////
#include "pointerstruct.h"

void pointersFunc()//this function runs and sets up the memory addresses
{

	point.DISPCNT = (unsigned short *)0x04000000;//creates a pointer to the memory address given

	point.BGCNT = (unsigned short *)0x04000008;

	point.base_block4 = (unsigned short *)0x6002000;
	point.base_block8 = (unsigned short *)0x6004000;
	point.base_block9 = (unsigned short *)0x6004800;
	point.base_block10 = (unsigned short *)0x6005000;
	point.base_block11 = (unsigned short *)0x6005800;

	point.base_block20 = (unsigned short *)0x600a000;
	point.base_block24 = (unsigned short *)0x600c000;
	point.base_block25 = (unsigned short *)0x600c800;
	point.base_block26 = (unsigned short *)0x600d000;
	point.base_block27 = (unsigned short *)0x600d800;

	point.bg_palette = (unsigned short *)0x05000000;
	point.obj_palette = (unsigned short *)0x05000200;

	point.characterAddressFirst = (unsigned int *)0x06000000;
	point.characterAddress = (unsigned int *)0x06008000;
	point.spriteAddress = (unsigned int *)0x06010000;
	point.obj_holderAddress = (unsigned short *)0x07000000;

}

