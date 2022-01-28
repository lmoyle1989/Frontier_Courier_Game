/***********************************************************************
 * Program:	FRONTIER COURIER
 * Author:	Lucas Moyle
 * Date:	12/10/2019
 * Descrip:	This is a game that is somewhat "Oregon Trail"-esque. It is
 * 			based around linked terrain nodes that the player can
 * 			travel through an interact with. The player must move
 * 			through a "web" of randomly generated connected terrain 
 * 			nodes with a limited amount of resources that can be spent 
 * 			and exchanged for each other using actions that depend on 
 * 			the terrain types. The goal of the game is to reach the 
 * 			right-most node in the node web alive and the score is based 
 * 			on the remaining resources and time to arrive.
 **********************************************************************/

#include <iostream>
#include "Menu.hpp"
#include "ClassSpace.hpp"
#include "ClassMap.hpp"
#include <cstdlib>

int main()
{
	srand(time(0));
	bool quit = false;
	bool gameQuit = false;
	int menuChoice;
	Menu MainMenu;

	while(!quit)
	{
		std::cout << std::endl;
		MainMenu.prompt("Welcome to 'FRONTIER COURIER'");
		MainMenu.prompt("Choose and option:");
		MainMenu.prompt("1. Start new game");
		MainMenu.prompt("2. Quit");
		
		menuChoice = MainMenu.integerInput(1, 2);

		if (menuChoice == 1)
		{
			gameQuit = false;
			Map GameMap;

			GameMap.setupGame();

			while (!gameQuit)
			{
				gameQuit = GameMap.displayGameMenu();
			}
		}

		else if (menuChoice == 2)
		{
			quit = true;
		}
	}

	return 0;
}

