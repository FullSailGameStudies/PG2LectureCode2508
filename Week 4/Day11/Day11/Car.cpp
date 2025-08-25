#include "Car.h"

std::string Car::vehicleInformation()
{
	return std::to_string(mModelYear) + " " + mMake + " " + mModel;
}

//serialize == save (writing data)
void Car::SerializeCSV(std::ofstream& outFile, char delimiter)
{
	outFile << mModelYear << delimiter << mMake << delimiter << mModel;
}

//deserialize == load (reading data)
void Car::DeserializeCSV(const std::string& csvData, char delimiter)
{
	//parse the year,make,model out of the csvData string
	std::string data;
	std::stringstream dataStream(csvData);
	std::getline(dataStream, data, delimiter);
	mModelYear = std::stoi(data);
	std::getline(dataStream, mMake, delimiter);
	std::getline(dataStream, mModel, delimiter);
}
