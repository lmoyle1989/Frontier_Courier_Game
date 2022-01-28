/***********************************************************************
 * Class:	Mountain
 * Author:	Lucas Moyle
 * Date:	12/10/2019
 * Descrip:	A dervied class of the Space type. Represents mountains that
 * 			the player moves through. Constructor function sets member
 * 			variables that are specific to this derived class. 
 * 			See Space class for virtual functions descriptions.
 **********************************************************************/

#ifndef CLASSMOUNTAIN_HPP
#define CLASSMOUNTAIN_HPP

#include "ClassPlayer.hpp"
#include "ClassSpace.hpp"
#include <iostream>
#include <string>

class Mountain : public Space
{
	
	private:

	public:
		
		Mountain();

		virtual bool rest(Player*);
		virtual bool gatherSupplies(Player*);
		virtual void printDescription();
		virtual bool specialAction(Player*);
};

#endif
