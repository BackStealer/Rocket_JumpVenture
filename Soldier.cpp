#include "Game.h"
#include "Soldier.h"
#include "Rocket.h"
#include "Blu_bots.h"
#include "Intel.h"
#include <QGraphicsScene>
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

    if (pressedKeys[Qt::Key::Key_W])
    {
        if(pos().y() > 0)
        velocity.setY(velocity.y() - 5);
    }
    if (pressedKeys[Qt::Key::Key_S])
    {
        if(pos().y() < 500)
        velocity.setY(velocity.y() + 5);
    }
    if (pressedKeys[Qt::Key_Space] && !cooldown)
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
    if (pressedKeys[Qt::Key_K] && !skillCooldown)
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
        }
        game->skill->decrease();
        skill->decrease();
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
    qDebug()<<"złapaned";
    game->skill->increase();
    skill->increase();
    qDebug()<<skill->getSkill();
}
