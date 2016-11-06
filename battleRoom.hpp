/****************************************************************************************
**Program Filename: battleRoom.hpp
**Author: Jay Steingold
**Date: 3/9/16
**Description: Header file for battleRoom Room
**Input: none
**Output: none
****************************************************************************************/ 

#ifndef BATTLEROOM_HPP
#define BATTLEROOM_HPP
#include "room.hpp"

class BattleRoom: public Room
{
	public:
		BattleRoom();
		int action();
};

#endif
