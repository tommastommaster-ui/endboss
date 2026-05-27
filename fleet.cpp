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
        jäger = checkInput();
        std::cout << "How many Zerstörer" << std::endl;
        zerstörer = checkInput();
        std::cout << "How many Kreuzer" << std::endl;
        kreuzer = checkInput();
        if (jäger + zerstörer + kreuzer > 9 || jäger + zerstörer + kreuzer < 1)
        {
            std::cout << "Fleet can't be bigger than 9 and samller than 1!" << std::endl;
        }
    } while (jäger + zerstörer + kreuzer > 9 || jäger + zerstörer + kreuzer < 1);
}

int Fleet::checkInput()
{
    while (true)
    {
        std::string str;
        std::cin >> str;
        if (str.size() >= 2)
        {
            std::cout << "Input is only 0-9" << std::endl;
            continue;
        }
        char wert = str[0] - '0';
        // std::cout << wert;
        if (wert > 9)
        {
            std::cout << "Only numbers";
            continue;
        }

        return wert;
    }

    // std::cout << tmp << std::endl;
}

void Fleet::setShips(bool oponent) //left or right
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
    for (int i = 0; i < ships.size();)
    {
        if (ships[i]->gethp() <= 0)
        {
            ships.erase(ships.begin() + i);
        }
        else {
            ++i;
        }
    }
}

bool Fleet::checkEmpty()
{
    if (ships.size() == 0)
    {
        std::cout << "\nFleet " << name << " has won!!!" << std::endl;
        return true;
    }
    return false;


}
int Fleet::searchForTarget(Fleet& enemy)
{
    auto& enemyShip = enemy.getShips();
    int hp = 1000;
    int best = 0;
    for(int i = 0; i < enemyShip.size(); ++i)
    {
        int tmp = enemyShip[i]->gethp();
        if(tmp < hp)
        {
            hp = tmp;
            best = i;
        }
    }
    return best;
}
