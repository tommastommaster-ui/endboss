#include "ships.hpp"
#include "fleet.hpp"
#include <string>
#include <vector>
int main()
{
    Jäger();
    Kreuzer();
    Zerstörer();
    Fleet a;
    Fleet b;

    int jäger = 0;
    int zerstörer = 0;
    int kreuzer = 0;
    bool fleet2 = false;

    while (fleet2)
    {
    }

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

    for (int i = 0; i < jäger; i++)
    {
        a.addShip(new Jäger());
    }
    for (int i = 0; i < zerstörer; i++)
    {
        a.addShip(new Zerstörer());
    }
    for (int i = 0; i < kreuzer; i++)
    {
        a.addShip(new Kreuzer());
    }

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

    for (int i = 0; i < jäger; i++)
    {
        b.addShip(new Jäger());
    }
    for (int i = 0; i < zerstörer; i++)
    {
        b.addShip(new Zerstörer());
    }
    for (int i = 0; i < kreuzer; i++)
    {
        b.addShip(new Kreuzer());
    }

    for (int i = 0; i < a.getShips().size(); i++)
    {
        std::cout << a.getShips()[i]->gethp() << std::endl;
    }
    std::cout << std::endl;
    for (int i = 0; i < b.getShips().size(); i++)
    {
        std::cout << b.getShips()[i]->gethp() << std::endl;
    }
    return 0;
}