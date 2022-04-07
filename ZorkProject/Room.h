#ifndef ROOM_H_
#define ROOM_H_

#include <map>
#include <string>
#include <vector>
#include "item.h"
#include "enemy.h"
using namespace std;
using std::vector;//sequence containers that store elements for dynamic data

class Room {

    friend class MainWindow;

protected:
    string description;
	map<string, Room*> exits;
	string exitString();
    vector <Item> itemsInRoom;
   // vector <enemy> enemyInRoom;


public:
    int numberOfItems();
    Room(string description);
	void setExits(Room *north, Room *east, Room *south, Room *west);
    string shortDescription();
    string longDescription();
	Room* nextRoom(string direction);
    void addItem(Item *inItem);
    //void addEnemy(enemy *inEnemy );
    vector<Item> viewItems();
    string displayItem();
    int isItemInRoom(string inString);
    void removeItemFromRoom(int location);
    bool allItemsCollected();
};

#endif
