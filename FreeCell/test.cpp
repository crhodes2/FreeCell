/*========================================================

Name:         CHRISTIAN RHODES
Class:        CST 211 - DATA STRUCTURES
HW:           LAB - FREECELL
File:         test.h

========================================================*/

#include "freecell.h"

#include <crtdbg.h> 
#define _CRTDBG_MAP_ALLOC

void main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	freeCell freecellGame;
	freecellGame.RunGame();
}