/***********************************************************************
 * Class:	Map
 * Author:	Lucas Moyle
 * Date:	12/10/2019
 * Descrip: A better name for this class would have been "Game". That
 * 			said, Map represents the structure that is built around
 * 			the Player and Space objects. It controls the flow of the
 * 			game and calls the class' member functions to interact with
 * 			the space node web that this class sets up.
 **********************************************************************/

#include "Menu.hpp"
#include "ClassMap.hpp"
#include "ClassSpace.hpp"
#include "ClassForest.hpp"
#include "ClassMountain.hpp"
#include "ClassDesert.hpp"


/* Map()
 *
 * Summary: Constructor function that randomly generated the nodes
 * 			of the game map and connects them by setting their
 * 			member variable pointers.
 * Param:	NA
 * Returns:	NA
 */
Map::Map()
{
	currentDay = 1;

	startLocation = generateRandomSpace();
	oneOne = generateRandomSpace();
	twoOne = generateRandomSpace();
	twoTwo = generateRandomSpace();
	twoThree = generateRandomSpace();
	threeOne = generateRandomSpace();
	threeTwo = generateRandomSpace();
	threeThree = generateRandomSpace();
	threeFour = generateRandomSpace();
	fourOne = generateRandomSpace();
	fourTwo = generateRandomSpace();
	fourThree = generateRandomSpace();
	fiveOne = generateRandomSpace();
	fiveTwo = generateRandomSpace();
	endLocation = generateRandomSpace();

	startLocation->setPointers(NULL, oneOne, NULL, NULL, NULL);
	oneOne->setPointers(twoOne, twoTwo, twoThree, startLocation, NULL);
	twoOne->setPointers(threeOne, NULL, threeTwo, oneOne, NULL);
	twoTwo->setPointers(threeTwo, NULL, threeThree, oneOne, NULL);
	twoThree->setPointers(threeThree, NULL, threeFour, oneOne, NULL);
	threeOne->setPointers(NULL, fourOne, NULL, twoOne, NULL);
	threeTwo->setPointers(fourOne, NULL, fourTwo, twoOne, twoTwo);
	threeThree->setPointers(fourTwo, NULL, fourThree, twoTwo, twoThree);
	threeFour->setPointers(NULL, fourThree, NULL, twoThree, NULL);
	fourOne->setPointers(NULL, fiveOne, NULL, threeOne, threeTwo);
	fourTwo->setPointers(fiveOne, NULL, fiveTwo, threeTwo, threeThree);
	fourThree->setPointers(NULL, fiveTwo, NULL, threeThree, threeFour);
	fiveOne->setPointers(NULL, endLocation, NULL, fourOne, fourTwo);
	fiveTwo->setPointers(NULL, endLocation, NULL, fourTwo, fourThree);
	endLocation->setPointers(NULL, NULL, NULL, fiveOne, fiveTwo);

	ThePlayer.setPlayerLocation(startLocation);
}


/* ~Map()
 *
 * Summary: Destructor function that cleans up the dynamic memory
 * 			allocated for the random Space objects.
 * Param:	NA
 * Returns:	NA
 */
Map::~Map()
{
	delete startLocation;
	delete oneOne;
	delete twoOne;
	delete twoTwo;
	delete twoThree;
	delete threeOne;
	delete threeTwo;
	delete threeThree;
	delete threeFour;
	delete fourOne;
	delete fourTwo;
	delete fourThree;
	delete fiveOne;
	delete fiveTwo;
	delete endLocation;
}


/* Space* generateRandomSpace()
 *
 * Summary:	Dynamically creates a space object of one of three random
 * 			types and returns the pointer to it.
 * Param:	NA
 * Returns:	A pointer to the newly created object of a derived Space
 * 			class.
 */
Space* Map::generateRandomSpace()
{
	Space* temp;
	int random;

	random = (rand() % 3);

	if (random == 0)
	{
		temp = new Forest;
		return temp;
	}
	else if (random == 1)
	{
		temp = new Mountain;
		return temp;
	}
	else if (random == 2)
	{
		temp = new Desert;
		return temp;
	}
}


/* void movePlayer(Space*)
 *
 * Summary: A function that calls the Player function of the same name.
 * Param:	A pointer to the Space type object to move the player to.
 * Returns: NA
 */
