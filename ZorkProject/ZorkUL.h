#ifndef ZORKUL_H_
#define ZORKUL_H_

#include "Command.h"
#include "Parser.h"
#include "Room.h"
#include "item.h"
#include <iostream>
#include <string>
using namespace std;

class ZorkUL {
    friend class MainWindow;
private:
	Room *currentRoom;
    void createRooms();
    void createItems();
    void displayItems();
    Room* roomList[6];

public:
	ZorkUL();
    string printWelcome();
    string printHelp();
	void play();
    string go(string direction);
    Room getRoom();
    void viewItems();
};

#endif /*ZORKUL_H_*/
