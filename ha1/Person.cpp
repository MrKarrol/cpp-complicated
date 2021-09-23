#include "Person.h"


bool operator < (const Person& lhv, const Person& rhv)
{
	return std::tie(lhv.first_name, lhv.second_name, lhv.third_name) < std::tie(rhv.first_name, rhv.second_name, rhv.third_name);
}

bool operator ==(const Person& lhv, const Person& rhv)
{
	return std::tie(lhv.first_name, lhv.second_name, lhv.third_name) == std::tie(rhv.first_name, rhv.second_name, rhv.third_name);
}

std::ostream& operator << (std::ostream& out, const Person& person)
{
	out << person.first_name << " " << person.second_name;
	if (person.third_name.has_value())
		out << " " << person.third_name.value();
	return out;
}
