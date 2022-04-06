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

    QPixmap room("C:/CS4076/April/images/Centre.jpg");
    //int y = ui->roomPic->width();
    //int x = ui->roomPic->height();
    ui->roomPic->setPixmap(room/*.scaled(x,y,Qt::KeepAspectRatio)*/);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete zork;
}

void MainWindow::on_North_clicked()
{
      ui->dirLabel->setText("NORTH");
      goRoom("North");
      vector<Item> items = zork->getRoom().viewItems();
      listItems(items, "room");
}


void MainWindow::on_South_clicked()
{
      ui->dirLabel->setText("SOUTH");
      goRoom("South");
      vector<Item> items = zork->getRoom().viewItems();
      listItems(items, "room");
}


void MainWindow::on_East_clicked()
{
      ui->dirLabel->setText("EAST");
      goRoom("East");
      vector<Item> items = zork->getRoom().viewItems();
      listItems(items, "room");
}



void MainWindow::on_West_clicked()
{
      ui->dirLabel->setText("WEST");
      goRoom("West");
      vector<Item> items = zork->getRoom().viewItems();
      listItems(items, "room");
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

void MainWindow::goRoom(string direction){
       ui->textBox->append(QString::fromStdString(zork->go(direction) + "\n"));
       if(zork->getRoom().description == "Dio's Tomb"){
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
    ui->listWidget->setEnabled(false);

    ui->textBox->setText(QString::fromStdString(character.description + " has " + message + ". You have succesfully escaped.\n"));
}

void MainWindow::addToListWidget(vector<Item> item){
    ui->listWidget->clear();
    if(putInInventory){
        if (!zork->getRoom().allItemsCollected()) {
                 for (unsigned int i = 0; (unsigned int)i < (unsigned int)zork->getRoom().numberOfItems(); i++) {
                     ui->listWidget->addItem(QString::fromStdString(item[i].getShortDescription()));
                 }
             }
             else {
                 ui->textBox->setText(QString::fromStdString("There are no items in the room."));
    }
    }
}

void MainWindow::listItems(vector<Item> items, QString description) {
        if (!items.empty()) {
            addToListWidget(items);
        }
        else {
            ui->textBox->setText("No " + description + " items could be found.\n");
        }
    }

void MainWindow::on_pick_up_clicked()
{
    QMessageBox::StandardButton take = QMessageBox::question(this,"Musuem", ui->listWidget->currentItem()->text() ,
                                                             QMessageBox::Yes | QMessageBox::No);
    if(take == QMessageBox::Yes){
        QMessageBox::information(this,"Musuem","This has been sent to the musuem");
    } else {
          QMessageBox::information(this,"Musuem","This has been left in the Forbidden Pyramid");
    }

}

