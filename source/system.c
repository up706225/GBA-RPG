////////////////////////////////////////////////////////////////////////////////
// Filename: system.c
////////////////////////////////////////////////////////////////////////////////

/////////////////
// My INCLUDES //
/////////////////
#include "system.h"

//---------------------------------------------------------------------------------
// SETUP
//---------------------------------------------------------------------------------
//This is the main setup function, this sets up pointers, the graphical settings, sprites and characters
void setupFunction()
{
	pointersFunc();
	
	//---------------------------------------------------------------------------------
	// FONT/SPRITE SETUP - OLD MANUAL METHOD 
	//---------------------------------------------------------------------------------
	// *****************
	// Character (font) 
	// *****************
	//tile ref, pixels
	//--- Adds the custom characters to the character list
	//myChar_function(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0); //character tile 0 (blank)
	//myChar_function(1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0); //character tile 1 (backwards L) 
	//myChar_function(2,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0); //character tile 2 (backwards L)
	//myChar_function(3,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0); //character tile 3 (backwards L)
	//
	//// *****************
	//// Sprite
	//// *****************
	////tile ref, pixels
	////--- Adds the custom characters to the sprite list
	//mySprite_function(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0); //sprite tile 0 (blank)
	//mySprite_function(1,0,0,1,1,1,1,0,0,0,1,1,1,1,1,0,0,0,0,1,0,1,1,0,1,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,1,1,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0); //sprite tile 1
	//mySprite_function(2,0,0,1,1,1,1,0,0,0,1,1,1,1,1,0,0,0,0,1,0,1,1,0,1,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,1,1,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0); //sprite tile 1
	//mySprite_function(3,0,0,1,1,1,1,0,0,0,1,1,1,1,1,0,0,0,0,1,0,1,1,0,1,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,1,1,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0); //sprite tile 1
	//mySprite_function(4,0,0,1,1,1,1,0,0,0,1,1,1,1,1,0,0,0,0,1,0,1,1,0,1,0,0,0,0,1,1,0,0,0,0,0,0,1,1,0,0,1,1,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0); //sprite tile 1
	
	//---------------------------------------------------------------------------------
	// FONT/SPRITE SETUP - OLD AUTOMATED METHOD 
	//---------------------------------------------------------------------------------
	//int i;
	//for (i = 0; i < 256; i++)
	//{
	//	point.characterAddress[i] = spriteData[i];
	//}
	//auto adds sprites to tile list
	//for (i = 0; i < 2048; i++)
	//{
	//	point.spriteAddress[i] = spriteData[i];
	//}
	//---------------------------------------------------------------------------------
	// FONT/SPRITE SETUP - NEW ASM METHOD
	//---------------------------------------------------------------------------------
	int start = 0;
	int finish = 256;
	addSprites(&start, &finish, &point.characterAddressFirst[0], &spriteData[0]); //Adds charactres to tile list
	finish = 2048;
	addSprites(&start, &finish, &point.characterAddress[0], &spriteData[0]); //Adds charactres to tile list
	addSprites(&start, &finish, &point.spriteAddress[0], &spriteData[0]);	//Adds sprites to sprite list
	//---------------------------------------------------------------------------------
	// GRAPHICS SETUP
	//---------------------------------------------------------------------------------
	// *****************
	// Display
	// *****************
	//graphics_mode (0 - 5), obj_data_mode (0 - 1), bg0 off/on (0 - 1), bg1 off/on (0 - 1), bg2 bg1 off/on (0 - 1), bg3 bg1 off/on (0 - 1), obj bg1 off/on (0 - 1))
	myDisplay_function(0, 1, 1, 1, 1, 1, 1);

	// *****************
	// Backgroundz
	// *****************
	//bg_layer (0 - 3), layer_priority (0 - 3), char_base_block (0 - 3), colour_mode (0 - 16), screen_base_block (0 - 31), screen_size (0 - 3)
	mybg_function(0, 1, 0, 0, 8, 0);
	mybg_function(1, 3, 0, 0, 11, 0);
	mybg_function(2, 2, 0, 0, 9, 0);
	mybg_function(3, 0, 0, 0, 4, 0);


	//---------------------------------------------------------------------------------
	// PALETTE SETUP
	//---------------------------------------------------------------------------------
	// *****************
	// Background palette
	// *****************
	//palette (0 - 16), palette tile (0 - 16) , red (0 - 31), green (0 - 31), blue (0 - 31)
	bgPalette_function(0, 0, 0, 15, 15);//BG colour
	bgPalette_function(0, 1, 0, 0, 0);//Black
	bgPalette_function(0, 2, 31, 0, 0);//Red
	bgPalette_function(0, 3, 0, 31, 0); //green
	bgPalette_function(0, 4, 0, 0, 31); //blue
	bgPalette_function(0, 5, 31, 31, 0); //Yellow
	bgPalette_function(0, 6, 31, 31, 31); //white
	bgPalette_function(0, 7, 31, 0, 31); //purple
	bgPalette_function(0, 8, 0, 31, 31); //light blue
	bgPalette_function(0, 9, 13, 8, 5); //brown
	bgPalette_function(0, 10, 0, 14, 0); //dark green
	bgPalette_function(0, 11, 14, 14, 14); //grey
	bgPalette_function(0, 12, 9, 9, 8); //dark grey
	bgPalette_function(0, 13, 27, 0, 0);//RED
	bgPalette_function(0, 14, 31, 22, 25);//Pink

	bgPalette_function(1, 0, 0, 0, 31);//BG colour
	bgPalette_function(1, 1, 0, 0, 0);//Black
	bgPalette_function(1, 2, 31, 0, 0);//Red
	bgPalette_function(1, 3, 0, 31, 0); //green
	bgPalette_function(1, 4, 0, 0, 31); //blue
	bgPalette_function(1, 5, 31, 31, 0); //Yellow
	bgPalette_function(1, 6, 31, 31, 31); //white
	bgPalette_function(1, 7, 31, 0, 31); //purple
	bgPalette_function(1, 8, 0, 31, 31); //light blue
	bgPalette_function(1, 9, 13, 8, 5); //brown
	bgPalette_function(1, 10, 0, 14, 0); //dark green
	bgPalette_function(1, 11, 14, 14, 14); //grey
	bgPalette_function(1, 12, 9, 9, 8); //dark grey
	bgPalette_function(1, 13, 27, 0, 0);//RED
	bgPalette_function(1, 14, 31, 22, 25);//Pink
	// *****************
	// Object palette 
	// *****************
	//palette (0 - 16), palette tile (0 - 16) , red (0 - 31), green (0 - 31), blue (0 - 31)
	objPalette_function(0, 0, 31, 0, 0);//Blank (BG) colour - Yellow
	objPalette_function(0, 1, 0, 0, 0);//Black
	objPalette_function(0, 2, 31, 0, 0);//Red
	objPalette_function(0, 3, 0, 31, 0); //green
	objPalette_function(0, 4, 0, 0, 31); //blue
	objPalette_function(0, 5, 31, 31, 0); //Yellow
	objPalette_function(0, 6, 31, 31, 31); //white
	objPalette_function(0, 7, 31, 0, 31); //purple
	objPalette_function(0, 8, 0, 31, 31); //light blue
	objPalette_function(0, 9, 13, 8, 5); //brown
	objPalette_function(0, 10, 0, 14, 0); //dark green
	objPalette_function(0, 11, 14, 14, 14); //grey	
	objPalette_function(0, 12, 9, 9, 8);//dark grey
	objPalette_function(0, 13, 27, 0, 0);//RED
	objPalette_function(0, 14, 31, 22, 25);//Pink


}


