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
	typedef bool (*Predicate)(const T&);

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
	 * D'tor of Queue class.
	 */
	~Queue();

	/*
	* Assignment operator of Queue class.
	*
	* @param queue - reference to a Queue object.
	* @return
	*      reference to a Queue object.
	*/
	Queue& operator=(const Queue& queue) = default;

	/*
	* Copy C'tor of Queue class.
	*
	* @param mtmchkin - reference to a Queue object.
	* @return
	*      reference to a Queue object.
	*/
	Queue(const Queue& queue) = default;

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
	static void transform(Queue& queue, Operation operation);

#pragma region Nested Classes

#pragma region Iterators
	class Iterator
	{
		//TODO: Complete class & implement its functions within this file

		class InvalidOperation : public std::logic_error
		{
		public:
			InvalidOperation() :
				std::logic_error("Iterator has reached the end of the queue")
			{}
		};
	};

	class ConstIterator
	{
		//TODO: Complete class & implement its functions within this file
	};
#pragma endregion

#pragma region Exceptions
	class EmptyQueue : public std::logic_error
	{
	public:
		EmptyQueue(const string& what) : std::logic_error(what)
		{}
	};
#pragma endregion

#pragma endregion

private:
#pragma region Node
	template <class T>
	class Node
	{
	public:
		/*
		* C'tor of Node Class
		*/
		Node(T data) : m_data(data)
		{
			m_next = NULL;
		}

		/*
		* D'tor of Node Class
		*/
		~Node()
		{
			Node* toDelete = this;
			while (toDelete) {
				Node* next = toDelete.m_next;
				delete toDelete;
				toDelete = next;
			}
		}

		/*
		* Assignment operator of Node class.
		*
		* @param node - reference to a Node object.
		* @return
		*      reference to a Node object.
		*/
		Node& operator=(const Node& node) = default;

	private:
		T m_data;
		Node* m_next;
	};
#pragma endregion

	int m_size;
	Node<T>* m_first;
	Node<T>* m_last;
};
#endif //EX3_QUEUE_H
