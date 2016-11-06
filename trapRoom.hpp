/****************************************************************************************
**Program Filename: trapRoom.hpp
**Author: Jay Steingold
**Date: 3/9/16
**Description: Header file for trapRoom Room
**Input: none
**Output: none
****************************************************************************************/ 

#ifndef TRAPROOM_HPP
#define TRAPROOM_HPP

#include "room.hpp"

class TrapRoom: public Room
{
	public:
		TrapRoom();
		int action();
};

#endif
