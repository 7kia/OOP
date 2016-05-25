#pragma once

#include "StringListIterator.h"

class CNotChangeItaratorData
	: public CChangeItaratorData
{
public:
	virtual ~CNotChangeItaratorData();

	const std::string&									operator*() const;// TODO : NOT TESTS
	const std::string*									operator->() const;// TODO : NOT TESTS
protected:
	const CStringList*									m_target;

};

class CStringList::CConstIterator
	: public CNotChangeItaratorData
	, public std::iterator<std::bidirectional_iterator_tag, std::string>
{
public:
	CConstIterator();
	CConstIterator(bool isEnd
				, std::weak_ptr<Node> const& node// TODO refers
				, const CStringList* list);


	virtual ~CConstIterator();
public:
	friend bool const									operator==(const CConstIterator& first
																	, const CConstIterator & second);// TODO : NOT TESTS
	friend bool const									operator!=(const CConstIterator& first
																	, const CConstIterator & second);// TODO : NOT TESTS

	CConstIterator&										operator++();
	CConstIterator&										operator--();

};