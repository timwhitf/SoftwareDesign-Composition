// -*- C++ -*-

//==============================================================================
/**
 * @file       Array_Base.cpp
 *
 * Author: Tim Whitfield
 * CSCI 49000
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help on this assignment.
 */
//==============================================================================

#include <stdexcept>         // for std::out_of_bounds exception
#include "Array_Base.h"

#define RANGE_MESSAGE_ "index is out of range\n"
#define DEFAULT_LENGTH_ 6

//
// Array_Base
//
template <typename T>
Array_Base <T>::Array_Base (void) : 
    data_ (new T [DEFAULT_LENGTH_]), 
    size_ (DEFAULT_LENGTH_)
{
    // no code required here
}

//
// Array_Base (size_t)
//
template <typename T>
Array_Base <T>::Array_Base (size_t length) : 
    data_ (new T [length]), 
    size_ (length)
{
    // no code required here
}

//
// Array_Base (size_t, char)
//
template <typename T>
Array_Base <T>::Array_Base (size_t length, T fill) : 
    data_ (new T [length]), 
    size_ (length)
{
    this->fill (fill);
}

//
// Array_Base (const Array_Base &)
//
template <typename T>
Array_Base <T>::Array_Base (const Array_Base & arr_base) : 
    data_ (new T [arr_base.size () ] ), 
    size_ (arr_base.size () )
{
    this->import_elements (arr_base, arr_base.size () );
}

//
// ~Array_Base
//
template <typename T>
Array_Base <T>::~Array_Base (void)
{
    delete [] this->data_;
}

//
// operator []
//
template <typename T>
T & Array_Base <T>::operator [] (size_t index)
{
    if (index < this->size_)
    {
        return this->data_ [index];
    }
    else
    {
        throw std::out_of_range (RANGE_MESSAGE_);
    }
}

//
// operator [] 
//
template <typename T>
const T & Array_Base <T>::operator [] (size_t index) const
{
    if (index < this->size_)
    {
        return this->data_ [index];
    }
    else
    {
        throw std::out_of_range (RANGE_MESSAGE_);
    }
}

//
// get
//
template <typename T>
T Array_Base <T>::get (size_t index) const
{
    if (index < this->size_)
    {
        return this->data_ [index];
    }
    else
    {
        throw std::out_of_range (RANGE_MESSAGE_);
    }
}

//
// set
//
template <typename T>
void Array_Base <T>::set (size_t index, T value)
{
    if (index < this->size_)
    {
        this->data_ [index] = value;
    }
    else
    {
        throw std::out_of_range (RANGE_MESSAGE_);
    }
}

//
// find (char)
//
template  <typename T>
int Array_Base <T>::find (T value) const
{
    return (this->find (value, 0) );
}

//
// find (char, size_t) 
//
template <typename T>
int Array_Base <T>::find (T value, size_t start) const
{
    if (start < this->size_)
    {
        for (size_t i = start; i < this->size_; i++)
        {
            if (this->data_ [i] == value)
            {
                return i;
            }
        }
        return -1;
    }
    else
    {
        throw std::out_of_range (RANGE_MESSAGE_);
    }
}

//
// operator ==
//
template <typename T>
bool Array_Base <T>::operator == (const Array_Base & rhs) const
{
    if (this->size_ != rhs.size () )
    {
        return false;
    }
    for (size_t i = 0; i < this->size_; i++)
    {
        if (this->data_ [i] != rhs.data_ [i] )
        {
            return false;
        }
    }
    return true;
}

//
// operator !=
//
template <typename T>
bool Array_Base <T>::operator != (const Array_Base & rhs) const
{
    return ! (this->operator == (rhs) );
}

//
// fill
//
template <typename T>
void Array_Base <T>::fill (T value)
{
    for (size_t i = 0; i < this->size_; i++)
    {
        this->data_ [i] = value;
    }
}

//
// copy elements
//
template <typename T>
void Array_Base <T>::import_elements (const Array_Base <T> & src, size_t num_to_copy)
{
    for (size_t i = 0; i < num_to_copy; i++)
    {
        this->data_ [i] = src.data_ [i];
    }
}