// *****************
// Display
// *****************
//sets up the display, selecting graphics mode, turning objects on/off and turning on the backgrounds - 
void myDisplay_function(int graphics_mode, int obj_data_mode, int bg0, int bg1, int bg2, int bg3, int obj)
{
	point.DISPCNT[0] = ((obj << 12) | (bg3 << 11) | (bg2 << 10) | (bg1 << 9) | (bg0 << 8) | (obj_data_mode << 6) | (graphics_mode << 0));
}
// *****************
// Background
// *****************
//sets up the background, configuring (BG0CNT - BG3CNT) automatically - BGCNT number (0 - 3), layers priority, characters base block, the colour mode, screen baseblock, screen size
void mybg_function(int bg_layer, int layer_priority, int char_base_block, int colour_mode, int screen_base_block, int screen_size)
{
	point.BGCNT[bg_layer] = ((screen_size << 14) | (screen_base_block << 8) | (colour_mode << 7) | (char_base_block << 2) | (layer_priority << 0));
}

// *****************
// Background palette
// *****************
//creates the background pallete - palette number, tile number, RED, GREEN, BLUE - adjust to change the colours
void bgPalette_function(int palette, int palette_tile, int red, int green, int blue)
{
	int i = palette * 16; //Works out the palette number
	unsigned short *palette_address = (unsigned short *)&point.bg_palette[i]; //creates a pointer to the palette using the palette number

	palette_address[palette_tile] = ((blue << 10) | (green << 5) | (red << 0)); //uses the pointer created above and the tile number to apply the colour to a tile
}

// *****************
// Object palette
// *****************
//creates the objects pallete - palette number, tile number, RED, GREEN, BLUE - adjust to change the colours
void objPalette_function(int palette, int palette_tile, int red, int green, int blue)
{
	int i = palette * 16;//Works out the palette number
	unsigned short *palette_address = (unsigned short *)&point.obj_palette[i]; //creates a pointer to the palette using the palette number

	palette_address[palette_tile] = ((blue << 10) | (green << 5) | (red << 0));//uses the pointer created above and the tile number to apply the colour to a tile
}

// *****************
// Character (font) 
// *****************
//manually add characters to the character library
void myChar_function(int tile_ref,
	int a1, int b1, int c1, int d1, int e1, int f1, int g1, int h1,
	int a2, int b2, int c2, int d2, int e2, int f2, int g2, int h2,
	int a3, int b3, int c3, int d3, int e3, int f3, int g3, int h3,
	int a4, int b4, int c4, int d4, int e4, int f4, int g4, int h4,
	int a5, int b5, int c5, int d5, int e5, int f5, int g5, int h5,
	int a6, int b6, int c6, int d6, int e6, int f6, int g6, int h6,
	int a7, int b7, int c7, int d7, int e7, int f7, int g7, int h7,
	int a8, int b8, int c8, int d8, int e8, int f8, int g8, int h8)
{
	int i = tile_ref * 8;//Works out the tile number 
	unsigned int *character = (unsigned int *)&point.characterAddress[i];//creates a pointer to the character location

	character[0] = ((h1 << 28) | (g1 << 24) | (f1 << 20) | (e1 << 16) | (d1 << 12) | (c1 << 8) | (b1 << 4) | (a1 << 0)); //uses the pointer to set each row of the character
	character[1] = ((h2 << 28) | (g2 << 24) | (f2 << 20) | (e2 << 16) | (d2 << 12) | (c2 << 8) | (b2 << 4) | (a2 << 0));
	character[2] = ((h3 << 28) | (g3 << 24) | (f3 << 20) | (e3 << 16) | (d3 << 12) | (c3 << 8) | (b3 << 4) | (a3 << 0));
	character[3] = ((h4 << 28) | (g4 << 24) | (f4 << 20) | (e4 << 16) | (d4 << 12) | (c4 << 8) | (b4 << 4) | (a4 << 0));
	character[4] = ((h5 << 28) | (g5 << 24) | (f5 << 20) | (e5 << 16) | (d5 << 12) | (c5 << 8) | (b5 << 4) | (a5 << 0));
	character[5] = ((h6 << 28) | (g6 << 24) | (f6 << 20) | (e6 << 16) | (d6 << 12) | (c6 << 8) | (b6 << 4) | (a6 << 0));
	character[6] = ((h7 << 28) | (g7 << 24) | (f7 << 20) | (e7 << 16) | (d7 << 12) | (c7 << 8) | (b7 << 4) | (a7 << 0));
	character[7] = ((h8 << 28) | (g8 << 24) | (f8 << 20) | (e8 << 16) | (d8 << 12) | (c8 << 8) | (b8 << 4) | (a8 << 0));
}

