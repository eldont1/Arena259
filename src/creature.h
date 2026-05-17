#ifndef CREATURE_H
#define CREATURE_H

#include <string>
#include <iostream>


// added getters, setters, private static constants, and made variables protected
// the getters and setters are just generally better practice, and the private static
// constants are just so we can have an easily modifying range for valid health and valid damage.
// also, leaving implementation in .cpp file is better so we don't have to worry what order we implement functions in (we can call methods within methods without worrying about compiler errors)


class Creature
{
private:
	static int creatureCount; // will be increased in the constructor
	static const int MIN_HEALTH = 80; // ranges for valid health and damage
	static const int MAX_HEALTH = 120;
	static const int MIN_DAMAGE = 0;
	static const int MAX_DAMAGE = 20;

	std::string name;
	int startHealth; // maxmimum health stat
	int health;
	int startDamage; // maximum damage stat
	int damage;
	int damageDealt = 0;
	int defense;
	// the start variables don't get setters, since they don't ever change.
	// we can't make them const though because they are declare on construction.

public:
	// Constructor 
	Creature(std::string name, int health, int damage); 
	Creature(std::string name, int health, int damage, int defense);

	// Getters
	std::string getName() const; // returns the name variable
	int getHealth() const; // returns the health variable
	int getStartHealth() const;
	int getDamage() const; // returns the damage variable
	int getStartDamage() const;
	int getDamageDealt() const;
	bool isAlive() const; // checks if the health is >= 0
	static int getCreatureCount(); // get the total amount of creature instances
	
	// Setters
	void setName(const std::string&); // set name
	void setHealth(const int&); // set health
	void setDamage(const int&); // set damage
	void heal(const int&); // increase health
	void incDamage(const int&); // increase damage
	void incDamageDealt(const int&); // increase damage dealt stat

	// Damage other creatures
	virtual void attack(Creature& target); // decreases health of target 
	void takeDamage(int amount); // decrease this creature's health by amount - defense
	
	virtual void specialMove(Creature& other);

	// Validation checks
	static bool validate(Creature&); // returns true if health and damage are in valid
					 // ranges, false if otherwise (for balancing)
	static bool validateBattle(Creature&, Creature&); // checks two creatures and makes sure both of them have valid stats, 
							  // use before starting a battle between the two.
							  // returns false if either are invalid
							  // true if both are valid.
};

#endif
