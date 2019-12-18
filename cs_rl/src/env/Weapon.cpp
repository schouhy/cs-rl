#include "Weapon.h"

// Weapon
Weapon::Weapon(float damage, int rate_of_fire)
    : m_Damage(damage), m_RateOfFire(rate_of_fire), m_StepsToReady(0)
{
}

const bool Weapon::isReady() const
{
    return m_StepsToReady == 0;
}

void Weapon::update()
{
    if (m_StepsToReady > 0)
        m_StepsToReady--;
}

float Weapon::fire()
{
    m_StepsToReady = m_RateOfFire;
    return m_Damage;
}

