#include "gtest/gtest.h"
#include "PhoneNumber.h"

#include <algorithm>

TEST(PhoneNumberTest, OperatorLessTest)
{
	{
		std::vector<PhoneNumber> numbers{
		{3, 4, "1233321", 2},
		{2, 4, "1233321", 2},
		{1, 4, "1233321", 2},
		};
		std::sort(numbers.begin(), numbers.end());
		EXPECT_EQ(numbers.at(0).country_code, 1);
		EXPECT_EQ(numbers.at(1).country_code, 2);
		EXPECT_EQ(numbers.at(2).country_code, 3);
	}
	{
		std::vector<PhoneNumber> numbers{
		{3, 4, "1233321", 2},
		{3, 2, "1233321", 2},
		{3, 1, "1233321", 2},
		};
		std::sort(numbers.begin(), numbers.end());
		EXPECT_EQ(numbers.at(0).city_code, 1);
		EXPECT_EQ(numbers.at(1).city_code, 2);
		EXPECT_EQ(numbers.at(2).city_code, 4);
	}
	{
		std::vector<PhoneNumber> numbers{
		{3, 4, "3233321", 2},
		{3, 4, "2333321", 2},
		{3, 4, "2233321", 2},
		{3, 4, "12333221", 2},
		};
		std::sort(numbers.begin(), numbers.end());
		EXPECT_EQ(numbers.at(0).number, "2233321");
		EXPECT_EQ(numbers.at(1).number, "2333321");
		EXPECT_EQ(numbers.at(2).number, "3233321");
		EXPECT_EQ(numbers.at(3).number, "12333221");
	}
	{
		std::vector<PhoneNumber> numbers{
		{3, 4, "1233321", 3},
		{2, 4, "1233321", 2},
		{1, 4, "1233321", 1},
		};
		std::sort(numbers.begin(), numbers.end());
		EXPECT_EQ(numbers.at(0).additional_number, 1);
		EXPECT_EQ(numbers.at(1).additional_number, 2);
		EXPECT_EQ(numbers.at(2).additional_number, 3);
	}
}