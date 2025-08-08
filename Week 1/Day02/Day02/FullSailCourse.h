#pragma once
#include <vector>
#include <string>
class FullSailCourse
{
public:
	void GetGrades(std::vector<float>& grades) const;//declaration
	void PrintGrades(const std::vector<float>& grades) const;
	void EraseGrades(std::vector<float>& grades, float minGrade = 59.5f) const;

	const std::string& GetName() const
	{ 
		int n = 5;
		n++;
		//name = "Joker's class";
		//SetName("Joker's class");
		return name; 
	}
	void SetName(const std::string& newName = "Pg2");
private:
	std::string name;
};

