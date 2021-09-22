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

inline std::ostream& operator << (std::ostream& out, const PhoneNumber& phone_number)
{
	out << "+" << phone_number.country_code << "(" << phone_number.city_code << ")" << phone_number.number;
	if (phone_number.additional_number.has_value())
		out << " " << phone_number.additional_number.value();
	return out;
}