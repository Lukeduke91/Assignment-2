#pragma once
#include <cassert>
template<class T> class LinkIterator;
template<class T> class LinkList;

template<class T>
class LinkNode
{
public:
	friend class LinkIterator<T>;
	friend class LinkList<T>;
private:
	LinkNode() :m_next(0), m_previous(0)
	{

	}

	int priority;
	T m_data;
	LinkNode *m_next;
	LinkNode *m_previous;
};

template<class T>
class LinkIterator
{
public:

	friend class LinkList<T>;

	LinkIterator()
	{
		m_node = nullptr;
	}

	~LinkIterator()
	{}

	void operator--()
	{
		assert(m_node != nullptr);
		m_node = m_node->m_previous;
	}

	void operator--(int)
	{
		assert(m_node != nullptr);
		m_node = m_node->m_previous;
	}

	void operator=(LinkNode<T>* node)
	{
		m_node = node;
	}

	T &operator* ()
	{
		assert(m_node != nullptr);
		return m_node->m_data;
	}

	void operator++()
	{
		assert(m_node != nullptr);
		m_node = m_node->m_next;
	}

	void operator++(int)
	{
		assert(m_node != nullptr);
		m_node = m_node->m_next;
	}

	bool operator!=(LinkNode<T> *node)
	{
		return (m_node != node);
	}

	bool operator==(LinkNode<T> *node)
	{
		return (m_node == node);
	}

	bool isValid()
	{
		return (m_node != nullptr);
	}

private:
	LinkNode<T> *m_node;
};

template<class T>
class LinkList
{
public:
	LinkList() : m_size(0), m_root(nullptr), m_lastNode(nullptr) {}
	~LinkList()
	{
		while (m_root)
		{
			Pop();
		}
	}

	LinkNode<T>* Begin()
	{
		assert(m_root != nullptr);
		return m_root;
	}

	LinkNode<T>* End()
	{
		return nullptr;
	}

	LinkNode<T>* Last()
	{
		assert(m_lastNode != nullptr);
		return m_lastNode;
	}

	void Insert_Before(LinkIterator<T>& it, T newData, int newPriority)
	{
		assert(it.m_node != nullptr);

		LinkNode<T>* node = new LinkNode<T>;
		assert(node != nullptr);
		//priority here
		node->m_data = newData;
		node->priority = newPriority;
		node->m_next = it.m_node;
		node->m_previous = it.m_node->m_previous;

		if (node->m_previous != nullptr)
		{
			node->m_previous->m_next = node;
		}

		it.m_node->m_previous = node;

		if (it.m_node == m_root)
		{
			m_root = node;
		}

		m_size++;
	}

	void Push_Front(T newData, int newPriority)
	{
		LinkNode<T>* node = new LinkNode<T>;

		assert(node != nullptr);
		//priority here
		node->m_data = newData;
		node->priority = newPriority;
		node->m_next = nullptr;
		node->m_previous = nullptr;

		if (m_root != nullptr)
		{
			node->m_next = m_root;
			m_root->m_previous = node;
			m_root = node;
		}

		else
		{
			m_root = node;
			m_lastNode = node;
		}

		m_size++;
	}

	void Pop_Front()
	{
		assert(m_root != nullptr);

		LinkNode<T> *temp = m_root;

		m_root = m_root->m_next;

		if (m_root != nullptr)
		{
			m_root->m_previous = nullptr;
		}
		else
		{
			m_lastNode = nullptr;
		}
		
		delete temp;
		temp = nullptr;

		m_size = (m_size == 0 ? m_size : m_size - 1);
	}

	void Push(T newData, int newPriority)
	{
		LinkNode<T> *node = new LinkNode<T>;

		assert(node != nullptr);
		//priority here
		node->m_data = newData;
		node->priority = newPriority;
		node->m_next = nullptr;
		node->m_previous = nullptr;

		if (m_lastNode != nullptr)
		{
			m_lastNode->m_next = node;
			node->m_previous = m_lastNode;
		}
		else
		{
			m_root = node;
		}

		m_lastNode = node;
		m_size++;
	}

	void Pop()
	{
		assert(m_root != nullptr);

		if (m_root->m_next == nullptr)
		{
			delete m_root;
			m_root = nullptr;
			m_lastNode = nullptr;
		}
		else
		{
			LinkNode<T> *prevNode = m_lastNode->m_previous;

			prevNode->m_next = nullptr;
			delete m_lastNode;
			m_lastNode = prevNode;
			prevNode = nullptr;
		}

		m_size = (m_size == 0 ? m_size : m_size - 1);
	}

	int GetSize()
	{
		return m_size;
	}

private:
	int m_size;
	LinkNode<T>* m_root;
	LinkNode<T>* m_lastNode;
};

