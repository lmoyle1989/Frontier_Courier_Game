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

#ifndef CLASSSPACE_HPP
#define CLASSSPACE_HPP

#include <string>

//this is a forward declaration for the class Player because
//Player and Space circularly reference each other's headers
class Player;

class Space
{
	protected:
		
		Space* backUp;
		Space* backDown;
		Space* forward;
		Space* up;
		Space* down;
		
		std::string spaceType;
		std::string specialActionMessage;
		
		int travelTime;
		int supplyCost;

	public:
		
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
		virtual bool rest(Player*) = 0;


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
		virtual bool gatherSupplies(Player*) = 0;


/* void printDescription()
 *
 * Summary:	displays a description of a derived space objects that tells
 * 			the player what type of space they are in and what they can
 * 			do in it.
 * Param:	NA
 * Returns:	NA
 */
		virtual void printDescription() = 0;


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
		virtual bool specialAction(Player*) = 0;
	

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
		int printMoveOptions();


/* Space* getXXXXX()
 *
 * Summary:	Simple get functions that return a space class objects
 * 			pointers to adjacent nodes.
 * Param:	NA
 * Returns:	Pointer to a Space object that is a member variable of
 * 			the current node, representing adjacent spaces.
 */
		Space* getUp();
		Space* getForward();
		Space* getDown();
		Space* getBackUp();
		Space* getBackDown();


/* void setPointers(Space*, ... , Space*)
 *
 * Summary: A function used to set up the structure of the nodes.
 * 			Sets each of the 5 pointers in a space class object to
 * 			NULL or whatever node is chosen to be "adjacent" to it.
 * Param:	5 pointers to space class objects in the order of up,
 * 			forward, down, backup, backdown.
 * Returns: NA
 */
		void setPointers(Space*, Space*, Space*, Space*, Space*);


/* string/int getXXXX()
 *
 * Summary: Get functions for member variables of a Space type object.
 * Param:	NA
 * Returns:	The value of the member variable of the same name.
 */
		std::string getSpaceType();
		std::string getSpecialMessage();
		int getTime();
		int getCost();
};

#endif
