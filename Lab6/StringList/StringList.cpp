#include "stdafx.h"
#include "StringList.h"

using namespace std;

CStringList::CStringList()
{
}

CStringList::~CStringList()
{
	/*
		Node *deleteNode = m_begin.get();

	if (deleteNode != nullptr)
	{
		while (deleteNode->next != nullptr)
		{
			deleteNode->next->previous = nullptr;

			deleteNode = deleteNode->next.get();
		}
	}
	*/
	// TODO : rewrite with using iterators

	
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

		// last->next = newNode
		newNode->previous = m_end;
		newNode->data = addString;


		m_end.lock()->next = newNode;


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

		// last->next = newNode
		newNode->next = m_begin;
		newNode->data = addString;


		m_begin->previous = newNode;


		m_begin = newNode;
	}
}

std::string CStringList::front()
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
