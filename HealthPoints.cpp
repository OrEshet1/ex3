#include "HealthPoints.h"

HealthPoints::HealthPoints(const int maxHealth):
m_healthPoints(maxHealth)
{
    if(maxHealth <= 0)
    {
        throw InvalidArgument();
    }
}

HealthPoints &HealthPoints::operator+(const int value) const
{
    return this->m_healthPoints + value;
}
