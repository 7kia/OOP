#include "stdafx.h"
#include "StringList.h"

using namespace std;

CStringList::CStringList()
{
}

CStringList::~CStringList()
{	
	Clear();	
}


// TODO rename on lock
std::shared_ptr<CStringList::Node> CStringList::GetLockCopy(const std::weak_ptr<Node>& pointer)
{
	return move(pointer.lock());
}

void CStringList::PushToEnd(const std::string & addString)
{
	try
	{
		if (m_begin.get() == nullptr)
		{
			CreateFirstNode(addString);
		}
		else
		{
			std::shared_ptr<Node> newNode = make_shared<Node>();
			newNode->previous = m_end;
			newNode->data = addString;

			GetLockCopy(m_end)->next = newNode;
			m_end = newNode;
		}

		m_size++;
	}
	catch (const std::bad_alloc & exception)
	{
		throw;
	}
}

void CStringList::PushToStart(const std::string & addString)
{
	try
	{
		if (m_begin.get() == nullptr)
		{
			CreateFirstNode(addString);
		}
		else
		{
			std::shared_ptr<Node> newNode = make_shared<Node>();

			newNode->next = m_begin;
			newNode->data = addString;

			m_begin->previous = newNode;

			m_begin = newNode;
		}

		m_size++;
	}
	catch (const std::bad_alloc & exception)
	{
		throw;
	}
}

std::string CStringList::front() const
{
	try
	{
		CheckListForNotEmpty();

		return m_begin->data;
	}
	catch (const std::runtime_error & exception)
	{
		throw;
	}
}

std::string CStringList::back() const
{
	try
	{
		CheckListForNotEmpty();

		return m_end.lock()->data;
	}
	catch (const std::runtime_error & exception)
	{
		throw;
	}
}

size_t CStringList::GetSize() const
{
	return m_size;
}

bool CStringList::IsEmpty() const
{
	return GetSize() == 0;
}

void CStringList::CreateFirstNode(const std::string & data)
{
	std::shared_ptr<Node> newNode = make_shared<Node>();

	newNode->data = data;

	m_begin = newNode;

	m_end = m_begin;
}

void CStringList::CheckListForNotEmpty() const
{
	if (IsEmpty())
	{
		throw runtime_error(MESSAGE_EMPTY_LIST);
	}
}

CStringList::Node::~Node()
{
}

