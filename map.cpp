#include "map.hpp"
#include <iostream>

Map::Map(int w, int h)
{
    width = w;
    height = h;
}

void Map::print(Fleet &a, Fleet &b)
{
    std::vector<std::vector<char>> grid(height,
                                        std::vector<char>(width, '.'));

    // Fleet A
    for (auto &ship : a.getShips())
    {
        grid[ship->getY()][ship->getX()] = ship->getInfo()[0]; // Use first letter of ship name
    }
    // Fleet B
    for (auto &ship : b.getShips())
    {
        grid[ship->getY()][ship->getX()] = std::tolower(ship->getInfo()[0]);
        std::cout << "X : " << ship->getX() << " Y : " << ship->getY() << std::endl; // Use first letter of ship name
    }

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            std::cout << grid[y][x] << " ";
        }

        std::cout << "\n";
    }
}



void Map::move(Ship &attacker, Ship &enemy, Fleet &a, Fleet &b)
{
    int dx = enemy.getX() - attacker.getX();
    int dy = enemy.getY() - attacker.getY();

    std::cout << "[MOVE] attacker(" << attacker.getX() << "," << attacker.getY() 
              << ") -> enemy(" << enemy.getX() << "," << enemy.getY() << ")\n";

    // Achse mit größerer Distanz priorisieren
    if (std::abs(dx) >= std::abs(dy) && std::abs(dx) > 1)
    {
        int direction = (dx > 0) ? 1 : -1;
        int newX = attacker.getX() + direction;
        if (newX >= 0 && newX < width && !occupied(newX, attacker.getY(), a, b))
        {
            attacker.move(direction, 0);
            std::cout << "[MOVE] -> X to " << attacker.getX() << "\n";
        }
        else
        {
            std::cout << "[MOVE] -> X blocked\n";
        }
    }
    else if (std::abs(dy) > 1)
    {
        int direction = (dy > 0) ? 1 : -1;
        int newY = attacker.getY() + direction;
        if (newY >= 0 && newY < height && !occupied(attacker.getX(), newY, a, b))
        {
            attacker.move(0, direction);
            std::cout << "[MOVE] -> Y to " << attacker.getY() << "\n";
        }
        else
        {
            std::cout << "[MOVE] -> Y blocked\n";
        }
    }
    else
    {
        std::cout << "[MOVE] -> no move (close enough)\n";
    }
}

bool Map::occupied(int x, int y, Fleet &a, Fleet &b)
{
    for (auto &s : a.getShips())
        if (s->getX() == x && s->getY() == y)
        {
            return true;
        }
    for (auto &s : b.getShips())
        if (s->getX() == x && s->getY() == y)
        {
            return true;
        }
    return false;
}