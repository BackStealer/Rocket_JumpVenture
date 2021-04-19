#ifndef INTEL_H
#define INTEL_H

#include "Soldier.h"
#include "Skill.h"

class Intel: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Intel(QGraphicsItem *parent=0);
    void MineL();
    QMediaPlayer *Hehe;
public slots:
    void intelMove();
private:
    Skill *skill;
};


#endif // INTEL_H
