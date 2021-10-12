#pragma once

#include <set>
#include <iostream>
#include <thread>


bool CheckNumber(int n)
{
    for (int i = 2; i <= std::sqrt(n); ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void FindNumber(int index)
{
    std::set<int> numbers{ 2 };
    int current_number = 3;
    while (numbers.size() != index)
    {
        if (CheckNumber(current_number))
        {
            numbers.emplace(current_number);
            std::cout << "found " << numbers.size() << "st number - " << current_number << std::endl;
        }
        current_number += 2;
    }
    std::cout << index << "st prime number is " << *numbers.rbegin() << std::endl;
}

void Task2()
{
    int n{};
    std::cout << "Input prime number index: ";
    std::cin >> n;
    std::thread thread(FindNumber, n);
    if (thread.joinable())
        thread.join();
    std::cout << "task 2 complited" << std::endl;
}