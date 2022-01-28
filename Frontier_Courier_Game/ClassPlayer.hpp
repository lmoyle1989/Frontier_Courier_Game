/***********************************************************************
 * Class:	Player
 * Author:	Lucas Moyle
 * Date:	12/10/2019
 * Descrip:	This class represents the Player who exists in a given
 * 			terrain node. It contains member variables which represent
 * 			the player's resources and the player's location and
 * 			functions that manipulate them.
 **********************************************************************/

#ifndef CLASSPLAYER_HPP
#define CLASSPLAYER_HPP

#include "ClassSpace.hpp"
#include <string>

class Player
{
	private:

		std::string playerName;
		Space* currentLocation;
		int supplies;
		int equipment;
		int cargo;
		int currentWeight;
		int maxWeight;
		int stamina;
		int maxStamina;

	public:

/* Player();
 *
 * Summary:	Constructor function that sets member variables to the
 * 			values at the start of the game which are not chosen by
 * 			the player.
 * Param:	NA
 * Returns:	NA
 */
		Player();


/* void setPlayerLocation(Space*)
 *
 * Summary: The function that moves the player between nodes.
 * Param:	A Pointer to the Space object that the player wants to
 * 			move to.
 * Returns: NA
 */
		void setPlayerLocation(Space*);


/* void updateWeight()
 *
 * Summary: Weight is equal to the sum of resources which are member
 * 			variables of which the total needs to be updated regularly.
 * 			Equal to supplies + equipment + cargo.
 * Param:	NA
 * Returns:	NA
 */
		void updateWeight();


/* Get/Set Functions
 *
 * Summary: Get and set functions for the various member variables of
 * 			Player.
 * Param:	An integer to set the variable to if it is a set function.
 * Returns:	The value of the variable of the same name if it is a get.
 */
		Space* getPlayerLocation();	
		int getSupplies();
		void setSupplies(int);
		int getEquipment();
		void setEquipment(int);
		int getCargo();
		void setCargo(int);
		int getCurrentWeight();
		int getMaxWeight();
		int getStamina();
		int getMaxStamina();
		void setStamina(int);
};

#endif
