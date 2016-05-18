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

bool const CStringList::CReverseIterator::operator==(CStringList::CReverseIterator const & other) const
{
	// TODO : delete copy code
	if (m_isEnd != other.m_isEnd)
	{
		return false;
	}
	else if (m_isEnd)
	{
		return (m_target == other.m_target);
	}
	else
	{
		return (GetUnlockCopy(m_node).get() == GetUnlockCopy(other.m_node).get());
	}

}

bool const CStringList::CReverseIterator::operator!=(CReverseIterator const & other) const
{
	return !(*this == other);
}

CStringList::CReverseIterator & CStringList::CReverseIterator::operator++()
{
	// TODO : delete copy code
	assert(!m_isEnd);

	if (GetUnlockCopy(GetUnlockCopy(m_node)->previous))
	{
		m_node = GetUnlockCopy(m_node)->previous;
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
		assert(GetUnlockCopy(m_node)->next);
		m_node = GetUnlockCopy(m_node)->next;
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

const CStringList::CReverseIterator CStringList::rbegin() const
{
	return rbegin();
}

const CStringList::CReverseIterator CStringList::rend() const
{
	return rend();
}