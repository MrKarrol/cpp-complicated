#pragma once

#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <tuple>

#include "Person.h"
#include "PhoneNumber.h"

class PhoneBook
{
public:
	explicit PhoneBook(std::ifstream& in);
	void SortByName();
	void SortByPhone();
	std::tuple<std::string, PhoneNumber> GetPhoneNumber() const;
	void ChangePhoneNumber(const Person& person, PhoneNumber&& phone_number);

private:
	using Container = std::vector<std::pair<Person, PhoneNumber>>;
	Container m_container;

};