#pragma once
#include <vector>
#include <string>
#include "ships.hpp"

class Fleet
{
private:
    std::vector<Ship*> ships;

public:
    void addShip(Ship* ship)
    {
        ships.push_back(ship);
    }

    std::vector<Ship*>& getShips()
    {
        return ships;
    }

};

