#ifndef IROTABLE_H
#define IROTABLE_H

#include <iostream>
#include "CConfig.h"
#include "CExceptions.h"
 
using namespace std;

/*!
 * \brief Интерфейс для поворота.
*/

class IRotable {
public:
    //то, что задаётся один раз - в конструктор
    //то, что изменяется - в set/get
    IRotable(const int &angularVelocity) : m_angularVelocity(angularVelocity) {}

/*!
 * \brief Устанавливает направление, разрешенное конфигом.
*/
    int setAngular(const int &value) {

        if (value < 0 || value > CConfig::direction_count()) {
            std::string err = "angular is invalid";
            throw angular_value_is_invalid(err);
        }

        m_direction = value;
    }

/*!
 * \brief Возвращает направление.
*/
    int getAngular() {
        return m_direction;
    }

/*!
 * \brief Возвращает значение угловой скорости.
*/
    int getAngularVelocity() {
        return m_angularVelocity;
    }
private:
    int m_direction = 0;
    int m_angularVelocity = 0;
};
#endif
