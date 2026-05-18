#pragma once
#include <string>
#include <iostream>

class Ship
{
protected:
    int size;
    int hp;
    int damage;
    std::string special;

public:
    Ship(int s = 0, int h = 0, int d = 0)
    {
        size = s;
        hp = h;
        damage = d;

        //std::cout << "size:" << size << " damage" << damage << " hp" << hp << std::endl;
    }
    int gethp()
    {
        return hp;
    }
};

class Jäger : public Ship
{
public:
    Jäger(int s = 4, int h = 75, int d = 30) : Ship(s,h,d)
    { }
};

class Kreuzer : public Ship
{
public:
    Kreuzer(int s =6, int h=150, int d=50) : Ship(s,h,d)
    { }
};

class Zerstörer : public Ship
{
public:
    Zerstörer(int s=8, int h=250, int d=60) : Ship(s,h,d)
    { }
};

