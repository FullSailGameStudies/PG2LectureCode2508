#include "FullSailCourse.h"
#include <iostream>

void FullSailCourse::GetGrades(std::vector<float>& gradesToFill) const
{
	//add 20 random grades to the vector
	for (int i = 0; i < 20; i++)
	{
		gradesToFill.push_back(rand() % 10001 / 100.0f);
	}
}

void FullSailCourse::PrintGrades(const std::vector<float>& grades) const
{
	std::cout << "\n" << name << "\n";
	for (auto& grade : grades)
	{
		std::cout << grade << "\n";
	}
}

void FullSailCourse::EraseGrades(std::vector<float>& grades, float minGrade) const
{
	for (int i = grades.size() - 1; i >= 0; i--)
	{
		if (grades[i] < minGrade)
			grades.erase(grades.begin() + i);
	}
}

void FullSailCourse::SetName(const std::string& newName)
{
	name = newName;
}
