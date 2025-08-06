#pragma once
#include <vector>
#include <string>
class FullSailCourse
{
public:
	void GetGrades(std::vector<float>& grades) const;//declaration

	const std::string& GetName() const
	{ 
		int n = 5;
		n++;
		//name = "Joker's class";
		//SetName("Joker's class");
		return name; 
	}
	void SetName(const std::string& newName)
	{
		name = newName;
	}
private:
	std::string name;
};

