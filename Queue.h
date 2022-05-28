#ifndef EX3_QUEUE_H
#define EX3_QUEUE_H

#include <iostream>
using std::string;

template<class T>
class Queue
{
public:
	/*
	* Type of function for filtering queues.
	* This function should accept an element of a queue and
	* reutrn true if it matches a certain condition & false if it doesn't
	*/
	typedef bool (*Predicate)(const T);

	/*
	* Type of function for transforming queues.
	* This function should accept an element of a queue and change it
	*/
	typedef void (*Operation)(T&);

	/*
	 * C'tor of Queue Class
	 */
	Queue();

	/*
	* Copy C'tor of Queue class.
	*
	* @param source - reference to a Queue object.
	* @return
	*      reference to a Queue object.
	*/
	Queue(const Queue& source);

	/*
	* Assignment operator of Queue class.
	*
	* @param queue - reference to a Queue object.
	* @return
	*      reference to a Queue object.
	*/
	Queue& operator=(const Queue& queue);

	/*
	 * D'tor of Queue class.
	 */
	~Queue();

	/*
	* Inserts a new element to the end of the queue
	*
	* @param data - refernce to the new element's value.
	*
	* @return
	*      reference to the new element's value.
	*/
	T& pushBack(const T& data);

	/*
	* Returns queue's first element.
	*
	* @return
	*      reference to queue's first element.
	*/
	T& front() const;

	/*
	* Pops the first element out of queue.
	*/
	void popFront();

	/*
	* Returns queue's size.
	*
	* @return
	*      queue's elements count if it's not empty, and 0 otherwise.
	*/
	int size() const;

	/*
	* Creates a new queue consists of the given queue's elements that have matched the given predicate.
	*
	* @param originalQueue - the queue whose relevant elements are to be inserted to the new queue.
	* @param predicate - the predicate the original queue's elements will be filtered by.

	* @return
	*      reference to the new element's value.
	*/
	static Queue filter(const Queue<T> originalQueue, Predicate predicate);

	/*
	* Transforms each element of the queue using the given operation.
	*
	* @param queue - the queue whose elements are about to get transformed.
	* @param operation - the operation that will change the given queue's elements.
	*/
	static void transform(Queue<T>& queue, Operation operation);

	class Iterator;
	/*
	* Returns the beginning of the queue
	*
	* @return
	*	   Iterator pointing to the first element of the queue
	*/
	Iterator begin();

	/*
	* Returns the end of the queue
	*
	* @return
	*	   Iterator pointing to the end of the queue
	*/
	Iterator end();

	class ConstIterator;
	/*
	* Returns the beginning of a constant queue
	*
	* @return
	*	   Iterator pointing to the first element of the queue
	*/
	ConstIterator begin() const;

	/*
	* Returns the end of a constant queue
	*
	* @return
	*	   Iterator pointing to the end of the queue
	*/
	ConstIterator end() const;

private:
	int m_size;
	template<class T>
	class Element;
	Element<T>* m_first;
	Element<T>* m_last;

#pragma region Nested Classes
#pragma region Iterators
public:
	class Iterator
	{
	public:
		/*
		* C'tor of Iterator Class
		*/
		Iterator(Queue<T>* queue, int index);

		/*
		* Copy C'tor of Iterator class.
		*
		* @param source - reference to a Iterator object.
		* @return
		*      reference to a Iterator object.
		*/
		Iterator(const Iterator& source);

		/*
		* Assignment operator of Iterator class.
		*
		* @param source - reference to an Iterator object.
		* @return
		*      reference to an Iterator object.
		*/
		Iterator& operator=(const Iterator& source);

		/*
		* D'tor of Iterator Class
		*/
		~Iterator();

		/*
		* Dereference operator of Iterator class
		*
		* @return
		*      Reference to the value of the current iteration's queue element
		*/
		T& operator*() const;

		/*
		* Pre-increment operator of Iterator class
		*
		* @return
		*      Reference to an iterator indicating the next element of the queue
		*/
		Iterator& operator++();

		/*
		* Post-increment operator of Iterator class
		*
		* @return
		*      Reference to an iterator indicating the next element of the queue
		*/
		Iterator operator++(T);

