#pragma once

#include <vector>
#include <algorithm>
#include <iostream>


template<typename T>
void Swap(T* &t, T* &n)
{
	std::swap(t, n);
}

template<typename T>
void SortPointers(std::vector<T*>& data)
{
	std::sort(std::begin(data), std::end(data), [](const auto *a, const auto *b)
		{
			return *a < *b;
		});
}