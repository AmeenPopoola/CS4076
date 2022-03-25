#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
}


void MainWindow::on_South_clicked()
{
      ui->dirLabel->setText("SOUTH");
}


void MainWindow::on_East_clicked()
{
      ui->dirLabel->setText("EAST");
}



void MainWindow::on_West_clicked()
{
      ui->dirLabel->setText("WEST");
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


