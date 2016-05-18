#pragma once

#include "StringListIterator.h"


class CStringList::CReverseIterator
	: public CIteratorData
	, public std::iterator<std::bidirectional_iterator_tag, std::string>
{
public:
	CReverseIterator();
	CReverseIterator(bool isEnd
		, std::weak_ptr<Node> const& node// TODO refers
		, CStringList* list);

public:
	bool const							operator==(CReverseIterator const& other) const;// TODO : NOT TESTS
	bool const							operator!=(CReverseIterator const& other) const;// TODO : NOT TESTS

	CReverseIterator&					operator++();
	CReverseIterator&					operator--();
};
