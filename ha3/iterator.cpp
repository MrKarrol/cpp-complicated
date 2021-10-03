#include "iterator.h"

Container::Container(std::initializer_list<int> data)
	: m_size(data.size())
	, m_data(std::make_unique<int[]>(m_size))
{
	std::copy(std::begin(data), std::end(data), m_data.get());
}

Container::iterator Container::begin()
{
	return iterator(m_data.get());
}

Container::iterator Container::end()
{
	return iterator(m_data.get() + m_size);
}

Container::const_iterator Container::cbegin()
{
	return const_iterator(m_data.get());
}

Container::const_iterator Container::cend()
{
	return const_iterator(m_data.get() + m_size);
}
