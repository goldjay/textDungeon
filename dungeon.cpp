/****************************************************************************************
**Program Filename: dungeon.cpp
**Author: Jay Steingold
**Date: 3/9/16
**Description: Dungeon class builds a series of different rooms and allows
** the player to navigate them
**Input: none
**Output: none
****************************************************************************************/ 

#include "dungeon.hpp"
#include "itemRoom.hpp"
#include "trapRoom.hpp"
#include "battleRoom.hpp"
#include "room.hpp"
#include <iostream>

Dungeon::Dungeon()
{
	head = NULL;
	position = NULL;
	itemCount = 0; 
	moves = 30; 
	inventory[5];
}

Dungeon::~Dungeon()
{
	Room* temp;
	position = head;
	/*First level*/
	/*move position to the west room, delete*/
	temp = position->getWest();
	delete temp;
	/*move position to the east, delete*/
	temp = position->getEast();
	delete temp;
	/*move position to the north, delete position and reassign*/
	temp = position;
	position = position->getNorth();

	delete temp;
		
	
	/*Second level*/
	/*move position to the west room, delete*/
	temp = position->getWest();
	delete temp;
	/*move position to the east, delete*/
	temp = position->getEast();
	delete temp;
	/*move position to the north, delete position and reassign*/
	temp = position;
	position = position->getNorth();

	delete temp;

	/*Third level*/
	/*move position to the west room, delete*/
	temp = position->getWest();
	delete temp;
	/*move position to the east, delete*/
	temp = position->getEast();
	delete temp;
	/*move position to the north, delete position and reassign*/
	temp = position;
	position = position->getNorth();

	delete temp;

	/*Fourth level*/
	/*move position to the west room, delete*/
	temp = position->getWest();
	delete temp;
	/*move position to the east, delete*/
	temp = position->getEast();
	delete temp;
	/*move position to the north, delete position and reassign*/
	temp = position->getNorth();
	delete position;
	position = temp;	


	/*Fifth level*/	
	/*move position to the west room, delete*/
	temp = position->getWest();
	delete temp;
	/*move position to the east, delete*/
	temp = position->getEast();
	delete temp;
	/*move position to the north, delete position and reassign*/
	temp = position->getNorth();
	delete position;
	position = temp;	

	/*Reset position and head to null*/
	position = NULL;
	head = NULL;	

}

/****************************************************************************************
**Function: addNorth
**Description: Adds a room to the north pointer of the current position
**Parameters: string representing room type and an integer representing the room number
**Pre-conditions: Must have an initial room
**Post-Conditions: none
***************************************************************************************/ 
void Dungeon::addNorth(std::string word, int n)
{
	Room* temp;
	temp = position->getNorth();	

	if(word == "item")
	{ 
		temp = new ItemRoom;
	}
	if(word == "trap")
	{
		temp = new TrapRoom; 
	}
	if(word == "battle")
	{
		temp = new BattleRoom;
	}
	position->setNorth(temp);
	temp->setSouth(position);
	temp->setNumber(n);
	/*Sets pointer back to original position*/
	position = temp;
}

/****************************************************************************************
**Function: addWest
**Description: Adds a room to the west pointer of the current position
**Parameters: string representing room type and an integer representing the room number
**Pre-conditions: Must have an initial room
**Post-Conditions: none
***************************************************************************************/ 
void Dungeon::addWest(std::string word, int n)
{
	Room* temp;
	temp = position->getWest();	

	if(word == "item")
	{ 
		temp = new ItemRoom;
	}
	if(word == "trap")
	{
		temp = new TrapRoom; 
	}
	if(word == "battle")
	{
		temp = new BattleRoom;
	}
	position->setWest(temp);
	temp->setEast(position);
	/*Sets pointer back to original position*/
	temp->setNumber(n);
}

/****************************************************************************************
**Function: addEast
**Description: Adds a room to the east pointer of the current position
**Parameters: string representing room type and an integer representing the room number
**Pre-conditions: Must have an initial room
**Post-Conditions: none
***************************************************************************************/ 
void Dungeon::addEast(std::string word, int n)
{
	Room* temp;
	temp = position->getEast();	

	if(word == "item")
	{ 
		temp = new ItemRoom;
	}
	if(word == "trap")
	{
		temp = new TrapRoom; 
	}
	if(word == "battle")
	{
		temp = new BattleRoom;
	}
	position->setEast(temp);
	temp->setWest(position);
	temp->setNumber(n);
}

