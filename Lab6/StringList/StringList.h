﻿#include "stdafx.h"
#include "StringListInit.h"

using namespace std;

template<typename T>
CStringList<T>::CStringList<T>()
{
}

template<typename T>
CStringList<T>::~CStringList<T>()
{	
	Clear();	
}


// TODO rename on lock
template<typename T>
std::shared_ptr<CStringList<T>::Node> CStringList::GetLockCopy(const std::weak_ptr<CStringList<T>::Node>& pointer)
{
	return move(pointer.lock());
}

template<typename T>
void CStringList<T>::PushToEnd(const T & addString)
{
	try
	{
		if (m_begin.get() == nullptr)
		{
			CreateFirstNode(addString);
		}
		else
		{
			std::shared_ptr<CStringList<T>::Node> newNode = make_shared<CStringList<T>::Node>();
			newNode->previous = m_end;
			newNode->data = addString;

			GetLockCopy(m_end)->next = newNode;
			m_end = newNode;
		}

		m_size++;
	}
	catch (...)//(const std::bad_alloc & exception)
	{
		throw;
	}
}

template<typename T>
void CStringList<T>::PushToStart(const T & addString)
{
	try
	{
		if (m_begin.get() == nullptr)
		{
			CreateFirstNode(addString);
		}
		else
		{
			std::shared_ptr<CStringList<T>::Node> newNode = make_shared<CStringList<T>::Node>();

			newNode->next = m_begin;
			newNode->data = addString;

			m_begin->previous = newNode;

			m_begin = newNode;
		}

		m_size++;
	}
	catch (...)//(const std::bad_alloc & exception)
	{
		throw;
	}
}

template<typename T>
T CStringList<T>::front() const
{
	try
	{
		CheckListForNotEmpty();

		return m_begin->data;
	}
	catch (...)//(const std::runtime_error & exception)
	{
		throw;
	}
}

template<typename T>
T CStringList<T>::back() const
{
	try
	{
		CheckListForNotEmpty();

		return m_end.lock()->data;
	}
	catch (...)//(const std::runtime_error & exception)
	{
		throw;
	}
}

template<typename T>
size_t CStringList<T>::GetSize() const
{
	return m_size;
}

template<typename T>
bool CStringList<T>::IsEmpty() const
{
	return GetSize() == 0;
}

template<typename T>
void CStringList<T>::CreateFirstNode(const T & data)
{
	std::shared_ptr<CStringList<T>::Node> newNode = make_shared<CStringList<T>::Node>();

	newNode->data = data;

	m_begin = newNode;

	m_end = m_begin;
}

template<typename T>
void CStringList<T>::CheckListForNotEmpty() const
{
	if (IsEmpty())
	{
		throw runtime_error(MESSAGE_EMPTY_LIST);
	}
}

template<typename T>
CStringList<T>::Node::~Node()
{
}

