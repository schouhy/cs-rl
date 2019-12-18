#ifndef WEAPON_H
#define WEAPON_H


class Weapon
{
protected:
    const int m_RateOfFire;
    int m_StepsToReady;

public:
    Weapon(int rate_of_fire);
    virtual ~Weapon() = default;
    const bool isReady() const;
    void update();
    void fire();
    virtual const float getDamage() const = 0;
};


class Rifle : public Weapon
{
public:
    Rifle();
    ~Rifle();
    const float getDamage() const override;
};

#endif // WEAPON_H