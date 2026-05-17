// c++ libraries
#include <string>
#include <iostream>

// header files
#include "creature.h"
#include "utils.h"

int Creature::creatureCount = 0;
const int Creature::MIN_HEALTH;
const int Creature::MAX_HEALTH;
const int Creature::MIN_DAMAGE;
const int Creature::MAX_DAMAGE; 


// Constructor
Creature::Creature(std::string name, int health, int damage) 
	: name(name)
	, health(health)
	, startHealth(health)
	, damage(damage)
	, startDamage(damage)
	, defense(0)
	{ creatureCount++; }

Creature::Creature(std::string name, int health, int damage, int defense) 
	: name(name)
	, health(health)
	, startHealth(health)
	, damage(damage)
	, startDamage(damage)
	, defense(defense)
	{ creatureCount++; }


// Getters
std::string Creature::getName() const {
	return name; // return name
}

int Creature::getHealth() const {
	return health; // return health
}

int Creature::getStartHealth() const {
	return startHealth;
}

int Creature::getDamage() const {
	return damage; // return damage
}

int Creature::getStartDamage() const {
	return startDamage;
}

int Creature::getDamageDealt() const {
	return damageDealt;
}

bool Creature::isAlive() const {
	return health > 0; // return true if health > 0
}

int Creature::getCreatureCount() {
	return creatureCount;
}


// Setters
void Creature::setName(const std::string& newName) {
	name = newName; // update name, no checks needed
}

void Creature::setHealth(const int& newHealth) {
	health = newHealth; // update health
	if (getHealth() < 0) { // ensure that health stays non-negative
		health = 0;
	}
	else if (getHealth() > getStartHealth()) {
		setHealth(startHealth);
	}
}

void Creature::setDamage(const int& newDamage) {
	damage = newDamage; // update damage
	if (getDamage() < 0) { // don't allow damage to be negative
		damage = 0;
	}
}

// Incrementers
void Creature::heal(const int& increase) {
	setHealth(getHealth() + increase); // set the health + increase
}

void Creature::incDamage(const int& increase) {
	setDamage(getDamage() + increase); // just set the damage + increase
}

void Creature::incDamageDealt(const int& increase) {
	damageDealt += increase;
}

void Creature::takeDamage(int amount) {
	int reduced = amount - defense;
	if (reduced < 0) reduced = 0;

	health = std::max(0, health - reduced);
}

// Methods interacting with other creatures
void Creature::attack(Creature& target) {
	target.takeDamage(damage);
	incDamageDealt(damage);
}

void Creature::specialMove(Creature& other){
	std::cout << name << " has no special move." << std::endl;
}


// Validation
bool Creature::validate(Creature& creatureCheck) {
	if (creatureCheck.getHealth() < MIN_HEALTH || creatureCheck.getHealth() > MAX_HEALTH) { // check health is in a valid range
		
		std::cerr << "Error: " << creatureCheck.getName() << " has invalid health (" << creatureCheck.getHealth() 
		<< " HP). Health must be between " << MIN_HEALTH << " and " << MAX_HEALTH << std::endl; // print out an error 
		return false; // failed to validate
	}
	if (creatureCheck.getDamage() < MIN_DAMAGE || creatureCheck.getDamage() > MAX_DAMAGE) {
		std::cerr << "Error: " << creatureCheck.getName() << " has invalid damage (" << creatureCheck.getDamage() 
		<<  " DMG). Damage must be between " << MIN_DAMAGE << " and " << MAX_DAMAGE << std::endl;
		return false; // failed to validate
	}
	return true; // validation passed
}

// attempts to validate two creatures, returns true if they have valid stats, false otherwise
bool Creature::validateBattle(Creature& aCreature, Creature& bCreature) {
	if (validate(aCreature) && validate(bCreature)) { // if both creatures are valid, return true
		return true;
	}	
	else { // if one of them aren't
		std::cerr << "The stats of the creatures are invalid, so the battle cannot take place." << std::endl; // print an error
		return false; // return false
	}
}
