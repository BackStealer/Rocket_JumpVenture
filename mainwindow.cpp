#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->view->setScene(scene);
    soldier = scene->addRect(0,0,100,100);
    soldier->setFlag(QGraphicsItem::ItemIsFocusable);
    soldier->setFocus();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void Soldier::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left){
    setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_Right){
    setPos(x()+10,y());
    }
    else if (event->key() == Qt::Key_Down){
    setPos(x(),y()+10);
    }
    else if (event->key() == Qt::Key_Up){
    setPos(x(),y()-10);
    }
}
