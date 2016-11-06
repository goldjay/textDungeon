/****************************************************************************************
**Program Filename: itemRoom.hpp
**Author: Jay Steingold
**Date: 3/9/16
**Description: Defines the itemRoom Room class which gives the player an item
**Input: none
**Output: none
****************************************************************************************/ 

#ifndef ITEMROOM_HPP
#define ITEMROOM_HPP
#include "room.hpp"

class ItemRoom: public Room
{
	public:
		ItemRoom();
		int action();
};

#endif
