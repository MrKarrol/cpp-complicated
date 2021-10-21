#pragma once

#include <vector>
#include <atomic>
#include <thread>
#include <mutex>


struct Thing
{
	explicit Thing(int _value) : value(_value) {}
	int value{};
};

inline bool operator < (const Thing& lhv, const Thing& rhv)
{
	return lhv.value < rhv.value;
}


class HouseOwner
{
public:
	HouseOwner();
	~HouseOwner();

private:
	void LetsMakeHouseBetter();

private:
	std::thread work_thread;

};

class Thief
{
public:
	Thief();
	~Thief();

private:
	void LetsMakeHouseBetter();

private:
	std::vector<Thing> m_stolen_things;;

private:
	std::thread work_thread;

};

void Task3();
