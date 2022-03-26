#include "Character.h"

Character::Character(string name , string description){
    this->name = name;
    this->description = description;
}

string Character::getName(){
    return name;
}

string Character::getDescription(){
    return description;
}



