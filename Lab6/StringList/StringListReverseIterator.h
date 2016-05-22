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


	friend bool const					operator==(const CReverseIterator& first
													, const CReverseIterator & second);// TODO : NOT TESTS
	friend bool const					operator!=(const CReverseIterator& first
													, const CReverseIterator & second);// TODO : NOT TESTS

	//~CReverseIterator();
public:
	CReverseIterator&					operator++();
	CReverseIterator&					operator--();
};
