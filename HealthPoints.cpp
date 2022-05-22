#include "HealthPoints.h"

HealthPoints::HealthPoints(const int maxHealth):
m_healthPoints(maxHealth)
{
    try {
        if(maxHealth <= 0)
        {
            throw
        }
    }
}
