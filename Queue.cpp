#include "Queue.h"

#pragma region Queue<T>
template <class T>
Queue<T>::Queue()
{
	m_size = 0;
	m_first = m_last = NULL;
}

template<class T>
Queue<T>::Queue(const Queue& source) :
	m_size(source.m_size)
{
	*m_first = Element<T>(*(source.m_first));
	*m_last = m_first->getLast();
}

template<class T>
Queue<T>& Queue<T>::operator=(const Queue& queue)
{
	this->m_size = queue.m_size;
	this->m_first = queue.m_first;
	this->m_last = queue.m_last;
	return *this;
}

template <class T>
Queue<T>::~Queue()
{
	delete m_first;
}

template <class T>
T& Queue<T>::pushBack(const T& data)
{
	Element<T> newElement = Element<T>(data);
	if (m_last) {
		m_last->getNextElement() = newElement;
	}
	else {
		if (m_first) {
			m_first->getNextElement() = newElement;
		}
		else {
			*m_first = newElement;
		}
	}

	*m_last = newElement;
	m_size++;
	return newElement.getData();
}

template <class T>
T& Queue<T>::front() const
{
	if (!m_first) {
		throw Queue<T>::EmptyQueue("Can't return an element of an empty queue");
	}

	return m_first->getData();
}

template <class T>
void Queue<T>::popFront()
{
	if (!m_first) {
		throw Queue<T>::EmptyQueue("Can't pop out the first element of an empty queue");
	}

	Element<T>* head = m_first;
	*m_first = head->getNextElement();
	delete head;
	m_size--;
}

template <class T>
int Queue<T>::size() const
{
	return m_size;
}

template <class T>
Queue<T> Queue<T>::filter(const Queue<T> originalQueue, Queue<T>::Predicate predicate)
{
	Queue<T> newQueue;
	for (Queue<T>::ConstIterator i = originalQueue.begin(); i != originalQueue.end(); ++i) {
		if (predicate(*i)) {
			newQueue.pushBack(*i);
		}
	}

	return newQueue;
}

template<class T>
void Queue<T>::transform(Queue<T>& queue, Operation operation)
{
	for (Queue<T>::Iterator i = queue.begin(); i != queue.end(); ++i) {
		operation(*i);
	}
}

template<class T>
typename Queue<T>::Iterator Queue<T>::begin()
{
	return Iterator(this, 0);
}

template<class T>
typename Queue<T>::Iterator Queue<T>::end()
{
	return Iterator(this, m_size);
}

template<class T>
typename Queue<T>::ConstIterator Queue<T>::begin() const
{
	return ConstIterator(this, 0);
}

template<class T>
typename Queue<T>::ConstIterator Queue<T>::end() const
{
	return ConstIterator(this, m_size);
}
#pragma endregion

#pragma region Iterator
template<class T>
Queue<T>::Iterator::Iterator(Queue<T>* queue, int index) : m_queue(queue), m_index(index)
{
}

template<class T>
Queue<T>::Iterator::Iterator(const Iterator& source) :
	m_queue(Queue<T>(source.m_queue)), m_index(source.m_index)
{
}

template<class T>
typename Queue<T>::Iterator& Queue<T>::Iterator::operator=(const Iterator& source)
{
	this->m_index = source.m_index;
	this->m_queue = source.m_queue;
	return *this;
}

template<class T>
Queue<T>::Iterator::~Iterator()
{
}

template<class T>
typename T& Queue<T>::Iterator::operator*() const
{
	if (m_index == m_queue->size()) {
		throw Queue<T>::Iterator::InvalidOperation();
	}

	Queue<T>* temp = m_queue;
	int index = 0;
	while (index < m_index) {
		temp->popFront();
		++index;
	}

	return temp->front();
}

template<class T>
typename Queue<T>::Iterator& Queue<T>::Iterator::operator++()
{
	if (m_index == m_queue->size()) {
		throw Queue<T>::Iterator::InvalidOperation();
	}
	++m_index;
	return *this;
}

template<class T>
typename Queue<T>::Iterator Queue<T>::Iterator::operator++(T)
{
	if (m_index == m_queue->size()) {
		throw Queue<T>::Iterator::InvalidOperation();
	}

	Iterator result = *this;
	++* this;
	return result;
}

template<class T>
typename bool Queue<T>::Iterator::operator==(const Iterator& other) const
{
	return this->m_queue == other.m_queue && this->m_index == other.m_index;
}

template<class T>
typename bool Queue<T>::Iterator::operator!=(const Iterator& other) const
{
	return !(*this == other);
}

template<class T>
Queue<T>::Iterator::InvalidOperation::InvalidOperation() :
	std::logic_error("Iterator has reached the end of the queue")
{
}
#pragma endregion

#pragma region Const Iterator
template<class T>
Queue<T>::ConstIterator::ConstIterator(const Queue<T>* queue, int index) : m_queue(queue), m_index(index)
{
}

template<class T>
Queue<T>::ConstIterator::ConstIterator(const ConstIterator& source) :
	m_queue(Queue<T>(source.m_queue)), m_index(source.m_index)
{
}

template<class T>
typename Queue<T>::ConstIterator& Queue<T>::ConstIterator::operator=(const ConstIterator& source)
{
	this->m_index = source.m_index;
	this->m_queue = source.m_queue;
	return *this;
}

template<class T>
typename const T& Queue<T>::ConstIterator::operator*() const
{
	if (m_index == m_queue->size()) {
		throw Queue<T>::Iterator::InvalidOperation();
	}

	Element<T>* currentElement = m_queue->m_first;
	int index = 0;
	while (index < m_index) {
		*currentElement = currentElement->getNextElement();
		++index;
	}

	return currentElement->getData();
}

template<class T>
typename Queue<T>::ConstIterator& Queue<T>::ConstIterator::operator++()
{
	if (m_index == m_queue->size()) {
		throw Queue<T>::Iterator::InvalidOperation();
	}
	++m_index;
	return *this;
}

template<class T>
typename Queue<T>::ConstIterator Queue<T>::ConstIterator::operator++(T)
{
	if (m_index == m_queue->size()) {
		throw Queue<T>::Iterator::InvalidOperation();
	}

	Iterator result = *this;
	++* this;
	return result;
}

template<class T>
bool Queue<T>::ConstIterator::operator==(const ConstIterator& iterator) const
{
	return this->m_queue == iterator.m_queue && this->m_index == iterator.m_index;
}

template<class T>
bool Queue<T>::ConstIterator::operator!=(const Queue<T>::ConstIterator& iterator) const
{
	return !(*this == iterator);
}

template<class T>
Queue<T>::ConstIterator::~ConstIterator()
{
}

template<class T>
Queue<T>::ConstIterator::InvalidOperation::InvalidOperation() :
	std::logic_error("Const-Iterator has reached the end of the queue")
{
}
#pragma endregion

#pragma region Empty Queue Exception
template<class T>
Queue<T>::EmptyQueue::EmptyQueue(const string& what) : std::logic_error(what)
{
}
#pragma endregion
