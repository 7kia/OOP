#pragma once

#include "ConstStringListIterator.h"

class CStringList::CConstReverseIterator
	: public CNotChangeItaratorData
	, public std::iterator<std::bidirectional_iterator_tag, std::string>
{
public:
	CConstReverseIterator();
	CConstReverseIterator(bool isEnd
		, std::weak_ptr<Node> const& node// TODO refers
		, const CStringList* list);


	friend bool const					operator==(const CConstReverseIterator& first
													, const CConstReverseIterator & second);// TODO : NOT TESTS
	friend bool const					operator!=(const CConstReverseIterator& first
													, const CConstReverseIterator & second);// TODO : NOT TESTS

												//~CReverseIterator();
public:
	CConstReverseIterator&					operator++();
	CConstReverseIterator&					operator--();
};