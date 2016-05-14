#pragma once

#include <string>
#include <boost/algorithm/string.hpp>

class CStringListNode
{
	CStringListNode* previous;
	std::unique_ptr<CStringListNode> next;
};

class CStringList
{
public:
	void		Append(const std::string & addString);// TODO : first letter in low case

	size_t		GetSize() const;
private:
	size_t		m_size = 0;
};