/****************************************************************************************
**Function: generateDungeon
**Description: Creates a series of rooms which the player can move through
**Parameters:  none
**Pre-conditions: must have a dungeon
**Post-Conditions: none
***************************************************************************************/ 
void Dungeon::generateDungeon()
{
	Room* temp;

	//First Room (Should be battleroom 
	position = new BattleRoom;
	position->setNumber(1);
	head = position;
	addEast("item", 0);
	addWest("battle", 0);

	//Second Room
	addNorth("trap", 0); //CHANGE TO TRAP 
	addEast("trap", 0);
	addWest("battle", 0);

	//Third Room 
	addNorth("trap", 0);
	addEast("item", 3);
	addWest("item", 0);

	//Fourth Room
	addNorth("battle", 0);
	addEast("item", 0);
	addWest("trap", 0);

	//Fifth Room 
	addNorth("item", 5);
	addEast("item", 7);
	addWest("trap", 0);

	/*Allows the player to travel from the first to last room*/
	head->setSouth(position);
	/*Sets position to the original room*/
	position = head;
}

/****************************************************************************************
**Function: exploreDungeon
**Description: Allows the player to move through a series of Rooms using the position
** pointer as the player's current position.
**Parameters:  none
**Pre-conditions: must have a dungeon. The dungeon must have rooms.
**Post-Conditions: None
***************************************************************************************/ 
void Dungeon::exploreDungeon()
{
	Room* next;
	int choice = -1;

	std::cout << "\nYou awake in complete darkenss.\n";
	std::cout << "As sensation slowly returns to your body you feel small spiders\n";
	std::cout << "crawling all over you.\n";
	std::cout << "A voice whispers from the black...\n";
	std::cout << "Feeling woozy human?\n";
	std::cout << "Don't worry, I've already eaten...\n";
	std::cout << "but my children are so hungry.\n";
	std::cout << "Many adventurers have come here in search of treasure...\n";
	std::cout << "but I believe you will find time is greater than any gold...\n";

	/*Do the menu while the character is alive and the win condition is not met*/
	while(moves > 0 && !hasItem("antidote"))
	{ 
		/*Do while the user hasen't chosen a valid choice*/ 
		while(choice <= 0 || choice > 6)
		{  
			std::cout << "What do you want to do?\n";
			std::cout << "Press 1 to move North.\n";
			std::cout << "Press 2 to move East.\n";
			std::cout << "Press 3 to move South.\n";
			std::cout << "Press 4 to move West.\n";
			std::cout << "Press 5 to get health.\n";
			std::cout << "Press 6 to see your inventory.\n";
			std::cin >> choice;	 
		}
		switch(choice)
		{
			case 1:
				next = position->getNorth();
				moveNorth();
				getRoomType();
				break;
			case 2:
				next = position->getEast();
				moveEast();
				getRoomType();
				break;
	
			case 3:
				next = position->getSouth();
				moveSouth();
				getRoomType();
				break;
			case 4:
				next = position->getWest();
				moveWest();
				getRoomType();
				break;
			/*Prints the number of moves remaining*/
			case 5:
				next = position;
				std::cout << "You have " << getMoves() << " moves.\n\n"; 
				break;	
			/*Prints the items in your inventory*/
			case 6:
				next = position;
				printInv();			
				break;
		}
		/*If the next space is not a room*/
		if(next == NULL)
		{
			std::cout << "You can't move through walls, can you?\n";
		}
		/*If the next space is a room */
		else
		{
			int num = -1;
			/*If the next room is a battle room and
			**  you have a torch, skip the battle
			*/
			if(next->getType() == "battle" && hasItem("torch"))
			{
				std::cout << "You hear a loud scuffle and you step";
				std::cout << " into the room\n";
				std::cout << "A high pitched screech erupts from";
				std::cout << " your inventory.\n";
				removeItem("torch");	
				position = next;
			}
			/*If the next room is the final room*/
			if(position->getNumber() == 5) 
			{
				/*Sets choice to not perform an action*/
				choice = 6;
		
				std::cout << "You see a small vial atop a white marble";
				std::cout <<" pedistol.\n";
				std::cout << "From the ceiling shines a column of bright";
				std::cout << " white light.\n";
				std::cout << "What do you do?\n";
				while(num <= 0 || num > 3)
				{
					std::cout << "Press 1 to grab the vial.\n";
					std::cout << "Press 2 to throw your gauntlet into";
					std::cout << " the light.\n";
					std::cout << "Press 3 to do nothing.\n";
					std::cin >> num; 
				}
				/*Grab the vial, check if you have gauntlet*/
				if(num == 1)
				{
					if(hasItem("crystal"))
					{
						std::cout << "As your hand touches ";
						std::cout << "the light your gauntlet";
						std::cout << " explodes.\n";
						std::cout << "You lose 4 moves\n";
						moves -= 4;
						removeItem("crystal");
					}							
					else if(hasItem("leather"))
					{
						std::cout << "You grab the vial and drink";
						std::cout << " deeply.\n";
						addItem("antidote");		
					}
					else if(hasItem("iron"))
					{
						std::cout << "Your gauntlet burns white\n";
						std::cout << "You try to remove it, ";
						std::cout << "but it's stuck.\n";
						std::cout << "You lose 10 moves.\n";
						moves -= 10;
					}					
					/*If you don't have a gauntlet*/
					else
					{
						std::cout << "The light rends your flesh";
						std::cout << " from bone, you pull back";
						std::cout << "a skeleton hand.\n";
						std::cout << "You lose 7 moves.\n";
						moves -= 7;
					}
				}
				/*Throw gauntlet*/
				if(num == 2)
				{
					if(hasItem("crystal"))
					{
						std::cout << "Your crystal gauntlet";
						std::cout << " explodes!\n";
						std::cout << "Good thing you weren't";
						std::cout << " wearing it.\n";
						removeItem("crystal");
					}
					else if(hasItem("leather"))
					{
						std::cout << "Your leather gauntlet";
						std::cout << "lands on the floor.\n";
						std::cout << "You want it back.\n";
						removeItem("leather");
					}
					else if(hasItem("iron"))
					{
						std::cout << "Your iron gauntlet";
						std::cout << " turns white";
						std::cout << " and melts into a puddle.\n";
						removeItem("iron");
					}
					/*If you don't have a gauntlet*/
					else
					{
						std::cout << "Liar, you don't have one.\n";
					}
				}
				/*If you choose to do nothing*/
				if(num == 3)
				{
					std::cout << "Better leave it alone.\n";
				}
			} 
			/*If the room is not a special case and the player moved*/
			else if(choice != 5 && choice != 6)
			{
				/*Perform the room's action*/
				int number = position->action();

				/*Integers greater than 100 indicate an item*/
				if(number >= 100)
				{
					if(number == 100)
					{
						addItem("key");		
					}
					/*From trap room, if you have the iron
					**  gauntlet, you win
					*/ 
					if(number == 101)
					{
						if(hasItem("iron"))
						{
							std::cout << "You give the dwarf";
							std::cout << " your gauntlet.\n";
							std::cout << "His eyes shine";
							std::cout << " with tears";
							std::cout << " of happiness.\n";
							std::cout << "He gives you an";
							std::cout << " antidote.\n";
							removeItem("iron");
							addItem("antidote");
						}
						else
						{
							std::cout << "The dwarf goes back";
							std::cout << " to searching.\n";
						}
					}
					if(number == 102)
					{
						addItem("torch");
					}
					if(number == 103)
					{
						addItem("crystal");
					} 
					if(number == 104)
					{
						addItem("leather");
					}
					if(number == 105)
					{
						addItem("iron");
					}
					if(number == 106)
					{
						addItem("oldKey");
					}
				}

				/*subtract moves for failed battles */
				else
				{
					moves -= number;
				}
			}
			std::cout << std::endl; 
		}
	/*Resets choice */
	choice = -1;	
	}
	/*If the player ran out of moves*/
	if(moves <= 0)
	{
		std::cout << "It's just too much.\n";
		std::cout << "There is just not enough energy in your body to go on.\n";
		std::cout << "You slump to the floor and wait for a rescue.\n";
		std::cout << "Game over.\n"; 
	}
	/*If the player won the game*/
	if(hasItem("antidote"))
	{
		std::cout << "Strength returns to your body and you begin to retrace";
		std::cout << " your steps, searching for an exit... \n";
		std::cout << "You win!\n";
	}			
}

