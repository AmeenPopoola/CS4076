#include "Artifact.h"
#include <sstream>
Artifact::Artifact(string description, int weight , float value , int age) : Item(description,weight,value){
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
    stringstream desc;
   desc << "Artifact Name: " << getShortDescription() << endl << " | Value: "<< to_string(getValue()) << " | Weight: " << getWeight() << endl << " | Age Of This Artifact: "
         << getAge();
   return desc.str();
}