// *****************
// Sprite
// *****************
//manually add sprites to the sprite library
void mySprite_function(int tile_ref,
	int a1, int b1, int c1, int d1, int e1, int f1, int g1, int h1,
	int a2, int b2, int c2, int d2, int e2, int f2, int g2, int h2,
	int a3, int b3, int c3, int d3, int e3, int f3, int g3, int h3,
	int a4, int b4, int c4, int d4, int e4, int f4, int g4, int h4,
	int a5, int b5, int c5, int d5, int e5, int f5, int g5, int h5,
	int a6, int b6, int c6, int d6, int e6, int f6, int g6, int h6,
	int a7, int b7, int c7, int d7, int e7, int f7, int g7, int h7,
	int a8, int b8, int c8, int d8, int e8, int f8, int g8, int h8)
{
	int i = tile_ref * 8;//Works out the tile number 
	unsigned int *sprite = (unsigned int *)&point.spriteAddress[i];//creates a pointer to the sprite location

	sprite[0] = ((h1 << 28) | (g1 << 24) | (f1 << 20) | (e1 << 16) | (d1 << 12) | (c1 << 8) | (b1 << 4) | (a1 << 0)); //uses the pointer to set each row of the sprite
	sprite[1] = ((h2 << 28) | (g2 << 24) | (f2 << 20) | (e2 << 16) | (d2 << 12) | (c2 << 8) | (b2 << 4) | (a2 << 0));
	sprite[2] = ((h3 << 28) | (g3 << 24) | (f3 << 20) | (e3 << 16) | (d3 << 12) | (c3 << 8) | (b3 << 4) | (a3 << 0));
	sprite[3] = ((h4 << 28) | (g4 << 24) | (f4 << 20) | (e4 << 16) | (d4 << 12) | (c4 << 8) | (b4 << 4) | (a4 << 0));
	sprite[4] = ((h5 << 28) | (g5 << 24) | (f5 << 20) | (e5 << 16) | (d5 << 12) | (c5 << 8) | (b5 << 4) | (a5 << 0));
	sprite[5] = ((h6 << 28) | (g6 << 24) | (f6 << 20) | (e6 << 16) | (d6 << 12) | (c6 << 8) | (b6 << 4) | (a6 << 0));
	sprite[6] = ((h7 << 28) | (g7 << 24) | (f7 << 20) | (e7 << 16) | (d7 << 12) | (c7 << 8) | (b7 << 4) | (a7 << 0));
	sprite[7] = ((h8 << 28) | (g8 << 24) | (f8 << 20) | (e8 << 16) | (d8 << 12) | (c8 << 8) | (b8 << 4) | (a8 << 0));
}

// *****************
// Object list 
// ****************
//obj ref, 

//xCoor (0 - 511), ignore1, horizontal_flip (0 - 1), vertical_flip (0 - 1), size_lookup  (0 - 3), 
//sprite tile_number (0 - 1023), priority (0 - 3), palette (0 - 15),
//rotation and scaling

//adds sprite to the object list to be displayed
void myObj_function(int obj_ref,
	int yCoor, int rotation_scaling_flag, int object_disable, int ignore0, int shape_lookup,//yCoor (0 - 255),int rotation_scaling_flag (0-1) off/on, int object_disable (0-1) or double size flag (0-1) normal/double, int ignore0, int shape_lookup (0-3),
	int xCoor, int ignore1, int horizontal_flip, int vertical_flip, int size_lookup, //
	int tile_number, int priority, int palette,
	int rotation_scaling)
{
	int i = obj_ref * 4;//Works out the object tile number 
	unsigned short *obj = (unsigned short *)&point.obj_holderAddress[i];//sets the pointer to the object location

	obj[0] = ((shape_lookup << 14) | (ignore0 << 10) | (object_disable << 9) | (rotation_scaling_flag << 8) | (yCoor << 0)); //uses the pointer to set the values of the object 
	obj[1] = ((size_lookup << 14) | (vertical_flip << 13) | (horizontal_flip << 12) | (ignore1 << 9) | (xCoor << 0)); //xCoor (0 - 511), ignore if rotation/scaling not used, if it is, (0-31), horizontal_flip (0 - 1), vertical_flip (0 - 1), size_lookup  (0 - 3), 
	obj[2] = ((palette << 12) | (priority << 10) | (tile_number << 0));
	obj[3] = ((rotation_scaling << 0));
}


// *****************
// Draw 
// *****************
//draw - x, y, baseblock, pallet, character
//--- Draws one of the custom (font) characters added above (testing purposes)
//draws a character to the location specified 
void draw_function(int x, int y, int baseblock, int palette, int character)
{
	mybg_function(0, 1, 0, 0, 8, 0);
	mybg_function(1, 3, 0, 0, 11, 0);
	mybg_function(2, 2, 0, 0, 9, 0);
	mybg_function(3, 0, 0, 0, 4, 0);

	if (baseblock == 8)
	{
		point.base_block8[(y * 32) + x] = ((palette << 12) | (0 << 11) | (0 << 10) | (character << 0));
	}
	else if (baseblock == 9)
	{
		point.base_block9[(y * 32) + x] = ((palette << 12) | (0 << 11) | (0 << 10) | (character << 0));
	}
	else if (baseblock == 10)
	{
		point.base_block10[(y * 32) + x] = ((palette << 12) | (0 << 11) | (0 << 10) | (character << 0));
	}
	else if (baseblock == 11)
	{
		point.base_block11[(y * 32) + x] = ((palette << 12) | (0 << 11) | (0 << 10) | (character << 0));
	}
	else if (baseblock == 4)
	{
		point.base_block4[(y * 32) + x] = ((palette << 12) | (0 << 11) | (0 << 10) | (character << 0));
	}
}
void drawOtherfunction(int x, int y, int baseblock, int palette, int character)
{
	mybg_function(0, 0, 2, 0, 20, 0);
	mybg_function(1, 1, 2, 0, 24, 0);
	mybg_function(2, 2, 2, 0, 25, 0);
	mybg_function(3, 3, 2, 0, 27, 0);

	if (baseblock == 20)
	{
		point.base_block20[(y * 32) + x] = ((palette << 12) | (0 << 11) | (0 << 10) | (character << 0));
	}
	else if (baseblock == 24)
	{
		point.base_block24[(y * 32) + x] = ((palette << 12) | (0 << 11) | (0 << 10) | (character << 0));
	}
	else if (baseblock == 25)
	{
		point.base_block25[(y * 32) + x] = ((palette << 12) | (0 << 11) | (0 << 10) | (character << 0));
	}
	else if (baseblock == 26)
	{
		point.base_block26[(y * 32) + x] = ((palette << 12) | (0 << 11) | (0 << 10) | (character << 0));
	}
	else if (baseblock == 27)
	{
		point.base_block27[(y * 32) + x] = ((palette << 12) | (0 << 11) | (0 << 10) | (character << 0));
	}
}
//// *****************
//// Clear 
//// *****************
////clear - x, y, baseblock
//clears any character at location specified
void clear_function(int x, int y, int baseblock)
{
	if (baseblock == 8)
	{
		point.base_block8[(y * 32) + x] = ((0 << 12) | (0 << 11) | (0 << 10) | (0 << 0));
	}
	else if (baseblock == 9)
	{
		point.base_block9[(y * 32) + x] = ((0 << 12) | (0 << 11) | (0 << 10) | (0 << 0));
	}
	else if (baseblock == 10)
	{
		point.base_block10[(y * 32) + x] = ((0 << 12) | (0 << 11) | (0 << 10) | (0 << 0));
	}
	else if (baseblock == 11)
	{
		point.base_block11[(y * 32) + x] = ((0 << 12) | (0 << 11) | (0 << 10) | (0 << 0));
	}
	else if (baseblock == 4)
	{
		point.base_block4[(y * 32) + x] = ((0 << 12) | (0 << 11) | (0 << 10) | (0 << 0));
	}
	if (baseblock == 20)
	{
		point.base_block20[(y * 32) + x] = ((0 << 12) | (0 << 11) | (0 << 10) | (0 << 0));
	}
	else if (baseblock == 24)
	{
		point.base_block24[(y * 32) + x] = ((0 << 12) | (0 << 11) | (0 << 10) | (0 << 0));
	}
	else if (baseblock == 25)
	{
		point.base_block25[(y * 32) + x] = ((0 << 12) | (0 << 11) | (0 << 10) | (0 << 0));
	}
	else if (baseblock == 26)
	{
		point.base_block26[(y * 32) + x] = ((0 << 12) | (0 << 11) | (0 << 10) | (0 << 0));
	}
	else if (baseblock == 27)
	{
		point.base_block27[(y * 32) + x] = ((0 << 12) | (0 << 11) | (0 << 10) | (0 << 0));
	}
}
//CLEARS ALL CHARACTERS FROM SCREEN
void clearCharacters()
{
	int y;
	int x;
	int b;
	for (b = 8; b < 12; b++)
	{
		for (y = 0; y < 32; y++)
		{
			for (x = 0; x < 32; x++)
			{
				clear_function(x, y, 4);
				clear_function(x, y, b);
			}
		}
	}
}
//CLEARS ALL OBJECTS FROM SCREEN AND STOPS PLAYERS/ENEMIES FROM CONTINUING TO MOVE
void  clearObjects()
{

	playerClear();
	int i;
	for (i = 0; i < 128; i++)
	{
		myObj_function(i, 0, 0, 0, 0, 0, 240, 0, 0, 0, 0, 0, 0, 0, 0);
	}
}

