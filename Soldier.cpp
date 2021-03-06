#include "Game.h"
#include "Soldier.h"
#include "Rocket.h"
#include "Blu_bots.h"
#include "HeavyBot.h"
#include "Pyro.h"
#include "Intel.h"
#include <QGraphicsScene>
#include <stdlib.h>
#include <QKeyEvent>
#include <QVector2D>
#include <QPoint>

extern Game * game;

Soldier::Soldier(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
        setPixmap(QPixmap(":/new/img/img_res/Soldier.png"));
        QTimer *mvmnt = new QTimer(this);
        mvmnt->setInterval(10);
        connect(mvmnt,SIGNAL(timeout()),this,SLOT(move()));
        mvmnt->start();
        position.setX(position.x() + 35);
        position.setY(position.y() + 250);
        skill = new Skill();
        QTimer *SkillInfo = new QTimer();
        connect(SkillInfo,SIGNAL(timeout()),this,SLOT(SkillInfo()));
        SkillInfo->start(1);
        cooldown=false;
        skillCooldown=false;        
        ingame = false;
}

void Soldier::keyPressEvent(QKeyEvent *event)
{
    pressedKeys[event->key()] = true;
}
void Soldier::keyReleaseEvent(QKeyEvent *event)
{
    if(event->isAutoRepeat())
    {
        return;
    }
    pressedKeys[event->key()] = false;
}

//void Soldier::mousePressEvent(QMouseEvent *event)
//{
//    this->setFocus();
//}
void Soldier::spawn()
{
    Blu * blu = new Blu();
    scene()->addItem(blu);
}

void Soldier::heavySpawn()
{
    Heavy * heavy = new Heavy();
    scene()->addItem(heavy);
}

void Soldier::pyroSpawn()
{
    Pyro * pyro = new Pyro();
    scene()->addItem(pyro);
}

void Soldier::intelSpawn()
{
    Intel * intel = new Intel();
    connect(intel,SIGNAL(caught()),this,SLOT(caughtIntel()));
    scene()->addItem(intel);
}

void Soldier::endLaugh()
{
    setPixmap(QPixmap(":/new/img/img_res/Soldier.png"));
}

void Soldier::move()
{
    QVector2D velocity(0, 0);

//    if(this->y() <= 0 || this->y() >= 500)
//    {
//        return;
//    }

    if (pressedKeys[Qt::Key::Key_W] && ingame)
    {
        if(pos().y() > 0)
        velocity.setY(velocity.y() - 5);
    }
    if (pressedKeys[Qt::Key::Key_S] && ingame)
    {
        if(pos().y() < 500)
        velocity.setY(velocity.y() + 5);
    }
    if (pressedKeys[Qt::Key_Space] && !cooldown && ingame)
    {
        Rocket * rocket = new Rocket();
        rocket->setPos(x()+50,y());
        scene()->addItem(rocket);
        rktShoot = new QMediaPlayer();
        rktShoot->setMedia(QUrl("qrc:/new/sound/sound_res/rocket_shoot.wav"));
        rktShoot->setVolume(2);
        rktShoot->play();
        cooldown=true;
        QTimer::singleShot(500,this,SLOT(unlock()));
    }
    if (pressedKeys[Qt::Key_K] && !skillCooldown && ingame)
    {
        skillCooldown=true;
        QTimer::singleShot(500,this,SLOT(unlockSkill()));
        check = skill->getSkill();
        qDebug() << check;
        if(check>0)
        {
            laugh = new QMediaPlayer();
            laugh->setMedia(QUrl("qrc:/new/sound/sound_res/laugh_sold.mp3"));
            laugh->setVolume(30);
            laugh->play();
            setPixmap(QPixmap(":/new/img/img_res/Soldier_laugh.png"));
            QTimer * LaughT = new QTimer();
            connect(LaughT,SIGNAL(timeout()),this,SLOT(endLaugh()));
            LaughT->start(2500);
            for(int i=0;i<=600;i+=40)
            {
                int rktCount = rand()%600;
                Rocket * rocketSalve = new Rocket();
                rocketSalve->setPos(x()-30,rktCount);
                scene()->addItem(rocketSalve);
            }
        }
        game->skill->decrease();
        skill->decrease();
    }
    if(pressedKeys[Qt::Key_P] && !ingame)
    {
        qDebug() << "klikni??te Xd";
        game->StartGame();
        ingame=true;
    }
    position += velocity.toPointF();
    this->setPos(position);
    this->update();
}

void Soldier::SkillInfo()
{
    check = skill->getSkill();
}

void Soldier::unlock()
{
    cooldown=false;
}
void Soldier::unlockSkill()
{
    skillCooldown=false;
}

void Soldier::caughtIntel()
{
    qDebug()<<"z??apaned";
    game->skill->increase();
    skill->increase();
    qDebug()<<skill->getSkill();
}
