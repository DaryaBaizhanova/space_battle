#ifndef CROTATE_H
#define CROTATE_H

#include "IRotable.h"
#include "CConfig.h"

/*!
 * \brief Поворот.
*/
class CRotate
{
public:
    CRotate(IRotable &rotable) : m_rotable(rotable){}

    virtual void exec();
private:
    IRotable &m_rotable;
};


void CRotate::exec()
{
    //считаем по кругу от 0 до 359
    int newDirection = m_rotable.getAngular() + m_rotable.getAngularVelocity();
    if (newDirection > CConfig::direction_count()) {
        newDirection = newDirection % CConfig::direction_count();
    } else {
        if (newDirection < 0) {
            newDirection = CConfig::direction_count() + newDirection;
        }
    }

    m_rotable.setAngular(newDirection);
}

#endif // CROTATE_H
