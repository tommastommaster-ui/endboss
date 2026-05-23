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
    int fleetAShip = 1;
    int fleetBShip = 1;

    int fleetTmpA = 0;

    while (game)
    {

        int randomNum = rand() % 10 + 1;
        //std::cout << "debug 1"<< fleetAShip << "A " << fleetBShip << "B" << std::endl;

        auto &attacker = switchFleet ? b.getShips()[fleetBShip] : a.getShips()[fleetAShip];
        auto &target = switchFleet ? a.getShips()[fleetAShip] : b.getShips()[fleetBShip];
        //std::cout << "debug 2"<< std::endl;

        std::cout << "ATTACKING -> Fleet " << (switchFleet ? "A" : "B") << " Ship: " << (switchFleet ? fleetAShip : fleetBShip) << " " << attacker->getInfo() << " Attacking Fleet " << (switchFleet ? "B" : "A") << " Ship: " << (switchFleet ? fleetBShip : fleetAShip ) << " " << target->getInfo() << std::endl;
        std::cout << "Random Number: " << randomNum << std::endl;
        int targetSize = target->getSize();
        targetSize = attacker->getHitBonus(targetSize);
        if (randomNum >= targetSize)
        {
            int dmg = attacker->getDamage(randomNum);
            target->takeDamage(dmg);
            std::cout << "Hit!!!" << std::endl;
            randomNum = rand() % 10 + 1;
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

        int RealTimeSizeA = a.getShips().size() -1;
        int RealTimeSizeB = b.getShips().size() -1;

        int &currentFleet = switchFleet ? fleetAShip : fleetBShip;

        if (currentFleet >= (switchFleet ? RealTimeSizeA -1 : RealTimeSizeB -1))
        {
            currentFleet = 0;
        }
        else
        {
            currentFleet++;
        }
        //std::cout << "debugbefore: " << RealTimeSizeA << std::endl;

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