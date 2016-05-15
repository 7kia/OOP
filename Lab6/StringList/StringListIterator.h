#pragma once

#include "StringList.h"

class CStringList::CIterator
	: public std::iterator<std::bidirectional_iterator_tag, std::string>
{
public:
	CIterator();
	CIterator(bool isEnd
			, std::weak_ptr<Node> const& node// TODO refers
			, CStringList* list);
public:
	bool const							operator==(CStringList::CIterator const& other) const;// TODO : NOT TESTS
	bool const							operator!=(CIterator const& other) const;// TODO : NOT TESTS

	std::string&						operator*() const;// TODO : NOT TESTS
	std::string*						operator->() const;// TODO : NOT TESTS

	CIterator&							operator++();
	CIterator&							operator--();

	std::weak_ptr<Node>	GetNode() const;

	bool const							ReferToEnd() const;
private:
	std::weak_ptr<Node>			m_node;
	CStringList*				m_target;

	bool						m_isEnd = false;
};