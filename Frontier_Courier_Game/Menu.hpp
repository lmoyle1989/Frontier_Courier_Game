/***********************************************************************
 * Class Name: Menu
 * Author: Lucas Moyle
 * Date: 11/10/2019
 * Description: This is the header file for the object class
 * "Menu". This class will serve as a generic set of functions to use
 * with my programs for CS162. The functions consist of prompting the
 * user for a particular type of input and then validating that input
 * to ensure it is of the expected type and within the expected range
 * of acceptable values. Currently, only integer input is implemented
 * however additional functions for strings, floats, chars, etc. will
 * be added as needed.
 **********************************************************************/


#ifndef MENU_HPP
#define MENU_HPP


#include <iostream>
#include <string>

class Menu
{
	private:
	
	public:

/* void prompt(string stringIn)
 *
 * Summary: This function will simply print out a string input by the
 * 			coder, followed by a new line.
 * Param:	A string that the coder wants to see printed.
 * Returns:	N/A
 */
		void prompt(std::string stringIn);


/* int integerInput(int min, int max)
 *
 * Summary:	This function prompts the user for an integer input and then
 *			returns that value if it is within the desired range and
 *			validated to be an integer.
 * Param: 	int min - This parameter represents the minimum value that
 * 			is acceptable for a given call of this function. If the user
 * 			input a number less than this, the function will print an
 * 			error message and ask for input repeatedly until satisfied.
 * Param:	int max - This parameter function analogously to the
 * 			minimum parameter above, expect for the maximum
 * 			acceptable value.
 * Returns:	The user's inputted integer if it is within the min-max
 * 			range and is validated to be an integer.
 */
		int integerInput(int, int);


/* int integerInput(string promptInput, int min, int max)
 *
 * Summary:	This function is an overloaded version of the function
 * 			above with an extra string parameter. It functions the
 * 			same way however in addition to the generic prompt to enter
 * 			an integer between the min and max values, the function
 * 			also prints a string for the user as an additional prompt.
 * Param:	string promptInput - This parameter is the prompt that
 * 			will appear when the function is called. 
 * Param: 	int min - This parameter represents the minimum value that
 * 			is acceptable for a given call of this function. If the user
 * 			input a number less than this, the function will print an
 * 			error message and ask for input repeatedly until satisfied.
 * Param:	int max - This parameter function analogously to the
 * 			minimum parameter above, expect for the maximum
 * 			acceptable value.
 * Returns:	The user's inputted integer if it is within the min-max
 * 			range and is validated to be an integer.
 */
		int integerInput(std::string, int, int);


/* int integerInput()
 *
 * Summary:	Similar to the other integer input functions however this
 * 			one has no min or max and will allow the user to enter any
 * 			integer.
 * Param:	N/A
 * Returns:	An integer that is the one the user input, if it is
 * 			confirmed to be an integer.
 */
		int integerInput();

		int integerInputNoPrompt(int, int);

		int minIntegerInput(int);

		std::string stringInput();
};

#endif

