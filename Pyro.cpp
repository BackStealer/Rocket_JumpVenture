#include "Pyro.h"
#include <QGraphicsScene>
#include "Game.h"
#include <QTimer>
#include <stdlib.h>
#include <QList>
#include <QGraphicsScene>

extern Game * game;

Pyro::Pyro(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    int rng = rand()%500;
    setPos(800,rng);
    setPixmap(QPixmap(":/new/img/img_res/Pyrobot.png"));
    QTimer * pyroTimer = new QTimer();
    connect(pyroTimer,SIGNAL(timeout()),this,SLOT(pyroMove()));
    pyroTimer->start(30);
    rktExpl = new QMediaPlayer();
    rktExpl->setMedia(QUrl("qrc:/new/sound/sound_res/explode1.wav"));
    rktExpl->setVolume(3);
}

void Pyro::pyroMove()
{
    setPos(x()-5,y());
    if(pos().x()+100 < 0)
    {
        game->health->decrease();
        scene()->removeItem(this);
        delete this;
    }
}


