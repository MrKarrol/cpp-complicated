#pragma once

#include <string>
#include <optional>
#include <iostream>
#include <fstream>


struct PhoneNumber
{
	int country_code{};
	int city_code{};
	std::string number;
	std::optional<int> additional_number;
};

std::ostream& operator << (std::ostream& out, const PhoneNumber& phone_number);
bool operator < (const PhoneNumber& lhv, const PhoneNumber& rhv);
std::ofstream& operator << (std::ofstream& out, const PhoneNumber& phone);
std::ifstream& operator >> (std::ifstream& in, PhoneNumber& phone);
