// -*- C++ -*-

//==============================================================================
/**
 * @file       Stack.h
 *
 * Author: Tim Whitfield
 * CSCI 49000
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help on this assignment.
 */
//==============================================================================

#ifndef _STACK_H_
#define _STACK_H_

#include <exception>
#include "Array.h"

/**
 * @class Stack
 *
 * Basic stack for abitrary elements.
 */
template <typename T>
class Stack
{

public:
	
	/// Type definition of the type.
	typedef T type;

	/**
	 * @class empty_exception
	 *
	 * Exception thrown to indicate the stack is empty.
	 */
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
	Stack (void);

	/// Copy constructor.
	Stack (const Stack & s);

	/// Destructor.
	~Stack (void);

	/**
	 * Assignment operator
	 *
	 * @param[in]      rhs           Right-hand side of operator
	 * @return         Reference to self
	 */
	const Stack & operator = (const Stack & rhs);

	/**
	 * Push a new \a element onto the stack. The element is inserted
	 * before all the other elements in the list.
	 *
	 * @param[in]      element       Element to add to the list
	 */
	void push (T element);

	/**
	 * Remove the top-most element from the stack.
	 *
	 * @exception      empty_exception    The stack is empty.
	 */
	void pop (void);

	/**
	 * Get the top-most element on the stack. If there are no elements 
	 * on the stack, then the stack_is_empty exception is thrown.
	 *
	 * @return         Element on top of the stack.
	 * @exception      empty_exception    The stack is empty
	 */
	T top (void) const;

	/**
	 * Test if the stack is empty
	 *
	 * @retval         true          The stack is empty
	 * @retval         false         The stack is not empty
	 */
	bool is_empty (void) const;

	/**
	 * Number of elements on the stack.
	 *
	 * @return         Size of the stack.
	 */
	size_t size (void) const;

	/// Remove all elements from the stack.
	void clear (void);

private:
	
	// Timothy, there is no need to use a pointer here. Just aggregation is fine.
	// 
	// Tim's Response: I changed the data member from a pointer to an object in
	// order to implement aggregation.
	Array <T> array_;
	
	size_t size_;
	
};

#include "Stack.inl"
#include "Stack.cpp"

#endif  // !defined _STACK_H_
