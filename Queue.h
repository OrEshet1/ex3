#ifndef EX3_QUEUE_H
#define EX3_QUEUE_H

#include <iostream>
using std::string;

template<class T>
class Queue {
public:
    /*
     * C'tor of Queue Class
     */
    Queue() {
        m_size = 0;
        m_first = m_last = NULL;
    }

    /*
    * Copy C'tor of Queue class.
    *
    * @param source - reference to a Queue object.
    * @return
    *      reference to a Queue object.
    */
    Queue(const Queue &source) :
            m_size(0), m_first(NULL), m_last(NULL) {
        Element <T> *existingQueue = source.m_first;
        try{
            while (existingQueue) {
                this->pushBack(existingQueue->getData());
                existingQueue = existingQueue->getNextElement();
            }
        }
        catch (std::bad_alloc &)  //NECCESERY?
        {
            delete this;
        }
    }

    /*
    * Assignment operator of Queue class.
    *
    * @param queue - reference to a Queue object.
    * @return
    *      reference to a Queue object.
    */
    Queue& operator=(const Queue &queue)
    {
        if(this == &queue)
        {
            return *this;
        }
        Queue<T> backup = *this;
        try {
            delete this;
            Element <T> *existingElement = queue->m_first;
            while (existingElement) {
                this->pushBack(existingElement->getData())
                *existingElement = existingElement->getNextElement();
            }
        }
        catch (std::bad_alloc &) {
            delete this;
            Element <T> *oldElement = backup->m_first;
            while (oldElement) {
                this->pushBack(oldElement->getData())
                *oldElement = oldElement->getNextElement();
            }
        }
        delete backup;
        return *this;
    }

    /*
     * D'tor of Queue class.
     */
    ~Queue() {
        while (this->m_size) {
            popFront();
        }
    }


    /*
	* Inserts a new element to the end of the queue
	*
	* @param data - refernce to the new element's value.
	*
	* @return
	*      reference to the new element's value.
	*/
    void pushBack(const T &data) {
        Element <T>* newElement = new Element<T>(data);
        if (m_last) {
            m_last->setNextElement(newElement);
            m_last = newElement;
        } else {
            m_first = newElement;
            m_last = newElement;
        }
        m_size++;
    }

    /*
    * Returns queue's first element.
    *
    * @return
    *      reference to queue's first element.
    */
    T &front() const {
        if (!m_first) {
            throw Queue::EmptyQueue();
        }
        return m_first->getData();
    }

    /*
    * Pops the first element out of queue.
    */
    void popFront() {
        if (!m_first) {
            throw Queue::EmptyQueue();
        }

        Element <T> *head = m_first;
        m_first = head->getNextElement();
        delete head;
        m_size--;
    }

    /*
    * Returns queue's size.
    *
    * @return
    *      queue's elements count if it's not empty, and 0 otherwise.
    */
    int size() const {
        return m_size;
    }

    bool operator==(const Queue& other) const
    {
        Element<T>* temp = other.m_first;
        Element<T>* current = this->m_first;
        while(temp)
        {
            if(temp->getData() != current->getData())
            {
                return false;
            }
            temp = temp->getNextElement();
            current = current->getNextElement();
        }
        delete temp;
        delete current;
        return true;
    }

    bool operator!=(const Queue& other) const
    {
        return !(this == other);
    }

    class Iterator;

    /*
    * Returns the beginning of the queue
    *
    * @return
    *	   Iterator pointing to the first element of the queue
    */
    Iterator begin() {
        return Iterator(this, 0);
    }

    /*
    * Returns the end of the queue
    *
    * @return
    *	   Iterator pointing to the end of the queue
    */
    Iterator end() {
        return Iterator(this, m_size);
    }

    class ConstIterator;

    /*
    * Returns the beginning of a constant queue
    *
    * @return
    *	   Iterator pointing to the first element of the queue
    */
    ConstIterator begin() const {
        return ConstIterator(this, 0);
    }

    /*
    * Returns the end of a constant queue
    *
    * @return
    *	   Iterator pointing to the end of the queue
    */
    ConstIterator end() const
    {
        return ConstIterator(this, m_size);
    }

    class EmptyQueue {};
private:
	int m_size;
	template<class T>
	class Element;
	Element<T>* m_first;
	Element<T>* m_last;

public:
	class Iterator
	{
	public:
		/*
		* C'tor of Iterator Class
		*/
		Iterator(Queue<T>* queue, int index):
                m_queue(queue), m_index(index)
        {
        }

