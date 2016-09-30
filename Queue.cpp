// -*- C++ -*-

//==============================================================================
/**
 * @file       Queue.cpp
 *
 * Author: Tim Whitfield
 * CSCI 49000
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help on this assignment.
 */
//==============================================================================

#define GROWTH_FACTOR_ 2

// Timothy, there is no need of a pointer to the Array here. Just an aggregation is fine.
// 
// Tim's Response: I changed array_ from an Array * to just an Array.
template <typename T>
Queue <T>::Queue (void) : 
	array_ (Array <T> () ), 
	front_ (0), 
	back_ (0)
{
	// no code required here
}

// Tim: I changed this constructor to initialize array_ with the Array copy constructor
// instead of calling Queue::operator =.
template <typename T>
Queue <T>::Queue (const Queue & que) : 
	array_ (que.array_), 
	front_ (que.front_), 
	back_ (que.back_)
{
	// no code required here
}

template <typename T>
Queue <T>::~Queue (void)
{
	// Array destructor will delete array_ heap data
}

// Timothy, check for self assignment first.
// 
// Tim's Response: I deleted the code that copied manually by getting the elements from
// rhs' array and enqueing them into this queue. I replaced it with a call to Array::operator =,
// which checks for self assignment. Manually set other data members (front_ and back_), too.
template <typename T>
const Queue <T> & Queue <T>::operator = (const Queue & rhs)
{
	this->array_ = rhs.array_;
	this->front_ = rhs.front_;
	this->back_ = rhs.back_;
	return (* this);
}

// Progress back_ to see if there is another empty slot (in which case the previous slot can be
// filled with item).
// If back_ runs into front_, then the queue is full (is_empty () returns true in this case), so
// expand array_ before trying again.
// Then regress back_ to its original position, fill that slot with item, and progress it to mark
// the next empty slot.
template <typename T>
void Queue <T>::enqueue (T item)
{
	this->progress (this->back_);
	if (this->is_empty () )
	{
		this->regress (this->back_);
		this->expand ();
	}
	else
	{
		this->regress (this->back_);
	}
	this->array_.set (this->back_, item);
	this->progress (this->back_);
}

// Check whether queue is empty, and if so, throw empty_exception.
// If queue has at least one element, return a reference to that element and progress front_
// to mark that that element is no longer in the queue.
template <typename T>
T & Queue <T>::dequeue (void)
{
	if (this->is_empty () )
	{
		empty_exception ee;
		throw ee;
	}
	else
	{
		T & leaving = this->array_ [front_];
		this->progress (this->front_);
		return leaving;
	}
}

// By convention, always consider queue empty when front_ equals back_  (excpet during
// controlled instances such as for testing for available slots before enqueing).
template <typename T>
bool Queue <T>::is_empty (void) const
{
	if (this->front_ == this->back_)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// If back_ is ahead of front_, then the slots between them are filled and size_ should equal that
// number of slots.
// If back_ has wrapped around and is behind front_, then the slots between them are empty,
// and size_ should be length of underlying array_ minus those in-between slots.
// Always returns between 0 and one less than size of array_.
template <typename T>
size_t Queue <T>::size (void) const
{
	if (front_ < back_)
	{
		return (back_ - front_);
	}
	else if (front_ == back_)
	{
		return 0;
	}
	else
	{
		return ( this->array_.size () - (front_ - back_) );
	}
}

// Ignore contents of array_. Set front_ and back_ equal to each other (to make queue considered
// empty) at beginning of array_.
template <typename T>
void Queue <T>::clear (void)
{
	this->front_ = 0;
	this->back_ = 0;
}

// Move parameter (a queue boundary marker, either front_ or back_) forward one space, wrapping
// around to the beginning of array_ once the end is reached.
template <typename T>
void Queue <T>::progress (size_t & marker)
{
	marker = (marker + 1) % this->array_.size ();
}

// Move parameter (a queue boundary marker, either front_ or back_) backward one space, wrapping
// around to the end of array_ once the beginning is reached.
// Use if/else instead of modulus because size_t cannot be negative even for a short time.
template <typename T>
void Queue <T>::regress (size_t & marker)
{
	if (marker == 0)
	{
		marker = this->array_.size () - 1;
	}
	else
	{
		marker --;
	}
}

// Calling resize () will double the size of array_, with the first half of the new array having
// the same contents as the original array.
// If back_ had wrapped around to the beginning of array_ (back_ < front_), then all occupied
// queue slots in the beginning of the original (smaller) array_ need to be moved to the first
// available slots in the second half of the new (expanded) array_. Increment back_ by size of
// original (smaller array_) to reach new position (next empty slot in expanded array_).
// If nothing had been dequeued (and thus back_ occupied the last slot in the original array but
// could not wrap around because front_ occupied the first slot), then there is no need to move
// any elements around because back_ can continue into the second half of the expanded array_.
template <typename T>
void Queue <T>::expand (void)
{
	size_t old_size = this->array_.size ();
	this->array_.resize (this->array_.size () * GROWTH_FACTOR_);
	if (this->back_ < this->front_)
	{
		for (size_t i = 0; i < this->back_; i++)
		{
			T to_be_moved = this->array_.get (i);
			this->array_.set ( (old_size + i), to_be_moved );
		}
		this->back_ += old_size;
	}
}
