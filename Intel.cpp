#include "Intel.h"
#include <QGraphicsScene>
#include "Game.h"
#include <stdlib.h>
#include <QList>

extern Game * game;

Intel::Intel(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    int rng = rand()%500;
    setPos(800,rng);
    setPixmap(QPixmap(":/new/img/img_res/intel.png"));
    QTimer * intelTimer = new QTimer();
    connect(intelTimer,SIGNAL(timeout()),this,SLOT(intelMove()));
    intelTimer->start(25);
    Hehe = new QMediaPlayer();
    Hehe->setMedia(QUrl("qrc:/new/sound/sound_res/TF2 Soldier Mine.mp3"));
    Hehe->setVolume(10);
    skill = new Skill();
}

void Intel::MineL()
{
    Hehe->play();
}

void Intel::intelMove()
{
    QList<QGraphicsItem *> collision_intel = collidingItems();
    for ( int i=0, n = collision_intel.size(); i<n; ++i)
    {
        if(typeid(*(collision_intel[i])) == typeid(Soldier))
        {
            skill->skillIncrease();
            int temp = skill->getSkill();
            qDebug() << temp;
            game->skill->skillIncrease();
            scene()->removeItem(this);
            delete this;
            return MineL();
        }
    }
    setPos(x()-22,y());
    if(pos().x()+100 < 0)
    {
        scene()->removeItem(this);
        delete this;
    }
}

