#pragma once
#include "Weapon.h"
class Pistol : public Weapon
{
public:
	//we must have a ctor that calls the base ctor
	Pistol(int ammo, int capacity, int range, int damage) :
		//call the base ctor in the member initialization list
		//the base ctor is called first
		Weapon(range,damage),//making a method call
		ammoCount_(ammo),
		ammoCapacity_(capacity)
	{
		//do NOT duplicate what the base ctor does
		numberOfPistols++;
	}
	//OVERRIDE the virtual method
	//  the declaration MUST match the base declaration
	void showMe() override;//override is optional
	int calcDamage() override;

	static void Report();

	//static fields are SHARED by all objects of the class
	static int numberOfPistols;
private:
	int ammoCount_;
	int ammoCapacity_;
};

