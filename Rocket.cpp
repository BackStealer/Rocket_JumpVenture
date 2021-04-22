#include "Rocket.h"
#include "Blu_bots.h"
#include "HeavyBot.h"
#include "Pyro.h"
#include "Game.h"
#include "Airblasted.h"
#include <QTimer>
#include <QList>
#include <QGraphicsScene>

extern Game * game;

Rocket::Rocket(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    QTimer * Btimer = new QTimer();
    connect(Btimer,SIGNAL(timeout()),this,SLOT(move()));
    Btimer->start(10);
    rktExpl = new QMediaPlayer();
    rktExpl->setMedia(QUrl("qrc:/new/sound/sound_res/explode1.wav"));
    rktExpl->setVolume(3);
    airBlast = new QMediaPlayer();
    airBlast->setMedia(QUrl("qrc:/new/sound/sound_res/flame_thrower_airblast.wav"));
    airBlast->setVolume(3);


}

void Rocket::move()
{
    setPixmap(QPixmap(":/new/img/img_res/rocket.png"));
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
        if(typeid(*(collision_rkt[i])) == typeid(Heavy))
        {
            if(pos().x()<400)
            {
                game->score->heavyIncrease();
                scene()->removeItem(collision_rkt[i]);
                scene()->removeItem(this);
                delete collision_rkt[i];
                delete this;
                return Explode();
            }
            else
            {
                scene()->removeItem(this);
                delete this;
                return Explode();
            }
        }
        if(typeid(*(collision_rkt[i])) == typeid(Pyro))
        {
            if(pos().x()>350)
            {
                Airb * airb = new Airb();
                airb->setPos(x(),y());
                scene()->addItem(airb);
//                connect(airb,SIGNAL(airBlasted()),this,SLOT(moveAirb()));
//                emit airBlested();
                scene()->removeItem(this);
                delete this;
                return airBlastSf();
            }
            else
            {
                game->score->pyroIncrease();
                scene()->removeItem(collision_rkt[i]);
                scene()->removeItem(this);
                delete collision_rkt[i];
                delete this;
                return Explode();
            }
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

void Rocket::airBlastSf()
{
    airBlast->play();
}
