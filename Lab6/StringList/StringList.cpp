#include "stdafx.h"
#include "StringList.h"

using namespace std;

CStringList::CStringList()
{
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
		newNode->previous = m_end.get();
		newNode->data;

		m_end = newNode;
	}
}

std::string CStringList::GetStartElement()
{
	return m_begin->data;
}

std::string CStringList::back() const
{
	return m_end->data;
}

size_t CStringList::GetSize() const
{
	return m_size;
}
