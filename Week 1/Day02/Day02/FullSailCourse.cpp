#include "FullSailCourse.h"

void FullSailCourse::GetGrades(std::vector<float>& gradesToFill) const
{
	//add 20 random grades to the vector
	for (int i = 0; i < 20; i++)
	{
		gradesToFill.push_back(rand() % 10001 / 100.0f);
	}
}
