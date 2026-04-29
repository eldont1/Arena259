#ifndef CREATURE_H
#define CREATURE_H

#include <string>
#include <iostream>

#include "arenarand.h"

const int MIN_HEALTH = 80;
const int MAX_HEALTH = 120;


class Creature
{
private:
    std::string name;
    int health;
    int damage;
    int previous_damage = 0;
    bool previous_crit = false;
    inline static int creatureCount = 0;

public:

    // Constructor with initializer list
    Creature(std::string n, int h, int d)
        : name(n), health(h), damage(d) 
        {
            creatureCount += 1;
        }
    

    int getHealth() const
    {
        return health;
    }

    int getDamage() const
    {
        return damage;
    }

    int getPreviousDamage() const
    {
        return previous_damage;
    }

    bool getPreviousCrit() const
    {
        return previous_crit;
    }

    std::string getName() const
    {
        return name;
    }

    static int getCreatureCount()
    {
        return creatureCount;
    }

    // There's already the attack function, but this can be used for 
    // other sources of damage besides attacking
    void takeDamage(int d)
    {
        health -= d;
    }

    void attack(Creature &other)
    {
        // add a variation variable that is equal to 1/4 of the creature damage
        int variation = damage / 4;
        // make the new damage equal to creature damage plus the variation (positive or negative)
        int damage_varied = damage + ArenaRand::randomValue(-variation, variation);

        // CRIT LOGIC HERE
        // create a bool that reflects crit status -- if the number rolled between 1 and 10 is greater than nine, crit is a success (10% chance)
        // crits will deal double the already varied damage
        bool crit_roll = (ArenaRand::randomValue(1,10) > 9);
        if (crit_roll) {
            damage_varied *= 2;
        }
        // update the crit member variable for crit status checks in arena.cpp
        previous_crit = crit_roll;

        previous_damage = damage_varied;
        other.health -= damage_varied;
        if (other.health < 0)
        {
            other.health = 0;
        }
    }

    bool isAlive()
    {
        return health > 0;
    }

    static bool validate(Creature &c){
        if(c.health < MIN_HEALTH || c.health > MAX_HEALTH){
            std::cerr << "Error: " << c.name << " has invalid health. Health must be between " << MIN_HEALTH << " and " << MAX_HEALTH << std::endl;
            return false;
        }
        if(c.damage <= 0 || c.damage > 20){
            std::cerr << "Error: " << c.name << " has invalid damage. Damage must be > 0 or <= 20" << std::endl;
            return false;
        }
        return true;
        // minimum health to start a battle is 80, otherwise the battle would be predictable
        // 
    }

    /*
    If Creature a or b does not have the valid stats for health or damage
    It will output an error message and abort
    */
    static bool validateBattle(Creature &a, Creature &b){
        if(!validate(a) || !validate(b)){
            std::cerr << "The Battle cannot take place as there are invalid stats" << std::endl;
            return false;
        }
        return true;
    }
};

#endif