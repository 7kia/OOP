#include "stdafx.h"
#include "StringList.h"

void CStringList::Append(const std::string & addString)
{
	m_size++;
}

size_t CStringList::GetSize() const
{
	return m_size;
}
