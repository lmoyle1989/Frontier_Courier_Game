/***********************************************************************
 * Class:	Desert
 * Author:	Lucas Moyle
 * Date:	12/10/2019
 * Descrip:	A dervied class of the Space type. Represents a desert that
 * 			the player moves through. Constructor function sets member
 * 			variables that are specific to this derived class. 
 * 			See Space class for virtual functions descriptions.
 **********************************************************************/

#ifndef CLASSDESERT_HPP
#define CLASSDESERT_HPP

#include "ClassPlayer.hpp"
#include "ClassSpace.hpp"
#include <iostream>
#include <string>

class Desert : public Space
{
	
	private:

	public:
		
		Desert();

		virtual bool rest(Player*);
		virtual bool gatherSupplies(Player*);
		virtual void printDescription();
		virtual bool specialAction(Player*);	
	
};

#endif