void setupLevel(int levelNumber)
{
	player.positionX = XSTART;
	player.positionY = YSTART;
	setPlayerStartStats();
	playersetup(levelNumber);
	playerStart();
	enemyBattleSetup();
	int t;
	for (t = 0; t < 128; t++)
	{
		point.obj_holderAddress[(t * 4) + 1] = 240;//SETS ALL OBJECTS TO BE OFSCREEN BEFORE ACTUALLY SETTING THINGS UP
	}
	playersetup(levelNumber);
	playerStart();
	enemyBattleSetup();
}

int getxPos(int object)
{
	int maskR = 255;
	int xPos = point.obj_holderAddress[(object * 4) + 1] & maskR;
	return xPos;
}
int getyPos(int object)
{
	int maskR = 255;
	int yPos = point.obj_holderAddress[(object * 4)] & maskR;
	return yPos;
}
void moveUp(int object, int yPos)
{
	int maskL = 65280;
	if (collision(object, UP) != UP && borderCollision(object, UP) != UP)
	{
		point.obj_holderAddress[(object * 4)] &= maskL;
		point.obj_holderAddress[(object * 4)] |= (yPos - MOVE_SPEED);
		if (player.frame == FRAMETIME && (player.spriteRef != 40 || player.spriteRef != 42 || player.spriteRef != 44))
		{
			currentState = UP;
			player.spriteRef = 40;
			player.frame = 0;
		}
	}
}
void moveDown(int object, int yPos)
{
	int maskL = 65280;
	if (collision(object, DOWN) != DOWN && borderCollision(object, DOWN) != DOWN)
	{
		point.obj_holderAddress[(object * 4)] &= maskL;
		point.obj_holderAddress[(object * 4)] |= (yPos + MOVE_SPEED);
		if (player.frame == FRAMETIME && (player.spriteRef != 32 || player.spriteRef != 34 || player.spriteRef != 36 || player.spriteRef != 38))
		{
			currentState = DOWN;
			player.spriteRef = 32;
			player.frame = 0;
		}
	}
}
void moveLeft(int object, int xPos)
{
	int maskL = 65280;
	if (collision(object, LEFT) != LEFT && borderCollision(object, LEFT) != LEFT)
	{
		point.obj_holderAddress[(object * 4 + 1)] &= maskL;
		point.obj_holderAddress[(object * 4 + 1)] |= (xPos - MOVE_SPEED);
		if (player.frame == FRAMETIME && (player.spriteRef != 52 || player.spriteRef != 54 || player.spriteRef != 56))
		{
			currentState = LEFT;
			player.spriteRef = 52;
			player.frame = 0;
		}

	}
}
void moveRight(int object, int xPos)
{
	int maskL = 65280;
	if (collision(object, RIGHT) != RIGHT && borderCollision(object, RIGHT) != RIGHT)
	{
		point.obj_holderAddress[(object * 4 + 1)] &= maskL;
		point.obj_holderAddress[(object * 4 + 1)] |= (xPos + MOVE_SPEED);
		if (player.frame == FRAMETIME && (player.spriteRef != 46 || player.spriteRef != 48 || player.spriteRef != 50))
		{
			currentState = RIGHT;
			player.spriteRef = 46;
			player.frame = 0;
		}
	}
}

