#pragma once

#include <string>
#include <optional>
#include <iostream>

struct PhoneNumber
{
	int country_code{};
	int city_code{};
	std::string number;
	std::optional<int> additional_number;
};

std::ostream& operator << (std::ostream& out, const PhoneNumber& phone_number);
bool operator < (const PhoneNumber& lhv, const PhoneNumber& rhv);
