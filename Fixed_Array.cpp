// -*- C++ -*-

//==============================================================================
/**
 * @file       Fixed_Array.cpp
 *
 * Author: Tim Whitfield
 * CSCI 49000
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help on this assignment.
 */
//==============================================================================

#define RANGE_MESSAGE_ "index is out of range\n"
#define DEFAULT_LENGTH_ 6

//
// Fixed_Array ()
//
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (void) : 
	Array_Base <T> (N)
{
    // no code required here
}

//
// Fixed_Array
//
// Timothy make sure you are calling the correct base constructor.
// 
// Tim's Response: I changed the parameter of the base constructor from "N"
// to "N, fill" so that it will call the Array fill constructor. This does
// the filling automatically by calling Array::fill (T value).
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (T fill) : 
	Array_Base <T> (N, fill)
{
	// no code required here
}

//
// Fixed_Array (const Fixed_Array &)
//
// Timothy make sure you are calling the correct base constructor.
// 
// Tim's Response: I changed the parameter in the base constructor from "N" to
// "arr" and called the Array_Base (const Array &) constructor instead of the Array
// (size_t) constructor.
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (const Fixed_Array <T, N> & arr) : 
	Array_Base <T> (arr)
{
    // Timothy, this is not required as the base constructor will already do a copy.
	// 
	// Tim's Response: I removed the code that called operator =.
}

//
// ~Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::~Fixed_Array (void)
{
    // automatically calls ~Array_Base, which deletes data_ on heap
}

//
// operator =
//
// Timothy, always check for self initialization first. It would be better suited
// if you let the base class handle the copying logic by pass control to it.
// 
// Tim's Response: With the new design, Array_Base does not have an operator =. So I implemented
// it here and checked for self assignment. If it is not self assignment, I manually set the
// size_ and all of the elements of this array to equal those of rhs.
template <typename T, size_t N>
const Fixed_Array <T, N> & Fixed_Array <T, N>::operator = (const Fixed_Array <T, N> & rhs)
{
	if (& rhs == this)
    {
        return (* this);
    }
    else
    {
        this->size_ = rhs.size ();
        this->import_elements (rhs, N);
        return (* this);
    }
}
