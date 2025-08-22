// Day08.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory>
#include "Inheritance.h"
#include "Polymorphism.h"
#include "Car.h"
#include "Pistol.h"
#include "Knife.h"
#include <vector>

//knife class:
//  length, serrated
//  getters/setters
//  constructor
//create a knife object in main

//override the showMe method for the Knife class

class Print
{
public:
	//overloading (compile-time polymorphic)
	void show(int i) { std::cout << "show1\n" << i; }
	void show(double d) { std::cout << "show1\n" << d; }
	void show(int i, int i2) { std::cout << "show1\n" << i << i2; }
	void show() { std::cout << "show2\n"; }
	//bool show() { std::cout << "show2\n"; }
};

void Counter()
{
	//static data lives for the lifetime of the app (while the app is running)
	static int i = 0;
	std::cout << i << " ";
	i++;
}

void Sample(int*& numPtr)
{
	numPtr = new int(25);
	std::cout << *numPtr << "\n\n";
	//(*numPtr)++;
}
int main()
{
	int** numPtrPtr;

	int n = 5;
	int* numPtr3;
	numPtrPtr = &numPtr3;
	Sample(numPtr3);
	std::cout << *numPtr3 << "\n\n";
	std::cout << n << "\n\n";
	n++;
	int* nPtr;//pointer to a memory location
	//pointers can be either 4-bytes or 8-bytes
	// if the app is 32-bit, 4-bytes
	// if the app is 64-bit, 8-bytes
	//
	// Memory locations:
	//   1) stack memory (local variables)
	//		stack variables are destroyed when they go out-of-scope
	//   2) heap memory (dynamic variables)
	//		heap variables are destroyed when you delete them
	//		heap variables are not scope bound
	//		YOU are responsible for cleaning up your junk
	//		if you do NOT, you will have a memory leak!

	//pointer to stack memory
	//& on the right-hand side, it is called "address-of"
	nPtr = &n;
	std::cout << nPtr << "\n\n";

	//pointer to heap memory (dynamic memory)
	//  '= new' that is creating heap memory
	{
		int* nPtr2 = new int(10);
		delete nPtr2;
	}//the int on the heap is still alive!


	//accessing the values that the pointer points to
	//  use * or -> to dereference the pointer
	std::cout << *nPtr << "\n\n";

	//cleaning up the heap
	//   use the delete keyword
	nPtr = new int(25);
	delete nPtr;//deletes the int at that memory location
	nPtr = nullptr;
	if(nPtr != nullptr)
		std::cout << *nPtr << "\n\n";

	for (int i = 0; i < 10; i++)
	{
		Counter();
	}
	Print p;
	p.show();
	p.show(5);
	p.show(5,2);
	p.show(5.3);
	int range = 10, damage = 20;
	//Weapon wpn(range, damage);
	int rounds = 5, mag = 15;
	Pistol johnWickSpecial(rounds, mag, range, damage);
	Pistol p2(1, 5, 5, 10);
	johnWickSpecial = p2;//we could overload the assignment operator
	Knife stabby(5, true, 3, 10);

	std::cout << "\n\n";
	//RUN-TIME check
	johnWickSpecial.showMe();//we need to show Pistol info too
	stabby.showMe();//we need to show Knife info too
	Pistol::Report();

	//stabby = johnWickSpecial;

	//Friday preview...
	//upcasting: 
	//	casting from a DERIVED type (Pistol) to a base type (Weapon)
	Weapon* wpnPtr = &johnWickSpecial;//UPCAST
	(*wpnPtr).showMe();
	wpnPtr->showMe();//which one to call???
	wpnPtr = &stabby;
	wpnPtr->showMe();//which one to call???

	//create the Pistol object on the heap
	Pistol* pPistol = new Pistol(rounds, mag, range, damage);
	delete pPistol;

	std::vector<Weapon*> backpack;
	backpack.push_back(&johnWickSpecial);
	backpack.push_back(&stabby);
	std::cout << "\nBACKPACK:\n";
	for (auto& wpnPtr : backpack)
	{
		wpnPtr->showMe();//run-time polymorphism
	}

	//use std::make_unique in a similar way
	{
		std::unique_ptr<Pistol> uPistol = std::make_unique<Pistol>(rounds, mag, range, damage);
		
		//to use another variable for the same object, you must move it
		std::unique_ptr<Pistol> uPistol2 = std::move(uPistol);//uPistol no longer owns the memory

		uPistol2->showMe();

	}//the unique_ptr automatically deletes the memory when it goes out of scope


	int nVal = 5;
	long lval = nVal;//implicit cast
	double dVal = 5.3;
	nVal = (int)dVal;//explicit cast

	/*
		╔═══════════════╗
		║  Inheritance  ║
		╚═══════════════╝

								╔═════════╗     ╔══════════╗
						 class  ║SomeClass║  :  ║OtherClass║
								╚═════════╝     ╚══════════╝
									 │                │
									 └──┐             └──┐
								   ┌────▼────┐      ┌────▼────┐
								   │ Derived │      │  Base   │
								   │  Class  │      │  Class  │
								   └─────────┘      └─────────┘

			Access modes:
				public inheritance:
				protected inheritance:
				private inheritance: (default if not specified)



				CONSTRUCTORS: the derived constructor must call a base constructor
				public SomeClass(.....) : baseClass(....)


			Lecture Code: add a FlyingCar class that derives from Car

	*/



	/*
		╔*************╗
		║  CHALLENGE  ║
		╚*************╝

			add a new class, Pistol, that derives from Weapon.
			Pistol should have fields with getters/setters for rounds and magCapacity.
			Add a constructor that calls the base constructor

	*/






	/*
		╔═════════════════════════════╗
		║  COMPILE-TIME Polymorphism  ║
		╚═════════════════════════════╝

		Method Overloading:
			- changing the number of parameters
			- changing the types of the parameters

		Lecture Code: Overload the refuel method in Car

	*/



	/*
		╔*************╗
		║  CHALLENGE  ║
		╚*************╝

			Add an OVERLOAD of the calcDamage method in the Weapon class.
			The overload should take an int parameter called modifier
			to increase the damage when calculating the damage.

	*/





	/*
		╔═════════════════════════════╗
		║  COMPILE-TIME Polymorphism  ║
		╚═════════════════════════════╝

		Operator Overloading

		Lecture Code: overload the + operator in Account

	*/



	/*
		╔*************╗
		║  CHALLENGE  ║
		╚*************╝

		overload the + in the Pistol class to add 2 pistols
			- it sets the magCapacity to the max of the 2 pistols
			- adds the # of rounds from both pistols. should not exceed the magCapacity.
	*/






	/*
		╔════════════════════════╗
		║  RUNTIME Polymorphism  ║
		╚════════════════════════╝

		╔═════════════╗
		║ OVERRIDING  ║ - changing the behavior of a base method
		╚═════════════╝

		1) add 'virtual' to the base method
		2) add a method to the derived class that has the same signature as the base.
			OPTIONALLY put 'override' on the derived method


		FULLY OVERRIDING:
			not calling the base method from the derived method

		EXTENDING:
			calling the base method from the derived method
			to call the base method...  baseClassName::method(...)



		Lecture Code: override the print method in the base/derived classes in the Polymorphism.h file

	*/
	derived der1("Gotham", 1);
	base base1 = der1; //calls the assignment operator of base therefore you lose all the derived parts. base1 is JUST a base object.
	der1.print();
	std::cout << "\n";
	base1.print();



	/*
		╔*************╗
		║  CHALLENGE  ║
		╚*************╝

			Override Weapon's showMe method in the Pistol class.
			In Pistol's version, call the base version then print out the rounds and magCapacity



	*/



}

