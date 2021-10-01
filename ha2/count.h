#pragma once

#include <fstream>
#include <chrono>
#include <string>
#include <algorithm>
#include <sstream>
#include <tuple>


namespace task3
{
	namespace _task3
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

		CountResult MyMethod1(const std::string& in)
		{
			const auto before = std::chrono::high_resolution_clock::now();
			const auto count = std::count_if(std::begin(in), std::end(in), CheckVowel);
			return { std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - before), count };
		}

		CountResult MyMethod2(const std::string& in)
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
	} // end of namespace _task3

	void main(const std::string& filename)
	{
		using namespace _task3;
		std::ifstream in(filename);
		std::stringstream buffer;
		buffer << in.rdbuf();
		std::cout << "got volume 1. number of chars " << buffer.str().size() << std::endl;
		Print(MyMethod1(buffer.str()));
		in.seekg(0);
		Print(MyMethod2(buffer.str()));
	}
} // end of namespace task3