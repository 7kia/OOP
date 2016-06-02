#pragma once

#include <list>

#include <string>
#include <boost/algorithm/string.hpp>

static const std::string MESSAGE_EMPTY_LIST = "List is empty.";
static const std::string MESSAGE_EXPIRED_ITERATOR = "Iterator is expired.";
static const std::string MESSAGE_ITERATOR_HAS_NOT_INCREMENTABLE = "Iterator has not incrementable.";
static const std::string MESSAGE_ITERATOR_HAS_NOT_DECREMENTABLE = "Iterator has not decrementable.";
static const std::string MESSAGE_REVERSE_ITERATOR_HAS_NOT_INCREMENTABLE = "Reverse iterator has not incrementable.";
static const std::string MESSAGE_REVERSE_ITERATOR_HAS_NOT_DECREMENTABLE = "Reverse iterator has not decrementable.";


class CStringList
{
public:
	CStringList();
	~CStringList();

	CStringList& operator=(const CStringList &other);

	struct Node
	{
		~Node();// For debug
		std::weak_ptr<Node>		previous;
		std::shared_ptr<Node>	next;

		std::string				data;
	};
	class CIterator;
	class CConstIterator;
	class CReverseIterator;
	class CConstReverseIterator;

public:
	static std::shared_ptr<Node> GetLockCopy(const std::weak_ptr<Node> & pointer);

	void						PushToEnd(const std::string & addString);// TODO : rename
	void						PushToStart(const std::string & addString);// TODO : rename

	std::string					front() const;
	std::string					back() const;

	CIterator					begin();
	CIterator					end();
	const CIterator				cbegin() const ;// TODO : const iterator
	const CIterator				cend() const;

	CStringList::CIterator&		Insert(CIterator & iter
										, const std::string & data);
	CStringList::CIterator&		Erase(CIterator & iter);

	CReverseIterator			rbegin();
	CReverseIterator			rend();
	const CReverseIterator		rbegin() const;// TODO : reverse const iterator
	const CReverseIterator		rend() const;


	size_t						GetSize() const;
	bool						IsEmpty() const;

	void						Clear();

private:
	void						CreateFirstNode(const std::string & data);
	void						CheckListForNotEmpty() const;
private:
	size_t						m_size = 0;

	std::shared_ptr<Node>		m_begin;
	std::weak_ptr<Node>			m_end;

};