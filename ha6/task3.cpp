#include "task3.h"

#include <random>
#include <algorithm>
#include <iostream>


std::atomic_bool house_exist{ true };
std::mutex house_mutex;

struct House
{
	std::vector<Thing> things;
} house;



HouseOwner::HouseOwner()
{
	work_thread = std::thread(&HouseOwner::LetsMakeHouseBetter, this);
}

HouseOwner::~HouseOwner()
{
	if (work_thread.joinable())
		work_thread.join();

	int sum{};
	for (const auto& thing : house.things)
		sum += thing.value;
	std::cout << "In house left things for value " << sum << std::endl;
}

void HouseOwner::LetsMakeHouseBetter()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> get_sleep_time(1, 10);
	std::uniform_int_distribution<int> get_value(5, 20);
	while (house_exist.load())
	{
		{
			const std::lock_guard<std::mutex> lg(house_mutex);
			house.things.emplace_back(get_value(gen));
			std::cout << "Owner took new thing with value " << house.things.back().value << " at home! \"What for?..\" owner's thoughts" << std::endl;
		}
		std::this_thread::sleep_for(std::chrono::seconds(get_sleep_time(gen)));
	}
	
}

Thief::Thief()
{
	work_thread = std::thread(&Thief::LetsMakeHouseBetter, this);
}

Thief::~Thief()
{
	if (work_thread.joinable())
		work_thread.join();

	int sum{};
	for (const auto& thing : m_stolen_things)
		sum += thing.value;
	std::cout << "Thief stole things for value " << sum << std::endl;
}

void Thief::LetsMakeHouseBetter()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> get_sleep_time(1, 10);
	while (house_exist.load())
	{
		if (house.things.size())
		{
			const std::lock_guard<std::mutex> lg(house_mutex);
			std::sort(house.things.begin(), house.things.end());
			m_stolen_things.push_back(house.things.back());
			house.things.pop_back();
			std::cout << "Thief stole thing with value " << m_stolen_things.back().value << "! \"Owner must say me thans for sorting his things...\" thief's thoughts." << std::endl;
		}
		std::this_thread::sleep_for(std::chrono::seconds(get_sleep_time(gen)));
	}
}

void Task3()
{
	HouseOwner owner;
	Thief thief;
	std::this_thread::sleep_for(std::chrono::seconds(30));
	house_exist.store(false);
}
