#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    zork(new ZorkUL())
{
    ui->setupUi(this);
    ui->textBox->append(QString::fromStdString(zork->printWelcome()));

    QPixmap mapPic("C:/CS4076/April/images/MapGUI.png");
   // int w = ui->map->width();
    //int h = ui->map->height();
    ui->map->setPixmap(mapPic/*.scaled(w,h,Qt::KeepAspectRatio)*/);

    QPixmap room("C:/CS4076/April/images/roomA.jpg");
    //int y = ui->roomPic->width();
    //int x = ui->roomPic->height();
    ui->roomPic->setPixmap(room/*.scaled(x,y,Qt::KeepAspectRatio)*/);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_North_clicked()
{
      ui->dirLabel->setText("NORTH");
      inRoom("North");
}


void MainWindow::on_South_clicked()
{
      ui->dirLabel->setText("SOUTH");
      inRoom("South");
}


void MainWindow::on_East_clicked()
{
      ui->dirLabel->setText("EAST");
      inRoom("East");
}



void MainWindow::on_West_clicked()
{
      ui->dirLabel->setText("WEST");
      inRoom("West");
}


void MainWindow::on_quit_clicked()
{
    QMessageBox::StandardButton response = QMessageBox::question(this , "Quit" , "Do you want to quit the game?" ,
                          QMessageBox::Yes | QMessageBox::No);
    if(response == QMessageBox::Yes) {
        QApplication::quit();
    } else {
        qDebug() << "No is clicked";
    }

    }

void MainWindow::on_Help_clicked()
{
      ui->textBox->append(QString::fromStdString(zork->printHelp()));
}

void MainWindow::inRoom(string direction){
       ui->textBox->append(QString::fromStdString(zork->go(direction) + "\n"));
       if(zork->getRoom()->description == "Dio's Tomb"){
           endGame("entered the escape room");
       }
}

void MainWindow::endGame(string message){
    ui->East->setEnabled(false);
    ui->Help->setEnabled(false);
    ui->North->setEnabled(false);
    ui->pick_up->setEnabled(false);
    ui->West->setEnabled(false);
    ui->South->setEnabled(false);
    ui->inventory->setEnabled(false);

    ui->textBox->setText(QString::fromStdString(character.description + " has " + message + ". You have succesfully escaped.\n"));
}
