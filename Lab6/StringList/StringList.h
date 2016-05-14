#pragma once

#include <list>

#include <string>
#include <boost/algorithm/string.hpp>


class CIterator
{

};

class CStringList
{
public:
	CStringList();
	~CStringList();

	struct Node
	{
		std::weak_ptr<Node> previous;
		std::shared_ptr<Node> next;

		std::string data;
	};

public:
	void						Append(const std::string & addString);// TODO : first letter in low case

	std::string					GetStartElement();// TODO : rename
	std::string					back() const;


	size_t						GetSize() const;
private:
	size_t						m_size = 0;

	std::shared_ptr<Node>		m_begin;
	std::weak_ptr<Node>			m_end;

};
