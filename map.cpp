#include "map.hpp"
#include <iostream>

Map::Map(int w, int h)
{
    width = w;
    height = h;
}

void Map::print(Fleet& a, Fleet& b)
{
    std::vector<std::vector<char>> grid(height,
        std::vector<char>(width, '.'));

    // Fleet A
    for(auto& ship : a.getShips())
    {
        grid[ship->getY()][ship->getX()] = ship->getInfo()[0]; // Use first letter of ship name
    }
    // Fleet B
    for(auto& ship : b.getShips())
    {
        grid[ship->getY()][ship->getX()] = std::tolower(ship->getInfo()[0]);
        std::cout << "X : " << ship->getX() << " Y : " << ship->getY() << std::endl; // Use first letter of ship name
    }

    for(int y = 0; y < height; y++)
    {
        for(int x = 0; x < width; x++)
        {
            std::cout << grid[y][x] << " ";
        }

        std::cout << "\n";
    }
}