#include "stdafx.h"
#include "ConstStringListIterator.h"

using namespace std;

CStringList::CConstIterator::CConstIterator()
{
	m_isEnd = true;
	m_target = nullptr;

}

CStringList::CConstIterator::CConstIterator(bool isEnd
											, std::weak_ptr<Node> const & node
											, const CStringList * list)
{
	m_isEnd = isEnd;
	m_node = node;
	m_target = list;
}

CStringList::CConstIterator::~CConstIterator()
{
}

CStringList::CConstIterator & CStringList::CConstIterator::operator++()
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
}

CStringList::CConstIterator & CStringList::CConstIterator::operator--()
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

bool const operator==(const CStringList::CConstIterator & first
					, const CStringList::CConstIterator & second)
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
		return (CStringList::GetLockCopy(first.m_node).get()
			== CStringList::GetLockCopy(second.m_node).get());
	}
}

bool const operator!=(const CStringList::CConstIterator & first
					, const CStringList::CConstIterator & second)
{
	return !(first == second);
}




CNotChangeItaratorData::~CNotChangeItaratorData()
{
}

const std::string & CNotChangeItaratorData::operator*() const
{
	return CChangeItaratorData::operator*();
}

const std::string * CNotChangeItaratorData::operator->() const
{
	return CChangeItaratorData::operator->();
}


CStringList::CConstIterator CStringList::cbegin() const
{
	if (m_begin)
	{
		return CStringList::CConstIterator(false
								, m_begin
								, this);
	}
	else
	{
		return cend();
	}
}

CStringList::CConstIterator CStringList::cend() const
{
	return CStringList::CConstIterator(true
									, weak_ptr<Node>()
									, this);

}



CStringList & CStringList::operator=(const CStringList & other)
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
}