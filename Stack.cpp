// -*- C++ -*-

//==============================================================================
/**
 * @file       Stack.cpp
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

//
// Stack
//
// Timothy, there is no need to use a pointer here. Just aggregation is fine.
// 
// Tim's Response: I changed the data member from a pointer to an object in
// order to implement aggregation.
template <typename T>
Stack <T>::Stack (void) : 
	array_ (Array <T> () ), 
    size_ (0)
{
    // no code required here
}

//
// Stack
//
template <typename T>
Stack <T>::Stack (const Stack & stack) : 
    array_ (stack.array_), 
    size_ (stack.size_)
{
    // Timothy, this is not required.
    // 
    // Tim's Response: I deleted the call to Stack::operator = because I just need to make the
    // underlying array_ match that of parameter stack, and I did that by calling the copy constructor.
    // Underlying array_ was set to the right size, so no need to check for that. Jumped straight to
    // using Array::import_elements ().
    this->array_.import_elements (stack.array_, this->size_);
}

//
// ~Stack
//
template <typename T>
Stack <T>::~Stack (void)
{
    // Array destructor will release heap data in data_
}

//
// operator =
//
// Timothy, you should check for self initialization first. Also, you should let the array copy over its elements.
// 
// Tim's Response: I deleted the for-loop that used Array::get to access the elements of rhs and
// then used Stack::push to insert them into this stack. Instead, I am using the Array::operator =
// to make the underlying array_ of this stack be the same length and have the same elements as the
// array_ in rhs. Also set size_ (of this stack) equal to that of rhs (will also match length of
// array_). Array::operator = checks for self assignment, so no need to do that here.
template <typename T>
const Stack <T> & Stack <T>::operator = (const Stack & rhs)
{
    this->array_ = rhs.array_;
    this->size_ = rhs.size_;
    return (* this);
}


//
// push
//
// Set the next available slot in array_ (the one just past the current last element) to element,
// and then increment size_ of array_.
template <typename T>
void Stack <T>::push (T element)
{
    try
    {
	    this->array_.set (this->size_, element);
        this->size_ ++;
    }
    catch (std::out_of_range)
    {
	    this->array_.resize (this->array_.size () * GROWTH_FACTOR_);
	    this->array_.set (this->size_, element);
        this->size_ ++;
    }
}

//
// pop
//
// Decrement official size_ of this stack, which changes the results of top () as well. Element is still
// in array_, but this stack does not consider it as still being on the stack.
template <typename T>
void Stack <T>::pop (void)
{
    if (this->is_empty () )
    {
        empty_exception ee;
        throw ee;
    }
    else
    {
	    this->size_ --;
    }
}

//
// clear
//
// This stack considers all elements still in underlying array_ to no longer be on the stack
// if size_ is set to 0.
template <typename T>
void Stack <T>::clear (void)
{
    this->size_ = 0;
}
