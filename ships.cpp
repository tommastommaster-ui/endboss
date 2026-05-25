#include "ships.hpp"

Ship::Ship(int s, int h, int d, std::string name, int posX, int posY)
{
    size = s;
    hp = h;
    damage = d;
    shipName = name;
    x = posX;
    y = posY;
}
int Ship::getX()
{
    return x;
}
int Ship::getY()
{
    return y;
}
std::string Ship::getInfo()
{
    return shipName;
}
int Ship::gethp()
{
    return hp;
}
int Ship::getSize()
{
    return size;
}
void Ship::move(int moveX, int moveY)
{
    x += moveX;
    y += moveY;
}

int Ship::getDamage(int randomNum)
{
    return damage;
}

int Ship::takeDamage(int dam)
{
    return hp -= dam;
}

bool Ship::extraAttack()
{
    return false;
}
int Ship::getHitBonus(int size)
{
    return size;
}
//Jäger
int Jäger::getDamage(int randomNum)
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
//Kreuzer
bool Kreuzer::extraAttack()
{
    return true;
}
//Zerstörer
int Zerstörer::getHitBonus(int size)
{
    int randomNum = rand() % 3 + 1;
    if (randomNum == 1)
    {
        int newSize = size - 2;
        std::cout << "Size reduction " << size << " : " << newSize << std::endl;
        return size - 2;
    }
    else
    {
        return size;
    }
}