#include "gtest/gtest.h"
#include "Person.h"

#include <algorithm>

TEST(PersonTest, OperatorEqualTest)
{
    {
        Person lhv{ "Nikki", "Devil", "Yongest" };
        Person rhv = lhv;
        EXPECT_EQ(lhv, rhv);
    }
    {
        Person lhv{ "Nikki", "Devil", "Yongest" };
        Person rhv{ "Nikki", "Devil" };
        EXPECT_FALSE(lhv == rhv);
    }
    {
        Person lhv{ "Nikki", "Devil" };
        Person rhv = lhv;
        EXPECT_EQ(lhv, rhv);
    }
}

TEST(PersonTest, OperatorLessTest)
{
    {
        std::vector<Person> persons = {
        { "Cikki", "Devil", "Yongest" },
        { "Bikki", "Devil", "Yongest" },
        { "Aikki", "Devil", "Yongest" }
        };
        std::sort(persons.begin(), persons.end());
        EXPECT_EQ(persons.at(0).first_name, "Aikki");
        EXPECT_EQ(persons.at(1).first_name, "Bikki");
        EXPECT_EQ(persons.at(2).first_name, "Cikki");
    }
    {
        std::vector<Person> persons = {
        { "Ncikki", "Devil", "Yongest" },
        { "Nbikki", "Devil", "Yongest" },
        { "Naikki", "Devil", "Yongest" }
        };
        std::sort(persons.begin(), persons.end());
        EXPECT_EQ(persons.at(0).first_name, "Naikki");
        EXPECT_EQ(persons.at(1).first_name, "Nbikki");
        EXPECT_EQ(persons.at(2).first_name, "Ncikki");
    }
    {
        std::vector<Person> persons = {
        { "Nikki", "CDevil", "Yongest" },
        { "Nikki", "BDevil", "Yongest" },
        { "Nikki", "ADevil", "Yongest" }
        };
        std::sort(persons.begin(), persons.end());
        EXPECT_EQ(persons.at(0).second_name, "ADevil");
        EXPECT_EQ(persons.at(1).second_name, "BDevil");
        EXPECT_EQ(persons.at(2).second_name, "CDevil");
    }
    
    {
        std::vector<Person> persons = {
        { "Nikki", "Devil", "CYongest" },
        { "Nikki", "Devil", "BYongest" },
        { "Nikki", "Devil", "AYongest" }
        };
        std::sort(persons.begin(), persons.end());
        EXPECT_EQ(persons.at(0).third_name, "AYongest");
        EXPECT_EQ(persons.at(1).third_name, "BYongest");
        EXPECT_EQ(persons.at(2).third_name, "CYongest");
    }
}
