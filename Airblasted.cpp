#include "Airblasted.h"
#include "Blu_bots.h"
#include "HeavyBot.h"
#include "Pyro.h"
#include "Game.h"
#include <QTimer>
#include <QList>
#include <QGraphicsScene>

extern Game * game;

Airb::Airb(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    QTimer * Btimer = new QTimer();
    connect(Btimer,SIGNAL(timeout()),this,SLOT(moveAirb()));
    Btimer->start(10);
    rktExpl = new QMediaPlayer();
    rktExpl->setMedia(QUrl("qrc:/new/sound/sound_res/explode1.wav"));
    rktExpl->setVolume(3);

}

void Airb::moveAirb()
{
    setPixmap(QPixmap(":/new/img/img_res/rocket.png"));
    QList<QGraphicsItem *> collision_rkt = collidingItems();
    for ( int i=0, n = collision_rkt.size(); i<n; ++i)
    {
         if(typeid(*(collision_rkt[i])) == typeid(Soldier))
         {
            game->health->decrease();
            scene()->removeItem(this);
            delete this;
            return Explode();
         }
    }
    setPos(x()-10,y());
    if(pos().x() > 800)
    {
        scene()->removeItem(this);
        delete this;
    }
}

void Airb::Explode()
{
    rktExpl->play();
}
