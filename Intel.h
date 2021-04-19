#ifndef INTEL_H
#define INTEL_H

#include "Soldier.h"

class Intel: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Intel(QGraphicsItem *parent=0);
public slots:
    void intelMove();
};


#endif // INTEL_H
