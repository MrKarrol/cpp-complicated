#include <iostream>
#include <list>
#include <random>

#include "matrix.h"


void AddRealAverage(std::list<double>& list)
{
	double average = 0;
	for (const auto& item : list)
		average += item;
	list.push_back(average / list.size());
}


int main()
{
	// task 1
	{
		std::cout << "******* TASK 1 *******" << std::endl;
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_real_distribution<double> urd(0, 100);
		const auto size = static_cast<int>(urd(gen));
		std::list<double> list;
		for (int i = 0; i < size; ++i)
			list.push_back(urd(gen));
		// before
		std::cout << "before" << std::endl;
		for (const auto& item : list)
			std::cout << item << " ";
		std::cout << std::endl;

		AddRealAverage(list);

		// after
		std::cout << "after" << std::endl;
		for (const auto& item : list)
			std::cout << item << " ";
		std::cout << std::endl;
	}
	// task 2
	{
		std::cout << "******* TASK 2 *******" << std::endl;

		try
		{
			{
				Matrix matrix(2, { 3, -5, 2, 6 });
				std::cout << "Determinant of " << matrix << "is " << matrix.GetDeterminant() << std::endl;
			}
			{
				Matrix matrix(3, { 1, 2, 3, 4, 5, 6, 7, 8, 9 });
				std::cout << "Determinant of " << matrix << "is " << matrix.GetDeterminant() << std::endl;
			}
			{
				Matrix matrix(4, { 3, 5, -2, -25, 32, 15, 81, 3, 2, 23, 3, 4, 92, -9, -3, -1 });
				std::cout << "Determinant of " << matrix << "is " << matrix.GetDeterminant() << std::endl;
			}
			{
				Matrix matrix(5, { -1, 2, -3, 4, -5, 6, -7, 8, -9, 10, -11, 12, -13, 14, -15, 16, -17, 18, -19, 20, -21, 22, -23, 24, -25 });
				std::cout << "Determinant of " << matrix << "is " << matrix.GetDeterminant() << std::endl;
			}
		}
		catch (std::exception& e)
		{
			std::cerr << "ERROR!! " << e.what() << std::endl;
		}
	}
	return 0;
}
