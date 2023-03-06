#ifndef CCOORDS_H
#define CCOORDS_H

#include <vector>
#include <stdint.h>
#include <string>

#include "CExceptions.h"
#include "CConfig.h"

struct Coords {
public:
    Coords() {}

    Coords(int x, int y) : x(x), y(y) {

    }

    bool operator == (Coords a) {
        if (a.x == x && a.y == y) {
            return true;
        }
        return false;
    }

    bool operator != (Coords a) {
        if (a.x != x || a.y != y) {
            return true;
        }
        return false;
    }

    Coords additional(Coords a){
        return Coords(a.getX() + x, a.getY() + y);
    }

    void setX(const int &x_val) {
        x = x_val;
    }
    void setY(const int &y_val) {
        y = y_val;
    }

    int getX() const { return x; }
    int getY() const { return y; }

    bool isValid() {
        //не может быть меньше разрешенного
        if (x < CConfig::min_coord() || y < CConfig::min_coord()) {
            return false;
        }

        //не может быть больше разрешенного
        if (x > CConfig::max_coord() || y > CConfig::max_coord()) {
            return false;
        }
        return true;
    }

private:
    int x;
    int y;

};

struct CoordsVelocity {
    int x;
    int y;
    CoordsVelocity(const int &x, const int &y) : x(x), y(y) {

    }
    bool isValid() {
        //не может быть меньше разрешенного
        if (x < CConfig::min_velocity() || y < CConfig::min_velocity()) {
            return false;
        }

        //не может быть больше разрешенного
        if (x > CConfig::max_velocity() || y > CConfig::max_velocity()) {
            return false;
        }
        return true;
    }
};
#endif // CCOORDS_H
