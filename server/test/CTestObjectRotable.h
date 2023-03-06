#ifndef CTESTOBJECTROTABLE_H
#define CTESTOBJECTROTABLE_H

#include "CBaseSpaceObject.h"
#include "Rotate/IRotable.h"
#include <iostream>


/*!
 * \brief Объект, умеющий поворачивать.
*/
class CTestRotable : public IRotable, public CBaseSpaceObject
{
public:
    CTestRotable(const int &angularVelocity) : IRotable(angularVelocity), CBaseSpaceObject(){}
};
#endif // CTESTOBJECTROTABLE_H
