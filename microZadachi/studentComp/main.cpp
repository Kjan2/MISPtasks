#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>

struct Student
{
	std::string name;
	size_t age;
	float averageGrade;
};

int main()
{
	std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(1, 10);
	std::vector<Student> v;
	for (int i = 0; i < 10; i++)
	{
		float gradeInt = distr(gen);
		v.push_back(Student{"Adolf", 12, gradeInt});
	}

	std::sort(v.rbegin(), v.rend(),
	 [](Student a, Student b) { return a.averageGrade < b.averageGrade;});

	for (auto i : v)
	{
		std::cout << i.averageGrade << " ";
	}

	std::cout << "\n";

	std::sort(v.begin(), v.end(),
	 [](Student a, Student b) { return a.averageGrade < b.averageGrade;});

	for (auto i : v)
	{
		std::cout << i.averageGrade << " ";
	}
}
