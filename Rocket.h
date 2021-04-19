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
public slots:
    void move();
    void Explode();
};


#endif // ROCKET_H
