#pragma once

#include <algorithm>
#include <iostream>


template<typename T, 
	template <typename, typename = std::allocator<T>> class Container>
void insert_sorted(Container<T>& container, T value)
{
	const auto it = std::find_if(std::begin(container), std::end(container), [value](const auto& item) {return item > value; });
	container.insert(it, value);
}

template<typename T,
	template <typename, typename = std::allocator<T>> class Container>
std::ostream& operator <<(std::ostream& out, const Container<T>& container)
{
	for (const auto& item : container)
		out << item << " ";
	return out;
}