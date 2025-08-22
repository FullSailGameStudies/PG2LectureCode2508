#include "Pistol.h"
#include <iostream>

int Pistol::numberOfPistols = 0;
//non-static methods have a 'hidden' parameter called 'this'
//'this' is a POINTER to the object the method was called on
//non-static methods can access BOTH static and non-static
void Pistol::showMe()
{
	//2 kinds of override:
	//  FULL override: ONLY want the new behavior
	//  EXTENSION override: base behavior PLUS new behavior. call the base method.

	std::cout << "Ammo: " << ammoCount_ << "\t:Capacity: " << ammoCapacity_ << "\n";

	//do NOT duplicate what the base does
	// :: scope resolution operator
	Weapon::showMe();
	std::cout << "\n";
}

int Pistol::calcDamage()
{
	return Weapon::calcDamage();
}

//static methods do NOT have a 'this' pointer
//static methods CANNOT access non-static members
//static methods can ONLY access other static members
void Pistol::Report()
{
	//showMe();
	//std::cout << ammoCount_;
	std::cout << "Number of pistols: " << numberOfPistols << "\n";
}
