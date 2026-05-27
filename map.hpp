#pragma once
#include "fleet.hpp"
#include "ships.hpp"

class Map
{
    private:
        int width;
        int height;
        int roll;
    public:
        Map(int w , int h);
        int rollDice();
        void print(Fleet &a, Fleet &b);
        void move(Ship& attacker, Ship& enemy, Fleet &a, Fleet &b);
        void moveold(Ship& attacker, Ship& enemy, Fleet &a, Fleet &b);
        bool occupied(int x, int y, Fleet& a, Fleet& b);
};