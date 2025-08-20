#pragma once
#include "Weapon.h"
class Knife : public Weapon
{
public:
	Knife(int length, bool serrated, int range, int damage):
		Weapon(range, damage),//making a method call
		length_(length), serrated_(serrated)
	{
	}
	int Length() const { return length_; }
	void Length(int length)
	{
		if (length > 0 && length <= 12)
			length_ = length;
	}
	bool Serrated() const { return serrated_; }
	void Serrated(bool serrated)
	{
		serrated_ = serrated;
	}

private:
	int length_;
	bool serrated_;
};

