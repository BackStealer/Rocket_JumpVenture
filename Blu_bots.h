#ifndef BLU_BOTS_H
#define BLU_BOTS_H

#include "Soldier.h"
#include <QGraphicsPixmapItem>
#include <QObject>

class Blu: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Blu(QGraphicsItem *parent=0);
    int rngBlu = rand()%2;
public slots:
    void bluMove();
};

#endif // BLU_BOTS_H
