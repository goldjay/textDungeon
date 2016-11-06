/****************************************************************************************
**Program Filename: room.cpp
**Author: Jay Steingold
**Date: 3/9/16
**Description: Room class which gets created and linked together via pointers 
**Input: none
**Output: none
****************************************************************************************/ 

#include "room.hpp"
#include "itemRoom.hpp"
#include <string>

/****************************************************************************************
**Function: getType
**Description: Returns the type of the room (Battle, Item, Trap)
**Parameters: none
**Pre-conditions: Must have a room
**Post-Conditions: none
***************************************************************************************/ 
std::string Room::getType()
{
	return this->type;
}

/****************************************************************************************
**Function: getNorth
**Description: Returns the North pointer room
**Parameters: none
**Pre-conditions: Must have a room
**Post-Conditions: none
***************************************************************************************/ 

Room* Room::getNorth()
{
	return this->north;
}

 /****************************************************************************************
**Function: getSouth
**Description: Returns the South pointer room
**Parameters: none
**Pre-conditions: Must have a room
**Post-Conditions: none
***************************************************************************************/ 

Room* Room::getSouth()
{
	return this->south;
}

/****************************************************************************************
**Function: getEast
**Description: Returns the East pointer room
**Parameters: none
**Pre-conditions: Must have a room
**Post-Conditions: none
***************************************************************************************/ 
Room* Room::getEast()
{
	return this->east;
}

/****************************************************************************************
**Function: getWest
**Description: Returns the West pointer room
**Parameters: none
**Pre-conditions: Must have a room
**Post-Conditions: none
***************************************************************************************/ 
Room* Room::getWest()
{
	return this->west;
}

/****************************************************************************************
**Function: setNorth
**Description: Sets the north pointer room
**Parameters: pointer to a Room
**Pre-conditions: Must have a room
**Post-Conditions: none
***************************************************************************************/ 
void Room::setNorth(Room* setIn)
{
	this->north = setIn;
}

/****************************************************************************************
**Function: setSouth
**Description: Sets the south pointer room
**Parameters: pointer to a Room
**Pre-conditions: Must have a room
**Post-Conditions: none
***************************************************************************************/ 
void Room::setSouth(Room* setIn)
{
	this->south = setIn;
}

/****************************************************************************************
**Function: setEast
**Description: sets the east pointer room
**Parameters: Pointer to a room
**Pre-conditions: Must have a room
**Post-Conditions: none
***************************************************************************************/ 
void Room::setEast(Room* setIn)
{
	this->east = setIn;
}

/****************************************************************************************
**Function: setWest
**Description: Sets the west pointer to a room
**Parameters: pointer to a room
**Pre-conditions: Must have a room
**Post-Conditions: none
***************************************************************************************/ 
void Room::setWest(Room* setIn)
{
	this->west = setIn;
}

/****************************************************************************************
**Function: setNumber
**Description: sets a room's number variable
**Parameters: integer
**Pre-conditions: Must have a room
**Post-Conditions: none
***************************************************************************************/ 
void Room::setNumber(int numIn)
{
	number = numIn;
}

/****************************************************************************************
**Function: getNumber
**Description: Gets a room's number
**Parameters: none
**Pre-conditions: Must have a room
**Post-Conditions: none
***************************************************************************************/ 
int Room::getNumber()
{
	return number;
}
