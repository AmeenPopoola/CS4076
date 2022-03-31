#ifndef MUMMY_H
#define MUMMY_H

#include <enemy.h>

#include <QMainWindow>
#include <QObject>
#include <QWidget>

class mummy : public enemy {

    friend class Room;

private:
    int age;
public:
    mummy(string description , int damage , int age);
    ~mummy();
    void setAge(int age);
    string getDescription();
    int getDamage();
    int getAge();
};

#endif // MUMMY_H
