#include "Person.h"
#include "PhoneNumber.h"

#include <iostream>

int main()
{
	// person check
	{
		Person person = { "Ada", "Wong" };
		Person person2 = { "Ada", "Wong" };
		std::cout << (person == person2) << std::endl;
		person2.third_name = "Wife";
		std::cout << (person == person2) << std::endl;
	}
	// phone number check
	{
		PhoneNumber number;
		number.country_code = 7;
		number.city_code = 911;
		number.number = "1234567";
		std::cout << number << std::endl;
		number.additional_number = 12;
		std::cout << number << std::endl;
	}
	
	return 0;
}
