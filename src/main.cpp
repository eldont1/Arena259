#include "arena.h"
#include "creature.h"
#include "./creatures/sumo_sally.h"
#include "./creatures/giantleech.h"

int main()
{
    Creature c1(make_sumo_sally());
    Creature c2(makeGiantleech());
    
    std::cout << "Total creatures created: " << Creature::getCreatureCount() << std::endl; // print out the number of creatures in the arena

    Arena::battle(c1, c2);

    return 0;
}
