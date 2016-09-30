// -*- C++ -*-

//==============================================================================
/**
 * @file       Array.cpp
 *
 * Author: Tim Whitfield
 * CSCI 49000
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help on this assignment.
 */
//==============================================================================

#include "Array.h"

//
// Array
//
template <typename T>
Array <T>::Array (void) : 
    Array_Base <T> ()
{
    this->max_size_ = DEFAULT_LENGTH_;
}

//
// Array (size_t)
//
template <typename T>
Array <T>::Array (size_t length) : 
    Array_Base <T> (length)
{
    this->max_size_ = length;
}

//
// Array (size_t, char)
//
template <typename T>
Array <T>::Array (size_t length, T fill) : 
    Array_Base <T> (length, fill)
{
    this->max_size_ = length;
}

//
// Array (const Array &)
//
// We want each array to be unaware of the max_size_ of other arrays, and to base its size_ and
// max_size_ only on the real content in those arrays.
template <typename T>
Array <T>::Array (const Array & array) : 
    Array_Base <T> (array)
{
    this->max_size_ = array.max_size ();
    this->import_elements (array, array.size () );
}

//
// ~Array
//
template <typename T>
Array <T>::~Array (void)
{
    // automatically calls ~Array_Base, which deletes data_ on heap
}

//
// operator =
//
// First checks for self assignment (using locations of the two arrays), and in that case returns
// this array without modifying it.
// Then checks whether this array is large enough to store rhs, and if not, resizes this array
// manually (without calling resize (), which would wastefully copy over old elements of this array).
// Finally, sets size_ and all elements equal to those of rhs.
template <typename T>
const Array <T> & Array <T>::operator = (const Array & rhs)
{
    if (& rhs == this)
    {
        return (* this);
    }
    else
    {
        if (this->max_size_ < rhs.size () )
        {
            delete [] this->data_;
            this->data_ = new T [rhs.size () ];
            this->max_size_ = rhs.size ();
        }
        this->size_ = rhs.size ();
        this->import_elements (rhs, this->size_);
        return (* this);
    }
}

//
// resize
//
// Only set max_size_ to new_size if data_ is array must be moved to a new array of a longer
// length (max_size_ should always equal the length of data_).
template <typename T>
void Array <T>::resize (size_t new_size)
{
    if (this->max_size_ < new_size)
    {
        T * new_data = new T [new_size];
        for (size_t i = 0; i < this->size_; i++)
        {
            new_data [i] = this->data_ [i];
        }
        delete [] this->data_;
        this->data_ = new_data;
        this->max_size_ = new_size;
    }
    this->size_ = new_size;
}
