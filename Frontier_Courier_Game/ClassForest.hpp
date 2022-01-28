/***********************************************************************
 * Class:	Forest
 * Author:	Lucas Moyle
 * Date:	12/10/2019
 * Descrip:	A dervied class of the Space type. Represents a forest that
 * 			the player moves through. Constructor function set member
 * 			variables that are specific to this derived class. 
 * 			See Space class for virtual functions descriptions.
 **********************************************************************/

#ifndef CLASSFOREST_HPP
#define CLASSFOREST_HPP

#include "ClassPlayer.hpp"
#include "ClassSpace.hpp"
#include <iostream>
#include <string>

class Forest : public Space
{
	
	private:

	public:
		
		Forest();

		virtual bool rest(Player*);
		virtual bool gatherSupplies(Player*);
		virtual void printDescription();
		virtual bool specialAction(Player*);
};

#endif
