#pragma once
#include <string>
#include <iostream>
#include <string>

// Fragen wozu das in jäger dann noch ship:: s,h,d, name ???

class Ship
{
protected:
    std::string shipName;
    int size;
    int hp;
    int damage;
    std::string special;

public:
    Ship(int s = 0, int h = 0, int d = 0, std::string name = "parent");
    std::string getInfo();
    int gethp();
    int getSize();
    virtual int getDamage(int randomNum);
    virtual int takeDamage(int dam);
    virtual bool extraAttack();
    virtual int getHitBonus(int size);
};

class Jäger : public Ship
{
public:
    Jäger(int s = 4, int h = 75, int d = 30, std::string name = "Jäger") : Ship(s, h, d, name)
    {}
    int getDamage(int randomNum) override;
};

class Kreuzer : public Ship
{
public:
    Kreuzer(int s = 6, int h = 150, int d = 50, std::string name = "Kreuzer") : Ship(s, h, d, name)
    {}
    bool extraAttack() override;
};

class Zerstörer : public Ship
{
public:
    Zerstörer(int s = 8, int h = 250, int d = 60, std::string name = "Zerstörer") : Ship(s, h, d, name)
    {
    }

    int getHitBonus(int size) override;
};
