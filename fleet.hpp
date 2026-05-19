#pragma once
#include <vector>
#include <string>
#include "ships.hpp"
#include <algorithm>
#include <memory>
#include <string>

class Fleet
{
private:
    std::vector<std::unique_ptr<Ship>> ships;
    int jäger = 0;
    int zerstörer = 0;
    int kreuzer = 0;
    std::string name;

public:
    Fleet(std::string nameFleet)
    {
        name = nameFleet;
    }

    void getInput()
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

    void setShips()
    {
        for (int i = 0; i < jäger; ++i)
        {
            ships.push_back(std::make_unique<Jäger>());
        }
        for (int i = 0; i < zerstörer; ++i)
        {
            ships.push_back(std::make_unique<Zerstörer>());
        }
        for (int i = 0; i < kreuzer; ++i)
        {
            ships.push_back(std::make_unique<Kreuzer>());
        }
    }
    std::vector<std::unique_ptr<Ship>> &getShips()
    {
        return ships;
    }

    int getSumJäger()
    {
        return jäger;
    }
    int getSumKreuzer()
    {
        return kreuzer;
    }
    int getSumZerstöerer()
    {
        return zerstörer;
    }
    void print()
    {
        std::cout << "Fleet " << name << " Jäger " << getSumJäger() << " Zerstörer " << getSumZerstöerer() << " Kreuzerer " << getSumKreuzer() << std::endl;
        if (getShips().size() == 0)
        {
            std::cout << "No more Ships" << std::endl;
            return;
        }
        for (int i = 0; i < getShips().size(); i++)
            std::cout << i + 1 << " " << getShips()[i]->getInfo() << " HP: " << getShips()[i]->gethp() << std::endl;

        std::cout << "\n"
                  << std::endl;
    }
    std::string getName()
    {
        return name;
    }

    void checkDelete()
    {
        for (int i = 0; i < ships.size(); i++)
        {
            if (ships[i]->gethp() <= 0)
            {
                ships.erase(ships.begin() + i);
            }
        }
    }
    bool checkEmpty()
    {
        if (ships.size() == 0)
        {
            return true;
        }
        return false;
    }
};
