#ifndef HEAVYBOT_H
#define HEAVYBOT_H

#include "Soldier.h"
#include <QGraphicsPixmapItem>
#include <QObject>

class Heavy: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Heavy(QGraphicsItem *parent=0);
public slots:
    void heavyMove();
};

#endif // HEAVYBOT_H
