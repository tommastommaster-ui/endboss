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
    Fleet(std::string nameFleet);

    std::vector<std::unique_ptr<Ship>> &getShips();
    std::string getName();
    int getSumJäger();
    int getSumKreuzer();
    int getSumZerstöerer();
    int searchForTarget(Fleet& enemy);
    void getInput();
    int checkInput();
    void checkDelete();
    void setShips(bool oponent);
    void print();
    bool checkEmpty();
};
