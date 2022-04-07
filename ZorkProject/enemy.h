/*#ifndef ENEMY_H
#define ENEMY_H

#include <string>
#include <iostream>
using namespace std;

class enemy {



protected :
    string description;
    int damage;

public:
    enemy(string description , int damage);
    ~enemy();
    template <typename T>
        void setDamage(const T& damge);
    virtual string getDescription() ;
    virtual int getDamage() ;

};

#endif // ENEMY_H
*/
