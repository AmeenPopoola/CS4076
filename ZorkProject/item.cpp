#include "item.h"

//use of default parameters
Item::Item (string inDescription , int inWeightGrams = 0, float inValue = 0.0):value(inValue) {
	description = inDescription;
    setWeight(inWeightGrams);
}

Item::Item(string inDescription) {
	description = inDescription;
}

bool Item::operator==(Item &i)
{
    int test = 0;

    if (this->getShortDescription() == i.getShortDescription())
    {
        test = 1;
    }

    return test;
}

void Item::setWeight(int inWeightGrams)
{
    if (inWeightGrams > 9999 || inWeightGrams < 0)
       cout << "weight invalid, must be 0<weight<9999" ;
    else
	   weightGrams = inWeightGrams;
}

void Item::setValue(float inValue)
{
    if (inValue > 9999 || inValue < 0)
       cout << "value invalid, must be 0<value<9999" ;
    else
	   value = inValue;
}

int Item::getWeight(){
    return weightGrams;
}

float Item::getValue(){
    return value;
}


string Item::getShortDescription()
{
	return description;
}

string Item::getLongDescription()
{
	return " item(s), " + description + ".\n";
}

