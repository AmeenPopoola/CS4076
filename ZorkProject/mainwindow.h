#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Room.h"
#include "item.h"
#include "Character.h"
#include "ZorkUL.h"
#include <iostream>
#include <string>
using namespace std;

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    friend class ZorkUL;
    friend class Room;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void endGame(string message);
    void addListWidget(vector<Item> item);

private slots:
    void on_North_clicked();

    void on_South_clicked();

    void on_East_clicked();

    void on_West_clicked();

    void on_quit_clicked();

    void on_Help_clicked();

private:
    Ui::MainWindow *ui;
    ZorkUL *zork;
    void inRoom(string direction);
    Character character = *new Character("Jojo" , "Explorer");
    bool placeInInventory;
    void listItems(vector<Item> items , QString description);

};

#endif // MAINWINDOW_H
