/****************************************************************************************
**Program Filename: room.hpp
**Author: Jay Steingold
**Date: 3/9/16
**Description: Header file for room class which defines spaces
**Input: none
**Output: none
****************************************************************************************/ 

#ifndef ROOM_HPP
#define ROOM_HPP

#include <string>
class Room
{
	public:
		virtual int action() = 0;	
		std::string getType();
		Room* getNorth();
		Room* getSouth();
		Room* getEast();
		Room* getWest();
		void setNorth(Room* setIn);	
		void setSouth(Room* setIn);
		void setEast(Room* setIn);
		void setWest(Room* setIn);
		void setNumber(int numIn);
		int getNumber();

	protected:
		std::string type;
		int number;
		Room* north;
		Room* east;
		Room* south;
		Room* west;
};
#endif
