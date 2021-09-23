#pragma once

#include <string>
#include <optional>
#include <iostream>
#include <fstream>


struct Person
{
	std::string first_name;
	std::string second_name;
	std::optional <std::string> third_name;
};

bool operator < (const Person& lhv, const Person& rhv);
bool operator ==(const Person& lhv, const Person& rhv);
std::ostream& operator << (std::ostream& out, const Person& person);
