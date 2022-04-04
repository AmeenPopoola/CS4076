#include <iostream>
#include "item.h"
#include "Artifact.h"
#include "enemy.h"
#include "mummy.h"
#include "mainwindow.h"
#include <QApplication>

using namespace std;
#include "ZorkUL.h"

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
	ZorkUL temp;
	temp.play();
	return 0;
}

ZorkUL::ZorkUL() {
	createRooms();
}

//use of inline function
inline void ZorkUL::createRooms()  {
    Room *a, *b, *c, *d, *e , *f;

    a = new Room("Centre");
        a->addItem(new Artifact("Crown", 8, 150 , 2000));
        a->addItem(new Artifact("Amulet", 2, 220 , 1000));
    b = new Room("Kar's Tomb");
        b->addItem(new Artifact("Bracelet", 3, 330 , 3500));
        b->addItem(new Artifact("Earrings", 4, 500 , 2405));
        b->addEnemy(new mummy("Stratos", 50 , 240));
    c = new Room("Santana's Tomb");
    d = new Room("Wamuu's Tomb");
    e = new Room("Esidisi's Tomb");
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

/**
 *  Main play routine.  Loops until end of play.
 */
void ZorkUL::play() {
	printWelcome();

	// Enter the main command loop.  Here we repeatedly read commands and
	// execute them until the ZorkUL game is over.

	bool finished = false;
	while (!finished) {
		// Create pointer to command and give it a command.
		Command* command = parser.getCommand();
		// Pass dereferenced command and check for end of game.
		finished = processCommand(*command);
		// Free the memory allocated by "parser.getCommand()"
		//   with ("return new Command(...)")
		delete command;
	}
	cout << endl;
	cout << "end" << endl;
}

string ZorkUL::printWelcome() {
     return "Welcome\nYou are stranded in the Forbidden Pyramids of Egypt!!\n" +
            currentRoom->longDescription();
}

/**
 * Given a command, process (that is: execute) the command.
 * If this command ends the ZorkUL game, true is returned, otherwise false is
 * returned.
 */
bool ZorkUL::processCommand(Command command) {
	if (command.isUnknown()) {
		cout << "invalid input"<< endl;
		return false;
	}

	string commandWord = command.getCommandWord();
	if (commandWord.compare("info") == 0)
		printHelp();

    /*else if (commandWord.compare("map") == 0)
		{
        cout << "        [d] "              << endl;
        cout << "         |         "       << endl;
        cout << "         |         "       << endl;
        cout << "[b] --- [a]---[c]--- [f]"  << endl;
        cout << "               |         " << endl;
        cout << "               |         " << endl;
        cout << "              [e] "        << endl;
        }*/

	else if (commandWord.compare("go") == 0)
		goRoom(command);

    else if (commandWord.compare("take") == 0)
    {
       	if (!command.hasSecondWord()) {
		cout << "incomplete input"<< endl;
        }
        else
         if (command.hasSecondWord()) {
        cout << "you're trying to take the " + command.getSecondWord() << endl;
        int location = currentRoom->isItemInRoom(command.getSecondWord());
        if (location  < 0 )
            cout << "That item you are trying to take is not in this room " << endl;
        else
            cout << "You have picked up the " << command.getSecondWord() << endl;
            cout << "index number " << + location << endl;
            cout << endl;
            cout << currentRoom->longDescription() << endl;
        }
    }

    else if (commandWord.compare("put") == 0)
    {

    }
    /*
    {
    if (!command.hasSecondWord()) {
		cout << "incomplete input"<< endl;
        }
        else
            if (command.hasSecondWord()) {
            cout << "you're adding " + command.getSecondWord() << endl;
            itemsInRoom.push_Back;
        }
    }
*/
    else if (commandWord.compare("quit") == 0) {
		if (command.hasSecondWord())
			cout << "overdefined input"<< endl;
		else
			return true; /**signal to quit*/
	}
	return false;
}
/** COMMANDS **/
string ZorkUL::printHelp() {
    return "*Use Direction Buttons(NSFW) to move\n*Pick Up Button to pick up item in Room\n*Put Button to put down item\n*Help Button for info\n*Quit Button to quit game\n";
}

void ZorkUL::goRoom(Command command) {
	if (!command.hasSecondWord()) {
		cout << "incomplete input"<< endl;
		return;
	}

	string direction = command.getSecondWord();

	// Try to leave current room.
	Room* nextRoom = currentRoom->nextRoom(direction);

	if (nextRoom == NULL)
		cout << "underdefined input"<< endl;
	else {
		currentRoom = nextRoom;
        cout << currentRoom->longDescription() << endl;
	}
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

Room* ZorkUL::getRoom(){
    return currentRoom;
}