/****************************************************************************************
**Function: moveNorth
**Description: moves the position pointer to the north pointer
**Parameters: none
**Pre-conditions: must have two rooms
**Post-Conditions: none
***************************************************************************************/ 
void Dungeon::moveNorth()
{
	/*change position to  the north pointer of its current position*/
	Room* rm = position->getNorth();
	if(rm != NULL)
	{
		/*If you are trying to move North into the final room*/	
		if(rm->getNumber() == 5)
		{
			std::cout << "A strange force prevents you from entering.\n";
			std::cout << "Through the haze you can see a pedistol";
			std::cout << " and a bright light\n";
		}
		/*If the room is not the final room */
		else
		{
			position = rm;
			std::cout << "I moved north!\n";
			std::cout << "Room number: " << position->getNumber() << std::endl;
			moves--;	
		}
	}
}

/****************************************************************************************
**Function: moveSouth
**Description: Moves the current posiion to the room's south pointer
**Parameters: none
**Pre-conditions: must have two rooms
**Post-Conditions:  none
***************************************************************************************/ 

void Dungeon::moveSouth()
{
	Room* rm = position->getSouth();
	if(rm != NULL)
	{
		if(rm->getNumber() == 5)
		{
			/*If you are trying to move into the final room
			** and you don't have a key, don't move 
			*/
			if(!hasItem("key") && !hasItem("oldKey"))
			{
				std::cout << "Through some old spider webs";
				std::cout << " you can see a door.";
				std::cout << " You try to push it open but it is locked.\n"; 
			}	
			/*Destroy your old key if you are trying to move to
			** the final room 
			*/
			else if(hasItem("oldKey"))
			{
				std::cout << "You try your old key.\n";
				std::cout << "It crumbles in the lock.\n";
				std::cout << "Guess it was too old.\n";
				removeItem("oldKey");
			}
			/*If you have a key and you are moving into the final room
			** from the first, move
			*/
			else if(hasItem("key"))
			{
				std::cout << "You brush aside the cobwebs";
				std::cout << " to reveal a small wooden door.\n";
				std::cout << "The key fits perfectly!\n";
				std::cout << "You unlocked the door!\n";
				position = rm;
				removeItem("key");
				std::cout << "Room number: " << position->getNumber() << std::endl;
				moves--;
			}
		}
		/*If you are moving into a room that isn't 5 aka non-special */
		else
		{
			position = rm;
			std::cout << "I moved south!\n"; 
			std::cout << "Room number: " << position->getNumber() << std::endl;
			moves--;
		}
		/*If youi didn't move*/
		if(rm != position)
		{ 
			std::cout << "I didn't move.\n";		
		}
	}
}

