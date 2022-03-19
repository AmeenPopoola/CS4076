#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Room.h"
#include "item.h"
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

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_North_clicked();

    void on_South_clicked();

    void on_East_clicked();

    void on_West_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
