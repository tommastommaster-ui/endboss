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

public:
    Ship(int s, int h, int d, std::string name);
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
    Jäger() : Ship(4, 75, 30, "Jäger"){}
    int getDamage(int randomNum) override;
};

class Kreuzer : public Ship
{
public:
    Kreuzer() : Ship(6, 150, 50, "Kreuzer"){}
    bool extraAttack() override;
};

class Zerstörer : public Ship
{
public:
    Zerstörer() : Ship(8, 250, 60, "Zerstörer"){}

    int getHitBonus(int size) override;
};
