#include "count.h"

#include <iostream>
#include <fstream>
#include <chrono>
#include <string>
#include <algorithm>
#include <sstream>
#include <tuple>


namespace
{
	bool CheckVowel(char ch)
	{
		switch (ch)
		{
		case 'à':
		case 'ó':
		case 'å':
		case 'è':
		case 'î':
		case 'ý':
		case 'þ':
		case 'ÿ':
		case 'û':
		case '¸':
			return true;
		};
		return false;
	}

	using CountResult = std::tuple<std::chrono::nanoseconds, int>;

	CountResult CountWithCountIf(const std::string& in)
	{
		const auto before = std::chrono::high_resolution_clock::now();
		const auto count = std::count_if(std::begin(in), std::end(in), CheckVowel);
		return { std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - before), count };
	}

	CountResult CountWithForLoop(const std::string& in)
	{
		int count = 0;
		const auto before = std::chrono::high_resolution_clock::now();
		for (const auto& ch : in)
		{
			if (CheckVowel(ch))
				++count;
		}
		return { std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - before), count };
	}

	void Print(CountResult result)
	{
		std::cout << "Count by first method took " << std::get<0>(result).count() << " ns, vowels count " << std::get<1>(result) << std::endl;
	}
} // end of namespace


void Calculate(const std::string& filename)
{
	std::string volume;
	{
		std::ifstream in(filename);
		std::stringstream buffer;
		buffer << in.rdbuf();
		volume = buffer.str();
		std::transform(std::cbegin(volume), std::cend(volume), std::begin(volume), [](auto ch) { return std::tolower(ch); });
	}
	


	std::cout << "got volume 1. number of chars " << volume.size() << std::endl;
	Print(CountWithCountIf(volume));
	Print(CountWithForLoop(volume));
}
