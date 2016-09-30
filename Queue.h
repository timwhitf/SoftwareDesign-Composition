// -*- C++ -*-

//==============================================================================
/**
 * @file       Queue.h
 *
 * Author: Tim Whitfield
 * CSCI 49000
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help on this assignment.
 */
//==============================================================================

#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <exception>
#include "Array.h"

/**
 * @class Queue
 *
 * Implementation of a queue using a standard array class.
 */
template <typename T>
class Queue
{
	
public:
	
	/// Type defition of the type.
	typedef T type;
	
	/// Custom exception class.
	// This exception is to be thrown whenever caller tries to dequeue from an empty queue.
	class empty_exception : public std::exception
	{
	public:
		/// Default constructor.
		empty_exception (void)
			: std::exception ()
		{
			// no code required here
		}
	};
	
	/// Default constructor.
	Queue (void);
	
	/**
	 * Copy constructor.
	 *
	 * @param[in]     que         The source queue.
	 */
	Queue (const Queue & que);

    /// Destructor.
	~Queue (void);
	
	/**
	 * Assignment operator.
	 *
	 * @param[in]     rhs                  Right-hand side of assignment operation.
	 * @return        Reference to self.
	 */
	const Queue & operator = (const Queue & rhs);

    /**
	 * Enqueue one element.
	 *
	 * @param[in]     item                 Item to be enqueued.
	 */
	void enqueue (T item);
	
	/**
	 * Dequeue one element.
	 *
	 * @return        Item at front of queue (oldest item in queue).
	 * @exception     empty_exception      Queue is empty.
	 */
	T & dequeue (void);
	
	/**
	 * Check whether queue is empty.
	 *
	 * @return        true                 Queue is empty.
	 * @return        false                Queue is not empty.
	 */
	bool is_empty (void) const;
	
	/**
	 * Get size of queue.
	 *
	 * @return        Number of items in queue.
	 */
	size_t size (void) const;
	
	/// Clear all items from queue.
	void clear (void);
	
private:
	
	// Timothy, there is no need of a pointer here. Just an aggregation is fine.
	// 
	// Tim's Response: I changed the array_ data member from an Array * to just an Array.
	Array <T> array_;
	
	// Position (in array_) of item ready to be dequeued (oldest item in queue).
	// It usually represents a filled slot (unless the queue is empty, in which case
	// front_ == back_ and both are considered empty).
	size_t front_;
	
	// Position (in array_) of the next available slot in the queue. 
	// It ALWAYS represents an empty slot and is filled with the next item to be enqueued.
	// Queue::enqueue () will not allow it to progress forward to equal front_ because 
	// the array_ is considered full when back_ is one position behind front_.
	size_t back_;
	
	/**
	 * Increment the back or the front of the queue.
	 *
	 * @param[in]     marker              Array position marker (back or front) to be progressed.
	 */
	void progress (size_t & marker);
	
	/**
	 * Decrement the back or the front of the queue.
	 *
	 * @param[in]     marker              Array position marker (back or front) to be regressed.
	 */
	void regress (size_t & marker);
	
	/// Expand the queue to accomodate more enqueues.
	void expand (void);
	
};

#include "Queue.cpp"

#endif   // !defined _QUEUE_H_
