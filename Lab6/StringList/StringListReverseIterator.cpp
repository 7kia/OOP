#include "stdafx.h"
#include "StringListReverseIterator.h"

using namespace std;

CStringList::CReverseIterator::CReverseIterator()
{
	m_isEnd = true;
	m_target = nullptr;
}

CStringList::CReverseIterator::CReverseIterator(bool isEnd
	, const std::weak_ptr<Node> & node
	, CStringList * list)
{
	m_isEnd = isEnd;
	m_node = node;
	m_target = list;
}

/*
CStringList::CReverseIterator::~CReverseIterator()
{
}
*/


CStringList::CReverseIterator & CStringList::CReverseIterator::operator++()
{

	if (m_isEnd)
	{
		throw runtime_error(MESSAGE_REVERSE_ITERATOR_HAS_NOT_INCREMENTABLE);
	}

	if (!GetLockCopy(m_node)->previous.expired())
	{
		m_node = GetLockCopy(m_node)->previous;
	}
	else
	{
		m_isEnd = true;
		m_node.reset();
	}

	return *this;
}

CStringList::CReverseIterator & CStringList::CReverseIterator::operator--()
{
	if (!m_isEnd)
	{
		if (!GetLockCopy(GetLockCopy(m_node)->next))
		{
			throw runtime_error(MESSAGE_REVERSE_ITERATOR_HAS_NOT_DECREMENTABLE);
		}

		m_node = GetLockCopy(m_node)->next;
	}
	else
	{
		m_isEnd = false;
		m_node = m_target->m_begin;
	}

	return *this;
}

CStringList::CReverseIterator CStringList::rbegin()
{
	if (m_begin)
	{
		return CStringList::CReverseIterator(false
											, m_end
											, this);
	}
	else
	{
		return rend();

	}
}

CStringList::CReverseIterator CStringList::rend()
{
	return CStringList::CReverseIterator(true
		, weak_ptr<Node>()
		, this);
}

bool const operator==(const CStringList::CReverseIterator & first
					, const CStringList::CReverseIterator & second)
{
	return dynamic_cast<const CIteratorData*>(&first) == dynamic_cast<const CIteratorData*>(&second);
}

bool const operator!=(const CStringList::CReverseIterator & first
					, const CStringList::CReverseIterator & second)
{
	return dynamic_cast<const CIteratorData*>(&first) != dynamic_cast<const CIteratorData*>(&second);
}