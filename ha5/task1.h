#pragma once

#include <string>
#include <set>
#include <list>
#include <vector>
#include <iostream>


template<class Iterator>
void PrintUnique(Iterator first, Iterator last)
{
	std::set<std::string> set;
	while (first != last)
	{
		set.emplace(*first);
		++first;
	}
	std::copy(set.cbegin(), set.cend(), std::ostream_iterator<std::string>(std::cout, " "));
	std::cout << std::endl;
}

void Task1()
{
	std::initializer_list<std::string> init{ "Run", "for", "your", "life", "life", "beaf", "for", "better", "sweet", "better", "better", "simphony" };
	{
		std::list<std::string> list{ init };
		PrintUnique(list.cbegin(), list.cend());
	}
	{
		std::vector<std::string> vec{ init };
		PrintUnique(vec.cbegin(), vec.cend());
	}
	{
		PrintUnique(init.begin(), init.end());
	}
}