void enemyBattleSetup()
{
	int z = enemyNumberFunction();
	int e;
	levelSelectFunction();
	//SETS UP ALL ENEMIES DEFAULT INFO
	for (e = 0; e < (NUMBER_OF_ENEMIES + z); e++)
	{
		int t;
		enemy[e].damage = 10;
		enemy[e].defence = 40;
		enemy[e].maxHP = 40;
		enemy[e].currentHP = enemy[e].maxHP;
		for (t = 0; t < enemy[Battle.enemyRef].numberInGroup; t++)
		{
			enemy[Battle.enemyRef].enemyBattle[t].currentHP = enemy[e].currentHP;
		}
		//enemy[e].xPGive = enemy[e].xP * enemy[e].numberInGroup;
	}
}
//SETS UP THE PLAYERES X/Y POSITION AND THAT THE PLAYER WILL BE ALIVE - USED BELOW IN SETUP FUNCTION
void playerStart()
{

	point.obj_holderAddress[(player.objectRef * 4) + 1] = player.positionX;
	point.obj_holderAddress[(player.objectRef * 4)] = player.positionY;

	player.xPos = (unsigned short *)&point.obj_holderAddress[(player.objectRef * 4) + 1];
	player.yPos = (unsigned short *)&point.obj_holderAddress[(player.objectRef * 4)];
	player.alive = true;
	player.enable = 0;
	Menu.startPressed = false;
	Menu.selectPressed = false;
	Menu.aPressed = false;
	Menu.bPressed = false;
	player.score = player.score;
	player.time = 0;

	
}
void enemyStart()
{
	int z = enemyNumberFunction();
	int e;
	//SETS UP ALL ENEMIES DEFAULT INFO
	for (e = 0; e < (NUMBER_OF_ENEMIES + z); e++)
	{
		enemy[e].enable = 0;
		enemy[e].objectRef = (ENEMY_OBJECT_START + e);
		point.obj_holderAddress[(enemy[e].objectRef * 4) + 1] = enemy[e].xStart;
		point.obj_holderAddress[(enemy[e].objectRef * 4)] = enemy[e].yStart;
		enemy[e].xPos = (unsigned short *)&point.obj_holderAddress[(enemy[e].objectRef * 4) + 1];
		enemy[e].yPos = (unsigned short *)&point.obj_holderAddress[(enemy[e].objectRef * 4)];
		
	}

}
void enemyBattleStart()
{
	int e;
	//SETS UP ALL ENEMIES DEFAULT INFO for in battle
	for (e = 0; e < enemy[Battle.enemyRef].numberInGroup; e++)
	{
		enemy[Battle.enemyRef].enemyBattle[e].objectRef = (ENEMY_BATTLE_START + e);
		point.obj_holderAddress[(enemy[Battle.enemyRef].enemyBattle[e].objectRef * 4) + 1] =enemy[Battle.enemyRef].enemyBattle[e].xStart;
		point.obj_holderAddress[(enemy[Battle.enemyRef].enemyBattle[e].objectRef * 4)] =enemy[Battle.enemyRef].enemyBattle[e].yStart;
		enemy[Battle.enemyRef].enemyBattle[e].xPos = (unsigned short *)&point.obj_holderAddress[(enemy[Battle.enemyRef].enemyBattle[e].objectRef * 4) + 1];
		enemy[Battle.enemyRef].enemyBattle[e].yPos = (unsigned short *)&point.obj_holderAddress[(enemy[Battle.enemyRef].enemyBattle[e].objectRef * 4)];

	}

}
void setupBattle()
{
	int levelNumber = 1;
	playersetupBattle(levelNumber);
}
int collision(int object, int direction)
{
	int i = 1;
	int mask = 255;

	int object1x = point.obj_holderAddress[(object * 4) + 1] & mask; //sets the moving objects x
	int object1y = point.obj_holderAddress[(object * 4)] & mask; //sets the moving objects y

	for (i = 0; i < 128; i++) //checks every object against the current moving object
	{
		if (i != object)
		{
			int object2x = point.obj_holderAddress[(i * 4) + 1] & mask; //creates a temp x poistion to check against
			int object2y = point.obj_holderAddress[(i * 4)] & mask; //creates a temp y poistion to check against

			switch (direction)
			{
			case UP:
				if ((object1y <= (object2y + 8)) && (object1y >= object2y) && ((object1x + 7) >= object2x) && (object1x <= (object2x + 7)))
				{
					//doorCollision(i, object, player.level);
					enemyCollision(i, object, UP);
					//pickupCollision(i, object);
					return UP;
				}
				break;
			case DOWN:
				if (object == player.objectRef)
				{
					if ((((object1y + 12) >= object2y) && (object1y <= object2y) && ((object1x + 7) >= object2x) && (object1x <= (object2x + 7))))
					{
						//doorCollision(i, object, player.level);
						enemyCollision(i, object, DOWN);
						//pickupCollision(i, object);
						return DOWN;
					}
				}
				else
				{
					if ((((object1y + 8) >= object2y) && (object1y <= object2y) && ((object1x + 7) >= object2x) && (object1x <= (object2x + 7))))
					{
						//doorCollision(i, object, player.level);
						enemyCollision(i, object, DOWN);
						//pickupCollision(i, object);
						return DOWN;
					}
				}
				break;
			case LEFT:
				if (object == player.objectRef)
				{
					if (object1x >= (object2x + 8) && object1x <= (object2x + 8) && ((object1y + 11) >= object2y) && (object1y <= (object2y + 7)))
					{
						//doorCollision(i, object, player.level);
						enemyCollision(i, object, LEFT);
						//pickupCollision(i, object);
						return LEFT;
					}
				}
				else
				{
					if (object1x >= (object2x + 8) && object1x <= (object2x + 8) && ((object1y + 7) >= object2y) && (object1y <= (object2y + 7)))
					{
						//doorCollision(i, object, player.level);
						enemyCollision(i, object, LEFT);
						//pickupCollision(i, object);
						return LEFT;
					}
				}
			
				break;
			case RIGHT:
				if (object == player.objectRef)
				{
					if (((object1x + 8) >= object2x) && object1x <= (object2x) && ((object1y + 11) >= object2y) && (object1y <= (object2y + 7)))
					{
						//doorCollision(i, object, player.level);
						enemyCollision(i, object, RIGHT);
						//pickupCollision(i, object);
						return RIGHT;
					}
				}
				else
				{
					if (((object1x + 8) >= object2x) && object1x <= (object2x) && ((object1y + 7) >= object2y) && (object1y <= (object2y + 7)))
					{
						//doorCollision(i, object, player.level);
						enemyCollision(i, object, RIGHT);
						//pickupCollision(i, object);
						return RIGHT;
					}
				}
				break;
			}
		}
	}

	return 0;
}
// *****************
// BORDER COLLISION detection
// *****************
//border collision detection (checks the collisions against the border) - object ref, direction to check
int borderCollision(int object, int direction)
{
	int mask = 255;

	int objectX = point.obj_holderAddress[(object * 4) + 1] & mask; //sets the moving objects x
	int objectY = point.obj_holderAddress[(object * 4)] & mask; //sets the moving objects y
	switch (direction)
	{

	case UP:
		if (objectY == 0)
		{
			//int i;
			//for (i = 0; i < NUMBER_OF_ENEMIES; i++)
			//{
			//	if (object == ENEMY_OBJECT_START + i)
			//	{
			//		enemy[i].direction = random(UP);
			//	}
			//}
			return UP;

		}
		break;
	case DOWN:
		if (object == player.objectRef)
		{
			if (objectY+5 == HEIGHT)
			{
				//int i;
				//for (i = 0; i < NUMBER_OF_ENEMIES; i++)
				//{
				//	if (object == ENEMY_OBJECT_START + i)
				//	{
				//		enemy[i].direction = random(DOWN);
				//	}
				//}
				return DOWN;
			}
		}
		else
		{
			if (objectY == HEIGHT)
			{
				//int i;
				//for (i = 0; i < NUMBER_OF_ENEMIES; i++)
				//{
				//	if (object == ENEMY_OBJECT_START + i)
				//	{
				//		enemy[i].direction = random(DOWN);
				//	}
				//}
				return DOWN;
			}
		}
		break;
	case LEFT:
		if (objectX == 0)
		{
			//int i;
			//for (i = 0; i < NUMBER_OF_ENEMIES; i++)
			//{
			//	if (object == ENEMY_OBJECT_START + i)
			//	{
			//		enemy[i].direction = random(LEFT);
			//	}
			//}
			return LEFT;
		}
		break;
	case RIGHT:
		if (objectX == WIDTH)
		{
			//int i;
			//for (i = 0; i < NUMBER_OF_ENEMIES; i++)
			//{
			//	if (object == ENEMY_OBJECT_START + i)
			//	{
			//		enemy[i].direction = random(RIGHT);
			//	}
			//}
			return RIGHT;
		}
		break;

	}
	return 0;
}
void enemyCollision(int Object, int movingObject, int direction)
{
	int i;
	for (i = 0; i < (NUMBER_OF_ENEMIES + enemyNumberFunction()); i++)
	{
		if (movingObject == player.objectRef && enemy[i].alive == true)//makes sure enemy collisions is only run on the player (otherwise player would die if enemies collided)
		{
			int e = (ENEMY_OBJECT_START + i);//basically sets e to the enemies start object ref, if the object passed is the same as the enemies object, player will die
			if (Object == e)
			{
				for (int t = 0; t < NUMBER_OF_ENEMIES; t++)
				{
					enemy[t].enable = 1;
					Battle.enemyRef = enemy[t].refNumber;

				}
				Battle.enemyRef = e - 20;
				Battle.frame = 0;
				clearCharacters();
				enemyBattleSetup();
				battleMenuPos = attack;
				battleState = playerTurn;
				Menu.arrow = false;
				playState = battleSetup;
				player.positionX = *player.xPos;
				player.positionY = *player.yPos;
				mmStop();
				music = false;
			}
			
		}
		//else if (movingObject == ENEMY_OBJECT_START + i)
		//{
		//	for (int t = 0; t < NUMBER_OF_ENEMIES; t++)
		//	{
		//		enemy[t].enable = 1;
		//	}

		//	enemyBattle[movingObject].enable = 0;
		//	clearCharacters();
		//	playState = battle;
		//}
		
	}
}
void levelSelectFunction()
{
		//enemy 1 (map screen)
		enemy[0].xStart = 125;
		enemy[0].yStart = 25;
		enemy[0].numberInGroup = 2;
		enemy[0].refNumber = 0;
		//enemy 2
		enemy[1].xStart = 125;
		enemy[1].yStart = 100;
		enemy[1].numberInGroup = 3;
		enemy[1].refNumber = 1;
		//enemy 3
		enemy[2].xStart = 200;
		enemy[2].yStart = 60;
		enemy[2].numberInGroup = 1;
		enemy[2].refNumber = 2;
}
int enemyNumberFunction()
{
	int enemyNumber;

	enemyNumber = 3;

	return (enemyNumber - NUMBER_OF_ENEMIES);
}
void battlePosFunction(int numberInGroup)
{
	if (numberInGroup == 1)
	{
		enemy[Battle.enemyRef].enemyBattle[0].xStart = 185;
		enemy[Battle.enemyRef].enemyBattle[0].yStart = 55;
	}
	if (numberInGroup == 3)
	{
		enemy[Battle.enemyRef].enemyBattle[0].xStart = 185;
		enemy[Battle.enemyRef].enemyBattle[0].yStart = 25;
		enemy[Battle.enemyRef].enemyBattle[1].xStart = 185;
		enemy[Battle.enemyRef].enemyBattle[1].yStart = 85;
		enemy[Battle.enemyRef].enemyBattle[2].xStart = 185;
		enemy[Battle.enemyRef].enemyBattle[2].yStart = 55;
	}
	if (numberInGroup == 2)
	{
		enemy[Battle.enemyRef].enemyBattle[0].xStart = 185;
		enemy[Battle.enemyRef].enemyBattle[0].yStart = 25;
		enemy[Battle.enemyRef].enemyBattle[1].xStart = 185;
		enemy[Battle.enemyRef].enemyBattle[1].yStart = 85;
	}
	enemyBattleStart();
}
//calculates the actual damage done vs defence
int damageCalc(int currentHP, int damage, int defence)
{
	float fDamage = (float)damage;
	float fDefence = (float)defence;
	currentHP = currentHP - (fDamage - ((fDamage / fDefence) * 10));
	return currentHP;
}

