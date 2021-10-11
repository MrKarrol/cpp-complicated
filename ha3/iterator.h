#pragma once

#include <iterator>
#include <memory>


class Container;

template<class T>
class Iterator : public std::iterator<std::input_iterator_tag, T>
{
	friend class Container;
private:
	Iterator(T* p)
		: m_p(p)
	{}

public:
	Iterator(const Iterator& it)
		: m_p(it.m_p)
	{}

	bool operator !=(const Iterator& rhv) const
	{
		return m_p != rhv.m_p;
	}
	typename Iterator::reference operator *() const
	{
		return *m_p;
	}
	Iterator& operator ++()
	{
		++m_p;
		return *this;
	}

private:
	T* m_p;

};


class Container
{
public:
	using iterator = Iterator<int>;
	using const_iterator = Iterator<const int>;

	Container(std::initializer_list<int> data);

	iterator begin();
	iterator end();

	const_iterator cbegin();
	const_iterator cend();
	
private:
	const size_t m_size;
	std::unique_ptr<int[]> m_data;

};