void Map::movePlayer(Space* targetSpace)
{
	ThePlayer.setPlayerLocation(targetSpace);
}


/* void setupGame()
 *
 * Summary:	Displays game intro and instructions.
 * Param:	NA
 * Returns: NA
 */
void Map::setupGame()
{
	Menu ShopMenu;
	int choice;
	
	std::cout << std::endl;
	ShopMenu.prompt("You are a courier tasked with bringing cargo east to the coast across the frontier.");
	ShopMenu.prompt("You will travel through dangerous uncharted forests, mountains, and deserts to reach you destination");
	ShopMenu.prompt("How much cargo you decide to deliver is up to you but you have a maximum carrying capacity that you must balance with your supplies and equipment.");
	ShopMenu.prompt("You will consume supplies daily and equipment can be used to attempt to gather more supplies (success rate varies on terrain) and sometimes to cross terrain faster.");
	ShopMenu.prompt("If you run out of stamina or supplies in the wilderness, you will die.");
	std::cout << "You have " << maxDays << " days to reach the coast. Keep traveling east until you arrive or die." << std::endl;
	ShopMenu.prompt("If you manage to make it in time, your score will be based on how much cargo you delivered and how quickly you arrived.");

	std::cout << std::endl;
	std::cout << "You have " << ThePlayer.getMaxWeight() << " weight capacity. Each unit of supplies, equipment, and cargo weighs 1." << std::endl;

	ShopMenu.prompt("How much cargo would you like to attempt to deliver?");
	choice = ShopMenu.integerInput(1, ThePlayer.getMaxWeight());

	ThePlayer.setCargo(choice);
	
	ThePlayer.updateWeight();

	std::cout << "You have " << ThePlayer.getCurrentWeight() << "/" << ThePlayer.getMaxWeight() << " remaining weight capacity." << std::endl;

	ShopMenu.prompt("Much many units of supply would you like to bring?");

	choice = ShopMenu.integerInput(0, ThePlayer.getMaxWeight() - ThePlayer.getCurrentWeight());

	ThePlayer.setSupplies(choice);

	ThePlayer.updateWeight();
	
	std::cout << "You have " << ThePlayer.getCurrentWeight() << "/" << ThePlayer.getMaxWeight() << " remaining weight capacity." << std::endl;

	ShopMenu.prompt("Much many units of equipment would you like to bring?");

	choice = ShopMenu.integerInput(0, ThePlayer.getMaxWeight() - ThePlayer.getCurrentWeight());

	ThePlayer.setEquipment(choice);

	ThePlayer.updateWeight();

	std::cout << std::endl;
	std::cout << "GOOD LUCK ON YOUR JOURNEY!" << std::endl;
}


/* bool displayGameMenu()
 *
 * Summary: The primary working function of the game. Displays a menu
 * 			with all possible actions that the player can take for the
 * 			current day. Once and action is selected, the menu is
 * 			brought up again for the new node or for the updated
 * 			game values.
 * Param:	NA
 * Returns: A bool that if true, ends the game and returns to the main
 * 			menu.
 */
