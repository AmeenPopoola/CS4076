#ifndef ITEM_H_
#define ITEM_H_

#include <map>
#include <string>
#include <iostream>
using namespace std;

class Item {
protected:
	string description;
	string longDescription;
	int weightGrams;
	float value;
	bool weaponCheck;

public:
    Item (string description, int inWeight, float inValue);
    Item (string description);
	string getShortDescription();
    virtual string getLongDescription();
    bool operator==(Item &i);
	int getWeight();
template <typename T>
         void setWeight( T& weight);
	float getValue();
	void setValue(float value);
};

#endif /*ITEM_H_*/
