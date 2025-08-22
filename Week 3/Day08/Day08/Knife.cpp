#include "Knife.h"
#include <iostream>

void Knife::showMe()
{
	std::cout << "Length: " << length_ << "\tSerrated: " << serrated_ << "\n";
	Weapon::showMe();
	std::cout << "\n";
}

int Knife::calcDamage()
{
	return Weapon::calcDamage();
}