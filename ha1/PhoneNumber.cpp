#include "PhoneNumber.h"


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