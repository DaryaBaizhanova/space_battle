#ifndef CMOVE_H
#define CMOVE_H

#include <iostream>

#include <vector>

#include "IMovable.h"
#include "../CCoords.h"
#include "../CCalc.h"
 
using namespace std;

/*!
 * \brief Движение.
*/
class CMove {

public:
    CMove(IMovable &movable);// по ссылке будем изменять объект, умеющий двигаться

    virtual void exec() = 0;

//private:
    IMovable &m_movable;
};

inline CMove::CMove(IMovable &movable) : m_movable(movable) {

}
#endif
