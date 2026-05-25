#pragma once
#include "fleet.hpp"

class Map
{
    private:
        int width;
        int height;
    public:
        Map(int w , int h);
        void print(Fleet &a, Fleet &b);
};