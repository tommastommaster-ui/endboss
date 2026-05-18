#include "ships.hpp"
#include "fleet.hpp"
#include <string>
#include <vector>
#include <unistd.h>
#include <memory>
int main()
{
    srand(time(0));
    Fleet a;
    Fleet b;
    bool game = true;

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

    a.setShips(jäger, zerstörer, kreuzer);

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

    b.setShips(jäger, zerstörer, kreuzer);

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

    while (game)
    {
        int RealTimeSizeA = a.getShips().size();
        int RealTimeSizeB = b.getShips().size();

        if (RealTimeSizeA == fleetAShip)
        {
            fleetAShip = 0;
        }
        if (RealTimeSizeB == fleetBShip)
        {
            fleetBShip = 0;
        }

        int randomNum = rand() % 10 + 1;

        std::cout << randomNum << std::endl;

        auto &targetB = b.getShips()[fleetBShip];
        auto &targetA = a.getShips()[fleetAShip];

        if (!switchFleet)
        {
            std::cout << "Random Number: " << randomNum << std::endl;
            std::cout << "Fleet A Ship: " << targetA->getInfo() << " Attacking " << targetB->getInfo() << std::endl;
            if (randomNum >= targetB->getSize())
            {
                targetB->takeDamage(targetA->getDamage());
                std::cout << "Hit!!!" << std::endl;
            }
            else
            {
                std::cout << "No Hit!" << std::endl;
            }
            if (fleetAShip == RealTimeSizeA - 1)
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
                targetA->takeDamage(targetB->getDamage());
                std::cout << "Hit!!!" << std::endl;
            }
            else
            {
                std::cout << "No Hit!" << std::endl;
            }

            if (fleetBShip == RealTimeSizeB - 1)
            {
                fleetBShip = 0;
            }
            else
            {
                fleetBShip++;
            }

            switchFleet = false;
        }
        a.checkDelete();
        b.checkDelete();

        std::cout << "Fleet A: ";
        a.print(a);
        std::cout << "Fleet B: ";
        b.print(b);
        if (a.checkEmpty())
        {
            std::cout << "Fleet B has won!!!";
            game = false;
        }
        if (b.checkEmpty())
        {
            std::cout << "Fleet A has won!!!";
            game = false;
        }
        //std::cout << fleetAShip << "A" << RealTimeSizeA << std::endl;
        //std::cout << fleetBShip << "B" << RealTimeSizeB << std::endl;
        sleep(0.25);
    }

    // Heute noch gemacht werden muss wernn schiff 0 hat muss er raus
    // die special attacks
    return 0;
}