		/*
		* Copy C'tor of Iterator class.
		*
		* @param source - reference to a Iterator object.
		* @return
		*      reference to a Iterator object.
		*/
		Iterator(const Iterator& source):
                m_queue(source.m_queue), m_index(source.m_index)
        {
        }

		/*
		* Assignment operator of Iterator class.
		*
		* @param source - reference to an Iterator object.
		* @return
		*      reference to an Iterator object.
		*/
		Iterator& operator=(const Iterator& source)
        {
            if(this == source)
            {
                return *this;
            }
            this->m_index = source.m_index;
            this->m_queue = source.m_queue;
            return *this;
        }

		/*
		* D'tor of Iterator Class
		*/
		~Iterator() = default;

		/*
		* Dereference operator of Iterator class
		*
		* @return
		*      Reference to the value of the current iteration's queue element
		*/
		T& operator*() const
        {
            if (m_index == m_queue->size()) {
                throw InvalidOperation();
            }

            Element<T>* currentElement = m_queue->m_first;
            int index = 0;
            while (index < m_index) {
                currentElement = currentElement->getNextElement();
                ++index;
            }

            return currentElement->getData();
        }

		/*
		* Pre-increment operator of Iterator class
		*
		* @return
		*      Reference to an iterator indicating the next element of the queue
		*/
		Iterator& operator++()
        {
            if (m_index == m_queue.size()) {
                throw InvalidOperation();
            }
            ++m_index;
            return *this;
        }

		/*
		* Post-increment operator of Iterator class
		*
		* @return
		*      Reference to an iterator indicating the next element of the queue
		*/
		Iterator operator++(T)
        {
            if (m_index == m_queue.size()) {
                throw InvalidOperation();
            }

            Iterator result = *this;
            ++* this;
            return result;
        }

		/*
		* Not-Equal operator of Iterator class
		*
		* @param other - Reference to Iterator object to be compared with
		* @ return
		*      True if objects are different, False if equal
		*/
		bool operator!=(const Iterator& other) const
        {
            return this->m_index != other.m_index || this->m_queue != other.m_queue;
        }

		/*Exception thrown when there's an attempt to affect an iterator
		that has reached the end of its queue
		class InvalidOperation : public std::logic_error
		{
		public:

			* C'tor of InvalidOperation class

			InvalidOperation():
                    std::logic_error("Iterator has reached the end of the queue")
            {
            }

		};*/
        class InvalidOperation {};

	private:
        Queue<T>* m_queue;
		int m_index;
	};

	class ConstIterator
	{
	public:
		/*
		* C'tor of ConstIterator Class
		*/
		ConstIterator(const Queue<T>* queue, int index):
        m_queue(queue), m_index(index)
        {
        }

		/*
		* Copy C'tor of ConstIterator class.
		*
		* @param source - reference to a ConstIterator object.
		* @return
		*      reference to a ConstIterator object.
		*/
		ConstIterator(const ConstIterator& source) :
        m_index(source.m_index)
        {
            const Queue<T>* constQueue = source.m_queue;
            m_queue = constQueue;
        }

		/*
		* Assignment operator of ConstIterator class.
		*
		* @param source - reference to a ConstIterator object.
		* @return
		*      reference to a ConstIterator object.
		*/
		ConstIterator& operator=(const ConstIterator& source)
        {
            if(this == source)
            {
                return *this;
            }
            this->m_index = source.m_index;
            this->m_queue = source.m_queue;
            return *this;
        }

		/*
		* D'tor of Iterator Class
		*/
		~ConstIterator() = default;

		/*
		* Dereference operator of ConstIterator class
		*
		* @return
		*      Const reference to the value of the current iteration's queue element
		*/
		const T& operator*() const
        {
            if (m_index == m_queue->size()) {
                throw InvalidOperation();
            }

            Element<T>* currentElement = m_queue->m_first;
            int index = 0;
            while (index < m_index) {
                currentElement = currentElement->getNextElement();
                ++index;
            }

            return currentElement->getData();
        }

		/*
		* Pre-increment operator of ConstIterator class
		*
		* @return
		*      Reference to a ConstIterator indicating the next element of the queue
		*/
		ConstIterator& operator++()
        {
            if (m_index == m_queue->size()) {
                throw InvalidOperation();
            }
            ++m_index;
            return *this;
        }

