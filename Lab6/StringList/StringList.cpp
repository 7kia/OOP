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

std::shared_ptr<CStringList::Node> CStringList::GetUnlockCopy(const std::weak_ptr<Node>& pointer)
{
	return move(pointer.lock());
}

void CStringList::PushToEnd(const std::string & addString)
{
	m_size++;

	if (m_begin.get() == nullptr)
	{
		CreateFirstNode(addString);
	}
	else
	{
		std::shared_ptr<Node> newNode = make_shared<Node>();
		newNode->previous = m_end;
		newNode->data = addString;

		GetUnlockCopy(m_end)->next = newNode;
		m_end = newNode;
	}
}

void CStringList::PushToStart(const std::string & addString)
{
	m_size++;

	std::shared_ptr<Node> newNode = make_shared<Node>();
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
}

std::string CStringList::front() const
{
	return m_begin->data;
}

std::string CStringList::back() const
{
	return m_end.lock()->data;
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

	m_begin = newNode;

	m_begin->data = data;

	m_end = m_begin;
}

CStringList::Node::~Node()
{
}

