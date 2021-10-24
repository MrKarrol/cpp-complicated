#include "gtest/gtest.h"
#include "PhoneBook.h"

TEST(PhoneBookTest, GetPhoneNumberTest)
{
	PhoneBook book;
	Person ilin{ "Ilin", "Petr", "Artemovich" };
	PhoneNumber ilin_number{ 7, 17, "4550767" };
	Person zaitsev1{ "Zaitsev", "Zakhar", "Artemovich" };
	PhoneNumber zaitsev1_number{ 125, 44, "4164751" };
	Person zaitsev2{ "Zaitsev", "Ilit", "Artemovich" };
	PhoneNumber zaitsev2_number{ 3, 45, "23123" };

	book.AddRecord(ilin, ilin_number);
	book.AddRecord(zaitsev1, zaitsev1_number);
	book.AddRecord(zaitsev2, zaitsev2_number);
	// found
	{
		const auto [result, number] = book.GetPhoneNumber("Ilin");
		EXPECT_EQ(result, "");
		EXPECT_EQ(number, ilin_number);
	}
	// not found
	{
		const auto [result, number] = book.GetPhoneNumber("Kitty");
		EXPECT_EQ(result, "not found");
		EXPECT_EQ(number, PhoneNumber());
	}
	// found more than 1
	{
		const auto [result, number] = book.GetPhoneNumber(zaitsev1.first_name);
		EXPECT_EQ(result, "found more than 1");
		EXPECT_EQ(number, zaitsev1_number);
	}
}