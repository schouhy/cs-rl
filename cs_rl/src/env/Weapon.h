#ifndef WEAPON_H
#define WEAPON_H


class Weapon
{
friend class Environment;
private:
    float m_Damage;
    const int m_RateOfFire;
    int m_StepsToReady;

    const bool isReady() const;
    void update();
    float fire();
public:
    Weapon(float damage, int rate_of_fire);
    ~Weapon() = default;
};

#endif // WEAPON_H