#include "arenarand.h"

// simulates a coin flip and returns the result as a bool
bool ArenaRand::flipCoin() { return COIN(gen); }

// pass in two ints to define a range of values and return
// a random value from within that range.
int ArenaRand::randomValue(int min, int max) { return std::uniform_int_distribution<>{min, max}(gen); }