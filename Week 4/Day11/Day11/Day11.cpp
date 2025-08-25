// Day11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Car.h"
#include <vector>
#include <fstream>
#include "Console.h"
#include "Input.h"

int main()
{
	std::cout << "Gone in 60 Seconds!\n";//https://carbuzz.com/features/beyond-eleanor-gone-in-60-seconds-car-names#:~:text=The%20Complete%20List%20Of%20Gone%20In%2060%20Seconds,8%201961%20Porsche%20Speedster%20-%20%22Natalie%22%20More%20items

	Car myCar(1961, "Porsche", "Speedster");
	std::string file = "mygarage.csv";
	std::ofstream outFile(file);
	if (outFile.is_open())
	{
		myCar.SerializeCSV(outFile, '!');
	}
	else
	{
		std::cout << "file could not be opened.\n";
	}
	outFile.close();

	std::string carData = "1967,Ford,Shelby Mustang GT500";
	Car fav(carData, ',');

	std::ifstream inFile(file);
	if (inFile.is_open())
	{
		std::string line;
		std::getline(inFile, line);
		Car newCar(line, '!');
	}
	else
	{
		std::cout << "file could not be opened.\n";
	}
	inFile.close();

	std::vector<Car> garage;
	garage.push_back(Car(1967, "Ford", "Shelby Mustang GT500"));
	garage.push_back(Car(1956, "Ford", "T Bird"));
	garage.push_back(Car(1961, "Porsche", "Speedster"));
	garage.push_back(Car(1965, "Pontiac", "GTO"));
	garage.push_back(Car(1969, "Plymouth", "Hemi Cuda"));


	//save the vector to a file
	file = "jaysGarage.csv";
	std::ofstream garageFile(file);
	if (garageFile.is_open())
	{
		for (int i = 0; i < garage.size(); i++)
		{
			garage[i].SerializeCSV(garageFile, '!');
			if (i != garage.size() - 1)
				garageFile << '\n';
		}
	}
	else
	{
		std::cout << "file could not be opened.\n";
	}
	garageFile.close();

	//load the cars from the file
	std::vector<Car> loadedCars;
	std::ifstream jaysInFile(file);
	if (jaysInFile.is_open())
	{
		std::string csvData;
		//read all of the cars from the file and store them in a vector
		while (not jaysInFile.eof())//loop while we are NOT at the end of the file
		{
			std::getline(jaysInFile, csvData);
			Car nextCar(csvData, '!');
			loadedCars.push_back(nextCar);
		}
	}
	else
	{
		std::cout << "file could not be opened.\n";
	}
	jaysInFile.close();

	std::cout << "\n\nJay's Garage:\n";
	for (auto& car : loadedCars)
	{
		std::cout << car.ModelYear() << " " << car.Make() << " " << car.Model() << "\n";
	}


	/*
		╔═════════════╗
		║ Serializing ║
		╚═════════════╝

		Saving the state (data) of objects

		Lecture Code: serialize the vector of Cars to a file.
			Data Format:
				separates cars. EX: car1|car2|car3
				separates data inside a car. EX: 1967;Ford;Shelby Mustang GT500

	*/



	/*
		╔═══════════════╗
		║ Deserializing ║
		╚═══════════════╝

		Recreating the objects from the saved state (data) of objects

		Lecture Code:
			Open the file
			Read in each line
			split each line to get each car
			split each car to get the car details

	*/
}