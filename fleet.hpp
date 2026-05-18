#pragma once
#include <vector>
#include <string>
#include "ships.hpp"
#include <algorithm>
#include<memory>

class Fleet
{
private:
    std::vector<std::unique_ptr<Ship>> ships;
    int jäger = 0;
    int zerstörer = 0;
    int kreuzer = 0;

public:


    void setShips(int xJäger, int xZerstörer, int xKreuzer)
    {
        for (int i = 0; i < xJäger; ++i)
        {
            ships.push_back(std::make_unique<Jäger>());
            ++jäger;
        }
        for (int i = 0; i < xZerstörer; ++i)
        {
            ships.push_back(std::make_unique<Zerstörer>());
            ++zerstörer;
        }
        for (int i = 0; i < xKreuzer; ++i)
        {
            ships.push_back(std::make_unique<Kreuzer>());
            ++kreuzer;
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
    void print(Fleet &f)
    {
        std::cout << "Fleet A: " << "Jäger " << f.getSumJäger() << " Zerstörer " << f.getSumZerstöerer() << " Kreuzerer " << f.getSumKreuzer() << std::endl;
        for (int i = 0; i < f.getShips().size(); i++)
            std::cout << f.getShips()[i]->getInfo() << " " << f.getShips()[i]->gethp() << std::endl;

        std::cout << std::endl;
    }

    void checkDelete () 
    {
        for(int i = 0; i < ships.size(); i++)
        {
            if(ships[i]->gethp() <= 0)
            {
                ships.erase(ships.begin() + i);
            }
        }
    }
    bool checkEmpty()
    {
        if(ships.size() == 0)
        {
            return true;
        }
        return false;
    }
};
