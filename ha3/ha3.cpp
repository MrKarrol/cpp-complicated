#include <iostream>
#include <list>
#include <random>


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
	return 0;
}
