#ifndef SKILL_H
#define SKILL_H

#include <QGraphicsTextItem>

class Skill: public QGraphicsTextItem
{
public:
    Skill(QGraphicsItem * parent=0);
    void decrease();
    void increase();
    int getSkill();
    int skill;
};

#endif // SKILL_H
