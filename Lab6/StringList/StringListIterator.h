#pragma once

#include "StringList.h"


class CIteratorData
{
public:
	virtual ~CIteratorData();
public:
	bool const											ReferToEnd() const;

	friend bool const									operator==(const CIteratorData& first
																, const CIteratorData & second);// TODO : NOT TESTS
	friend bool const									operator!=(const CIteratorData& first
																, const CIteratorData & second);// TODO : NOT TESTS

	std::weak_ptr<CStringList::Node>					GetNode() const;
protected:
	void												CheckIteratorForNotExpired() const;
protected:
	std::weak_ptr<CStringList::Node>					m_node;
	CStringList*										m_target;

	bool												m_isEnd = false;

};

class CChangeItaratorData
	: public CIteratorData
{
public:
	virtual ~CChangeItaratorData();

public:
	std::string&										operator*() const;// TODO : NOT TESTS
	std::string*										operator->() const;// TODO : NOT TESTS
};


class CStringList::CIterator
	: public CChangeItaratorData
	, public std::iterator<std::bidirectional_iterator_tag, std::string>
{
public:
	CIterator();
	CIterator(bool isEnd
			, std::weak_ptr<Node> const& node// TODO refers
			, CStringList* list);

	virtual ~CIterator();
public:
	friend bool const									operator==(const CIterator& first
																, const CIterator & second);// TODO : NOT TESTS
	friend bool const									operator!=(const CIterator& first
																, const CIterator & second);// TODO : NOT TESTS

	CIterator&											operator++();
	CIterator&											operator--();
};

