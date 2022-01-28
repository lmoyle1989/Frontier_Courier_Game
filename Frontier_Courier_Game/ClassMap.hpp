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

#ifndef CLASSMAP_HPP
#define CLASSMAP_HPP

#include "ClassSpace.hpp"
#include "ClassPlayer.hpp"

class Map
{
	private:

		int currentDay;
		const int maxDays = 20;
		Player ThePlayer;
		Player* PlayerPtr = &ThePlayer;
		
		Space* startLocation;
		Space* oneOne;
		Space* twoOne;
		Space* twoTwo;
		Space* twoThree;
		Space* threeOne;
		Space* threeTwo;
		Space* threeThree;
		Space* threeFour;
		Space* fourOne;
		Space* fourTwo;
		Space* fourThree;
		Space* fiveOne;
		Space* fiveTwo;
		Space* endLocation;


	public:

/* Map()
 *
 * Summary: Constructor function that randomly generated the nodes
 * 			of the game map and connects them by setting their
 * 			member variable pointers.
 * Param:	NA
 * Returns:	NA
 */
		Map();


/* ~Map()
 *
 * Summary: Destructor function that cleans up the dynamic memory
 * 			allocated for the random Space objects.
 * Param:	NA
 * Returns:	NA
 */
		~Map();


/* Space* generateRandomSpace()
 *
 * Summary:	Dynamically creates a space object of one of three random
 * 			types and returns the pointer to it.
 * Param:	NA
 * Returns:	A pointer to the newly created object of a derived Space
 * 			class.
 */
		Space* generateRandomSpace();


/* void setupGame()
 *
 * Summary:	Displays game intro and instructions.
 * Param:	NA
 * Returns: NA
 */
		void setupGame();


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
		bool displayGameMenu();


/* void movePlayer(Space*)
 *
 * Summary: A function that calls the Player function of the same name.
 * Param:	A pointer to the Space type object to move the player to.
 * Returns: NA
 */
		void movePlayer(Space*);
};

#endif
