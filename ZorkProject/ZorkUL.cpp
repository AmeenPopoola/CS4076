#include <iostream>
#include "item.h"
#include "Artifact.h"
#include "image.h"
//#include "enemy.h"
//#include "mummy.h"
#include "mainwindow.h"
#include <QApplication>

using namespace std;
#include "ZorkUL.h"

ZorkUL::ZorkUL() {
	createRooms();
}

//use of inline function
inline void ZorkUL::createRooms()  {
    Room *a, *b, *c, *d, *e , *f;

    a = new Room("Centre");
        a->addItem(new Artifact("Crown", 8, 150 , 2000));
        a->addItem(new Artifact("Amulet", 2, 220 , 1000));
        //a->addImage(new Image("C:/CS4076/April/images/Centre.jpg"));
    b = new Room("Kar's Tomb");
        b->addItem(new Artifact("Bracelet", 3, 330 , 3500));
        b->addItem(new Artifact("Earrings", 4, 500 , 2405));
        //b->addEnemy(new mummy("Stratos", 50 , 240));
    c = new Room("Santana's Tomb");
        c->addItem(new Artifact("Mask", 3, 390 , 2500));
    d = new Room("Wamuu's Tomb");
         d->addItem(new Artifact("Rosetta Stone", 28 , 350 , 500));
    e = new Room("Esidisi's Tomb");
         e->addItem(new Artifact("Dynasty Vase", 13, 400 , 6500));
         e->addItem(new Artifact("Panther Bracelet", 43, 250 , 2500));
         e->addItem(new Artifact("Encrusted Sword", 83,260 , 9500));
    f = new Room("Dio's Tomb");

    roomList[0] = a;
    roomList[1] = b;
    roomList[2] = c;
    roomList[3] = d;
    roomList[4] = e;
    roomList[5] = f;

//             (N, E, S, W)
    a->setExits(d, c, NULL, b);
    b->setExits(NULL, a, NULL, NULL);
    c->setExits(NULL,f, e, a);
    d->setExits(NULL, NULL, a, NULL);
    e->setExits(c, NULL, NULL, NULL);
    f->setExits(NULL, NULL, NULL, c);

        currentRoom = a;
}

string ZorkUL::printWelcome() {
     return "Welcome\nYou are stranded in the Forbidden Pyramids of Egypt!!\nYour task is to find the escape room of the pyramids.\n" +
            currentRoom->longDescription();
}


/** COMMANDS **/
string ZorkUL::printHelp() {
    return "\n*Use Direction Buttons(NSFW) to move\n*Pick Up Button to pick up item in Room\n*Help Button for info\n*Quit Button to quit game\n";
}


string ZorkUL::go(string direction) {
	//Make the direction lowercase
	//transform(direction.begin(), direction.end(), direction.begin(),:: tolower);
	//Move to the next room
	Room* nextRoom = currentRoom->nextRoom(direction);
	if (nextRoom == NULL)
        return("You can't go this way");
	else
	{
		currentRoom = nextRoom;
        return currentRoom->longDescription();
	}
}

Room ZorkUL::getRoom(){
    return *currentRoom;
}

void ZorkUL::viewItems(){
    currentRoom->displayItem();
}