bool Map::displayGameMenu()
{
	Menu GameMenu;
	int menuChoice;

	//check for victory condition
	if (ThePlayer.getPlayerLocation() == endLocation)
	{
		std::cout << std::endl;
		std::cout << "You have made it to coast alive! You Win!" << std::endl;
		std::cout << "You did it with " << (maxDays - currentDay) << " days remaining!" << std::endl;
		std::cout << "You have managed to deliver " << ThePlayer.getCargo() << " units of cargo!" << std::endl;
		std::cout << "Your total score is: " << ((maxDays - currentDay) + ThePlayer.getCargo()) << std::endl;
		std::cout << std::endl << std::endl;

		return true;
	}	

	//check for loss condition
	if (ThePlayer.getStamina() <= 0)
	{
		std::cout << std::endl;
		std::cout << "You have run out of stamina and died alone in the wilderness. Game over.";
		std::cout << std::endl << std::endl;

		return true;
	}

	//check for loss condition
	if (currentDay > maxDays)
	{
		std::cout << std::endl;
		std::cout << "You have run out of time. Game over.";
		std::cout << std::endl << std::endl;

		return true;
	}

	ThePlayer.updateWeight();

	//display stats and menu
	std::cout << std::endl;
	std::cout << "~~~~~YOUR CURRENT STATUS~~~~~" << std::endl;
	std::cout << "Day: " << currentDay << " (must arrive by day " << maxDays << ")" << std::endl;
	std::cout << "Stamina: " << ThePlayer.getStamina() << "/" << ThePlayer.getMaxStamina() << std::endl;
	std::cout << "Supplies: " << ThePlayer.getSupplies() << std::endl;
	std::cout << "Equipment: " << ThePlayer.getEquipment() << std::endl;
	std::cout << "Cargo: " << ThePlayer.getCargo() << std::endl;
	std::cout << "Weight Capacity: " << ThePlayer.getCurrentWeight() << "/" << ThePlayer.getMaxWeight() << std::endl;

	std::cout << std::endl;
	ThePlayer.getPlayerLocation()->printDescription();
	GameMenu.prompt("What would you like to do?");
	GameMenu.prompt("1. Move on");
	GameMenu.prompt("2. Spend a day attempting to hunt/gather supplies");
	GameMenu.prompt("3. Rest for a day");
	std::cout << "4. " << ThePlayer.getPlayerLocation()->getSpecialMessage() << std::endl;
	GameMenu.prompt("5. Quit (does not save game)"); 

	menuChoice = GameMenu.integerInput(1, 5);

	if (menuChoice == 1)
	{
		int choice;
		choice = ThePlayer.getPlayerLocation()->printMoveOptions();
	
		int timeTemp;
		timeTemp = ThePlayer.getPlayerLocation()->getTime();

		int costTemp;
		costTemp = ThePlayer.getPlayerLocation()->getCost();

		std::string typeTemp;
		typeTemp = ThePlayer.getPlayerLocation()->getSpaceType();
		
		if (choice == 1)
		{
			movePlayer(ThePlayer.getPlayerLocation()->getUp());
		}
		else if (choice == 2)
		{
			movePlayer(ThePlayer.getPlayerLocation()->getForward());
		}
		else if (choice == 3)
		{
			movePlayer(ThePlayer.getPlayerLocation()->getDown());
		}
		else if (choice == 4)
		{
			movePlayer(ThePlayer.getPlayerLocation()->getBackUp());
		}
		else if (choice == 5)
		{
			movePlayer(ThePlayer.getPlayerLocation()->getBackDown());
		}

		ThePlayer.setStamina(ThePlayer.getStamina() - (timeTemp));

		ThePlayer.setSupplies(ThePlayer.getSupplies() - (timeTemp * costTemp));
		
		currentDay = (currentDay + timeTemp);

		std::cout << std::endl;
		std::cout << "You travel for " << timeTemp << " days through the " << typeTemp << " for a total cost of " << (timeTemp) << " stamina and " << (timeTemp * costTemp) << " supplies." << std::endl;

	}
	else if (menuChoice == 2)
	{
		if (ThePlayer.getPlayerLocation()->gatherSupplies(PlayerPtr) == true)
		{
			currentDay++;
		}
	}
	else if (menuChoice == 3)
	{
		if (ThePlayer.getPlayerLocation()->rest(PlayerPtr) == true)
		{
			currentDay++;
		}
	}
	else if (menuChoice == 4)
	{
		int choice;
		choice = ThePlayer.getPlayerLocation()->printMoveOptions();

		std::string typeTemp;
		typeTemp = ThePlayer.getPlayerLocation()->getSpaceType();

		if (ThePlayer.getPlayerLocation()->specialAction(PlayerPtr) == true)
		{
			if (choice == 1)
			{
				movePlayer(ThePlayer.getPlayerLocation()->getUp());
			}
			else if (choice == 2)
			{
				movePlayer(ThePlayer.getPlayerLocation()->getForward());
			}
			else if (choice == 3)
			{
				movePlayer(ThePlayer.getPlayerLocation()->getDown());
			}
			else if (choice == 4)
			{
				movePlayer(ThePlayer.getPlayerLocation()->getBackUp());
			}
			else if (choice == 5)
			{
				movePlayer(ThePlayer.getPlayerLocation()->getBackDown());
			}

			if (typeTemp == "Forest")
			{
				currentDay++;
			}
			else if (typeTemp == "Mountains")
			{
				currentDay++;
			}
			else if (typeTemp == "Desert")
			{
				currentDay = currentDay + 3;
			}
		}
	}	
	else if (menuChoice == 5)
	{
		return true;
	}

	return false;	
}

