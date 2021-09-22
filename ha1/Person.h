#pragma once

#include <string>
#include <optional>

struct Person
{
	std::string first_name;
	std::string second_name;
	std::optional <std::string> third_name;
};

inline bool operator ==(const Person& lhv, const Person& rhv)
{
	return std::tie(lhv.first_name, lhv.second_name, lhv.third_name) == std::tie(rhv.first_name, rhv.second_name, rhv.third_name);
}