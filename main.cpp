/****************************************************************************************
**Program Filename: main.cpp
**Author: Jay Steingold
**Date: 3/9/16
**Description: Creates a dungeon and allows the user to navigate it via numerical input
** If the user is grading the program, it gives the route to win.   
**Input: Numerical input for navigation and choices
**Output: none
****************************************************************************************/ 

#include "room.hpp"
#include "itemRoom.hpp"
#include "battleRoom.hpp"
#include "trapRoom.hpp"
#include "dungeon.hpp"
#include <iostream>
#include <cstdlib>
#include <time.h>

int main()
{
	int input = -1;

	/*For the random number generation */
	srand(time(NULL));

	std::cout << "Are you going to be grading this assignment?\n";
	while(input != 1 && input != 2)
	{
		std::cout << "Press 1 for yes\n";
		std::cout << "Press 2 for no\n";
		std::cin >> input;
	}
	/*If the user is the grader*/
	if(input == 1)
	{
		std::cout << "You should write this down:\n";
		std::cout << "To win, move North, North, East,\n";
		std::cout << "then sleep in the bed.\n";
		std::cout << "Move west, south, south, south";
		std::cout << " and do nothing.(Press 3)\n";
		std::cout << "Then move east and select the leather gauntlet.\n";
		std::cout << "Finally move west and grab the antidote.\n";
		std::cout << "There is another way to win with the iron gauntlet,\n";
		std::cout << "but it takes a bit of luck walking into a trap room.\n";
	}
	Dungeon d;
	d.generateDungeon();
	d.exploreDungeon();	
	return 0;
}
