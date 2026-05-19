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
    int damageSpecial = 0;
    std::string special;

public:
    Ship(int s = 0, int h = 0, int d = 0, std::string name = "parent")
    {
        size = s;
        hp = h;
        damage = d;
        shipName = name;

        // std::cout << "size:" << size << " damage" << damage << " hp" << hp << std::endl;
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

    virtual int getDamage(int randomNum)
    {
        return damage;
    }

    virtual int getDamageSpecial()
    {
        return damageSpecial;
    }

    virtual int takeDamage(int dam)
    {
        return hp -= dam;
    }

    virtual bool extraAttack()
    {
        return false;
    }

    virtual int getHitBonus(int size)
    {
        return size;
    }
};

class Jäger : public Ship
{
public:
    Jäger(int s = 4, int h = 75, int d = 30, std::string name = "Jäger") : Ship(s, h, d, name)
    {
    }

    int getDamage(int randomNum) override
    {
        if (randomNum >= 9)
        {
            std::cout << "Mega Hit!!!" << std::endl;
            return damage * 2;
        }
        else
        {
            return damage;
        }
    }
};

class Kreuzer : public Ship
{
public:
    Kreuzer(int s = 6, int h = 150, int d = 50, std::string name = "Kreuzer") : Ship(s, h, d, name)
    {
    }

    bool extraAttack() override
    {
        return true;
    }
};

class Zerstörer : public Ship
{
public:
    Zerstörer(int s = 8, int h = 250, int d = 60, std::string name = "Zerstörer") : Ship(s, h, d, name)
    {
    }

    int getHitBonus(int size) override
    {
        int randomNum = rand() % 3 + 1;
        if (randomNum == 1)
        {
            int newSize = size-2;
            std::cout << "Size reduction " << size << " : " << newSize << std::endl;
            return size - 2;
        }
        else
        {
            return size;
        }
    }
};
