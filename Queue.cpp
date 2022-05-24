#include "Queue.h"

template <class T>
Queue<T>::Queue()
{
	m_size = 0;
	m_first = m_last = NULL;
}

template <class T>
Queue<T>::~Queue()
{
	delete m_first;
}

template <class T>
T& Queue<T>::pushBack(const T& data)
{
	Node<T> newNode = Node<T>(data);
	if (m_last) {
		m_last.m_next = newNode;
	}
	else {
		if (m_first) {
			m_first.m_next = newNode;
		}
		else {
			m_first = newNode;
		}
	}

	m_last = newNode;
	m_size++;
	return newNode;
}

template <class T>
T& Queue<T>::front() const
{
	if (m_last) {
		return m_first.m_data;
	}

	throw Queue<T>::EmptyQueue("Can't return the first element of an empty queue");
}

template <class T>
void Queue<T>::popFront()
{
	if (m_first) {
		Node<T> head = m_first;
		m_first = head.m_next;
		delete head;
		m_size--;
	}

	throw Queue<T>::EmptyQueue("Can't pop out the first element of an empty queue");
}

template <class T>
int Queue<T>::size() const
{
	return m_size;
}

template <class T>
static Queue<T> Queue<T>::filter(const Queue<T> originalQueue, Predicate predicate)
{
	Queue<T> newQueue;
	/*TODO: Implement an iterator*/
	//for (Queue<T>::Iterator i = originalQueue.begin(); i != originalQueue.end(); ++i) {
	if (predicate(/*i*/)) {
		newQueue.pushBack(/*i*/);
	}
	//}

	return newQueue;
}

template<class T>
static void Queue<T>::transform(Queue& queue, Operation operation)
{
	/*TODO: Implement an iterator*/
	//for (Queue<T>::Iterator i = queue.begin(); i != queue.end(); ++i) {
	operation(/*i*/);
	//}
}



