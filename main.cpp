#include "ships.hpp"
#include "fleet.hpp"
#include <string>
#include <vector>
#include <unistd.h>
int main()
{
    srand(time(0));
    Fleet a;
    Fleet b;

    int jäger = 0;
    int zerstörer = 0;
    int kreuzer = 0;

    do
    {
        std::cout << "Flotte 1: 1-9 Schiffe" << std::endl;
        std::cout << "How many jäger?" << std::endl;
        std::cin >> jäger;
        std::cout << "How many Zerstörer" << std::endl;
        std::cin >> zerstörer;
        std::cout << "How many Kreuzer" << std::endl;
        std::cin >> kreuzer;
    } while (jäger + zerstörer + kreuzer > 10 || jäger + zerstörer + kreuzer < 1);

    a.setShips(jäger, zerstörer, kreuzer, a);

    zerstörer = 0;
    kreuzer = 0;
    jäger = 0;
    do
    {
        std::cout << "Flotte 2: 1-9 Schiffe" << std::endl;
        std::cout << "How many jäger?" << std::endl;
        std::cin >> jäger;
        std::cout << "How many Zerstörer" << std::endl;
        std::cin >> zerstörer;
        std::cout << "How many Kreuzer" << std::endl;
        std::cin >> kreuzer;
    } while (jäger + zerstörer + kreuzer > 10 || jäger + zerstörer + kreuzer < 1);

    b.setShips(jäger, zerstörer, kreuzer, b);

    // print
    a.print(a);
    b.print(b);

    int SizeA = a.getShips().size();
    int SizeB = b.getShips().size();

    // std::cout << SizeA << std::endl;
    // std::cout << a.getShips()[0]->getInfo() << std::endl;

    int fleetAShip = 0;
    int fleetBShip = 0;
    bool switchFleet = false;

    while (true)
    {
        int RealTimeSizeA = a.getShips().size();
        int RealTimeSizeB = b.getShips().size();

        int randomNum = rand() % 10 + 1;

        std::cout << randomNum << std::endl;

        Ship *targetB = b.getShips()[fleetBShip];
        Ship *targetA = a.getShips()[fleetAShip];

        if (!switchFleet)
        {
            std::cout << "Random Number: " << randomNum << std::endl;
            std::cout << "Fleet A Ship: " << targetA->getInfo() << " Attacking " << targetB->getInfo() << std::endl;
            if (randomNum >= targetB->getSize())
            {
                targetB->takeDamage(targetB->getDamage());
                std::cout << "Hit!!!" << std::endl;
            }
            else
            {
                std::cout << "No Hit!" << std::endl;
            }
            if (fleetAShip == RealTimeSizeA -1)
            {
                fleetAShip = 0;
            }
            else
            {
                fleetAShip++;
            }

            switchFleet = true;
        }
        else
        {
            std::cout << "Random Number: " << randomNum << std::endl;
            std::cout << "Fleet B Ship: " << targetB->getInfo() << " Attacking " << targetA->getInfo() << std::endl;
            if (randomNum >= targetA->getSize())
            {
                targetA->takeDamage(targetA->getDamage());
                std::cout << "Hit!!!" << std::endl;
            }
            else
            {
                std::cout << "No Hit!" << std::endl;
            }

            if (fleetBShip == RealTimeSizeB -1)
            {
                fleetBShip=0;
            }
            else
            {
                fleetBShip++;
            }

            switchFleet = false;
        }
        a.print(a);
        b.print(b);
        sleep(2);
    }

    return 0;
}