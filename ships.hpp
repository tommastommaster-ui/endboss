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
    int x;
    int y;

public:
    Ship(int s, int h, int d, std::string name, int posX, int posY);
    std::string getInfo();
    int gethp();
    int getSize();
    virtual int getDamage(int randomNum);
    virtual int takeDamage(int dam, int attacker, int target);
    virtual bool extraAttack();
    virtual int getHitBonus(int size);
    int getX();
    int getY();
    void move(int moveX, int moveY);
};

class Jäger : public Ship
{
public:
    Jäger(int posX, int posY) : Ship(4, 75, 30, "Jäger", posX, posY)
    {}
    int getDamage(int randomNum) override;
};

class Kreuzer : public Ship
{
public:
    Kreuzer(int posX, int posY) : Ship(6, 150, 50, "Kreuzer", posX, posY){}
    bool extraAttack() override;
};

class Zerstörer : public Ship
{
public:
    Zerstörer(int posX, int posY) : Ship(8, 250, 60, "Zerstörer", posX, posY){}
    int getHitBonus(int size) override;
};
