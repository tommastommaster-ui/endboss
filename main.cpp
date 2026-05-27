#include "ships.hpp"
#include "fleet.hpp"
#include "map.hpp"
#include <string>
#include <vector>
#include <unistd.h>
#include <memory>
int main()
{
    srand(time(0));
    Map map(10, 9);
    Fleet a("A");
    Fleet b("B");

    a.getInput();
    b.getInput();

    a.setShips(false);
    b.setShips(true);

    a.print();
    b.print();
    map.print(a, b);

    int SizeA = a.getShips().size();
    int SizeB = b.getShips().size();
    bool game = true;
    bool switchFleet = false;
    int fleetAShip = 0;
    int fleetBShip = 0;

    while (game)
    {

        int randomNum = rand() % 10 + 1;

        if (fleetAShip >= a.getShips().size())
        {
            fleetAShip = 0;
        }
        if (fleetBShip >= b.getShips().size())
        {
            fleetBShip = 0;
        }

        // HIER ÜBERARBEITEN

        // schiff geht von 1 bis zum letzten jede runde eins weiter runter;
        auto &attacker = switchFleet ? b.getShips()[fleetBShip] : a.getShips()[fleetAShip];

        int targetShip = switchFleet ? b.searchForTarget(a) : a.searchForTarget(b);
        auto &target = switchFleet ? a.getShips()[targetShip] : b.getShips()[targetShip];

        map.move(*attacker, *target, a, b);

        // Attack
        std::cout << "ATTACKING -> Fleet " << (switchFleet ? "B" : "A") << " Ship: " << (switchFleet ? fleetBShip : fleetAShip) << " " << attacker->getInfo() << " Attacking Fleet " << (switchFleet ? "A" : "B") << " Ship: " << (switchFleet ? fleetAShip : fleetBShip) << " " << target->getInfo() << std::endl;
        std::cout << "Random Number: " << randomNum << std::endl;
        int targetSize = target->getSize();
        targetSize = attacker->getHitBonus(targetSize);
        if (randomNum >= targetSize)
        {
            int dmg = attacker->getDamage(randomNum); // plus jäger special;
            target->takeDamage(dmg, attacker->getX(), target->getX());
            std::cout << "Hit!!!" << std::endl;
            randomNum = map.rollDice();
            if (attacker->extraAttack())
            {
                int i = 1;
                int tmpDmg = dmg;
                while (true)
                {
                    randomNum = map.rollDice();
                    if (randomNum >= target->getSize())
                    {
                        target->takeDamage(dmg, attacker->getX(), target->getX());
                        tmpDmg += dmg;
                        std::cout << "Extra Attack Times:" << i << " RandomNum: " << randomNum << "Total Damage: " << tmpDmg << std::endl;
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

        map.print(a, b);

        if(a.checkEmpty())
        {
            break;
        }
        if(b.checkEmpty())
        {
            break;
        }

        if (switchFleet)
        {
            fleetBShip++;
        }
        else
        {
            fleetAShip++;
        }

        switchFleet = !switchFleet;

        std::cout << "###############################################################\n"
                  << std::endl;
        // std::cout << fleetAShip << "A" << RealTimeSizeA << std::endl;
        // std::cout << fleetBShip << "B" << RealTimeSizeB << std::endl;
        // sleep(1);
    }

    // Heute noch gemacht werden muss wernn schiff 0 hat muss er raus
    // die special attacks
    // genau anschauen wegen realtime size und so

    // schöner machen und lernen wirklich fett lerenen
    return 0;
}