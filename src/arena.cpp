#include <iostream>
#include <iomanip>
#include "arena.h"
#include "rng.h"

void Arena::battle(Creature &temp1, Creature &temp2)
{

    Creature* first;
    Creature* second;

    if (RNG::flipCoin() == 1) {
        first = &temp1;
        second = &temp2;
    } else {
        first = &temp2;
        second = &temp1;
    }

    Creature& a = *first;
    Creature& b = *second;

    if(!Creature::validateBattle(a, b)){
        return;
    }
    
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


        std::cout << a.getName() << " attacks!" << std::endl;
        a.attack(b);
        std::cout << b.getName() << " health: " << b.getHealth() << std::endl;


        std::cout << b.getName() << " attacks!" << std::endl;
        b.attack(a);
        std::cout << a.getName() << " health: " << a.getHealth() << std::endl;

        turn++;
    }

    // Ezra's custom battle statistics code    
    // print out battle stats
    std::cout << std::endl;
    printStats(a, b, turn);
}

void Arena::printStats(Creature& a, Creature& b, int turns) {

    // print winner
    std::cout << "Battle finished, the winner is ";
    if (a.isAlive())
    {
        std::cout << a.getName() << "!" << std::endl;
    }
    else
    {
        std::cout << b.getName() << "!" << std::endl;
    }

    // arena stats
    std::cout << "Total turns: " << turns << std::endl;
    std::cout << "Total Damage Dealt: " << a.getDamageDealt() + b.getDamageDealt() << std::endl;
    std::cout << std::endl;

    // a creature stats
    std::cout << a.getName() << " Health: " << a.getHealth() << "/" << a.getStartHealth() << std::endl;
    std::cout << a.getName() << " Damage Dealt: " << a.getDamageDealt() << std::endl;
    std::cout << std::endl;

    // b creature stats
    std::cout << b.getName() << " Health: " << b.getHealth() << "/" << b.getStartHealth() << std::endl;
    std::cout << b.getName() << " Damage Dealt: " << b.getDamageDealt() << std::endl;

}
