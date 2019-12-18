#include "Weapon.h"

// Weapon
Weapon::Weapon(int rate_of_fire)
    : m_RateOfFire(rate_of_fire), m_StepsToReady(0)
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

void Weapon::fire()
{
    m_StepsToReady = m_RateOfFire;
}

// Rifle

Rifle::Rifle()
    : Weapon(30)
{
}

Rifle::~Rifle()
{
}

const float Rifle::getDamage() const
{
    return 100.f;
}
