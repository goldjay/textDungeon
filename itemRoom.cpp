/****************************************************************************************
**Program Filename: itemRoom.cpp
**Author: Jay Steingold
**Date: 3/9/16
**Description: itemRoom Room whose action gives the player an item
**Input: none
**Output: none
****************************************************************************************/ 

#include "itemRoom.hpp"
#include "room.hpp"
#include <iostream>
#include <cstdlib>

ItemRoom::ItemRoom()
{
	this->type = "item";
	north = NULL;
	south = NULL;
	east = NULL;
	west = NULL;
}

/****************************************************************************************
**Function: action
**Description: Depending on the room, gives the player an item
**Parameters: none
**Pre-conditions: Must have a room
**Post-Conditions: none
***************************************************************************************/ 
int ItemRoom::action()
{
	int num = -1;
	/*Only for the 3rd room*/
	if(this->number == 3) 
	{
		std::cout << "\nYou enter a room held together by vines.\n";
		std::cout << "Water flows down the cracked walls and\n";
		std::cout << "into a small grate in the floor.\n";
		std::cout << "In the center of the room is a large iron bed\n";
		std::cout << "with fluffy white sheets.\n";
		std::cout << "It's strange but your body aches from the venom.\n";
		std::cout << "Do you rest in the bed?\n";
		while(num != 1 && num != 2)
		{
			std::cout << "Type 1 for yes\n";
			std::cout << "Type 2 for no\n";
			std::cin >> num;
		}
		/*Sleep in the bed */ 
		if(num == 1)
		{
			std::cout << "You settle into the sheets but something is poking";
			std::cout << " you in the back!\n";
			std::cout << "It's a key!\n";
			return 100;	
		}
		/*Don't sleep in the bed */
		else
		{
			std::cout << "No, you'll be alright.\n"; 
		}
	}
	/*For the gauntlet Room*/
	else if(this->number == 7)
	{
		num = -1;
		std::cout << "\nYou arrive in a shining room of white marble.\n";
		std::cout << "Three gauntlets stand on pedistols\n";
		std::cout << "The first is made of crystal.\n";
		std::cout << "Inside you can see a skeleton hand.\n";
		std::cout << "The second is made of worn leather.\n";
		std::cout << "Though it is quite worn you can see no holes.\n";
		std::cout << "The third is a dull iron.\n";
		std::cout << "Its surface marred with thousands of tiny scratches.\n";
		std::cout << "What will you do?\n";
		while(num <= 0 || num > 4)
		{
			std::cout << "Press 1 to choose the crystal gauntlet.\n";
			std::cout << "Press 2 to choose the leather gauntles.\n";
			std::cout << "Press 3 to choose the iron gauntlet.\n"; 
		  	std::cout << "Press 4 to choose none of the gauntlets.\n";
			std::cin >> num;
		}
		/*If the player chooses the crystal gauntlet*/
		if(num == 1)
		{
			std::cout << "You grab the crystal gauntlet and the skeleton";
			std::cout << "  hand turns to dust.\n";
			std::cout << "You put it on a feel a surge of power.\n";
			return 103; 
		}
		if(num == 2)
		{
			std::cout << "You take the leather gauntlet and put it on.\n";
			std::cout << "It smells like a sweaty dungeon.\n";
			std::cout << "You begin to regret your decision.\n";
			return 104;
		}
		if(num == 3)
		{
			std::cout << "You have to lift the iron gauntlet with two hands.\n";
			std::cout << "It's much heavier than you thought.\n";
			return 105;
		}
		if(num == 4)
		{
			std::cout << "These sorts of things are better left alone.\n";
		}
	}
	/*If it's a normal item room*/
	else
	{
		//CHANGE BACK TO RANDOM 
		int random = 2;//rand() % 2 + 1;
		/*Reset the input int*/
		num = -1;

		/*Choose to get a torch */
		if(random == 1)
		{
			std::cout << "Your eyes burn at the sight of a bright light.\n";
			std::cout << "A voice whispers from the light\n";
			std::cout << "Do you want my help, human?\n";	
			while(num != 1 && num != 2)
			{
				std::cout << "Press 1 for yes\n";
				std::cout << "Press 2 for no\n";
				std::cin >> num;
			} 
			if (num == 1)
			{
				std::cout << "\nGood, but I should warn you,";
				std::cout <<" I'm afriad of spiders.\n";
				return 102;			
			}
			else
			{
				std::cout << "\nSuit yourself human.\n";
			}
		}
		/*Choose to get an old key*/
		else if(random == 2)
		{
			std::cout << "There is a skeleton laying face-down on the floor.\n";
			std::cout << "You spot a rusty key in its ribcage.\n";
			std::cout << "Do you take it?\n";
			while(num != 1 && num != 2)
			{
				std::cout << "Press 1 to take the key.\n";
				std::cout << "Press 2 to leave the key for someone else.\n";
				std::cin >> num;
			}
			/*Get the oldKey*/	
			if(num == 1)
			{
				std::cout << "You reach inside the ribcage and take the key.\n";
				return 106;
			}
			/*Get nothing*/
			if(num ==2)
			{
				std::cout << "It's too gross.\n";
				return 0;
			}
		}				
	}
}

