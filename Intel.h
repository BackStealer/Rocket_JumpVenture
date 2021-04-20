#ifndef INTEL_H
#define INTEL_H

#include "Soldier.h"
#include <QMediaPlayer>

class Intel: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Intel(QGraphicsItem *parent=0);
    void MineL();
    QMediaPlayer *Hehe;
public slots:
    void intelMove();
signals:
    void caught();

};


#endif // INTEL_H
