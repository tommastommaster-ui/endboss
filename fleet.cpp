#include "fleet.hpp"
#include <vector>
#include <memory>
#include <string>

Fleet::Fleet(std::string nameFleet)
{
    name = nameFleet;
}

void Fleet::getInput()
{
    do
    {
        std::cout << "Flotte " << name << ": 1-9 Schiffe" << std::endl;
        std::cout << "How many Jäger?" << std::endl;
        std::cin >> jäger;
        std::cout << "How many Zerstörer" << std::endl;
        std::cin >> zerstörer;
        std::cout << "How many Kreuzer" << std::endl;
        std::cin >> kreuzer;
    } while (jäger + zerstörer + kreuzer > 10 || jäger + zerstörer + kreuzer < 1);
}

void Fleet::setShips(bool oponent)
{
    int posX = oponent ? 9 : 0;
    
    for (int i = 0; i < jäger; ++i)
    {
        ships.push_back(std::make_unique<Jäger>(posX, i));
    }
    for (int i = 0; i < zerstörer; ++i)
    {
        int tmp = getSumJäger();
        ships.push_back(std::make_unique<Zerstörer>(posX, tmp + i));
    }
    for (int i = 0; i < kreuzer; ++i)
    {
        int tmp = getSumJäger() + getSumZerstöerer();
        ships.push_back(std::make_unique<Kreuzer>(posX, tmp + i));
    }
}

std::vector<std::unique_ptr<Ship>> &Fleet::getShips()
{
    return ships;
}
int Fleet::getSumJäger()
{
    return jäger;
}
int Fleet::getSumKreuzer()
{
    return kreuzer;
}
int Fleet::getSumZerstöerer()
{
    return zerstörer;
}

void Fleet::print()
{
    std::cout << "Fleet " << name << " Jäger " << getSumJäger() << " Zerstörer " << getSumZerstöerer() << " Kreuzerer " << getSumKreuzer() << std::endl;
    if (getShips().size() == 0)
    {
        std::cout << "No more Ships" << std::endl;
        return;
    }
    for (int i = 0; i < getShips().size(); i++)
        std::cout << i << " " << getShips()[i]->getInfo() << " HP: " << getShips()[i]->gethp() << " Position X: " << getShips()[i]->getX() << "Y: " << getShips()[i]->getY() << std::endl;

    std::cout << "\n"
              << std::endl;
}

std::string Fleet::getName()
{
    return name;
}
void Fleet::checkDelete()
{
    for (int i = 0; i < ships.size(); i++)
    {
        if (ships[i]->gethp() <= 0)
        {
            ships.erase(ships.begin() + i);
        }
    }
}

bool Fleet::checkEmpty()
{
    if (ships.size() == 0)
    {
        return true;
    }
    return false;
}
