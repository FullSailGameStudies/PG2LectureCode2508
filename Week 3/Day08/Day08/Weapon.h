#pragma once
//abstract base class
class Weapon
{
public:
	Weapon(int range, int damage);
	//to OVERRIDE
	//1) mark the BASE method as 'virtual'
	//	tells the compiler that it MIGHT be overridden in the derived
	//  causes a tiny performance hit.
	//  at runtime, the C++ runtime will check a v-table to see
	//  if the method was overridden
	virtual void showMe();
	virtual int calcDamage() = 0;//make the method a pure virtual method
	int calcDamage(int modifier);

	int range() const
	{
		return mRange;
	}
	int damage() const
	{
		return mDamage;
	}
private:
	int mRange;
	int mDamage;
};

