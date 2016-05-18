#pragma once

#include <list>

#include <string>
#include <boost/algorithm/string.hpp>

class CStringList
{
public:
	CStringList();
	~CStringList();

	struct Node
	{
		~Node();// For debug
		std::weak_ptr<Node>		previous;
		std::shared_ptr<Node>	next;

		std::string				data;
	};
	class CIterator;
	class CReverseIterator;

public:
	static std::shared_ptr<Node> GetUnlockCopy(const std::weak_ptr<Node> & pointer);

	void						PushToEnd(const std::string & addString);// TODO : rename
	void						PushToStart(const std::string & addString);// TODO : rename

	std::string					front() const;
	std::string					back() const;

	CIterator					begin();
	CIterator					end();
	const CIterator				begin() const;
	const CIterator				end() const;

	void						Insert(const CIterator & iter
										, const std::string & data);
	void						Remove(const CIterator & iter);

	CReverseIterator			rbegin();
	CReverseIterator			rend();
	const CReverseIterator		rbegin() const;
	const CReverseIterator		rend() const;


	size_t						GetSize() const;
	bool						IsEmpty() const;

	void						Clear();// TODO

private:
	void						CreateFirstNode(const std::string & data);
private:
	size_t						m_size = 0;

	std::shared_ptr<Node>		m_begin;
	std::weak_ptr<Node>			m_end;

};