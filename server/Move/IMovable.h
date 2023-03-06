#ifndef IMOVABLE_H
#define IMOVABLE_H

#include <iostream>
#include "vector"

#include "../CCoords.h"
 
using namespace std;

/*!
 * \brief Интерфейс для движения.
*/
class IMovable {

public:
    IMovable(const CoordsVelocity &velocity = CoordsVelocity(0, 0));

    /*!
     * \brief Устанавливает позицию.
    */
    void setPosition(Coords value);
    Coords getPosition();

    //void setVelocity(const Coords &value); - движение равномерное, скорость менять не будем
    CoordsVelocity getVelocity();

private:
    Coords m_position = Coords(CConfig::min_coord(), CConfig::min_coord());
    CoordsVelocity m_velocity = CoordsVelocity(CConfig::min_velocity(), CConfig::min_velocity());
};

#endif
