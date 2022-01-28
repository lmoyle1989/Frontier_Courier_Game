/***********************************************************************
 * Class:	Desert
 * Author:	Lucas Moyle
 * Date:	12/10/2019
 * Descrip:	A dervied class of the Space type. Represents a desert that
 * 			the player moves through. Constructor function sets member
 * 			variables that are specific to this derived class. 
 * 			See Space class for virtual functions descriptions.
 **********************************************************************/

#include "ClassPlayer.hpp"
#include "ClassDesert.hpp"
#include "ClassSpace.hpp"
#include <iostream>
#include <string>
	
Desert::Desert()
{	
	backUp = NULL;
	backDown = NULL;
	forward = NULL;
	up = NULL;
	down = NULL;	

	spaceType = "Desert";
	specialActionMessage = "Take a detour and spend an extra day in the desert but reduce total supply cost to 1.";

	travelTime = 2;
	supplyCost = 2;
}

bool Desert::rest(Player* playerPtr)
{
	std::cout << std::endl;
	if (playerPtr->getSupplies() <= 1)
	{
		std::cout << "You do not have have enough supplies to rest here." << std::endl;
		return false;
	}
	else if (playerPtr->getStamina() >= playerPtr->getMaxStamina())
	{
		std::cout << "You already have maximum stamina and cannot rest." << std::endl;
		return false;
	}
	else
	{
		std::cout << "You rest in the desert for the night. (-2 supplies, +1 stamina)" << std::endl;
		playerPtr->setStamina(playerPtr->getStamina() + 1);
		playerPtr->setSupplies(playerPtr->getSupplies() - 2);
		return true;
	}

}

bool Desert::gatherSupplies(Player* playerPtr)
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

		if (successChance <= 25)
		{
			std::cout << std::endl;
			std::cout << "You successfully use your equipment to gather food and water and gain 2 supplies and lose 1 equipment." << std::endl;
			
			playerPtr->setEquipment(playerPtr->getEquipment() - 1);

			playerPtr->setSupplies(playerPtr->getSupplies() + 2);
		}
		else
		{
			std::cout << std::endl;
			std::cout << "You search the desert for anything edible but you are unsuccessful and you lose 1 equipment." << std::endl;

			playerPtr->setEquipment(playerPtr->getEquipment() - 1);
		}

		return true;
	}
}

void Desert::printDescription()
{
	std::cout << "You find yourself in the harsh barren desert." << std::endl;
	std::cout << "It takes 2 days to cross the desert normally and costs 2 supplies per day due to the scarcity of resources." << std::endl;
	std::cout << "You can rest here for a night at the cost of 2 supplies." << std::endl;
	std::cout << "You can take a detour to find water but it will take 3 days total to cross the desert. However it will only cost 1 supply total." << std::endl;
	std::cout << "Hunting and gathering supplies here will most likely yield nothing." << std::endl;
	std::cout << std::endl;
}

bool Desert::specialAction(Player* playerPtr)
{
	std::cout << std::endl;
	std::cout << "You take a detour to an oasis and save some supplies. You continue through the desert for a total cost of 1 supply and 3 stamina over 3 days.";
	std::cout << std::endl;
	
	playerPtr->setSupplies(playerPtr->getSupplies() - 1);

	playerPtr->setStamina(playerPtr->getStamina() - 3);

	return true;
}
