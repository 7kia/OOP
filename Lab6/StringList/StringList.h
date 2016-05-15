﻿#pragma once

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
		~Node();// For debug
		std::weak_ptr<Node>		previous;
		std::shared_ptr<Node>	next;

		std::string				data;
	};
	class CIterator;

public:
	static std::shared_ptr<Node> GetUnlockCopy(const std::weak_ptr<Node> & pointer);

	void						PushToEnd(const std::string & addString);// TODO : first letter in low case
	void						PushToStart(const std::string & addString);// TODO : first letter in low case

	std::string					front() const;
	std::string					back() const;

	CIterator					begin();
	CIterator					end();

	size_t						GetSize() const;
	bool						IsEmpty() const;

	void						Clear();

private:
	void						CreateFirstNode(const std::string & data);
private:
	size_t						m_size = 0;

	std::shared_ptr<Node>		m_begin;
	std::weak_ptr<Node>			m_end;

};