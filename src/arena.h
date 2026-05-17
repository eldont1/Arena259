#ifndef ARENA_H
#define ARENA_H

#include "creature.h"

// added a battle statistics function, good for debugging and generally fun

class Arena
{
	private:
	
	public:
		static void battle(Creature &a, Creature &b);
		static void printStats(Creature& a, Creature& b, int turns); // pass in battling creatures, total turns
};

#endif
