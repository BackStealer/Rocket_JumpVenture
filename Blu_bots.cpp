#include "Blu_bots.h"
#include <QGraphicsScene>
#include "Game.h"
#include <QTimer>
#include <stdlib.h>
#include <QGraphicsScale>

extern Game * game;

Blu::Blu(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    int rng = rand()%500;
    setPos(800,rng);
    if (rngBlu == 1) setPixmap(QPixmap(":/new/img/img_res/Spyware.png"));
    else setPixmap(QPixmap(":/new/img/img_res/Scoutbot.png"));
    QTimer * bluTimer = new QTimer();
    connect(bluTimer,SIGNAL(timeout()),this,SLOT(bluMove()));
    bluTimer->start(30);
}

void Blu::bluMove()
{
    if(rngBlu==1)
    {
        setPos(x()-5,y());
    }
    else
    {
        setPos(x()-10,y());
    }
    if(pos().x()+100 < 0)
    {
        game->health->decrease();
        scene()->removeItem(this);
        delete this;
    }
}
