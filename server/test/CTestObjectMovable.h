#ifndef CTESTOBJECTMOVABLE_H
#define CTESTOBJECTMOVABLE_H

#include "CBaseSpaceObject.h"
#include "Move/IMovable.h"
#include <iostream>

/*!
 * \brief Объект, умеющий двигаться.
*/
class CTestMovable : public IMovable, public CBaseSpaceObject
{
public:
    CTestMovable(const CoordsVelocity &velocity) : IMovable(velocity), CBaseSpaceObject()
    {        
    }

};

#endif // CTESTOBJECTMOVABLE_H
