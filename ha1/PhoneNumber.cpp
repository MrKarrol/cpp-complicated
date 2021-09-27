#include "PhoneNumber.h"

#include <sstream>
#include <iomanip>


std::ostream& operator << (std::ostream& out, const PhoneNumber& phone_number)
{
	out << "+" << phone_number.country_code << "(" << phone_number.city_code << ")" << phone_number.number;
	if (phone_number.additional_number.has_value())
		out << " " << phone_number.additional_number.value();
	return out;
}

bool operator < (const PhoneNumber& lhv, const PhoneNumber& rhv)
{
	return std::tie(lhv.country_code, lhv.city_code, lhv.number, lhv.additional_number)
		< std::tie(rhv.country_code, rhv.city_code, rhv.number, rhv.additional_number);
}

std::ofstream& operator << (std::ofstream& out, const PhoneNumber& phone_number)
{
	out << "+" << phone_number.country_code << "(" << phone_number.city_code << ")" << phone_number.number;
	if (phone_number.additional_number.has_value())
		out << " " << phone_number.additional_number.value();
	out << std::endl;
	return out;
}

std::ifstream& operator >> (std::ifstream& in, PhoneNumber& phone)
{
	std::string phone_str;
	try
	{
		std::getline(in, phone_str);
		if (phone_str.empty())
			throw std::invalid_argument("No string for phone number");

		// country code
		{
			std::string cc_str = phone_str.substr(0, phone_str.find('('));
			phone.country_code = std::stoi(cc_str);
			phone_str = phone_str.substr(cc_str.size());
		}
		// city code
		{
			std::string cc_str = phone_str.substr(1, phone_str.find(')'));
			phone.city_code = std::stoi(cc_str);
			phone_str = phone_str.substr(phone_str.find(')') + 1);
		}
		// number and additional number
		if (phone_str.find(' ') != std::string::npos)
		{
			// number
			{
				std::string number;
				phone.number = phone_str.substr(0, phone_str.find(' '));
				phone_str = phone_str.substr(phone.number.size() + 1);
			}
			
			// additional number
			{
				phone.additional_number = std::stoi(phone_str);
			}
		}
		else // just number
		{
			phone.number = phone_str;
		}
	}
	catch (std::exception& e)
	{
		std::cerr << "Can't read phone. Error: " << e.what() << std::endl;
	}

	return in;
}