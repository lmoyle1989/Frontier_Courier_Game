/***********************************************************************
 * Class Name: Menu
 * Author: Lucas Moyle
 * Date: 10/20/2019
 * Description: This is the implementation file for the object class
 * "Menu". This class will serve as a generic set of functions to use
 * with my programs for CS162. The functions consist of prompting the
 * user for a particular type of input and then validating that input
 * to ensure it is of the expected type and within the expected range
 * of acceptable values. Currently, only integer input is implemented
 * however additional functions for strings, floats, chars, etc. will
 * be added as needed.
 **********************************************************************/


#include "Menu.hpp"
#include <iostream>
#include <string>
#include <sstream>


/* void prompt(string stringIn)
 *
 * Summary: This function will simply print out a string input by the
 * 			coder, followed by a new line.
 * Param:	A string that the coder wants to see printed.
 * Returns:	N/A
 */
void Menu::prompt(std::string stringIn)
{
	std::cout << stringIn;
	std::cout << std::endl;
}


/* int integerInput(int min, int max)
 *
 * Summary:	This function prompts the user for an integer input and then
 *			returns that value if it is within the desired range and
 *			validated to be an integer.
 * Param: 	int min - This parameter represents the minimum value that
 * 			is acceptable for a given call of this function. If the user
 * 			inputs a number less than this, the function will print an
 * 			error message and ask for input repeatedly until satisfied.
 * Param:	int max - This parameter functions analogously to the
 * 			minimum parameter above, expect for the maximum
 * 			acceptable value.
 * Returns:	The user's inputted integer if it is within the min-max
 * 			range and is validated to be an integer.
 */
int Menu::integerInput(int min, int max)
{
	std::string input;
	int output = 0;

	//The method for using the stream for this function I found here:
	//"cplusplus.com/forum/beginner/58833" and modified.
	while(true)
	{
		//Prompt the user for an integer in a range.
		std::cout << "Enter an integer from " << min;
		std::cout << " through " << max << ": "; 
		
		//Use getline to convert the input into a string.
		std::getline(std::cin, input);

		//Create a stream object from whatever getline got.
		std::stringstream inputStream(input);

		//Convert the numbers in the string (stream) into integers.
		//If the string has anything that can be converted into
		//an integer AND, once that has been converted, there is
		//not anything left that could be put back into a string
		//then proceed into the if statement.
		if ((inputStream >> output) && !(inputStream >> input))
		{   
			//Ensure that the integer is within the desired range.
			if ((output >= min) && (output <= max))
			{
				return output;
			}
		}

		//Clear buffer in case of EOF
		std::cin.clear();

		//Error message.
		std::cout << "Invalid input. Please try again." << std::endl;	
	}
}


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
 * 			inputs a number less than this, the function will print an
 * 			error message and ask for input repeatedly until satisfied.
 * Param:	int max - This parameter functions analogously to the
 * 			minimum parameter above, expect for the maximum
 * 			acceptable value.
 * Returns:	The user's inputted integer if it is within the min-max
 * 			range and is validated to be an integer.
 */
int Menu::integerInput(std::string promptInput, int min, int max)
{
	std::string userInput;
	int output = 0;

	while(true)
	{
		std::cout << promptInput << std::endl;
		
		std::cout << "Enter an integer from " << min;
		std::cout << " through " << max << ": ";

		std::getline(std::cin, userInput);

		std::stringstream inputStream(userInput);

		if ((inputStream >> output) && !(inputStream >> userInput))
		{   
			if ((output >= min) && (output <= max))
			{
				return output;
			}
		}

		std::cin.clear();

		std::cout << "Invalid input. Please try again." << std::endl;		
	}
}


int Menu::integerInput()
{
	std::string input;
	int output = 0;

	while(true)
	{
		std::cout << "Enter an integer: ";
		
		std::getline(std::cin, input);

		std::stringstream inputStream(input);

		if ((inputStream >> output) && !(inputStream >> input))
		{   
			return output;
		}

		std::cin.clear();

		std::cout << std::endl;
		std::cout << "Invalid input. Please try again." << std::endl;	
	}
}


int Menu::integerInputNoPrompt(int min, int max)
{
	std::string input;
	int output = 0;

	while(true)
	{
		//std::cout << "Enter an integer from " << min;
		//std::cout << " through " << max << ": "; 
		
		std::getline(std::cin, input);

		std::stringstream inputStream(input);

		if ((inputStream >> output) && !(inputStream >> input))
		{   
			if ((output >= min) && (output <= max))
			{
				return output;
			}
		}

		std::cin.clear();

		std::cout << "Invalid input. Please try again." << std::endl;	
	}
}


int Menu::minIntegerInput(int min)
{
	std::string input;
	int output = 0;

	while(true)
	{
		std::cout << "Enter an integer greater than " << min << ": ";
		
		std::getline(std::cin, input);

		std::stringstream inputStream(input);

		if ((inputStream >> output) && !(inputStream >> input))
		{   
			if (output > min)
			{
				return output;
			}
		}

		std::cin.clear();

		std::cout << std::endl;
		std::cout << "Invalid input. Please try again." << std::endl;	
	}
}


std::string Menu::stringInput()
{
	std::string input;

	std::getline(std::cin, input);

	return input;
}
