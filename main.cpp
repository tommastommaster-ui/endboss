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
    a.print();
    b.print();

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


        auto &targetB = b.getShips()[fleetBShip];
        auto &targetA = a.getShips()[fleetAShip];

        if (!switchFleet)
        {
            std::cout << "ATTACKING -> Fleet A Ship: " << fleetAShip + 1 << " " << targetA->getInfo() << " Attacking Fleet B Ship: " << fleetBShip + 1 << " " << targetB->getInfo() << std::endl;
            std::cout << "Random Number: " << randomNum << std::endl;
            int bSize = targetB->getSize();
            bSize = targetA->getHitBonus(bSize);
            if (randomNum >= bSize)
            {
                int dmg = targetA->getDamage(randomNum);
                targetB->takeDamage(dmg);
                std::cout << "Hit!!!" << std::endl;
                randomNum = rand() % 10 + 1;
                if (targetA->extraAttack())
                {
                    int i = 1;
                    while (bSize >= randomNum)
                    {
                        targetB->takeDamage(dmg);
                        randomNum = rand() % 10 + 1;
                        std::cout << "Extra Attack Times:" << i << std::endl;
                        i++;
                    }
                }
            }
            else
            {
                std::cout << "No Hit!!!" << std::endl;
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
            std::cout << "ATTACKING -> Fleet B Ship: " << fleetBShip + 1 << " " << targetB->getInfo() << " Attacking Fleet A Ship: " << fleetAShip + 1 << " " << targetA->getInfo() << std::endl;
            std::cout << "Random Number: " << randomNum << std::endl;
            int aSize = targetA->getSize();
            aSize = targetB->getHitBonus(aSize);
            if (randomNum >= aSize)
            {
                int dmg = targetB->getDamage(randomNum);
                targetA->takeDamage(dmg);
                std::cout << "Hit!!!" << std::endl;
                randomNum = rand() % 10 + 1;
                if (targetB->extraAttack())
                {
                    int i = 1;
                    while (aSize >= randomNum)
                    {
                        targetA->takeDamage(dmg);
                        randomNum = rand() % 10 + 1;
                        std::cout << "Extra Attack Times:" << i << std::endl;
                        i++;
                    }
                }
            }
            else
            {
                std::cout << "No Hit!!!" << std::endl;
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

        a.print();
        b.print();
        

        if (a.checkEmpty())
        {
            std::cout << "\nFleet B has won!!!"<< std::endl;
            game = false;
        }
        if (b.checkEmpty())
        {
            std::cout << "\nFleet A has won!!!"<< std::endl;
            game = false;
        }
        std::cout << "###############################################################\n" << std::endl;
        // std::cout << fleetAShip << "A" << RealTimeSizeA << std::endl;
        // std::cout << fleetBShip << "B" << RealTimeSizeB << std::endl;
        // sleep(1);
    }

    // Heute noch gemacht werden muss wernn schiff 0 hat muss er raus
    // die special attacks
    return 0;
}