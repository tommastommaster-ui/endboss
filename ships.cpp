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
int Ship::getX() const
{
    return x;
}
int Ship::getY() const
{
    return y;
}
std::string Ship::getInfo()
{
    return shipName;
}
int Ship::gethp() const
{
    return hp;
}
int Ship::getSize() const
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

void Ship::takeDamage(int dam, int attackerX, int attackerY, int targetX, int targetY) // hier noch y kordinate wichtig
{

    int dist = std::abs(attackerX - targetX) + std::abs(attackerY - targetY);

    if (dist < 11 && dist >= 7)
    {
        dam *= 0.5;
    }
    if (dist <= 6 && dist >= 4)
    {
        dam *= 0.75;
    }
    std::cout << "Position from: " << dist << " Damage: " << dam << std::endl;
    hp -= dam;
}

bool Ship::extraAttack()
{
    return false;
}
int Ship::getHitBonus(int size)
{
    return size;
}
// Jäger
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
// Kreuzer
bool Kreuzer::extraAttack()
{
    return true;
}
// Zerstörer
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