/****************************************************************************************
**Function: moveEast
**Description: moves the current position to the room's east pointer
**Parameters: none 
**Pre-conditions: must have two rooms
**Post-Conditions: none
***************************************************************************************/ 
void Dungeon::moveEast()
{
	Room* rm = position->getEast();
	if(rm != NULL)
	{
		std::cout << "I moved east!\n";
		std::cout << "Room number: " << position->getNumber() << std::endl;
		position = rm;
		moves--;
	}
}

/****************************************************************************************
**Function: moveWest
**Description: moves the current position to the room's west pointer
**Parameters: none
**Pre-conditions: must have two rooms
**Post-Conditions: none
***************************************************************************************/ 
void Dungeon::moveWest()
{
	Room* rm = position->getWest();
	if(rm != NULL)
	{
	
		std::cout << "I moved west!\n";
		std::cout << "Room number: " << position->getNumber() << std::endl;
		position = rm;
		moves--;
	}
}

/****************************************************************************************
**Function: getRoomType 
**Description: prints the type of Room (used for debugging) 
**Parameters: none
**Pre-conditions: must have a room
**Post-Conditions: none
***************************************************************************************/ 

void Dungeon::getRoomType()
{
	if(position == NULL)
	{
		std::cout << "It's NULL!\n";
	}
	else
	{
		std::cout << "You are in a " << position->getType() << " room\n";
	}
}

