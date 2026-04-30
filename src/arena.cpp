#include <iostream>
#include <iomanip>
#include "arena.h"
#include "arenarand.h"

void Arena::battle(Creature &temp1, Creature &temp2)
{
<<<<<<< HEAD
    std::cout << a.getName() << " vs. " << b.getName() << std::endl;
=======

    Creature* first;
    Creature* second;

    if (ArenaRand::flipCoin() == 1) {
        first = &temp1;
        second = &temp2;
    } else {
        first = &temp2;
        second = &temp1;
    }

    Creature& a = *first;
    Creature& b = *second;
>>>>>>> 46a0b0e228e9fa836e5b433dc5f7380cbffb9ba3

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
        std::cout << "\n-----------------------------\n";
	std::cout << "Turn " << turn << std::endl;
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
    std::cout << "=============================\n";
}
