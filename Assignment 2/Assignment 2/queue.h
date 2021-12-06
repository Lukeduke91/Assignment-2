#pragma once
#include "LinkedList.h"

template<class T>
class PriorityQueue
{
public:
	PriorityQueue(int size)
	{
		assert(size > 0);
		m_size = size;
	}
	~PriorityQueue() {}

	void push(T val, int pri)
	{
		assert(m_elements.GetSize() < m_size);

		if (m_elements.GetSize() == 0)
		{
			m_elements.Push(val, pri);
		}
		else
		{
			LinkIterator<T> it;
			it = m_elements.Begin();

			while (it.isValid())
			{
				if (val < *it && pri < *it)
				{
					break;
				}
				it++;
			}

			if (it.isValid())
			{
				m_elements.Insert_Before(it, val, pri);
			}
			else
			{
				m_elements.Push(val, pri);
			}
		}
	}
	void pop()
	{
		m_elements.Pop_Front();
	}

	T& front()
	{
		LinkIterator<T> it;
		it = m_elements.Begin();

		return *it;
	}

	T& back()
	{
		LinkIterator<T> it;
		it = m_elements.Last();

		return *it;
	}

	int GetSize()
	{
		return m_elements.GetSize();
	}

	int GetMaxSize()
	{
		return m_size;
	}

	

	bool isEmpty()
	{
		return (m_elements.GetSize() == 0);
	}

	void Resize(int size)
	{
		assert(size > 0);
		m_size = size;
	}

private:
	LinkList<T> m_elements;
	int m_size; 
	LinkList<T> m_priority;
};