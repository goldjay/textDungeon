/****************************************************************************************
**Program Filename: trapRoom.cpp
**Author: Jay Steingold
**Date: 3/9/16
**Description: trapRoom is a Room whose action gives the player "damage"
**Input: none
**Output: none
****************************************************************************************/ 

#include "trapRoom.hpp"
#include <iostream>
#include <cstdlib>

TrapRoom::TrapRoom()
{
	this->type = "trap";
	north = NULL;
	south = NULL;
	east = NULL;
	west = NULL;
}

/****************************************************************************************
**Function: action
**Description: Player loses moves based on a random number
**Parameters: none
**Pre-conditions: Must have a room
**Post-Conditions: none
***************************************************************************************/ 
int TrapRoom::action()
{
	int random = rand() % 5 + 1;

	/*Damage the player */
	if(random == 1)
	{
		std::cout << "It's a trap!\n";
		std::cout << "Spikes shoot out of the floor and one catches your leg.\n";
		std::cout << "Lose 3 steps.\n";
		return 3;
	}
	/*Gives the player an antidote if they have an iron gauntlet*/	
	if(random == 2)
	{
		std::cout << "A surly-looking dwarf is crawling over the floor on all fours\n";
		std::cout << "I don't suppose you've found my iron gauntlet, human?\n";
		std::cout << "I'll make it worth your while.\n";		
		return 101; 
	}
	/*Damage the player */
	if(random == 3)
	{
	
		std::cout << "Your leg goes numb.\n";
		std::cout << "You can feel death close behind.\n";
		std::cout << "Lose 2 steps.\n";
		return 2;  
	}
	/*Player takes no damage*/
	else
	{
		std::cout << "There is a trap wire inches from  the floor.\n";
		std::cout << "You step over it.\n";
		return 0;
	}		
}
