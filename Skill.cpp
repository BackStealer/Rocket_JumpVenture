 #include "Skill.h"
#include <QFont>

Skill::Skill(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    skillN = 1;
    setPlainText(QString("Super Skills: ") + QString::number(skillN));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times",14));
}

void Skill::decrease()
{
    if(skillN>0)
    {
    skillN--;
    setPlainText(QString("Super Skills: ") + QString::number(skillN));
    }
    else return;
}
int Skill::getSkill()
{
    return skillN;
}
void Skill::skillIncrease()
{
    skillN += 1;
    setPlainText(QString("Super Skills: ") + QString::number(skillN));
}
