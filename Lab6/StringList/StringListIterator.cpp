#include "stdafx.h"
#include "StringList.h"
#include "StringListIterator.h"

using namespace std;

CStringList::CIterator::CIterator()
{
	m_isEnd = true;
	m_target = nullptr;
}

CStringList::CIterator::CIterator(bool isEnd
								, const std::weak_ptr<Node> & node
								, CStringList * list)
{
	m_isEnd = isEnd;
	m_node = node;
	m_target = list;
}

/*
CStringList::CIterator::~CIterator()
{
	m_node.reset();
}
*/


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

string& CIteratorData::operator*() const
{
	assert(!m_isEnd);
	return CStringList::GetUnlockCopy(m_node)->data;
}

string* CIteratorData::operator->() const
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

CIteratorData::~CIteratorData()
{
}

weak_ptr<CStringList::Node> CIteratorData::GetNode() const
{
	return m_node;
}

bool const CIteratorData::ReferToEnd() const
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

const CStringList::CIterator CStringList::begin() const
{
	return begin();
}

const  CStringList::CIterator CStringList::end() const
{
	return end();
}

void CStringList::Insert(const CIterator & iter, const string & data)
{
	weak_ptr<Node> node = GetUnlockCopy(iter.GetNode());

	std::shared_ptr<Node> newNode = make_shared<Node>();

	newNode->data = data;
	newNode->next = GetUnlockCopy(node);

	//if (node.get() != nullptr)
	//{
	GetUnlockCopy(node)->previous = newNode;
	//}

	if (!GetUnlockCopy(node)->previous.expired())//== nullptr
	{
		GetUnlockCopy(GetUnlockCopy(node)->previous)->next = newNode;
		newNode->previous = GetUnlockCopy(node)->previous;
	}

}


