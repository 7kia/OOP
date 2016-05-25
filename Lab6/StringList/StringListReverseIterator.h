#include "stdafx.h"
#include "StringListReverseIteratorInit.h"

using namespace std;

template<typename T>
CStringList<T>::CReverseIterator::CReverseIterator()
{
	m_isEnd = true;
	m_target = nullptr;
}

template<typename T>
CStringList<T>::CReverseIterator::CReverseIterator(bool isEnd
	, const std::weak_ptr<CStringList<T>::Node> & node
	, CStringList<T> * list)
{
	m_isEnd = isEnd;
	m_node = node;
	m_target = list;
}

/*
CStringList<T>::CReverseIterator::~CReverseIterator()
{
}
*/

template<typename T>
CStringList<T>::CReverseIterator & CStringList<T>::CReverseIterator::operator++()
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

template<typename T>
CStringList<T>::CReverseIterator & CStringList<T>::CReverseIterator::operator--()
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

template<typename T>
CStringList<T>::CReverseIterator CStringList<T>::rbegin()
{
	if (m_begin)
	{
		return CStringList<T>::CReverseIterator(false
											, m_end
											, this);
	}
	else
	{
		return rend();

	}
}

template<typename T>
CStringList<T>::CReverseIterator CStringList<T>::rend()
{
	return CStringList<T>::CReverseIterator(true
		, weak_ptr<CStringList<T>::Node>()
		, this);
}

template<typename T>
bool const operator==(const CStringList<T>::CReverseIterator & first
					, const CStringList<T>::CReverseIterator & second)
{
	return dynamic_cast<const CIteratorData*>(&first) == dynamic_cast<const CIteratorData*>(&second);
}

template<typename T>
bool const operator!=(const CStringList<T>::CReverseIterator & first
					, const CStringList<T>::CReverseIterator & second)
{
	return dynamic_cast<const CIteratorData*>(&first) != dynamic_cast<const CIteratorData*>(&second);
}