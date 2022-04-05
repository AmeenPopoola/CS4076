#ifndef CHARACTER_H_
#define CHARACTER_H_
#include "ZorkUL.h"

#include <string>
using namespace std;
#include <vector>
using std::vector;


class Character {
    friend class MainWindow;
private:
	string description;
    string name;



public:

    Character(string name , string description);
    string getDescription();
    string getName();

};

#endif /*CHARACTER_H_*/
