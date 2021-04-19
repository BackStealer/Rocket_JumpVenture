#include "Skill.h"
#include <QFont>

Skill::Skill(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    skill = 1;
    setPlainText(QString("Super Skills: ") + QString::number(skill));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times",14));
}

void Skill::decrease()
{
    if(skill>0)
    {
    skill--;
    setPlainText(QString("Super Skills: ") + QString::number(skill));
    }
    else return;
}
int Skill::getSkill()
{
    return skill;
}
