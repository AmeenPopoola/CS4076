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

    QPixmap mapPic("C:/Users/ameen/Downloads/MapGUI.png");
    int w = ui->map->width();
    int h = ui->map->height();
    ui->map->setPixmap(mapPic.scaled(w,h,Qt::KeepAspectRatio));
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


void MainWindow::inRoom(string direction){
       ui->textBox->append(QString::fromStdString(zork->go(direction) + "\n"));
}

void MainWindow::on_Help_clicked()
{
      ui->textBox->append(QString::fromStdString(zork->printHelp()));
}

