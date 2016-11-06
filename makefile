all:crawl

crawl: main.o battleRoom.o itemRoom.o trapRoom.o room.o dungeon.o 
	g++ main.o battleRoom.o itemRoom.o trapRoom.o room.o dungeon.o -o crawl

main.o: main.cpp
	g++ -c main.cpp

battleRoom.o: battleRoom.hpp battleRoom.cpp
	g++ -c battleRoom.cpp

itemRoom.o: itemRoom.hpp itemRoom.cpp
	g++ -c itemRoom.cpp

trapRoom.o: trapRoom.hpp trapRoom.cpp
	g++ -c trapRoom.cpp

dungeon.o: dungeon.hpp dungeon.cpp
	g++ -c dungeon.cpp

room.o: room.hpp room.cpp
	g++ -c room.cpp

clean:
	rm *o crawl