/****************************************************************************************
**Program Filename: dungeon.hpp
**Author: Jay Steingold
**Date: 3/9/16
**Description: Header file for dungeon class which builds a series of rooms and allows
** the player to navigate them
**Input: none
**Output: none
****************************************************************************************/ 

#ifndef DUNGEON_HPP
#define DUNGEON_HPP

#include <string>
#include "room.hpp"

class Dungeon
{
	public:
		Dungeon();
		~Dungeon();
		void generateDungeon();
		void addNorth(std::string type, int n);	
		void addEast(std::string type, int n);
		void addWest(std::string type, int n);
		void moveNorth();
		void moveSouth();
		void moveEast();
		void moveWest();	
		void getRoomType();
		bool hasItem(std::string name);
		void addItem(std::string name);
		void removeItem(std::string name);
		void printInv();
		void exploreDungeon();
		int getMoves();
			
	private:
		int moves;
		int itemCount;
		Room* head;
		Room* position;
		std::string inventory[10];
};

#endif
