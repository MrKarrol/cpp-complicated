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
	PhoneBook(); // to write initial settings
	explicit PhoneBook(std::ifstream& in);

	void SortByName();
	void SortByPhone();
	std::tuple<std::string, PhoneNumber> GetPhoneNumber(const std::string& second_name) const;
	void ChangePhoneNumber(const Person& person, PhoneNumber&& phone_number);

	friend std::ostream& operator << (std::ostream&, const PhoneBook&);
	friend std::ofstream& operator << (std::ofstream& out, const PhoneBook& book);

	void AddRecord(Person&& person, PhoneNumber&& phone);
	void AddRecord(const Person& person, const PhoneNumber& phone);

private:
	using Container = std::vector<std::pair<std::unique_ptr<Person>, std::unique_ptr<PhoneNumber>>>;
	Container m_container;

};

std::ostream& operator << (std::ostream& out, const PhoneBook& book);
std::ofstream& operator << (std::ofstream& out, const PhoneBook& book);