void setPlayerStartStats()
{
	player.xP = 400;
	levelCheck();
}
void levelCheck()
{
	if (player.xP >= player.nextLevel)
	{
		player.currentLevel = player.currentLevel + 1;
		statCheck();
		player.currentHP = player.maxHP;
		player.currentMP = player.maxMP;
		if (player.xP >= player.nextLevel)
		{
			levelCheck();
		}
	}
}
void statCheck()
{
	int first, second, third, number;
	// ASM FUNCTION for calculating the required XP until next level, see below for the math breakdown (it works the same as in old, but using ASM)
	first = 20;
	second = player.currentLevel;
	third = 150;
	statMath(&first, &second, &third); 
	player.nextLevel = third;

	first = 3;
	second = player.endurance;
	third = player.currentLevel;
	statMath(&first, &second, &third);
	player.maxHP = third;

	first = 2;
	second = player.intelligence;
	third = player.currentLevel;
	statMath(&first, &second, &third);
	player.maxMP = third;

	//ASM Add function used to give the players stat values
	number = 3;
	addToTotal(&number, &player.currentLevel, &player.strength);
	addToTotal(&number, &player.currentLevel, &player.endurance);
	number = 2;
	addToTotal(&number, &player.currentLevel, &player.agility);
	addToTotal(&number, &player.currentLevel, &player.intelligence);

	//old code, I have basically rewritten this section completely with ASM
	/*player.nextLevel = (20 * (player.currentLevel * player.currentLevel) + 100 + 50);
	player.strength = (3 + player.currentLevel);
	player.agility = (2 + player.currentLevel);
	player.intelligence = (2 + player.currentLevel);
	player.endurance = (3 + player.currentLevel);
	player.maxHP = (3 * (player.endurance * player.endurance) + player.currentLevel);
	player.maxMP = (2 * (player.intelligence * player.intelligence) + player.currentLevel);*/
	if (player.currentHP > player.maxHP)
	{
		player.currentHP = player.maxHP;
	}
	if (player.maxHP > player.totalMaxHP)
	{
		player.maxHP = player.totalMaxHP;
	}
	if (player.currentMP > player.maxMP)
	{
		player.currentMP = player.maxMP;
	}
	if (player.maxMP > player.totalMaxMP)
	{
		player.maxMP = player.totalMaxMP;
	}
}

