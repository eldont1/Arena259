#include <iostream>
#include <iomanip>
#include "arena.h"

void Arena::battle(Creature &a, Creature &b)
{
    std::cout << a.getName() << " vs. " << b.getName() << std::endl;

    if(!Creature::validateBattle(a, b)){
        return;
    }

    std::cout << "=============================\n";
    std::cout << "        ARENA BATTLE        \n";
    std::cout << "=============================\n";

    std::cout << a.getName() << " vs " << b.getName() << std::endl;

    int turn = 1;

    while (a.isAlive() && b.isAlive())
    {
        std::cout << "-----------------------------\n";
	std::cout << "\nTurn " << turn << std::endl;
	std::cout << "-----------------------------\n";


	std::cout << std::left
                  << std::setw(10) << a.getName() << " HP: " << a.getHealth() << "\n"
                  << std::setw(10) << b.getName() << " HP: " << b.getHealth() << "\n";


        a.attack(b);
        std::cout << a.getName() << " dealt " << a.getPreviousDamage() << " damage to " << b.getName() << "!";
        if (a.getPreviousCrit()) std::cout << " CRITICAL HIT!";
        std::cout << std::endl;
        std::cout << b.getName() << " health is: " << b.getHealth() << " HP" << std::endl;


        b.attack(a);
        std::cout << b.getName() << " dealt " << b.getPreviousDamage() << " damage to " << a.getName() << "!";
        if (b.getPreviousCrit()) std::cout << " CRITICAL HIT!";
        std::cout << std::endl;
        std::cout << a.getName() << " health is: " << a.getHealth() << " HP" << std::endl;

        turn++;
    }

    std::cout << "\n=============================\n";
    if (a.isAlive())
    {
        std::cout << a.getName() << " defeats " << b.getName() << "!" << std::endl;
        std::cout << a.getName() << " has " << a.getHealth() << " HP remaining." << std::endl;
    }
    else
    {
        std::cout << b.getName() << " defeats " << a.getName() << "!"<< std::endl;
        std::cout << b.getName() << " has " << b.getHealth() << " HP remaining." << std::endl;
    }
    std::cout << "\n=============================\n";
}
