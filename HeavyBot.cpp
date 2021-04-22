#include "HeavyBot.h"
#include <QGraphicsScene>
#include "Game.h"
#include <QTimer>
#include <stdlib.h>
#include <QGraphicsScale>

extern Game * game;

Heavy::Heavy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    int rng = rand()%500;
    setPos(800,rng);
    setPixmap(QPixmap(":/new/img/img_res/Heavybot.png"));
    QTimer * heavyTimer = new QTimer();
    connect(heavyTimer,SIGNAL(timeout()),this,SLOT(heavyMove()));
    heavyTimer->start(40);
}

void Heavy::heavyMove()
{
    setPos(x()-5,y());
    if(pos().x()+100 < 0)
    {
        game->health->decrease();
        scene()->removeItem(this);
        delete this;
    }
}
