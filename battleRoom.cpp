/****************************************************************************************
**Program Filename: battleRoom.cpp
**Author: Jay Steingold
**Date: 3/9/16
**Description: Special type of room whose action triggers a rock, paper, scissors game
**Input: none
**Output: none
****************************************************************************************/ 

#include "battleRoom.hpp"
#include <iostream>
#include <cstdlib>

BattleRoom::BattleRoom()
{
	this->type = "battle";
	north = NULL;
	south = NULL;
	east = NULL;
	west = NULL;

}

/****************************************************************************************
**Function: action
**Description: Places the player against a spider in a game of rock, paper scissors.
** where losing means losing steps
**Parameters: none
**Pre-conditions: Must have a room
**Post-Conditions: none
***************************************************************************************/ 
int BattleRoom::action()
{
	int input = -1;
	int spider = rand() % 3 + 1;

	/*Room that gives you a hint about which gauntlet you can use*/
	if(this->number == 9)
	{
		std::cout << "As you open the door a fog billows out into the corridor\n";
		std::cout << "A frail voice calls from the darkness.\n";
		std::cout << "Come my child. I will not harm thee. I only require your time.\n";
		std::cout << "When you enter, the door closes behind you.\n";
		std::cout << "On the opposite wall is a lich, impaled in thousands of ice shards.\n";
		std::cout << "Living flesh is weak, human.\n";
		std::cout << "Only with the skin of undead can you escape this tomb.\n";
		std::cout << "You want to ask more questions, but the lich has dozed off.\n";
		return 0; 
	}
	/*Battle a spider in rock, paper,scissors*/
	std::cout << "A spider appears behind you!\n";
	std::cout << "One of its nasty legs has a human hand on it?!\n";
	std::cout << "\"Rock, paper scissors.\" it hisses\n";

	while(input <= 0 || input > 3)
	{
		std::cout << "Press 1 for rock.\n";
		std::cout << "Press 2 for paper.\n";
		std::cout << "Press 3 for scissors.\n";
		std::cin >> input;
		}
		switch(input)
		{
			case 1:
				std::cout << "You chose rock!\n";
				/*Spide chose rock */
				if(spider == 1)
				{
					std::cout << "The spider scurries away\n";
					std::cout << "Everyone knows spiders hate ties\n";
					return 0;
				}
				/*Spider chose paper */
				if(spider == 2)
				{
					std::cout << "The spider flicks your forehead";
					std::cout << " giving you a concussion.\n";
					std::cout << "Lose 5 steps.\n";
					return 5;	
				}
				/* Spider chose scissors*/
				else
				{
					std::cout << "You crush the spider's scissors!\n";
					std::cout << "The victory gives you hope.\n";
					std::cout << "Gain 1 step.\n";
					return 1;
				}
				break;
			case 2:
				std::cout << "You chose paper!\n";
				/*Spider chose rock */
				if(spider == 1)
				{
					std::cout << "You crush the spider's rock!\n";
					std::cout << "The victory gives you hope!\n";
					std::cout << "Gain 1 step.\n";
					return 1;
				}
				/*Spider chose paper */
				if(spider == 2)
				{
					std::cout << "The spider scurries away\n";
					std::cout << "It must hate ties.\n";
					return 0;	
				}
				/* Spider chose scissors*/
				else
				{
					std::cout << "The spider lets out a chuckle\n";
					std::cout << "and slices you across the chest.\n";
					std::cout << "Lose 5 steps.\n";
					return 5;
				}

				break;
			case 3:
				std::cout << "You chose scissors!\n";
				/*Spider chose rock */
				if(spider == 1)
				{
					std::cout << "The spider crushes your scissors!\n";
					std::cout << "Lose 5 steps.\n";
					return 5;
				}
				/*Spider chose paper */
				if(spider == 2)
				{
					std::cout << "You slice the spider's paper!\n";
					std::cout << "The victory gives you hope.\n";
					std::cout << "Gain 1 step.\n";
					return 1;	
				}
				/* Spider chose scissors*/
				else
				{
					std::cout << "The spider scurries away.\n";
					std::cout << "I guess it doesn't like ties\n";			
					return 0;
				}
				break;
		}
} 
