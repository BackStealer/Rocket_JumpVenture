#include "Intel.h"
#include <QGraphicsScene>
#include "Game.h"
#include <stdlib.h>

//extern Game * game;

Intel::Intel(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    int rng = rand()%500;
    setPos(800,rng);
    setPixmap(QPixmap(":/new/img/img_res/intel.png"));
    QTimer * intelTimer = new QTimer();
    connect(intelTimer,SIGNAL(timeout()),this,SLOT(intelMove()));
    intelTimer->start(25);
}

void Intel::intelMove()
{
    setPos(x()-22,y());
    if(pos().x()+100 < 0)
    {
        scene()->removeItem(this);
        delete this;
    }
}

