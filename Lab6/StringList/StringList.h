#pragma once

#include <list>

#include <string>
#include <boost/algorithm/string.hpp>

class CStringList
{
public:
	CStringList();
	~CStringList();

	struct Node
	{
		~Node();
		std::weak_ptr<Node>		previous;
		std::shared_ptr<Node>	next;

		std::string				data;
	};
	class CIterator;

public:
	void						PushToEnd(const std::string & addString);// TODO : first letter in low case
	void						PushToStart(const std::string & addString);// TODO : first letter in low case


	std::string					front();// TODO : rename
	std::string					back() const;


	size_t						GetSize() const;
	bool						IsEmpty() const;

private:
	void						CreateFirstNode(const std::string & data);
private:
	size_t						m_size = 0;

	std::shared_ptr<Node>		m_begin;
	std::weak_ptr<Node>			m_end;

};

class CStringList::CIterator
	: public std::iterator<std::bidirectional_iterator_tag, std::string>
{
public:
private:
	std::weak_ptr<Node>			m_node;
	CStringList*				m_target;

};