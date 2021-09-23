#include "PhoneBook.h"

#include <algorithm>


PhoneBook::PhoneBook(std::ifstream& in)
{

}

void PhoneBook::SortByName()
{
	std::sort(std::begin(m_container), std::end(m_container), [](const auto& lhv, const auto& rhv)
		{
			return lhv.first < rhv.first;
		});
}

void PhoneBook::SortByPhone()
{
	std::sort(std::begin(m_container), std::end(m_container), [](const auto& lhv, const auto& rhv)
		{
			return lhv.second < rhv.second;
		});
}

std::tuple<std::string, PhoneNumber> PhoneBook::GetPhoneNumber(const std::string& second_name) const
{
	int count = 0;
	PhoneNumber seeked_number;
	std::for_each(std::begin(m_container), std::end(m_container), [second_name, &seeked_number, &count](const auto& record)
		{
			if (record.first.second_name == second_name)
			{
				++count;
				if (count == 1)
					seeked_number = record.second;
			}
		});
	if (count > 1)
		return std::tuple(std::string("found more than 1"), seeked_number);
	else if (count)
		return std::tuple(std::string(""), seeked_number);

	return std::tuple(std::string("not found"), seeked_number);
}

void PhoneBook::ChangePhoneNumber(const Person& person, PhoneNumber&& phone_number)
{
	const auto it = std::find_if(std::begin(m_container), std::end(m_container), [&person](const auto& record)
		{
			return record.first == person;
		});
	if (it != std::end(m_container))
		it->second = std::move(phone_number);
}

std::ostream& operator << (std::ostream& out, const PhoneBook& book)
{
	for (const auto& [person, phone_number] : book.m_container)
	{
		out << person << " " << phone_number << std::endl;
	}
	return out;
}