/****************************************************************************************
**Function: getMoves
**Description: returns the number of moves left for the player
**Parameters: none
**Pre-conditions: must have a dungeon
**Post-Conditions: none
***************************************************************************************/ 
int Dungeon::getMoves()
{
	return this->moves;
}

/****************************************************************************************
**Function: hasItem
**Description: returns a bool if the given item is in the player's inventory
**Parameters: string of the item name
**Pre-conditions: must have a dungeon 
**Post-Conditions: none
***************************************************************************************/ 
bool Dungeon::hasItem(std::string name)
{
	for(int i = 0; i < 10; i++)
	{
		if (inventory[i] == name)
		return true;
	} 
	return false;

}

/****************************************************************************************
**Function: addItem
**Description: adds an item string to the inventory if it isn't already included
**Parameters: string of item name
**Pre-conditions: must have a dungeon
**Post-Conditions: none
***************************************************************************************/ 
void Dungeon::addItem(std::string name)
{

	/*If you don't have a key, add to the key slot*/
	if(name == "torch")
	{
		if(inventory[0] == "")
		{
			inventory[0] = "torch";
		}
		else
		{	
			std::cout << "You already have a " << name << std::endl;
		}
	}
	/*If the item is a key, add to the key slot*/	
	else if(name == "key")
	{
		if(inventory[1] == "")
		{
			inventory[1] = "key";
		}
		else
		{	
			std::cout << "You already have a " << name << std::endl; 
		}
	}	
	/*You can only carry one gauntlet*/
	/*if the item is a crystal gauntlet*/ 
	else if(name == "crystal")
	{
		if(inventory[2] == "")
		{
			inventory[2] = "crystal";
		}
		else
		{
			std::cout << "You already have a " << name << std::endl; 
		}
	}
	/*If the item is a leather gauntlet*/
	else if(name == "leather")
	{
		if(inventory[2] == "")
		{
			inventory[2] = "leather";
		}
		else
		{
			std::cout << "You already have a " << name << std::endl; 
		}
	}
	/*If the item is an iron gauntlet*/
	else if(name == "iron")
	{
		if(inventory[2] == "")
		{
			inventory[2] = "iron";
		}
		else
		{
			std::cout << "You already have a " << name << std::endl; 
		}
	}
	/*If the item is an antidote*/
	else if(name == "antidote")
	{
		if(inventory[3] == "")
		{
			inventory[3] = "antidote";
		}
		else
		{
			std::cout << "You already have a " << name << std::endl;
		}		
	}
	/*If the item is an old key*/
	else if(name == "oldKey")
	{
		if(inventory[4] == "")
		{
			inventory[4] = "oldKey";
		}
		else
		{
			std::cout << "You already have a " << name << std::endl;
		}
	}
}

/****************************************************************************************
**Function: removeItem
**Description: if the item is found within the inventory, remove it
**Parameters: name of the item
**Pre-conditions: none
**Post-Conditions: none
***************************************************************************************/ 
void Dungeon::removeItem(std::string name)
{
	int count = 0;
	bool found = false;
	while(count < 5 && found == false)
	{
		/*If the item to be removed is found*/
		if(inventory[count] == name)
		{
			std::cout << name << " was removed.\n\n";
			inventory[count] = "";
			found = true;
		}
		else
		{
			count++;
		}
	}
	/*If the inventoy has been iterated over*/
	if(count == 5)
	{
		std::cout << "You don't have a " << name << std::endl;
	} 
}

/****************************************************************************************
**Function: printInv
**Description: Prints the names of the inventory
**Parameters: none
**Pre-conditions: none
**Post-Conditions: none
***************************************************************************************/ 
void Dungeon::printInv()
{
	for(int i = 0; i < 5; i++)
	{
		std::cout << inventory[i] << std::endl;
	} 
}

	

