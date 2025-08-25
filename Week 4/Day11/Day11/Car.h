#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

//car class will be responsible for saving and loading itself
//it will NOT be responsible for opening/closing files
class Car
{
private:
	int mModelYear;
	std::string mModel;
	std::string mMake;

public:

	std::string vehicleInformation();

	Car() :mModelYear(0), mMake(""), mModel("") {}
	Car(int modelYear, std::string make, std::string model) :
		mModelYear(modelYear), mMake(make), mModel(model)
	{
	}
	Car(const std::string& csvData, char delimiter)
	{
		DeserializeCSV(csvData, delimiter);
	}
	void SerializeCSV(std::ofstream& outFile, char delimiter);
	void DeserializeCSV(const std::string& csvData, char delimiter);

	int ModelYear() const  //const says the method can't modify anything
	{ 
		return mModelYear;  //provides access to the field's value
	}

	void ModelYear(int modelYear)
	{
		mModelYear = modelYear;
	}

	const std::string& Make() const
	{
		return mMake;
	}
	void Make(std::string make)
	{
		mMake = make;
	}

	const std::string& Model() const
	{
		return mModel;
	}
	void Model(std::string model)
	{
		mModel = model;
	}
};