		/*
		* Equality operator of Iterator class
		*
		* @param other - Reference to Iterator object to be compared with
		* @return
		*      True if objects are equal, False if different
		*/
		bool operator==(const Iterator& other) const;

		/*
		* Not-Equal operator of Iterator class
		*
		* @param other - Reference to Iterator object to be compared with
		* @ return
		*      True if objects are different, False if equal
		*/
		bool operator!=(const Iterator& other) const;

		/*Exception thrown when there's an attempt to affect an iterator
		that has reached the end of its queue*/
		class InvalidOperation : public std::logic_error
		{
		public:
			/*
			* C'tor of InvalidOperation class
			*/
			InvalidOperation();
		};

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
		ConstIterator(const Queue<T>* queue, int index);

		/*
		* Copy C'tor of ConstIterator class.
		*
		* @param source - reference to a ConstIterator object.
		* @return
		*      reference to a ConstIterator object.
		*/
		ConstIterator(const ConstIterator& source);

		/*
		* Assignment operator of ConstIterator class.
		*
		* @param source - reference to a ConstIterator object.
		* @return
		*      reference to a ConstIterator object.
		*/
		ConstIterator& operator=(const ConstIterator& source);

		/*
		* D'tor of Iterator Class
		*/
		~ConstIterator();

		/*
		* Dereference operator of ConstIterator class
		*
		* @return
		*      Const reference to the value of the current iteration's queue element
		*/
		const T& operator*() const;

		/*
		* Pre-increment operator of ConstIterator class
		*
		* @return
		*      Reference to a ConstIterator indicating the next element of the queue
		*/
		ConstIterator& operator++();

		/*
		* Post-increment operator of ConstIterator class
		*
		* @return
		*      Reference to a ConstIterator indicating the next element of the queue
		*/
		ConstIterator operator++(T);

		/*
		* Equality operator of ConstIterator class
		*
		* @param other - Reference to ConstIterator object to be compared with
		* @ return
		*      True if objects are equal, False if different
		*/
		bool operator==(const ConstIterator& iterator) const;

		/*
		* Not-Equal operator of Iterator class
		*
		* @param other - Reference to Iterator object to be compared with
		* @ return
		*      True if objects are different, False if equal
		*/
		bool operator!=(const ConstIterator& iterator) const;

		/*Exception thrown when there's an attempt to affect a const iterator
		that has reached the end of its queue*/
		class InvalidOperation : public std::logic_error
		{
		public:
			/*
			* C'tor of InvalidOperation class
			*/
			InvalidOperation();
		};

		friend class Queue<T>;

	private:
		const Queue<T>* m_queue;
		int m_index;
	};
#pragma endregion

#pragma region Exceptions
	/*Exception thrown when there's an attempt to affect an empty queue*/
	class EmptyQueue : public std::logic_error
	{
	public:
		/*
		* C'tor of EmptyQueue class
		*/
		EmptyQueue(const string& what);
	};
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
		Element(const T& data) : m_data(data)
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
		Element(const Element& source) : m_data(source.m_data), m_nextElement(source.m_nextElement)
		{
			*this = Element<T>(source.m_data);
			Element<T>* current = this;
			Element<T> temp = source;
			while (&temp) {
				current->getNextElement() = Element<T>(temp.m_data);
				current = current->m_nextElement;
				temp = temp.getNextElement();
			}
		}

		/*
		* Assignment operator of Element class.
		*
		* @param element - reference to an Element object.
		* @return
		*      reference to an Element object.
		*/
		Element& operator=(const Element& element)
		{
			m_data = element.m_data;
			m_nextElement = element.m_nextElement;
			return *this;
		}

		/*
		* D'tor of Element Class
		*/
		~Element()
		{
			Element* toDelete = this;
			while (toDelete) {
				Element* next = toDelete->m_nextElement;
				delete toDelete;
				toDelete = next;
			}
		}

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

		Element getNextElement()
		{
			return *m_nextElement;
		}

	private:
		T m_data;
		Element* m_nextElement;
	};
#pragma endregion
#pragma endregion
};
#endif //EX3_QUEUE_H
