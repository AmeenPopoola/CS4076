#ifndef ARTIFACT_H
#define ARTIFACT_H

#include "item.h"

//Artifact Inherits from Item class
class Artifact : public Item {
    private:
       int age;


    public:
     Artifact(string description , int weight , float value , int age);
     ~Artifact();
     void setAge(int age);
     int getAge();
     string getLongDescription();
};

#endif // ARTIFACT_H
