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
    int maxHealth = this->m_maxHealthPoints;
    int currentPoints = this->m_healthPoints;
    if((currentPoints + points)>maxHealth)
    {
        this->m_healthPoints = maxHealth;
        return *this;
    }
    if((currentPoints + points) < 0)
    {
        this->m_healthPoints = 0;
        return *this;
    }
    this->m_healthPoints -= points;
    return *this;
}

HealthPoints operator+(const HealthPoints &current, const HealthPoints &other)
{
    HealthPoints result = current;
    result += other;
    return result;
}

HealthPoints& HealthPoints::operator-=(const int points)
{
    int maxHealth = this->m_maxHealthPoints;
    int currentPoints = this->m_healthPoints;
    if((currentPoints - points)>maxHealth)
    {
        this->m_healthPoints = maxHealth;
        return *this;
    }
    if(currentPoints - points < 0)
    {
        this->m_healthPoints = 0;
        return *this;
    }
    this->m_healthPoints -= points;
    return *this;
}

HealthPoints operator-(const HealthPoints& current, const int points)
{
    HealthPoints result = current;
    result-=points;
    return result;
}

bool operator==(const HealthPoints& current, const HealthPoints& other)
{
    return (current.m_healthPoints == other.m_healthPoints);
}

bool operator<(const HealthPoints& current, const HealthPoints& other)
{
    return (current.m_healthPoints < other.m_healthPoints);
}

bool operator>(const HealthPoints& current, const HealthPoints& other)
{
    return ((!(current < other))&&(!(current == other)));
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
    return (!(current == other));
}

std::ostream& operator<<(std::ostream& os, const HealthPoints& current)
{
    os << current.m_healthPoints << "(" << current.m_maxHealthPoints << ")";
    return os;
}