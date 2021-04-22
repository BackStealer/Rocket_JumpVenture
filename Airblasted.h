#ifndef AIRBLASTED_H
#define AIRBLASTED_H

#include "Soldier.h"
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QMediaPlayer>
#include <QUrl>

class Airb: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Airb(QGraphicsItem *parent=0);
    QMediaPlayer * rktExpl;
    QMediaPlayer * airBlast;
    int hp = 3;
    int defl = 1;
    void airBlastSf();
public slots:
    void moveAirb();
    void Explode();
};

#endif // AIRBLASTED_H
