#pragma once

#include "stdafx.h"
#include "ConstStringListIteratorInit.h"

using namespace std;

template<typename T>
CStringList<T>::CConstIterator::CConstIterator()
{
	m_isEnd = true;
	m_target = nullptr;

};

template<typename T>
CStringList<T>::CConstIterator::CConstIterator(bool isEnd
											, std::weak_ptr<Node> const & node
											, const CStringList * list)
{
	m_isEnd = isEnd;
	m_node = node;
	m_target = list;
};

template<typename T>
CStringList<T>::CConstIterator::~CConstIterator()
{
};

template<typename T>
CStringList<T>::CConstIterator & CStringList<T>::CConstIterator::operator++()
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
CStringList<T>::CConstIterator & CStringList<T>::CConstIterator::operator--()
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
bool const operator==(const CStringList<T>::CConstIterator & first
					, const CStringList<T>::CConstIterator & second)
{
	//return *dynamic_cast<const CIteratorData*>(&first) == *dynamic_cast<const CIteratorData*>(&second);
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
bool const operator!=(const CStringList<T>::CConstIterator & first
					, const CStringList<T>::CConstIterator & second)
{
	return !(first == second);
};



template<typename T>
CNotChangeItaratorData<T>::~CNotChangeItaratorData()
{
};

template<typename T>
const std::string & CNotChangeItaratorData<T>::operator*() const
{
	return CChangeItaratorData<T>::operator*();
};

template<typename T>
const std::string * CNotChangeItaratorData<T>::operator->() const
{
	return CChangeItaratorData<T>::operator->();
};

template<typename T>
CStringList<T>::CConstIterator CStringList<T>::cbegin() const
{
	if (m_begin)
	{
		return CStringList<T>::CConstIterator(false
								, m_begin
								, this);
	}
	else
	{
		return cend();
	}
};

template<typename T>
CStringList<T>::CConstIterator CStringList<T>::cend() const
{
	return CStringList<T>::CConstIterator(true
									, weak_ptr<Node>()
									, this);

};


template<typename T>
CStringList<T> & CStringList<T>::operator=(const CStringList & other)
{
	if (this != &other)
	{
		Clear();

		for (auto iter = other.cbegin(); iter != other.cend(); ++iter)
		{
			//*iter = "sd"; // проверка что нельзя изменить содержимое const итератора

			//auto it = begin();
			//*it = "sd";// проверка что можно изменить содержимое обычного итератора
			PushToEnd(*iter);
		}
	}

	return *this;
};