#include "Card.h"
#include <iostream>

void Card::Print() const
{
	std::cout << face_ << " " << suit_;
}

int Card::Value() const
{
	int value = (int)face_;
	return value;
}
