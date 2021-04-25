#ifndef ROCKET_H
#define ROCKET_H

#include "Soldier.h"
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QMediaPlayer>
#include <QUrl>

class Rocket: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Rocket(QGraphicsItem *parent=0);
    QMediaPlayer * rktExpl;
    QMediaPlayer * airBlast;
    int hp = 3;
    int defl = 1;
public slots:
    void move();
    void Explode();
    void airBlastSf();
    void rktStop();
signals:
    void airBlested();
};


#endif // ROCKET_H
