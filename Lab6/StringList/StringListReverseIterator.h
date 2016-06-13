#pragma once

#include "StringListIterator.h"


class CStringList::CReverseIterator
	: public CIterator
{
public:
	CReverseIterator();
	CReverseIterator(bool isEnd
					, std::weak_ptr<Node> const& node// TODO refers
					, const CStringList* list);

	virtual ~CReverseIterator();


	friend bool const					operator==(const CReverseIterator& first
													, const CReverseIterator & second);// TODO : NOT TESTS
	friend bool const					operator!=(const CReverseIterator& first
													, const CReverseIterator & second);// TODO : NOT TESTS

public:
	CReverseIterator&					operator++();
	CReverseIterator&					operator--();
};
