/***********************************************************************
 * Class:	Mountain
 * Author:	Lucas Moyle
 * Date:	12/10/2019
 * Descrip:	A dervied class of the Space type. Represents mountains that
 * 			the player moves through. Constructor function sets member
 * 			variables that are specific to this derived class. 
 * 			See Space class for virtual functions descriptions.
 **********************************************************************/

#include "ClassPlayer.hpp"
#include "ClassMountain.hpp"
#include "ClassSpace.hpp"
#include <iostream>
#include <string>
	
Mountain::Mountain()
{	
	backUp = NULL;
	backDown = NULL;
	forward = NULL;
	up = NULL;
	down = NULL;	

	spaceType = "Mountains";
	specialActionMessage = "Use 1 equipment to move through the mountains in 1 day.";

	travelTime = 3;
	supplyCost = 1;
}

bool Mountain::rest(Player* playerPtr)
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
		std::cout << "You rest in the mountains for the night. (-1 supplies, +1 stamina)" << std::endl;
		playerPtr->setStamina(playerPtr->getStamina() + 1);
		playerPtr->setSupplies(playerPtr->getSupplies() - 1);
		return true;
	}
}

bool Mountain::gatherSupplies(Player* playerPtr)
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

		if (successChance <= 50)
		{
			std::cout << std::endl;
			std::cout << "You successfully hunt in the mountains and gain 2 supplies and lose 1 equipment." << std::endl;
			
			playerPtr->setEquipment(playerPtr->getEquipment() - 1);

			playerPtr->setSupplies(playerPtr->getSupplies() + 2);
		}
		else
		{
			std::cout << std::endl;
			std::cout << "Your mountain hunt is unsuccessful and you lose 1 equipment." << std::endl;

			playerPtr->setEquipment(playerPtr->getEquipment() - 1);
		}

		return true;
	}
}

void Mountain::printDescription()
{
	std::cout << "You are in a the cold a foreboding mountains." << std::endl; 
	std::cout << "It takes 3 days to move through mountain terrain and costs 1 supply per day." << std::endl; 
	std::cout << "You can rest here for a day at the cost of 1 supply." << std::endl; 
	std::cout << "You can use 1 piece of equipment to for climbing assistance and move through the mountains in 1 day." << std::endl;
	std::cout << "There is a moderate chance that hunting and gathering will be successful here." << std::endl;
	std::cout << std::endl;
}

bool Mountain::specialAction(Player* playerPtr)
{
	if (playerPtr->getEquipment() <= 0)
	{
		std::cout << std::endl;
		std::cout << "You do not have enough equipment to do this." << std::endl;
		
		return false;
	}
	else
	{
		std::cout << std::endl;
		std::cout << "You fashion some climbing gear out of your equipment and move the through the mountains quickly for a total cost of 1 stamina, 1 supply, and 1 equipment.";
		std::cout << std::endl;

		playerPtr->setEquipment(playerPtr->getEquipment() - 1);

		playerPtr->setStamina(playerPtr->getStamina() - 1);

		playerPtr->setSupplies(playerPtr->getSupplies() - 1);	

		return true;
	}
}

