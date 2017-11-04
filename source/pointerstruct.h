////////////////////////////////////////////////////////////////////////////////
// Filename: pointerstruct.h
////////////////////////////////////////////////////////////////////////////////
#ifndef POINTERSTRUCT_H_
#define POINTERSTRUCT_H_

//Pointers struct
// *****************
// Pointers
// *****************
typedef struct Pointers
{
	unsigned short *DISPCNT; //creates a pointer to the memory address given

	unsigned short *BGCNT;

	unsigned short *base_block4;
	unsigned short *base_block8;
	unsigned short *base_block9;
	unsigned short *base_block10;
	unsigned short *base_block11;

	unsigned short *base_block20;
	unsigned short *base_block24;
	unsigned short *base_block25;
	unsigned short *base_block26;
	unsigned short *base_block27;

	unsigned short *bg_palette;
	unsigned short *obj_palette;

	unsigned int *characterAddressFirst;
	unsigned int *characterAddress;
	unsigned int *spriteAddress;
	unsigned short *obj_holderAddress;

} Pointer;
Pointer point;

#endif