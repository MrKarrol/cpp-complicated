#include "PhoneBook.h"

#include <algorithm>


PhoneBook::PhoneBook()
{
}

PhoneBook::PhoneBook(std::ifstream& in)
{
	int size{};
	try
	{
		std::string size_str;
		std::getline(in, size_str);
		size = std::stoi(size_str);
	}
	catch (std::exception &e)
	{
		std::cerr << "Can't read size, book is empty. Error: " << e.what() << std::endl;
		return;
	}

	for (int i = 0; i < size; ++i)
	{
		Person person;
		PhoneNumber phone;
		in >> person >> phone;
		AddRecord(std::move(person), std::move(phone));
	}
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

std::tuple<std::string, PhoneNumber> PhoneBook::GetPhoneNumber(const std::string& first_name) const
{
	int count = 0;
	PhoneNumber seeked_number;
	std::for_each(std::begin(m_container), std::end(m_container), [first_name, &seeked_number, &count](const auto& record)
		{
			if (record.first.first_name == first_name)
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

void PhoneBook::AddRecord(Person&& person, PhoneNumber&& phone)
{
	m_container.emplace_back(person, phone);
}

std::ostream& operator << (std::ostream& out, const PhoneBook& book)
{
	for (const auto& [person, phone_number] : book.m_container)
		out << person << "    " << phone_number << std::endl;
	return out;
}

std::ofstream& operator << (std::ofstream& out, const PhoneBook& book)
{
	out << book.m_container.size() << std::endl;
	for (const auto& [person, phone] : book.m_container)
		out << person << phone;
	return out;
}