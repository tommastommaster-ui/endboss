#include "ships.hpp"
#include "fleet.hpp"
#include <string>
#include <vector>
#include <unistd.h>
#include <memory>
int main()
{
    srand(time(0));
    Fleet a("A");
    Fleet b("B");
    bool game = true;

    a.getInput();
    b.getInput();

    a.setShips();
    b.setShips();

    // print
    a.print();
    b.print();

    int SizeA = a.getShips().size();
    int SizeB = b.getShips().size();

    // std::cout << SizeA << std::endl;
    // std::cout << a.getShips()[0]->getInfo() << std::endl;
    bool switchFleet = false;
    int fleetAShip = 0;
    int fleetBShip = 0;

    int fleetTmpA = 0;

    while (game)
    {

        int randomNum = rand() % 10 + 1;

        auto &attacker = switchFleet ? a.getShips()[fleetAShip] : b.getShips()[fleetBShip];
        auto &target = switchFleet ? b.getShips()[fleetBShip] : a.getShips()[fleetAShip];

        std::cout << "ATTACKING -> Fleet " << (switchFleet ? "A" : "B") << " Ship: " << (switchFleet ? fleetAShip + 1 : fleetBShip + 1) << " " << attacker->getInfo() << " Attacking Fleet " << (switchFleet ? "B" : "A") << " Ship: " << (switchFleet ? fleetBShip + 1 : fleetAShip + 1) << " " << target->getInfo() << std::endl;
        std::cout << "Random Number: " << randomNum << std::endl;
        int targetSize = target->getSize();
        targetSize = attacker->getHitBonus(targetSize);
        if (randomNum >= targetSize)
        {
            int dmg = attacker->getDamage(randomNum);
            attacker->takeDamage(dmg);
            std::cout << "Hit!!!" << std::endl;
            if (attacker->extraAttack())
            {
                int i = 1;
                while (true)
                {
                    randomNum = rand() % 10 + 1;
                    if (randomNum >= target->getSize())
                    {
                        target->takeDamage(dmg);
                        std::cout << "Extra Attack Times:" << i << " RandomNum: " << randomNum << std::endl;
                        i++;
                    }
                    else
                    {
                        std::cout << "Extra Attack Failed :(" << std::endl;
                        break;
                    }
                }
            }
        }
        else
        {
            std::cout << "Miss!!!" << std::endl;
        }

        a.checkDelete();
        b.checkDelete();

        a.print();
        b.print();

        int RealTimeSizeA = a.getShips().size();
        int RealTimeSizeB = b.getShips().size();

        int &currentFleet = switchFleet ? fleetAShip : fleetBShip;

        if (currentFleet <= (switchFleet ? RealTimeSizeA - 1 : RealTimeSizeB - 1))
        {
            currentFleet = 0;
        }
        else
        {
            currentFleet++;
        }

        switchFleet = !switchFleet;

        if (a.checkEmpty())
        {
            std::cout << "\nFleet B has won!!!" << std::endl;
            game = false;
        }
        if (b.checkEmpty())
        {
            std::cout << "\nFleet A has won!!!" << std::endl;
            game = false;
        }
        std::cout << "###############################################################\n"
                  << std::endl;
        // std::cout << fleetAShip << "A" << RealTimeSizeA << std::endl;
        // std::cout << fleetBShip << "B" << RealTimeSizeB << std::endl;
        // sleep(1);
    }

    // Heute noch gemacht werden muss wernn schiff 0 hat muss er raus
    // die special attacks
    return 0;
}