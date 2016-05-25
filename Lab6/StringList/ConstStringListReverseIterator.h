#include "stdafx.h"
#include "ConstStringListReverseIteratorInit.h"

using namespace std;

template<typename T>
CStringList<T>::CConstReverseIterator::CConstReverseIterator()
{
	m_isEnd = true;
	m_target = nullptr;
}

template<typename T>
CStringList<T>::CConstReverseIterator::CConstReverseIterator(bool isEnd
	, const std::weak_ptr<CStringLits<T>::Node> & node
	, const CStringList<T> * list)
{
	m_isEnd = isEnd;
	m_node = node;
	m_target = list;
}

template<typename T>
CStringList<T>::CConstReverseIterator & CStringList<T>::CConstReverseIterator::operator++()
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
CStringList<T>::CConstReverseIterator & CStringList<T>::CConstReverseIterator::operator--()
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
bool const operator==(const CStringList<T>::CConstReverseIterator & first
						, const CStringList<T>::CConstReverseIterator & second)
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
}

template<typename T>
bool const operator!=(const CStringList<T>::CConstReverseIterator & first
						, const CStringList<T>::CConstReverseIterator & second)
{
	return dynamic_cast<const CIteratorData<T>*>(&first) != dynamic_cast<const CIteratorData<T>*>(&second);
}

template<typename T>
CStringList<T>::CConstReverseIterator CStringList<T>::crbegin() const
{
	if (m_begin)
	{
		return CStringList<T>::CConstReverseIterator(false
			, m_end
			, this);
	}
	else
	{
		return crend();

	}
}

template<typename T>
CStringList<T>::CConstReverseIterator CStringList<T>::crend() const
{
	return CStringList<T>::CConstReverseIterator(true
		, weak_ptr<CStrinList<T>::Node>()
		, this);
}
