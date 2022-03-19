#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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