		/*
		* Post-increment operator of ConstIterator class
		*
		* @return
		*      Reference to a ConstIterator indicating the next element of the queue
		*/
		ConstIterator operator++(T)
        {
            if (m_index == m_queue->size()) {
                throw InvalidOperation();
            }

            Iterator result = *this;
            ++* this;
            return result;
        }

		/*
		* Equality operator of ConstIterator class
		*
		* @param other - Reference to ConstIterator object to be compared with
		* @ return
		*      True if objects are equal, False if different
		*/
		bool operator==(const ConstIterator& iterator) const
        {
            return this->m_queue == iterator.m_queue && this->m_index == iterator.m_index;
        }

		/*
		* Not-Equal operator of Iterator class
		*
		* @param other - Reference to Iterator object to be compared with
		* @ return
		*      True if objects are different, False if equal
		*/
		bool operator!=(const ConstIterator& iterator) const
        {
            return !(*this == iterator);
        }

		/*Exception thrown when there's an attempt to affect a const iterator
		that has reached the end of its queue
		class InvalidOperation : public std::logic_error
		{
		public:

			* C'tor of InvalidOperation class

			InvalidOperation() :
            std::logic_error("Const-Iterator has reached the end of the queue")
            {
            }
		};*/
        class InvalidOperation {};
		friend class Queue<T>;  //IS THIS NECCESERY?

	private:
		const Queue<T>* m_queue;
		int m_index;
	};
#pragma endregion

#pragma region Exceptions

#pragma endregion

#pragma region Element
private:
	template <class T>
	/*This class represents a single element of a Queue,
	and behaves like a linked list data structure*/
	class Element
	{
	public:
		/*
		* C'tor of Element Class
		*/
		Element(const T data) : m_data(data)
		{
			m_nextElement = NULL;
		}

		/*
		* Copy C'tor of Element class.
		*
		* @param source - reference to an Element object.
		* @return
		*      reference to an Element object.
		*/
		Element(const Element& source):
        m_data(source.m_data), m_nextElement(NULL)
        {
        }

        /*
         * Function sets the next element into the given pointer
         *
         * @param newNextElement - pointer to a next Element
         */
        void setNextElement(Element<T>* newNextElement)
        {
            this->m_nextElement = newNextElement;
        }


		/*
		* Assignment operator of Element class.
		*
		* @param element - reference to an Element object.
		* @return
		*      reference to an Element object.
		*/
		Element& operator=(const Element& element) = default;

		/*
		* D'tor of Element Class
		*/
		~Element() = default;


		Element getLast()
		{
			Element<T>* last = this;
			while (last->m_nextElement) {
				last = last->m_nextElement;
			}
			return *last;
		}

		T& getData()
		{
			return m_data;
		}

		Element *getNextElement()
		{
			return m_nextElement;
		}

	private:
		T m_data;
		Element* m_nextElement;
	};
#pragma endregion
#pragma endregion
};

/*
* Creates a new queue consists of the given queue's elements that have matched the given predicate.
*
* @param originalQueue - the queue whose relevant elements are to be inserted to the new queue.
* @param predicate - the predicate the original queue's elements will be filtered by
*					(Predicate = functor that accepts an element of a queue and
*					returns true if it matches a certain condition & false if it doesn't).
*
* @return
*      reference to the new element's value.
*/
template<class T, class Predicate>
Queue<T> filter(const Queue<T> originalQueue, Predicate predicate)
{
    Queue<T> newQueue;
    for (typename Queue<T>::ConstIterator i = originalQueue.begin(); i != originalQueue.end(); ++i) {
        if (predicate(*i)) {
            newQueue.pushBack(*i);
        }
    }
    return newQueue;
}

/*
	* Transforms each element of the queue using the given operation.
	*
	* @param queue - the queue whose elements are about to get transformed.
	* @param operation - the operation that will change the given queue's elements
	*					(Operation = functor that accepts an element of a queue and changes it somehow).
	*/
template<class T, class Operation>
void transform(Queue<T>& queue, Operation operation)
{
    for (typename Queue<T>::Iterator i = queue.begin(); i != queue.end(); ++i) {
        operation(*i);
    }
}
#endif //EX3_QUEUE_H
