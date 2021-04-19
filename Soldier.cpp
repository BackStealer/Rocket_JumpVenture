#include "Soldier.h"
#include "Rocket.h"
#include "Blu_bots.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QTimer>
#include <QGraphicsScale>
#include <QVector2D>
#include <QPoint>

Soldier::Soldier(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
        setPixmap(QPixmap(":/new/img/img_res/Soldier.png"));
        QTimer *mvmnt = new QTimer(this);
        mvmnt->setInterval(10);
        connect(mvmnt,SIGNAL(timeout()),this,SLOT(move()));
        mvmnt->start();
        position.setX(position.x() + 35);
        position.setY(position.y() + 250);
}

void Soldier::keyPressEvent(QKeyEvent *event)
{
//    if (event->key() == Qt::Key_W)
//    {
//        if(pos().y() > 0)
//        setPos(x(),y()-10);
//    }
//    else if (event->key() == Qt::Key_S)
//    {
//        if(pos().y() < 500)
//        setPos(x(),y()+10);
//    }
    pressedKeys[event->key()] = true;
    if (event->key() == Qt::Key_Space)
    {
        Rocket * rocket = new Rocket();
        rocket->setPos(x()+50,y());
        scene()->addItem(rocket);
        rktShoot = new QMediaPlayer();
        rktShoot->setMedia(QUrl("qrc:/new/sound/sound_res/rocket_shoot.wav"));
        rktShoot->setVolume(6);
        rktShoot->play();
    }
    else if (event->key() == Qt::Key_K)
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
}
void Soldier::keyReleaseEvent(QKeyEvent *event)
{

    if(event->isAutoRepeat())
    {
        return;
    }
    pressedKeys[event->key()] = false;
}

void Soldier::mousePressEvent(QMouseEvent *event)
{
    this->setFocus();
}
void Soldier::spawn()
{
    Blu * blu = new Blu();
    scene()->addItem(blu);
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

    position += velocity.toPointF();
    this->setPos(position);
    this->update();
}

