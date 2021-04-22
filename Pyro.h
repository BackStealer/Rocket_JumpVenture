#ifndef PYRO_H
#define PYRO_H

#include "Soldier.h"
#include <QGraphicsPixmapItem>
#include <QObject>

class Pyro: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Pyro(QGraphicsItem *parent=0);
    QMediaPlayer * rktExpl;
public slots:
    void pyroMove();
};


#endif // PYRO_H
