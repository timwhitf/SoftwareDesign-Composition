// -*- C++ -*-

//==============================================================================
/**
 * @file       Stack.inl
 *
 * Author: Tim Whitfield
 * CSCI 49000
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help on this assignment.
 */
//==============================================================================

//
// size
//
template <typename T>
inline
size_t Stack <T>::size (void) const
{
    return this->size_;
}

//
// top
//
// Get the top-most element, which means return the earliest
// element in the underlying array (array_). Array::get () method
// is zero-indexed, so subtract additional 1.
template <typename T>
inline
T Stack <T>::top (void) const
{
    if (this->is_empty () )
    {
        empty_exception ee;
	    throw ee;
    }
    else
    {
	    return ( this->array_.get (this->size_ - 1) );
    }
}

//
// is_empty
//
template <typename T>
inline
bool Stack <T>::is_empty (void) const
{
    if (this->size_ == 0)
	{
	    return true;
	}
    else
    {
        return false;
    }
}
