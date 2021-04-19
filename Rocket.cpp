#include "Rocket.h"
#include "Blu_bots.h"
#include "Game.h"
#include <QTimer>
#include <QList>
#include <QGraphicsScene>
#include <QGraphicsScale>

extern Game * game;

Rocket::Rocket(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/new/img/img_res/rocket.png"));
    QTimer * Btimer = new QTimer();
    connect(Btimer,SIGNAL(timeout()),this,SLOT(move()));
    Btimer->start(10);
    rktExpl = new QMediaPlayer();
    rktExpl->setMedia(QUrl("qrc:/new/sound/sound_res/explode1.wav"));
    rktExpl->setVolume(6);
}

void Rocket::move()
{
    QList<QGraphicsItem *> collision_rkt = collidingItems();
    for ( int i=0, n = collision_rkt.size(); i<n; ++i)
    {
        if(typeid(*(collision_rkt[i])) == typeid(Blu))
        {
            game->score->increase();
            scene()->removeItem(collision_rkt[i]);
            scene()->removeItem(this);
            delete collision_rkt[i];
            delete this;            
            return Explode();
        }
    }

    setPos(x()+10,y());
    if(pos().x() > 800)
    {
        scene()->removeItem(this);
        delete this;
    }
}

void Rocket::Explode()
{
    rktExpl->play();
}
