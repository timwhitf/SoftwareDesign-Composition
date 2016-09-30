// -*- C++ -*-

//==============================================================================
/**
 * @file       Array_Base.inl
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
size_t Array_Base <T>::size (void) const
{
    return  this->size_;
}
