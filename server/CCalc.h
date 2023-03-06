#ifndef CCALC_H
#define CCALC_H

#include "math.h"
#include "vector"
#include "CCoords.h"

using namespace std;

class CCalc
{
public:
    CCalc();
    static Coords additionalCoords(const Coords &position, const CoordsVelocity &velocity){

        Coords res(position.getX() + velocity.x, position.getY() + velocity.y);

        return res;

    }
};

#endif // CCALC_H
