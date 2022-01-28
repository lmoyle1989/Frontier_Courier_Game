/***********************************************************************
 * Class:	Forest
 * Author:	Lucas Moyle
 * Date:	12/10/2019
 * Descrip:	A dervied class of the Space type. Represents a forest that
 * 			the player moves through. Constructor function set member
 * 			variables that are specific to this derived class. 
 * 			See Space class for virtual functions descriptions.
 **********************************************************************/

#include "ClassPlayer.hpp"
#include "ClassForest.hpp"
#include "ClassSpace.hpp"
#include <iostream>
#include <string>


Forest::Forest()
{	
	backUp = NULL;
	backDown = NULL;
	forward = NULL;
	up = NULL;
	down = NULL;	

	spaceType = "Forest";
	specialActionMessage = "Spend 3 total stamina and move through the forest in 1 day.";

	travelTime = 2;
	supplyCost = 1;
}


bool Forest::rest(Player* playerPtr) 
{
	std::cout << std::endl;
	if (playerPtr->getSupplies() <= 0)
	{
		std::cout << "You have no supplies and cannot rest." << std::endl;
		return false;
	}
	else if (playerPtr->getStamina() >= playerPtr->getMaxStamina())
	{
		std::cout << "You already have maximum stamina and cannot rest." << std::endl;
		return false;
	}
	else
	{
		std::cout << "You rest in the forest for the night. (-1 supplies, +1 stamina)" << std::endl;
		playerPtr->setStamina(playerPtr->getStamina() + 1);
		playerPtr->setSupplies(playerPtr->getSupplies() - 1);
		return true;
	}
}


bool Forest::gatherSupplies(Player* playerPtr)
{
	if (playerPtr->getEquipment() < 1)
	{
		std::cout << std::endl;
		std::cout << "You have no equipment to hunt or gather with." << std::endl;	

		return false;
	}
	else if (playerPtr->getCurrentWeight() >= (playerPtr->getMaxWeight() - 1))
	{
		std::cout << std::endl;
		std::cout << "You do not have enough weight capacity for any more supplies." << std::endl;

		return false;
	}
	else
	{
		int successChance;
		successChance = ((rand() % 100) + 1);

		if (successChance <= 75)
		{
			std::cout << std::endl;
			std::cout << "You successfully hunt in the forest and gain 2 supplies and lose 1 equipment." << std::endl;
			
			playerPtr->setEquipment(playerPtr->getEquipment() - 1);

			playerPtr->setSupplies(playerPtr->getSupplies() + 2);
		}
		else
		{
			std::cout << std::endl;
			std::cout << "Your forest hunt is unsuccessful and you lose 1 equipment." << std::endl;

			playerPtr->setEquipment(playerPtr->getEquipment() - 1);
		}

		return true;
	}
}

void Forest::printDescription()
{
	std::cout << "You are in a woodland forest." << std::endl;
	std::cout << "It takes 2 days to move through forest terrain and costs 1 supply per day." << std::endl; 
	std::cout << "You can rest here for a day at the cost of 1 supply." << std::endl; 
	std::cout << "You can spend 2 extra stamina to move through the forest in only 1 day (3 stamina total)." << std::endl;
	std::cout << "There is a good chance that hunting and gathering supplies in the forest will be successful." <<std::endl;
	std::cout << std::endl;
}

bool Forest::specialAction(Player* playerPtr)
{
	std::cout << std::endl;
	std::cout << "You exert yourself and move through the forest quickly in 1 day for a total cost of 3 stamina and 1 supply.";
	std::cout << std::endl;
	
	playerPtr->setStamina(playerPtr->getStamina() - 3);

	playerPtr->setSupplies(playerPtr->getSupplies() - 1);

	return true;
}
