#include <iostream>
#include <random>
#include <list>
#include <vector>
#include <algorithm>
#include <numeric>

#include "insert.h"


int main()
{
	// task 1
	{
		std::cout << "***** TASK 1 *****" << std::endl;

		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<int> uid(-100, 100);
		std::uniform_real_distribution<double> urd(-100.f, 100.f);

		{
			std::list<double> list(20);
			std::generate(std::begin(list), std::end(list), [&urd, &gen]() { return urd(gen); });
			list.sort();

			std::cout << "sorted list before insertion" << std::endl << list << std::endl;
			const auto elem_to_insert = urd(gen);
			std::cout << "element to insert " << elem_to_insert << std::endl;
			insert_sorted(list, elem_to_insert);
			std::cout << "sorted list after insertion" << std::endl << list << std::endl;
		}
		{
			std::vector<int> vec(10);
			std::generate(std::begin(vec), std::end(vec), [&uid, &gen]() { return uid(gen); });
			std::sort(std::begin(vec), std::end(vec));

			std::cout << "sorted vector before insertion" << std::endl << vec << std::endl;
			const auto elem_to_insert = uid(gen);
			std::cout << "element to insert " << elem_to_insert << std::endl;
			insert_sorted(vec, elem_to_insert);
			std::cout << "sorted list after insertion" << std::endl << vec << std::endl;
		}
	}
	// task 2
	{
		std::cout << "***** TASK 2 *****" << std::endl;

		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_real_distribution<double> urd(-100.f, 100.f);

		std::vector<double> analog(100);
		std::generate(std::begin(analog), std::end(analog), [&urd, &gen]() { return urd(gen); });
		std::vector<int> digital(analog.size());
		std::copy(std::begin(analog), std::end(analog), std::begin(digital));

		std::cout << "analog" << std::endl;
		std::copy(std::begin(analog), std::end(analog), std::ostream_iterator<double>{std::cout, " "});
		std::cout << std::endl;
		std::cout << "digital" << std::endl;
		std::copy(std::begin(digital), std::end(digital), std::ostream_iterator<int>{std::cout, " "});
		std::cout << std::endl;

		std::vector<double> errors(analog.size());
		std::transform(std::cbegin(analog), std::cend(analog), std::cbegin(digital), std::begin(errors), std::minus<>{});
		std::transform(std::cbegin(errors), std::cend(errors), std::begin(errors), [](const auto& item) { return item * item; });
		const auto signal_error = std::accumulate(std::begin(errors), std::end(errors), 0.f);

		std::cout << "Signal error is " << signal_error << std::endl;
	}
	return 0;
}
