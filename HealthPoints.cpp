#include "HealthPoints.h"

HealthPoints::HealthPoints(const int maxHealth):
m_healthPoints(maxHealth), m_maxHealthPoints(maxHealth)
{
    if(maxHealth <= 0)
    {
        throw InvalidArgument();
    }
}

HealthPoints& HealthPoints::operator+=(const int points)
{
    if((m_healthPoints + points)>m_maxHealthPoints)
    {
        m_healthPoints = m_maxHealthPoints;
        return *this;
    }
    if((m_healthPoints + points) < 0)
    {
        m_healthPoints = 0;
        return *this;
    }
    m_healthPoints += points;
    return *this;
}

HealthPoints HealthPoints::operator+(const int points) const
{
    HealthPoints result = *this;
    result += points;
    return result;
}

HealthPoints operator+(const int points, const HealthPoints& current)
{
    return current + points;
}

HealthPoints& HealthPoints::operator-=(const int points)
{
    *this += (-points);
    return *this;
}

HealthPoints HealthPoints::operator-(const int points) const
{
    HealthPoints result = *this;
    result-=points;
    return result;
}

bool operator==(const HealthPoints& current, const HealthPoints& other)
{
    return !((current < other)||(other < current));
}

bool operator<(const HealthPoints& current, const HealthPoints& other)
{
    return (current.m_healthPoints < other.m_healthPoints);
}

bool operator>(const HealthPoints& current, const HealthPoints& other)
{
    return !((current < other)||(current == other));
}
bool operator>=(const HealthPoints& current, const HealthPoints& other)
{
    return ((current > other)||(current == other));
}

bool operator<=(const HealthPoints& current, const HealthPoints& other)
{
    return ((current < other)||(current == other));
}

bool operator!=(const HealthPoints& current, const HealthPoints& other)
{
    return !(current == other);
}

std::ostream& operator<<(std::ostream& os, const HealthPoints& current)
{
    os << current.m_healthPoints << "(" << current.m_maxHealthPoints << ")";
    return os;
}