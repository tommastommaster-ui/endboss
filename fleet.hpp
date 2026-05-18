#pragma once
#include <vector>
#include <string>
#include "ships.hpp"
#include <algorithm>

class Fleet
{
private:
    std::vector<Ship *> ships;
    int jäger = 0;
    int zerstörer = 0;
    int kreuzer = 0;

public:
    void addShip(Ship *ship)
    {
        ships.push_back(ship);
    }

    void removeShip (Ship *ship)
    {

    }
    void setShips(int xJäger, int xZerstörer, int xKreuzer, Fleet &f)
    {
        for (int i = 0; i < xJäger; ++i)
        {
            f.addShip(new Jäger());
            ++jäger;
        }
        for (int i = 0; i < xZerstörer; ++i)
        {
            f.addShip(new Zerstörer());
            ++zerstörer;
        }
        for (int i = 0; i < xKreuzer; ++i)
        {
            f.addShip(new Kreuzer());
            ++kreuzer;
        }
    }
    std::vector<Ship *> &getShips()
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
};
