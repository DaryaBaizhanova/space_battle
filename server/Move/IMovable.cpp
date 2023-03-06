#include "IMovable.h"

IMovable::IMovable(const CoordsVelocity &velocity) : m_velocity(velocity)
{
}

void IMovable::setPosition(Coords value)
{
    if (!value.isValid()) {
        std::string err = "coord is invalid (" + std::to_string(value.getX()) + ";" + std::to_string(value.getY()) + ")";
        throw position_coord_invalid(err);
    }

    m_position = value;
}

Coords IMovable::getPosition()
{
    if (!m_position.isValid()) {
        std::string err = "coord is invalid (" + std::to_string(m_position.getX()) + ";" + std::to_string(m_position.getY()) + ")";
        throw position_coord_invalid(err);
    }

    return m_position;
}

CoordsVelocity IMovable::getVelocity()
{
    if (!m_velocity.isValid()) {
        //случится только при корявом создании объекта
        std::string err = "velocity is invalid (" + std::to_string(m_velocity.x) + ";" + std::to_string(m_velocity.y) + ")";
        throw velocity_is_invalid(err);
    }

    return m_velocity;
}
