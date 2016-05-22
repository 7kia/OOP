#pragma once

#include "StringList.h"

class CIteratorData
{
public:
	virtual ~CIteratorData();
public:
	std::string&										operator*() const;// TODO : NOT TESTS
	std::string*										operator->() const;// TODO : NOT TESTS

	std::weak_ptr<CStringList::Node>					GetNode() const;

	bool const											ReferToEnd() const;

	friend bool const									operator==(const CIteratorData& first
																, const CIteratorData & second);// TODO : NOT TESTS
	friend bool const									operator!=(const CIteratorData& first
																, const CIteratorData & second);// TODO : NOT TESTS

protected:
	void												CheckIteratorForNotExpired() const;
protected:
	std::weak_ptr<CStringList::Node>					m_node;
	CStringList*										m_target;

	bool												m_isEnd = false;

};


class CStringList::CIterator
	: public CIteratorData
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

	CIterator&							operator++();
	CIterator&							operator--();
};

class CStringList::CConstIterator
	: public CStringList::CIterator
{
public:
	CConstIterator(bool isEnd
				, std::weak_ptr<Node> const& node// TODO refers
				, const CStringList* list);
private:
	const CStringList* m_target;
};
