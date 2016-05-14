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

void CStringList::Append(const std::string & addString)
{
	m_size++;

	std::shared_ptr<Node> newNode = make_shared<Node>();
	if (m_begin.get() == nullptr)
	{
		m_begin = newNode;

		m_begin->data = addString;

		m_end = m_begin;
	}
	else
	{
		// last->next = newNode
		newNode->previous = m_end;
		newNode->data = addString;


		m_end.lock()->next = newNode;


		m_end = newNode;
	}
}

std::string CStringList::GetStartElement()
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
