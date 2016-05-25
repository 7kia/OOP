#include "stdafx.h"
#include "ConstStringListReverseIterator.h"

using namespace std;

CStringList::CConstReverseIterator::CConstReverseIterator()
{
	m_isEnd = true;
	m_target = nullptr;
}

CStringList::CConstReverseIterator::CConstReverseIterator(bool isEnd
	, const std::weak_ptr<Node> & node
	, const CStringList * list)
{
	m_isEnd = isEnd;
	m_node = node;
	m_target = list;
}

CStringList::CConstReverseIterator & CStringList::CConstReverseIterator::operator++()
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

CStringList::CConstReverseIterator & CStringList::CConstReverseIterator::operator--()
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

bool const operator==(const CStringList::CConstReverseIterator & first
	, const CStringList::CConstReverseIterator & second)
{
	if (first.m_isEnd != second.m_isEnd)
	{
		return false;
	}
	else if (first.m_isEnd)
	{
		return (first.m_target == second.m_target);
	}
	else
	{
		return (CStringList::GetLockCopy(first.m_node).get()
			== CStringList::GetLockCopy(second.m_node).get());
	}
}

bool const operator!=(const CStringList::CConstReverseIterator & first
	, const CStringList::CConstReverseIterator & second)
{
	return dynamic_cast<const CIteratorData*>(&first) != dynamic_cast<const CIteratorData*>(&second);
}


CStringList::CConstReverseIterator CStringList::crbegin() const
{
	if (m_begin)
	{
		return CStringList::CConstReverseIterator(false
			, m_end
			, this);
	}
	else
	{
		return crend();

	}
}

CStringList::CConstReverseIterator CStringList::crend() const
{
	return CStringList::CConstReverseIterator(true
		, weak_ptr<Node>()
		, this);
}
