#include "Artifact.h"
#include <iostream>
Artifact::Artifact(string description, int weight , float value , int age = 0) : Item(description,weight,value){
    setAge(age);
}

Artifact::~Artifact(){
}

void Artifact::setAge(int years){
    this->age = years;
}

int Artifact::getAge(){
    return this->age;
}

string Artifact::getLongDescription(){

  return "Artifact Name: " + description + "\n";
}
