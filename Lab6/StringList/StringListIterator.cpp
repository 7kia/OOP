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
								, const weak_ptr<Node> & node
								, CStringList * list)
{
	m_isEnd = isEnd;
	m_node = node;
	m_target = list;
}

void CStringList::Clear()
{
	CStringList::CIterator iter = begin();
	while(iter != end())
	{
		Remove(iter);
		iter = begin();
	}
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
	/*
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
	*/
	return begin();
}

const  CStringList::CIterator CStringList::end() const
{
	/*
		return CStringList::CIterator(true
								, weak_ptr<Node>()
								, this);

	*/
	return end();
}

void CStringList::Insert(const CIterator & iter, const string & data)
{
	try
	{
		shared_ptr<Node> newNode(new Node);
		newNode->data = data;

		if (iter.ReferToEnd())
		{
			if (m_begin)
			{
				newNode->previous = m_end;
				GetUnlockCopy(m_end)->next = newNode;
				m_end = newNode;
			}
			else
			{
				m_begin = newNode;
				m_end = newNode;
			}
		}
		else
		{
			if (GetUnlockCopy(iter.GetNode()).get() == m_begin.get())
			{
				newNode->next = m_begin;
				m_begin->previous = newNode;
				m_begin = newNode;
			}
			else
			{
				shared_ptr<Node> nextNode(GetUnlockCopy(iter.GetNode()));
				shared_ptr<Node> prevNode(GetUnlockCopy(nextNode->previous));

				newNode->previous = prevNode;
				newNode->next = nextNode;

				prevNode->next = newNode;
				nextNode->previous = newNode;
			}
		}

		m_size++;
	}
	catch (const std::bad_alloc & exception)
	{
		throw;
	}
}

void CStringList::Remove(const CIterator & iter)
{
	try
	{
		CheckListForNotEmpty();

		shared_ptr<Node> deleteNode = GetUnlockCopy(iter.GetNode());
		shared_ptr<Node> prevNode = GetUnlockCopy(deleteNode->previous);
		shared_ptr<Node> nextNode = deleteNode->next;

		if (prevNode)
		{
			if (nextNode)
			{
				prevNode->next = nextNode;
				nextNode->previous = prevNode;
			}
			else
			{
				prevNode->next.reset();
				m_end = prevNode;
			}
		}
		else
		{
			if (nextNode)
			{
				nextNode->previous.reset();
				m_begin = nextNode;
			}
			else
			{
				m_begin.reset();
				m_end.reset();
			}
		}

		m_size--;
	}
	catch (const std::bad_alloc & exception)
	{
		throw;
	}
	catch (const std::runtime_error & exception)
	{
		throw;
	}
}


