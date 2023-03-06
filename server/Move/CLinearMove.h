#ifndef CLINEARMOVE_H
#define CLINEARMOVE_H

#include "CMove.h"

/*!
 * \brief Прямолинейное движение.
*/
class CLinearMove : public CMove {

public:
    CLinearMove(IMovable &movable) : CMove(movable) {

    }

    void exec() override {
        //нужно изменить координаты
        //чтобы изменить координаты, нужно знать скорость и позицию на начало движения
        Coords newPosition = CCalc::additionalCoords(m_movable.getPosition(), m_movable.getVelocity());
        m_movable.setPosition(newPosition);
    }

private:
    //IMovable &m_movable;
};

#endif // CLINEARMOVE_H
