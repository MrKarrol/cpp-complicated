#include <iostream>
#include <list>
#include <random>
#include <numeric>
#include <algorithm>

#include "matrix.h"
#include "iterator.h"


void AddRealAverage(std::list<double>& list)
{
	double average = std::accumulate(std::begin(list), std::end(list), 0.f) /  list.size();
	list.push_back(average);
}

std::ostream& operator << (std::ostream& out, const std::list<double>& list)
{
	for (const auto& item : list)
		out << item << " ";
	return out;
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
		std::list<double> list(size);
		std::generate(std::begin(list), std::end(list), [&urd, &gen]() {return urd(gen); });

		std::cout << "before" << std::endl << list << std::endl;
		AddRealAverage(list);
		std::cout << "after" << std::endl << list << std::endl;
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
	// task 3
	{
		std::cout << "******* TASK 2 *******" << std::endl;

		Container container{ 3, 5, -2, -3, -18, -32, 5, 666, 3 };
		for (const auto& item : container)
			std::cout << item << " ";
		std::cout << std::endl;
	}
	return 0;
}
