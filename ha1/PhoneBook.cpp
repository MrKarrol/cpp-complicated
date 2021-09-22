#include "PhoneBook.h"

PhoneBook::PhoneBook(std::ifstream& in)
{
}

void PhoneBook::SortByName()
{
}

void PhoneBook::SortByPhone()
{
}

std::tuple<std::string, PhoneNumber> PhoneBook::GetPhoneNumber() const
{
	return std::tuple<std::string, PhoneNumber>();
}

void PhoneBook::ChangePhoneNumber(const Person& person, PhoneNumber&& phone_number)
{

}
