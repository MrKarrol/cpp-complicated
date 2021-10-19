#pragma once

#include <map>
#include <string>
#include <iostream>


template<typename T>
bool is_in(const T& value, std::initializer_list<T> list)
{
	return std::find(list.begin(), list.end(), value) != list.end();
}

const auto delims = { '.', '!', '?' };

bool operator < (const std::string& lhv, const std::string& rhv)
{
	return lhv.length() < rhv.length();
}

void Task2()
{
	std::cout << "Type \"exit\" to stop writing." << std::endl;
	std::map<int, std::string> sequences;

	while (true)
	{
		std::string line;
		std::getline(std::cin, line);
		if (line == "exit")
			break;
		std::size_t prev{};
		std::size_t pos{};
		while ((pos = line.find_first_of(".!?", prev)) != std::string::npos)
		{
			while (pos + 1 < line.length() && is_in(line.at(pos), delims) && is_in(line.at(pos + 1), delims))
				++pos;
			if (pos > prev)
			{
				const auto&& seq = line.substr(prev, pos - prev + 1);
				sequences.emplace(seq.length(), seq);
			}

			prev = pos + 1;
			while (prev + 1 < line.length() && line.at(prev) == ' ')
				++prev;
		}
		if (prev < line.length())
		{
			const auto&& seq = line.substr(prev, std::string::npos);
			sequences.emplace(seq.length(), seq);
		}
	}
	std::cout << "Num of sequences is " << sequences.size() << ". Sequences: " << std::endl;
	for (const auto& seq : sequences)
		std::cout << seq.second << std::endl;
}
