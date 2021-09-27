#include "Person.h"

#include <sstream>
#include <iomanip>


bool operator < (const Person& lhv, const Person& rhv)
{
	return std::tie(lhv.first_name, lhv.second_name, lhv.third_name)
		< std::tie(rhv.first_name, rhv.second_name, rhv.third_name);
}

bool operator ==(const Person& lhv, const Person& rhv)
{
	return std::tie(lhv.first_name, lhv.second_name, lhv.third_name)
		== std::tie(rhv.first_name, rhv.second_name, rhv.third_name);
}

std::ostream& operator << (std::ostream& out, const Person& person)
{
	out << std::setw(12) << person.first_name << std::setw(11) << person.second_name;
	if (person.third_name.has_value())
		out << std::setw(16) << person.third_name.value();
	else
		out << std::setw(16) << " ";
	return out;
}

std::ofstream& operator << (std::ofstream& out, const Person& person)
{
	out << person.first_name << " " << person.second_name;
	if (person.third_name.has_value())
		out << " " << person.third_name.value();
	out << std::endl;
	return out;
}

std::ifstream& operator >> (std::ifstream& in, Person& person)
{
	std::string person_str;
	try
	{
		std::getline(in, person_str);
		if (person_str.empty())
			throw std::invalid_argument("No string for person");

		auto GetName = [](std::string& input, std::string& output)
		{
			output = input.substr(0, input.find(' '));
			input = input.substr(output.size() + 1);
		};
		
		GetName(person_str, person.first_name);

		// second and third name
		if (person_str.find(' ') != std::string::npos)
		{
			GetName(person_str, person.second_name);
			person.third_name = person_str;
		}
		else
			person.second_name = person_str;
	}
	catch (std::exception& e)
	{
		std::cerr << "Can't read person. Error: " << e.what() << std::endl;
	}

	return in;
}
