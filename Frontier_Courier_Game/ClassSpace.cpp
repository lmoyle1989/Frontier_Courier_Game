/***********************************************************************
 * Class:	Space
 * Author:	Lucas Moyle
 * Date:	12/10/2019
 * Descrip:	Space is an abstract class that is the parent class for
 * 			the objects that represent the terrain nodes in the game.
 * 			Each space object has 5 pointers that can link to other
 * 			spaces by which the player moves, 3 "east" or forward
 * 			pointers and 2 "backwards" pointers. The player exists
 * 			in a space node by way of a pointer to a space class
 * 			object in the player class' member vars.
 **********************************************************************/

#include "ClassPlayer.hpp"
#include "ClassSpace.hpp"
#include "Menu.hpp"
#include <iostream>
#include <string>


/* bool rest(Player*)
 * 
 * Summary: this function is purely virtual and represents the player
 * 			recovering stamina at the expense of other resources.
 * 			Rest is unique to each terrain type each with their own
 * 			requirements for doing so.
 * Param:	Pointer to the player object, this is needed in order to
 * 			manipulate Player member variables.
 * Returns:	A bool that is used by the calling function to determine
 * 			if the requirements are met for resting in a particular
 * 			node type.
 */
bool Space::rest(Player* playerPtr) 
{
}


/* bool gatherSupplies(Player*)
 *
 * Summary:	much like the rest function above, this functoin represemts
 * 			the player exchanging certain resources for others,
 * 			dependant on the terrain type.
 * Param:	Pointer to the player object such that its member vars can
 * 			be manipulated.
 * Returns:	Bool that is used by calling function to determine if
 * 			the requirements are met for a particular terrain.
 */
bool Space::gatherSupplies(Player* playerPtr)
{
}


/* void printDescription()
 *
 * Summary:	displays a description of a derived space objects that tells
 * 			the player what type of space they are in and what they can
 * 			do in it.
 * Param:	NA
 * Returns:	NA
 */
void Space::printDescription()
{
}


/* int printMoveOptions()
 *
 * Summary: Displays the available nodes that a player can move to from
 * 			the current node that they are in. This function is
 * 			inherited by all children.
 * Param:	NA
 * Returns:	An integer from 1-5 which corresponds to the choice of
 * 			pointer to the node that the player wants to move to.
 * 			Accepted by the calling function which does the actual
 * 			moving of the player.
 */
int Space::printMoveOptions()
{
	Menu MoveMenu;
	int moveChoice;
	bool upAble = false;
	bool forwardAble = false;
	bool downAble = false;
	bool backUpAble = false;
	bool backDownAble = false;

	std::cout << std::endl;
	std::cout << "Your movement options:" << std::endl;

	std::cout << "1. The trail northeast leads to ";
	if (up == NULL)
	{
		std::cout << "nowhere." << std::endl;
	}
	else if (up != NULL)
	{
		std::cout << up->getSpaceType() << "." << std::endl;
		upAble = true;
	}
	
	std::cout << "2. The trail east leads to ";
	if (forward == NULL)
	{
		std::cout << "nowhere." << std::endl;
	}
	else if (forward != NULL)
	{
		std::cout << forward->getSpaceType() << "." << std::endl;
		forwardAble = true;
	}
	
	std::cout << "3. The trail southeast leads to ";
	if (down == NULL)
	{
		std::cout << "nowhere." << std::endl;
	}
	else if (down != NULL)
	{
		std::cout << down->getSpaceType() << "." << std::endl;
		downAble = true;
	}

	std::cout << "4. The first trail back leads to ";
	if (backUp == NULL)
	{
		std::cout << "nowhere." << std::endl;
	}
	else if (backUp != NULL)
	{
		std::cout << backUp->getSpaceType() << "." << std::endl;
		backUpAble = true;
	}

	std::cout << "5. The second trail back leads to ";
	if (backDown == NULL)
	{
		std::cout << "nowhere." << std::endl;
	}
	else if (backDown != NULL)
	{
		std::cout << backDown->getSpaceType() << "." << std::endl;
		backDownAble = true;
	}
	
	while (true)
	{
		moveChoice = MoveMenu.integerInput("Choose your destination: ", 1, 5);

		if (moveChoice == 1)
		{
			if (upAble == true)
			{
				return 1;
			}
			else
			{
				std::cout << "That trail leads nowhere, choose again." << std::endl;
			}
		}
		else if (moveChoice == 2)
		{
			if (forwardAble == true)
			{
				return 2;
			}
			else
			{
				std::cout << "That trail leads nowhere, choose again." << std::endl;
			}
		}
		else if (moveChoice == 3)
		{
			if (downAble == true)
			{
				return 3;
			}
			else
			{
				std::cout << "That trail leads nowhere, choose again." << std::endl;
			}
		}
		else if (moveChoice == 4)
		{
			if (backUpAble == true)
			{
				return 4;
			}
			else
			{
				std::cout << "That trail leads nowhere, choose again." << std::endl;
			}
		}
		else if (moveChoice == 5)
		{
			if (backDownAble == true)
			{
				return 5;
			}
			else
			{
				std::cout << "That trail leads nowhere, choose again." << std::endl;
			}
		}
	}
}


/* bool specialAction(Player*)
 *
 * Summary:	Each derived terrain type has a special action that the
 * 			player can use to move through a type of terrain for
 * 			a different resource cost. Purely virtual.
 * Param:	Pointer to the play object such that its member vars can
 * 			be manipulated.
 * Returns: bool used by the calling function to determine if the 
 * 			requirements are met for the special action.
 */
bool Space::specialAction(Player*)
{
}


/* Space* getXXXXX()
 *
 * Summary:	Simple get functions that return a space class objects
 * 			pointers to adjacent nodes.
 * Param:	NA
 * Returns:	Pointer to a Space object that is a member variable of
 * 			the current node, representing adjacent spaces.
 */
Space* Space::getUp()
{
	return up;
}

Space* Space::getForward()
{
	return forward;
}

Space* Space::getDown()
{
	return down;
}

Space* Space::getBackUp()
{
	return backUp;
}

Space* Space::getBackDown()
{
	return backDown;
}


/* void setPointers(Space*, ... , Space*)
 *
 * Summary: A function used to set up the structure of the nodes.
 * 			Sets each of the 5 pointers in a space class object to
 * 			NULL or whatever node is chosen to be "adjacent" to it.
 * Param:	5 pointers to space class objects in the order of up,
 * 			forward, down, backup, backdown.
 * Returns: NA
 */
void Space::setPointers(Space* upIn, Space* forwardIn, Space* downIn, Space* backUpIn, Space* backDownIn)
{
	up = upIn;
	forward = forwardIn;
	down = downIn;
	backUp = backUpIn;
	backDown = backDownIn;
}


/* string/int getXXXX()
 *
 * Summary: Get functions for member variables of a Space type object.
 * Param:	NA
 * Returns:	The value of the member variable of the same name.
 */
std::string Space::getSpaceType()
{
	return this->spaceType;
}

std::string Space::getSpecialMessage()
{
	return this->specialActionMessage;
}

int Space::getTime()
{
	return travelTime;
}

int Space::getCost()
{
	return supplyCost;
}
