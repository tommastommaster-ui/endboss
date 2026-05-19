#pragma once
#include <string>
#include <iostream>
#include <string>

//Fragen wozu das in jäger dann noch ship:: s,h,d, name ???


class Ship
{
protected:
    std::string shipName;
    int size;
    int hp;
    int damage;
    int damageSpecial = 0;
    std::string special;

public:
    Ship(int s = 0, int h = 0, int d = 0, std::string name = "parent")
    {
        size = s;
        hp = h;
        damage = d;
        shipName = name;

        //std::cout << "size:" << size << " damage" << damage << " hp" << hp << std::endl;
    }
    std::string getInfo()
    {
        return shipName;
    }

    int gethp()
    {
        return hp;
    }
    
    int getSize()
    {
        return size;
    }

    int getDamage()
    {
        return damage;
    }

    virtual int getDamageSpecial()
    {
        return damageSpecial;
    }

    int takeDamage(int dam)
    {
        return hp -= dam;
    }
    virtual bool specialAttack(int randomNum)
    {
        return false;
    }
};

class Jäger : public Ship
{
public:
    Jäger(int s = 4, int h = 75, int d = 30, std::string name = "Jäger") : Ship(s,h,d, name)
    { }
    bool specialAttack(int randomNum) override 
    {
        if(randomNum > 8)
        {
            return true;
        }
        return false;
    }
    int getDamageSpecial() override
    {
        damageSpecial = 60;
        return damageSpecial;
    }

};

class Kreuzer : public Ship
{
public:
    Kreuzer(int s =6, int h=150, int d=50, std::string name = "Kreuzer") : Ship(s,h,d, name)
    { }
};

class Zerstörer : public Ship
{
public:
    Zerstörer(int s=8, int h=250, int d=60, std::string name = "Zerstörer") : Ship(s,h,d, name)
    { }
};


