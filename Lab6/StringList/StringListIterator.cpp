#include "stdafx.h"
#include "StringList.h"
#include "StringListIterator.h"

using namespace std;

CStringList::CIterator::CIterator()
	: m_isEnd(true)
	, m_target(nullptr)
{
}

CStringList::CIterator::CIterator(bool isEnd
								, const std::weak_ptr<Node> & node
								, CStringList * list)
	: m_isEnd(isEnd)
	, m_node(node)
	, m_target(list)
{
}

bool const  CStringList::CIterator::operator==(CIterator const & other) const
{
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

bool const CStringList::CIterator::operator!=(CIterator const& other) const
{
	return !(*this == other);
}

string& CStringList::CIterator::operator*() const
{
	assert(!m_isEnd);
	return GetUnlockCopy(m_node)->data;
}

string* CStringList::CIterator::operator->() const
{
	return &(*(*this));
}

CStringList::CIterator& CStringList::CIterator::operator++()
{
	assert(!m_isEnd);

	if (GetUnlockCopy(m_node)->next)
	{
		m_node = GetUnlockCopy(m_node)->next;
	}
	else
	{
		m_isEnd = true;
		m_node.reset();
	}

	return *this;
}

CStringList::CIterator& CStringList::CIterator::operator--()
{
	if (!m_isEnd)
	{
		assert(GetUnlockCopy(GetUnlockCopy(m_node)->previous));
		m_node = GetUnlockCopy(GetUnlockCopy(m_node)->previous);
	}
	else
	{
		m_isEnd = false;
		m_node = m_target->m_end;
	}

	return *this;
}

weak_ptr<CStringList::Node> CStringList::CIterator::GetNode() const
{
	return m_node;
}

bool const CStringList::CIterator::ReferToEnd() const
{
	return m_isEnd;
}


CStringList::CIterator CStringList::begin()
{
	if (m_begin)
	{
		return CStringList::CIterator(false
									, m_begin
									, this);
	}
	else
	{
		return end();
	}
}

CStringList::CIterator CStringList::end()
{
	return CStringList::CIterator(true
								, weak_ptr<Node>()
								, this);
}
