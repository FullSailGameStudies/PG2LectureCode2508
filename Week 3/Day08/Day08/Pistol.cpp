#include "Pistol.h"
#include <iostream>

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