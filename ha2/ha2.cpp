#include <iostream>
#include <random>

#include "templates.h"
#include "count.h"


namespace task2
{
	struct Temp
	{
		int a = 0;
	};
	bool operator < (const Temp& lhv, const Temp& rhv)
	{
		return lhv.a < rhv.a;
	}
	std::ostream& operator << (std::ostream& out, const Temp& item)
	{
		out << item.a;
		return out;
	}
} // end of namespace task2

int main()
{
	// check Swap
	{
		struct Temp
		{
			int a = 1;
			int b = 2;
		};
		Temp* a = new Temp;
		Temp* b = new Temp{ 3, 4 };
		std::cout << "a: " << a->a << ", " << a->b << std::endl;
		std::cout << "b: " << b->a << ", " << b->b << std::endl;

		Swap(a, b);
		std::cout << "a (now b): " << a->a << ", " << a->b << std::endl;
		std::cout << "b (now a): " << b->a << ", " << b->b << std::endl;

		delete a;
		delete b;
	}
	// check SortPointers
	{
		using namespace task2;
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<int> uid(0, 1000);
		std::vector<Temp*> data;
		for (int i = 0; i < 100; ++i)
			data.push_back(new Temp{ uid(gen) });

		// print before
		std::cout << "before" << std::endl;
		for (const auto& item : data)
			std::cout << *item << " ";
		std::cout << std::endl;

		SortPointers(data);

		// print after
		std::cout << "after" << std::endl;
		for (const auto& item : data)
			std::cout << *item << " ";
		std::cout << std::endl;

		for (auto item : data)
			delete item;
	}
	// check counts
	{
		task3::main("./../../../../../volume1.txt");
	}
	return 0;
}