void calcStats(int number)
{
	if (items[number].inUse == true)
	{
		player.armourDefence += items[number].defence;
		player.weaponDamage += items[number].damage;
	}
	else
	{
		player.armourDefence -= items[number].defence;
		player.weaponDamage -= items[number].damage;
	}
	calcDamDef();
}
void calcDamDef()
{
	player.damage = player.strength + player.weaponDamage;
	if (player.damage > player.MaxDamage)
	{
		player.damage = player.MaxDamage;
	}
	player.defence = player.endurance + player.baseDefence + player.armourDefence;
	if (player.defence > player.MaxDefence)
	{
		player.defence = player.MaxDefence;
	}
}
void playerClear()
{
	player.upPressed = false;
	player.downPressed = false;
	player.leftPressed = false;
	player.rightPressed = false;
}
void move_function(int trigger, int object)
{
	int xPos = getxPos(object);
	int yPos = getyPos(object);

	if (trigger == UP)
	{
		moveUp(object, yPos);
	}
	if (trigger == DOWN)
	{
		moveDown(object, yPos);
	}
	if (trigger == LEFT)
	{
		moveLeft(object, xPos);
	}
	if (trigger == RIGHT)
	{
		moveRight(object, xPos);
	}
}
void moveCheck()
{
	if (player.upPressed)
	{

		move_function(UP, player.objectRef);
	}
	if (player.downPressed)
	{
		move_function(DOWN, player.objectRef);
	}
	if (player.leftPressed)
	{
		move_function(LEFT, player.objectRef);
	}
	if (player.rightPressed)
	{
		move_function(RIGHT, player.objectRef);
	}
}
void displayEnemyHP()
{
	if (battleState != itemMenu)
	{
		if (enemy[Battle.enemyRef].numberInGroup == 1)
		{
			iprintf("\x1b[7;26H%d", enemy[Battle.enemyRef].enemyBattle[0].currentHP);
		}
		if (enemy[Battle.enemyRef].numberInGroup == 2)
		{
			if (enemyBattlePos == top)
			{
				clear_function(26, 11, 4);
				clear_function(27, 11, 4);
				iprintf("\x1b[3;26H%d", enemy[Battle.enemyRef].enemyBattle[0].currentHP);
			}
			if (enemyBattlePos == bottom)
			{
				clear_function(26, 3, 4);
				clear_function(27, 3, 4);
				iprintf("\x1b[11;26H%d", enemy[Battle.enemyRef].enemyBattle[1].currentHP);
			}
		}
		if (enemy[Battle.enemyRef].numberInGroup == 3)
		{
			if (enemyBattlePos == top)
			{
				clear_function(26, 11, 4);
				clear_function(27, 11, 4);
				clear_function(26, 7, 4);
				clear_function(27, 7, 4);
				iprintf("\x1b[3;26H%d", enemy[Battle.enemyRef].enemyBattle[0].currentHP);
			}
			if (enemyBattlePos == bottom)
			{
				clear_function(26, 3, 4);
				clear_function(27, 3, 4);
				clear_function(26, 7, 4);
				clear_function(27, 7, 4);
				iprintf("\x1b[11;26H%d", enemy[Battle.enemyRef].enemyBattle[1].currentHP);
			}
			if (enemyBattlePos == middle)
			{
				clear_function(26, 11, 4);
				clear_function(27, 11, 4);
				clear_function(26, 3, 4);
				clear_function(27, 3, 4);
				iprintf("\x1b[7;26H%d", enemy[Battle.enemyRef].enemyBattle[2].currentHP);
			}
		}
	}
}
void runAnimation(int object, int spriteRef, int state, bool step)
{
	if (playState == map)
	{
		if (state == IDLE && object == player.objectRef)
		{
			if (player.frame == 300 && player.spriteRef == 32)
			{
				player.spriteRef = 34;
				player.frame = 0;
			}
			if (player.frame == 300 && player.spriteRef == 34)
			{
				player.spriteRef = 32;
				player.frame = 0;
			}
			if (player.frame == 600)
			{
				player.horFlip = 0;
				player.spriteRef = 32;
				player.frame = 0;
			}
		}
		if (state == RIGHT && object == player.objectRef)
		{
			if (player.frame == FRAMETIME && player.spriteRef == 46 && step == false)
			{
				player.spriteRef = 48;
				player.frame = 0;
			}
			if (player.frame == FRAMETIME && player.spriteRef == 48)
			{
				player.spriteRef = 46;
				player.step = true;
				player.frame = 0;
			}
			if (player.frame == FRAMETIME && player.spriteRef == 46 && step == true)
			{
				player.spriteRef = 50;
				player.step = false;
				player.frame = 0;
			}
			if (player.frame == FRAMETIME && player.spriteRef == 50)
			{
				player.spriteRef = 46;
				player.frame = 0;
			}
			if (player.frame == 5 && player.rightPressed == false)
			{
				player.spriteRef = 46;
				player.step = false;
				player.frame = 0;
			}
		}

		if (state == LEFT && object == player.objectRef)
		{
			if (player.frame == FRAMETIME && player.spriteRef == 52 && step == false)
			{
				player.spriteRef = 54;
				player.frame = 0;
			}
			if (player.frame == FRAMETIME && player.spriteRef == 54)
			{
				player.spriteRef = 52;
				player.step = true;
				player.frame = 0;
			}
			if (player.frame == FRAMETIME && player.spriteRef == 52 && step == true)
			{
				player.spriteRef = 56;
				player.step = false;
				player.frame = 0;
			}
			if (player.frame == FRAMETIME && player.spriteRef == 56)
			{
				player.spriteRef = 52;
				player.frame = 0;
			}
			if (player.frame == 5 && player.leftPressed == false)
			{
				player.spriteRef = 52;
				player.step = false;
				player.frame = 0;
			}
		}

		if (state == UP && object == player.objectRef)
		{
			if (player.frame == FRAMETIME && player.spriteRef == 40 && step == false)
			{
				player.spriteRef = 42;
				player.frame = 0;
			}
			if (player.frame == FRAMETIME && player.spriteRef == 42)
			{
				player.spriteRef = 40;
				player.step = true;
				player.frame = 0;
			}
			if (player.frame == FRAMETIME && player.spriteRef == 40 && step == true)
			{
				player.spriteRef = 44;
				player.step = false;
				player.frame = 0;
			}
			if (player.frame == FRAMETIME && player.spriteRef == 44)
			{
				player.spriteRef = 40;
				player.frame = 0;
			}
			if (player.frame == 5 && player.upPressed == false)
			{
				player.spriteRef = 40;
				player.step = false;
				player.frame = 0;
			}
		}
		if (state == DOWN && object == player.objectRef)
		{

			if (player.frame == FRAMETIME && player.spriteRef == 32)
			{
				player.spriteRef = 38;
				player.frame = 0;
			}
			if (player.frame == FRAMETIME && player.spriteRef == 38)
			{
				player.spriteRef = 34;
				player.frame = 0;
			}
			if (player.frame == FRAMETIME && player.spriteRef == 34)
			{
				player.spriteRef = 36;
				player.frame = 0;
			}
			if (player.frame == FRAMETIME && player.spriteRef == 36)
			{
				player.spriteRef = 32;
				player.frame = 0;
			}
			if (player.frame == 5 && player.downPressed == false)
			{
				player.spriteRef = 42;
				player.step = false;
				player.frame = 0;
			}
		}

	}
	if (playState == battle)
	{
		if (state == attacking && battleState == playerAttacking)
		{

			if (Battle.frame == (FRAMETIME * 2) && player.spriteRef == 66)
			{
				player.spriteRef = 68;
				draw_function(3, 7, 4, 0, 18);
				Battle.frame = 0;
			}
			if (Battle.frame == FRAMETIME && player.spriteRef == 68)
			{
				clearCharacters();
				player.spriteRef = 70;
				Battle.frame = 0;
				if (enemyBattlePos == top)
				{
					playSFX(32);
					draw_function(23, 3, 4, 0, 19);
					draw_function(24, 3, 4, 0, 20);
					draw_function(24, 4, 4, 0, 19);
					enemy[Battle.enemyRef].enemyBattle[0].currentHP = damageCalc(enemy[Battle.enemyRef].enemyBattle[0].currentHP, player.damage, enemy[Battle.enemyRef].enemyBattle[0].defence);
					
				}
				if (enemyBattlePos == middle)
				{
					if (enemy[Battle.enemyRef].numberInGroup == 1)
					{
						playSFX(32);
						draw_function(23, 7, 4, 0, 19);
						draw_function(24, 7, 4, 0, 20);
						draw_function(24, 8, 4, 0, 19);
						enemy[Battle.enemyRef].enemyBattle[0].currentHP = damageCalc(enemy[Battle.enemyRef].enemyBattle[0].currentHP, player.damage, enemy[Battle.enemyRef].enemyBattle[0].defence);
					}

					if (enemy[Battle.enemyRef].numberInGroup == 3)
					{
						playSFX(32);
						draw_function(23, 7, 4, 0, 19);
						draw_function(24, 7, 4, 0, 20);
						draw_function(24, 8, 4, 0, 19);
						enemy[Battle.enemyRef].enemyBattle[2].currentHP = damageCalc(enemy[Battle.enemyRef].enemyBattle[2].currentHP, player.damage, enemy[Battle.enemyRef].enemyBattle[2].defence);
					}
				}
				if (enemyBattlePos == bottom)
				{
					playSFX(32);
					draw_function(23, 11, 4, 0, 19);
					draw_function(24, 11, 4, 0, 20);
					draw_function(24, 12, 4, 0, 19);
					enemy[Battle.enemyRef].enemyBattle[1].currentHP = damageCalc(enemy[Battle.enemyRef].enemyBattle[1].currentHP, player.damage, enemy[Battle.enemyRef].enemyBattle[1].defence);
				}
			}
			if (Battle.frame == (FRAMETIME * 2) && player.spriteRef == 70)
			{
				player.spriteRef = 66;
				Battle.frame = 0;


				clearCharacters();
				battleState = enemyAttack;
				currentState = enemyAnimation;
			}
		}
		if (state == enemyAnimation && battleState == enemyAttacking)
		{
			int a;
			for (a = 0; a < enemy[Battle.enemyRef].numberInGroup; a++)
			{
				if (enemy[Battle.enemyRef].enemyBattle[a].alive)				//checks if the enemy is alive
				{
					if (Battle.frame == FRAMETIME && enemy[Battle.enemyRef].enemyBattle[a].spriteRef == 83 && enemy[Battle.enemyRef].enemyBattle[a].attacked == false)
					{
						clearCharacters();
						enemy[Battle.enemyRef].enemyBattle[a].shape = 1;
						enemy[Battle.enemyRef].enemyBattle[a].size = 2;
						enemy[Battle.enemyRef].enemyBattle[a].spriteRef = 87;
						Battle.frame = 0;

					}
					if (Battle.frame == FRAMETIME && enemy[Battle.enemyRef].enemyBattle[a].spriteRef == 87 && enemy[Battle.enemyRef].enemyBattle[a].attacked == false)
					{
						playSFX(32);
						draw_function(2, 7, 4, 0, 19);
						player.currentHP = damageCalc(player.currentHP, enemy[Battle.enemyRef].enemyBattle[a].damage, player.defence);
						Battle.frame = 0;
						enemy[Battle.enemyRef].enemyBattle[a].attacked = true;
						enemy[Battle.enemyRef].enemyBattle[a].spriteRef = 83;
						enemy[Battle.enemyRef].enemyBattle[a].shape = 0;
						enemy[Battle.enemyRef].enemyBattle[a].size = 1;

					}
					if (Battle.frame == FRAMETIME && enemy[Battle.enemyRef].numberInGroup == 3 && enemy[Battle.enemyRef].enemyBattle[0].attacked == true && enemy[Battle.enemyRef].enemyBattle[1].attacked == true && enemy[Battle.enemyRef].enemyBattle[2].attacked == true)
					{
						clearCharacters();
						Battle.frame = 0;
						battleState = playerTurn;
						currentState = battleIdle;
					}
					if (enemy[Battle.enemyRef].numberInGroup == 2 && enemy[Battle.enemyRef].enemyBattle[0].attacked == true && enemy[Battle.enemyRef].enemyBattle[1].attacked == true)
					{
						clearCharacters();
						Battle.frame = 0;
						battleState = playerTurn;
						currentState = battleIdle;
					}
					if (enemy[Battle.enemyRef].numberInGroup == 1 && enemy[Battle.enemyRef].enemyBattle[0].attacked == true)
					{
						clearCharacters();
						Battle.frame = 0;
						battleState = playerTurn;
						currentState = battleIdle;
					}

				}

			}


		}
	}
}

void playSFX(int effect)
{
	if (effect == 33)
	{
		mm_sound_effect sfxKACHING = {
			{ SFX_KACHING },			// id
			(int)(1.0f * (1 << 10)),	// rate
			50,		// handle
			100,	// volume
			127,	// panning
		};
		mmEffectEx(&sfxKACHING);
	}
	if (effect == 32)
	{
		mm_sound_effect sfxHIT = {
			{ SFX_HIT },			// id
			(int)(1.0f * (1 << 10)),	// rate
			0,		// handle
			75,	// volume
			127,	// panning
		};
		mmEffectEx(&sfxHIT);
	}
	if (effect == 31)
	{
		mm_sound_effect sfxCANCEL = {
			{ SFX_CANCEL },			// id
			(int)(1.0f * (1 << 10)),	// rate
			50,		// handle
			100,	// volume
			127,	// panning
		};
		mmEffectEx(&sfxCANCEL);
	}
}