#pragma once

#include "stdafx.h"
#include "StringList.h"
#include "ConstStringListIterator.h"
#include "ConstStringListReverseIterator.h"

using namespace std;

template<typename T>
CStringList<T>::CIterator::CIterator()
{
	m_isEnd = true;
	m_target = nullptr;
};

template<typename T>
CStringList<T>::CIterator::CIterator(bool isEnd
								, const weak_ptr<Node> & node
								, CStringList * list)
{
	m_isEnd = isEnd;
	m_node = node;
	m_target = list;
};

template<typename T>
CStringList<T>::CIterator::~CIterator()
{
};

template<typename T>
void CStringList<T>::Clear()
{
	CStringList<T>::CIterator iter = begin();
	while(iter != end())
	{
		Erase(iter);
		iter = begin();
	}
};

template<typename T>
bool const operator==(const CIteratorData<T> & first, const CIteratorData<T> & second)
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
		return (CStringList<T>::GetLockCopy(first.m_node).get()
			== CStringList<T>::GetLockCopy(second.m_node).get());
	}
};

template<typename T>
bool const operator!=(const CIteratorData<T> & first
					, const CIteratorData<T> & second)
{
	return !(first == second);
};

template<typename T>
bool const operator==(const CStringList<T>::CIterator & first
					, const CStringList<T>::CIterator & second)
{
	return *dynamic_cast<const CIteratorData<T>*>(&first) == *dynamic_cast<const CIteratorData<T>*>(&second);
};

template<typename T>
bool const operator!=(const CStringList<T>::CIterator & first
					, const CStringList<T>::CIterator & second)
{
	return *dynamic_cast<const CIteratorData<T><T>*>(&first) != *dynamic_cast<const CIteratorData<T><T>*>(&second);
};
//	return !(dynamic_cast<const CIteratorData<T>*>(&first) == dynamic_cast<const CIteratorData<T>*>(&second));

template<typename T>
string& CChangeItaratorData<T>::operator*() const
{
	try
	{
		CheckIteratorForNotExpired();

		return CStringList<T>::GetLockCopy(m_node)->data;
	}
	catch (...)//(const std::runtime_error & exception)
	{
		throw;
	}
};


template<typename T>
string* CChangeItaratorData<T>::operator->() const
{
	try
	{
		assert(!m_isEnd);
		CheckIteratorForNotExpired();

		return &(*(*this));
	}
	catch (...)//(const std::runtime_error & exception)
	{
		throw;
	}
};

template<typename T>
CStringList<T>::CIterator& CStringList<T>::CIterator<T>::operator++()
{
	try
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
	catch (...)//(const std::runtime_error & exception)
	{
		throw;
	}
};


template<typename T>
CStringList<T>::CIterator& CStringList<T>::CIterator::operator--()
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
};


template<typename T>
weak_ptr<CStringList<T>::Node> CIteratorData<T>::GetNode() const
{
	return m_node;
};

template<typename T>
bool const CIteratorData<T>::ReferToEnd() const
{
	return m_isEnd;
};

template<typename T>
void CIteratorData<T>::CheckIteratorForNotExpired() const
{
	if (m_node.expired())
	{
		throw(std::runtime_error(MESSAGE_EXPIRED_ITERATOR));
	}
};


template<typename T>
CStringList<T>::CIterator CStringList<T>::begin()
{
	if (m_begin)
	{
		return CStringList<T>::CIterator(false
									, m_begin
									, this);
	}
	else
	{
		return end();
	}
};

template<typename T>
CStringList<T>::CIterator CStringList<T>::end()
{
	return CStringList<T>::CIterator(true
								, weak_ptr<Node>()
								, this);
};

template<typename T>
CStringList<T>::CIterator& CStringList<T>::Insert(CIterator & iter, const string & data)
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
	catch (...)//(const std::bad_alloc & exception)
	{
		throw;
	}
};

template<typename T>
void CStringList<T>::Erase(CIterator & iter)
{
	try
	{
		CheckListForNotEmpty();

		shared_ptr<Node> deleteNode = GetLockCopy(iter.GetNode());
		shared_ptr<Node> prevNode = GetLockCopy(deleteNode->previous);
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
		//return iter;
	}
	catch (...)//(const std::bad_alloc & exception)
	{
		throw;
	}
	// (const std::runtime_error & exception)

};