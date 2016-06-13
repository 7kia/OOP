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
								, const CStringList * list)
{
	m_isEnd = isEnd;
	m_node = node;
	m_target = list;
}

CStringList::CIterator::~CIterator()
{
}

void CStringList::Clear()
{
	CStringList::CIterator iter = begin();
	while(iter != end())
	{
		Erase(iter);
		iter = begin();
	}
}


CStringList & CStringList::operator=(const CStringList & other)
{
	if (this != &other)
	{
		Clear();

		for (auto iter = other.cbegin(); iter != other.cend(); ++iter)
		{
			PushToEnd(*iter);
		}
	}

	return *this;
}

bool const operator==(const CStringList::CIterator & first, const CStringList::CIterator & second)
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

bool const operator!=(const CStringList::CIterator & first
					, const CStringList::CIterator & second)
{
	return !(first == second);
}


string& CStringList::CIterator::operator*() const
{
	CheckIteratorForNotExpired();

	return CStringList::GetLockCopy(m_node)->data;
}

string* CStringList::CIterator::operator->() const
{
	
	assert(!m_isEnd);
	CheckIteratorForNotExpired();

	return &(*(*this));
}

CStringList::CIterator& CStringList::CIterator::operator++()
{
	if (m_isEnd)
	{
		throw runtime_error(MESSAGE_ITERATOR_HAS_NOT_INCREMENTABLE);
	}

	if (GetLockCopy(m_node)->next)
	{
		m_node = GetLockCopy(m_node)->next;
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
		if (!GetLockCopy(GetLockCopy(m_node)->previous))
		{
			throw runtime_error(MESSAGE_ITERATOR_HAS_NOT_DECREMENTABLE);
		}

		m_node = GetLockCopy(GetLockCopy(m_node)->previous);
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

void CStringList::CIterator::CheckIteratorForNotExpired() const
{
	if (m_node.expired())
	{
		throw(std::runtime_error(MESSAGE_EXPIRED_ITERATOR));
	}
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

const CStringList::CIterator CStringList::cbegin() const
{
	if (m_begin)
	{
		return CStringList::CIterator(false
								, m_begin
								, this);
	}
	else
	{
		return cend();
	}
}

const  CStringList::CIterator CStringList::cend() const
{
	return CStringList::CIterator(true
								, weak_ptr<Node>()
								, this);// TODO : dublicate

}

CStringList::CIterator& CStringList::Insert(CIterator & iter, const string & data)
{
	shared_ptr<Node> newNode(new Node);
	newNode->data = data;

	if (iter.ReferToEnd())
	{
		if (m_begin)
		{
			newNode->previous = m_end;
			GetLockCopy(m_end)->next = newNode;
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
		if (GetLockCopy(iter.GetNode()).get() == m_begin.get())
		{
			PushToStart(data);
			return iter;
		}
		else
		{
			shared_ptr<Node> nextNode(GetLockCopy(iter.GetNode()));
			shared_ptr<Node> prevNode(GetLockCopy(nextNode->previous));

			newNode->previous = prevNode;
			newNode->next = nextNode;

			prevNode->next = newNode;
			nextNode->previous = newNode;
		}
	}

	m_size++;
	return iter;
}

CStringList::CIterator& CStringList::Erase(CIterator & iter)
{
	CheckListForNotEmpty();

	shared_ptr<Node> deleteNode = GetLockCopy(iter.GetNode());
	shared_ptr<Node> prevNode = GetLockCopy(deleteNode->previous);
	shared_ptr<Node> nextNode = deleteNode->next;

	m_size--;

	if (prevNode)
	{
		if (nextNode)
		{
			prevNode->next = nextNode;
			nextNode->previous = prevNode;

			return CStringList::CIterator(false, nextNode, this);
		}
		else
		{
			prevNode->next.reset();
			m_end = prevNode;

			return CStringList::CIterator(false, m_end, this);
		}
	}
	else
	{
		if (nextNode)
		{
			nextNode->previous.reset();
			m_begin = nextNode;

			return begin();
		}
		else
		{
			m_begin.reset();
			m_end.reset();
			
			return end();
		}
	}
}