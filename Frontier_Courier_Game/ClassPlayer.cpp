/***********************************************************************
 * Class:	Player
 * Author:	Lucas Moyle
 * Date:	12/10/2019
 * Descrip:	This class represents the Player who exists in a given
 * 			terrain node. It contains member variables which represent
 * 			the player's resources and the player's location and
 * 			functions that manipulate them.
 **********************************************************************/

#include "ClassPlayer.hpp"
#include "ClassSpace.hpp"

/* Player();
 *
 * Summary:	Constructor function that sets member variables to the
 * 			values at the start of the game which are not chosen by
 * 			the player.
 * Param:	NA
 * Returns:	NA
 */
Player::Player()
{
	playerName = "TempName";
	currentLocation = NULL;
	supplies = 0;
	equipment = 0;
	cargo = 0;
	currentWeight = (supplies + equipment + cargo);
	maxWeight = 40;
	stamina = 10;
	maxStamina = 10;
}


/* void setPlayerLocation(Space*)
 *
 * Summary: The function that moves the player between nodes.
 * Param:	A Pointer to the Space object that the player wants to
 * 			move to.
 * Returns: NA
 */
void Player::setPlayerLocation(Space* spaceIn)
{
	currentLocation = spaceIn;
}


/* void updateWeight()
 *
 * Summary: Weight is equal to the sum of resources which are member
 * 			variables of which the total needs to be updated regularly.
 * 			Equal to supplies + equipment + cargo.
 * Param:	NA
 * Returns:	NA
 */
void Player::updateWeight()
{
	currentWeight = (supplies + equipment + cargo);
}


/* Get/Set Functions
 *
 * Summary: Get and set functions for the various member variables of
 * 			Player.
 * Param:	An integer to set the variable to if it is a set function.
 * Returns:	The value of the variable of the same name if it is a get.
 */
Space* Player::getPlayerLocation()
{
	return currentLocation;
}


int Player::getSupplies()
{
	return supplies;
}

void Player::setSupplies(int input)
{
	supplies = input;
}

int Player::getEquipment()
{
	return equipment;
}

void Player::setEquipment(int equipIn)
{
	equipment = equipIn;
}

int Player::getCargo()
{
	return cargo;
}

void Player::setCargo(int cargoIn)
{
	cargo = cargoIn;
}

int Player::getCurrentWeight()
{
	return currentWeight;
}

int Player::getMaxWeight()
{
	return maxWeight;
}

int Player::getStamina()
{
	return stamina;
}

int Player::getMaxStamina()
{
	return maxStamina;
}

void Player::setStamina(int input)
{
	stamina = input;
}
