// -*- C++ -*-

//==============================================================================
/**
 * @file       driver.cpp
 *
 * Driver program to test ADTs in Composition assignment.
 *
 * Author: Tim Whitfield
 * CSCI 49000
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help on this assignment.
 */
//==============================================================================

#include "Array_Base.h"
#include "Array.h"
#include "Fixed_Array.h"
#include "Stack.h"
#include "Queue.h"
#include <iostream>
#include <string>

using namespace std;

// Test Array_Base methods on arr_base.
// details enables function to print how arr_base was constructed
// elem_a and elem_b will be set to val_a and val_b
// elem_c will be before one value but after the other
// val_c will not be in arr_base
// fill will be used to fill a copy of arr_base
template <typename T>
void test_array_base (Array_Base <T> & arr_base, string details, size_t elem_a, size_t elem_b,
    T val_a, T val_b, size_t elem_c, T val_c, T fill)
{
    cout << endl << "Testing Array_Base Class:" << endl << endl;
    
    cout << details << endl << endl;
    print_vals (arr_base);
    
    cout << "array [" << elem_a << "] = " << val_a << endl;
    arr_base [elem_a] = val_a;
    cout << "array.set (" << elem_b << ", " << val_b << ')' << endl;
    arr_base.set (elem_b, val_b);
    cout << endl;
    cout << "array.get (" << elem_a << ") returns " << arr_base.get (elem_a) << endl;
    cout << "array [" << elem_b << "] returns " << arr_base [elem_b] << endl;
    print_vals (arr_base);
    
    cout << "array.find (" << val_a << ") returns " << arr_base.find (val_a) << endl;
    cout << "array.find (" << val_b << ") returns " << arr_base.find (val_b) << endl;
    cout << "array.find (" << val_a << ", " << elem_c << ") returns " << arr_base.find (val_a, elem_c)
        << endl;
    cout << "array.find (" << val_b << ", " << elem_c << ") returns " << arr_base.find (val_b, elem_c)
        << endl;
    cout << "array.find (" << val_c << ") returns " << arr_base.find (val_c) << endl;
    cout << endl;
    
    cout << "array2 (array)" << endl;
    Array_Base <T> arr_base_copy (arr_base);
    print_vals (arr_base_copy);
    cout << "array2 == array1 returns " << (arr_base_copy == arr_base) << endl;
    cout << "array2 != array1 returns " << (arr_base_copy != arr_base) << endl;
    cout << "array2.fill (" << fill << ')' << endl;
    arr_base_copy.fill (fill);
    print_vals (arr_base_copy);
    cout << "array2 == array1 returns " << (arr_base_copy == arr_base) << endl;
    cout << "array2 != array1 returns " << (arr_base_copy != arr_base) << endl;
    
}

template <typename T>
void test_array (Array <T> & arr, size_t val_a, size_t val_b)
{
    cout << endl << "Testing Special Functionality of Array Class: " << endl << endl;
    
    cout << "Array <T> new_array (array)" << endl;
    Array <T> new_arr (arr);
    print_vals (new_arr);
    
    cout << "new_array.resize (" << val_a << ')' << endl;
    new_arr.resize (val_a);
    print_vals (new_arr);
    
    cout << "array = new_array" << endl;
    arr = new_arr;
    print_vals (arr);
    
    cout << "array.resize (" << val_b << ')' << endl;
    arr.resize (val_b);
    print_vals (arr);
    
    cout << "new_array = array" << endl;
    new_arr = arr;
    print_vals (new_arr);
    
    cout << "array = array" << endl;
    arr = arr;
    print_vals (arr);
}

template <typename T, size_t N>
void test_fixed_array (Fixed_Array <T, N> & fix_arr, size_t elem_a, T val_a)
{
    cout << endl << "Testing Fixed_Array Class: " << endl << endl;
    
    cout << "Fixed_Array <T, N> new_fixed_array (fixed_array)" << endl;
    Fixed_Array <T, N> new_fix_arr (fix_arr);
    print_vals (new_fix_arr);
    
    cout << "new_fixed_array.set (" << elem_a << ", " << val_a << ')' << endl;
    new_fix_arr.set (elem_a, val_a);
    print_vals (new_fix_arr);
    
    cout << "fixed_array = new_fixed_array" << endl;
    fix_arr = new_fix_arr;
    print_vals (fix_arr);
    
    cout << "fixed_array = fixed_array" << endl;
    fix_arr = fix_arr;
    print_vals (fix_arr);

}

template <typename T>
void print_vals (Array_Base <T> & arr_base)
{
    cout << endl << "size: " << arr_base.size () << endl;
    for (size_t i = 0; i < arr_base.size (); i++)
    {
        cout << i << ": " << arr_base [i] << endl;
    }
    cout << endl;
}

template <typename T>
void print_vals (const Array_Base <T> & arr_base)
{
    cout << endl << "size: " << arr_base.size () << endl;
    for (size_t i = 0; i < arr_base.size (); i++)
    {
        cout << i << ": " << arr_base [i] << endl;
    }
    cout << endl;
}

template <typename T>
void print_vals (Array <T> & arr)
{
    cout << endl << "size: " << arr.size () << "    max_size: " << arr.max_size () << endl;
    for (size_t i = 0; i < arr.size (); i++)
    {
        cout << i << ": " << arr [i] << endl;
    }
    cout << endl;
}

template <typename T>
void print_vals (const Array <T> & arr)
{
    cout << endl << "size: " << arr.size () << "    max_size: " << arr.max_size () << endl;
    for (size_t i = 0; i < arr.size (); i++)
    {
        cout << i << ": " << arr [i] << endl;
    }
    cout << endl;
}

template <typename T>
void try_to_resize (Array_Base <T> & arr_base)
{
    arr_base.resize (arr_base.size () * GROWTH_FACTOR_);
    print_vals (arr_base);
}

template <typename T>
void print_vals (Queue <T> & que)
{
    cout << endl;
    size_t num_to_print = que.size ();
    for (size_t i = 0; i < num_to_print; i++)
    {
        cout << "size: " << que.size () << endl;
        cout << i << ": " << que.dequeue () << endl;
    }
}

int main (void)
{
    
    // Array_Base driver
    
    // Default Constructor
    Array_Base <int> ab1;
    test_array_base (ab1, "Array_Base <int> ab1", 2, 4, 23, 19, 3, 15, 46);
    
    // Length Constructor
    //Array_Base <char> ab2 (10);
    //test_array_base (ab2, "Array_Base <char> ab2 (10)", 1, 7, 'g', '+', 5, '#', '~');
    
    // Length / Fill Constructor
    //Array_Base <long> ab3 (3, 465);
    //test_array_base <long> (ab3, "Array_Base <long> ab3 (3, 465)", 0, 2, 65, 70, 1, 69, 74);
    
    // Heap
    Array_Base <short> * ab4 = new Array_Base <short> (4, 5);
    test_array_base <short> (* ab4, "Array_Base <short> * ab4 = new Array_Base <short> (4, 5)", 
        1, 3, 65, 70, 2, 69, 74);
    delete ab4;
    
    
    
    // Array driver
    
    // Default Constructor
    //Array <int> a1;
    //test_array_base <int> (a1, "Array <int> a1", 2, 4, 23, 19, 3, 15, 46);
    //test_array <int> (a1, 4, 9);
    
    // Length Constructor
    //Array <char> a2 (10);
    //test_array_base (a2, "Array <char> a2 (10)", 1, 7, 'g', '+', 5, '#', '~');
    //test_array <char> (a2, 11, 9);
    
    // Length / Fill Constructor
    Array <long> a3 (3, 465);
    test_array_base <long> (a3, "Array <long> a3 (3, 465)", 0, 2, 65, 70, 1, 69, 74);
    test_array <long> (a3, 0, 3);
    
    // Heap
    Array <short> * a4 = new Array <short> (4, 5);
    test_array_base <short> (* a4, "Array <short> * a4 = new Array <short> (4, 5)", 
        1, 3, 65, 70, 2, 69, 74);
    test_array <short> (* a4, 4, 15);
    delete a4;
    
    
    
    // Fixed_Array driver
    
    // Default Constructor
    Fixed_Array <int, 5> fa1;
    test_array_base <int> (fa1, "Fixed_Array <int, 5> fa1", 2, 4, 23, 19, 3, 15, 46);
    test_fixed_array <int, 5> (fa1, 2, 17);
    
    Fixed_Array <short, 6> * fa2 = new Fixed_Array <short, 6> ();
    test_array_base <short> (* fa2, "Fixed_Array <short, 6> fa2", 4, 5, 65, 70, 5, 15, 46);
    test_fixed_array <short, 6> (* fa2, 4, 74);
    delete fa2;
    
    
    
    /*
    
    // Attempts to confuse Array and Fixed_Array
    
    cout << "\n\n\n\nTesting Casting Interchangeability between Array and Fixed_Array...\n\n\n";
    
    Array <int> a7;
    cout << "Array <int> a7" << endl;
    a7.fill (3);
    cout << "a7.fill (3)" << endl;
    print_vals (a7);
    cout << "a7 is variable-length:" << endl;
    a7.resize (8);
    cout << "size of a7 after calling a7.resize (8) is " << a7.size () << endl << endl;
    
    Fixed_Array <int, 7> fa7;
    cout << "Fixed_Array <int, 7> fa7" << endl;
    fa7.fill (4);
    cout << "fa7.fill (4)" << endl;
    print_vals (fa7);
    cout << "fa7 is fixed-length:" << endl;
    fa7.resize (9);
    cout << "size of fa7 after calling fa7.resize (9) is " << fa7.size () << endl << endl;
    
    cout << "TESTING COPY CONSTRUCTOR: ARRAY FROM FIXED_ARRAY" << endl;
    Array <int> a8 (fa7);
    cout << "Array <int> a8 (fa7)" << endl;
    print_vals (a8);
    cout << "a8 is a variable-length Array:" << endl;
    a8.resize (11);
    cout << "size of a8 after calling a8.resize (11) is " << a8.size () << endl << endl;
    
    cout << "TESTING CASTING ARRAY * TO FIXED_ARRAY *" << endl;
    Array <int> * a9 = 0;
    cout << "Array <int> * a9 = 0" << endl;
    a9 = new Fixed_Array <int, 3> ();
    cout << "a9 = new Fixed_Array <int, 3> ()" << endl;
    print_vals (* a9);
    cout << "a9 has been converted to a fixed-length Array:" << endl;
    a9->resize (5);
    // returned 3 only after "virtual" added to resize () declaration in Array.h
    cout << "size of a9 after calling a9.resize (5) is " << a9->size () << endl << endl;
    
    cout << "Try to resize all 4:" << endl;
    try_to_resize (a7);
    try_to_resize (fa7);
    try_to_resize (a8);
    try_to_resize (* a9);
    
    delete a9;
    
    */
    
    
    
    
    // Stack driver
    
    cout << "\n\n\n\nTesting Stack class...\n\n\n";
    
    try
    {
        Stack <int> s1;
        cout << "Stack <int> s1" << endl;
        s1.push (3);
        cout << "s1.push (3)" << endl;
        s1.pop ();
        cout << "s1.pop ()" << endl;
        cout << "s1.size () returns " << s1.size () << endl;
        cout << "s1.is_empty () returns " << s1.is_empty () << endl;
        // uncomment to test exception handling:
        // cout << "s1.top () returns " << s1.top () << endl;
        cout << endl;
        
        s1.push (6);
        cout << "s1.push (6)" << endl;
        s1.push (7);
        cout << "s1.push (7)" << endl;
        s1.push (1);
        cout << "s1.push (1)" << endl;
        cout << "s1.size () returns " << s1.size () << endl;
        cout << "s1.is_empty () returns " << s1.is_empty () << endl;
        cout << "s1.top () returns " << s1.top () << endl;
        cout << endl;
        
        s1.pop ();
        cout << "s1.pop ()" << endl;
        cout << "s1.size () returns " << s1.size () << endl;
        cout << "s1.is_empty () returns " << s1.is_empty () << endl;
        cout << "s1.top () returns " << s1.top () << endl;
        cout << endl;
        
        s1.clear ();
        cout << "s1.clear ()" << endl;
        cout << "s1.size () returns " << s1.size () << endl;
        cout << "s1.is_empty () returns " << s1.is_empty () << endl;
        // uncomment to test exception handling:
        // cout << "s1.top () returns " << s1.top () << endl;
        cout << endl;
        
        cout << "s1.push (2)" << endl;
        s1.push (2);
        cout << "s1.size () returns " << s1.size () << endl;
        cout << "s1.is_empty () returns " << s1.is_empty () << endl;
        cout << "s1.top () returns " << s1.top () << endl;
        cout << endl;
        
        cout << "s1.push (9)" << endl;
        s1.push (9);
        cout << "s1.push (9)" << endl;
        s1.push (9);
        cout << "s1.push (6)" << endl;
        s1.push (6);
        cout << "s1.push (1)" << endl;
        s1.push (1);
        cout << "s1.push (3)" << endl;
        s1.push (3);
        cout << "s1.push (0)" << endl;
        s1.push (0);
        cout << endl;
        
        Stack <int> s2;
        cout << "Stack <int> s2" << endl;
        cout << "s2 = s1" << endl;
        s2 = s1;
        cout << "s2.top () returns " << s2.top () << endl;
        cout << "s2.pop ()" << endl;
        s2.pop ();
        cout << "s2.top () returns " << s2.top () << endl;
        cout << "s2.pop ()" << endl;
        s2.pop ();
        cout << "s2.top () returns " << s2.top () << endl;
        cout << "s2.pop ()" << endl;
        s2.pop ();
        cout << "s2.top () returns " << s2.top () << endl;
        cout << "s2.pop ()" << endl;
        s2.pop ();
        cout << "s2.top () returns " << s2.top () << endl;
        cout << "s2.pop ()" << endl;
        s2.pop ();
        cout << "s2.top () returns " << s2.top () << endl;
        cout << "s2.pop ()" << endl;
        s2.pop ();
        cout << "s2.top () returns " << s2.top () << endl;
        cout << "s2.pop ()" << endl;
        s2.pop ();
        // uncomment to test exception handling:
        // cout << "s2.top () returns " << s2.top () << endl;
        
        cout << endl;
        
        Stack <int> s3 (s1);
        cout << "Stack <int> s3 (s1)" << endl;
        cout << "s3.top () returns " << s3.top () << endl;
        cout << "s3.pop ()" << endl;
        s3.pop ();
        cout << "s3.top () returns " << s3.top () << endl;
        cout << "s3.pop ()" << endl;
        s3.pop ();
        cout << "s3.top () returns " << s3.top () << endl;
        cout << "s3.pop ()" << endl;
        s3.pop ();
        cout << "s3.top () returns " << s3.top () << endl;
        cout << "s3.pop ()" << endl;
        s3.pop ();
        cout << "s3.top () returns " << s3.top () << endl;
        cout << "s3.pop ()" << endl;
        s3.pop ();
        cout << "s3.top () returns " << s3.top () << endl;
        cout << "s3.pop ()" << endl;
        s3.pop ();
        cout << "s3.top () returns " << s3.top () << endl;
        cout << "s3.pop ()" << endl;
        s3.pop ();
        // uncomment to test exception handling:
        // cout << "s3.top () returns " << s3.top () << endl;
        cout << endl;
        
        cout << "full into empty" << endl;
        s3 = s1;
        cout << "s3 = s1" << endl;
        cout << "s3.top () returns " << s3.top () << endl;
        
        cout << "empty into full" << endl;
        s1 = s2;
        cout << "s1 = s2" << endl;
        // cout << "s1.top () returns " << s1.top () << endl;
        
        cout << "empty into itself" << endl;
        s1 = s1;
        cout << "s1 = s1" << endl;
        // cout << "s1.top () returns " << s1.top () << endl;
        
        cout << "full into empty" << endl;
        s2 = s3;
        cout << "s2 = s3" << endl;
        cout << "s2.top () returns " << s2.top () << endl;
        
        cout << "full into empty" << endl;
        s1 = s3;
        cout << "s1 = s3" << endl;
        cout << "s1.top () returns " << s1.top () << endl;
        
        cout << "full into itself" << endl;
        s3 = s3;
        cout << "s3 = s3" << endl;
        cout << "s3.top () returns " << s3.top () << endl;
        
    }
    catch (std::out_of_range)
    {
        cout << endl << endl << "EXCEPTION: index out of range" << endl;
    }
    catch (std::exception ee)
    {
        cout << "Array is empty!" << endl;
    }
    
    
    
    
    // Queue driver
    
    cout << "\n\n\n\nTesting Queue class...\n\n\n";
    
    try
    {
        cout << "TESTING DEFAULT CONSTRUCTOR" << endl;
        Queue <int> q1;
        cout << "Queue <int> q1" << endl;
        print_vals (q1);
        
        cout << "TESTING ENQUEUE ()" << endl;
        cout << "q1.enqueue (10)" << endl;
        q1.enqueue (10);
        cout << "q1.enqueue (16)" << endl;
        q1.enqueue (16);
        cout << "q1.enqueue (30)" << endl;
        q1.enqueue (30);
        cout << "q1.enqueue (38)" << endl;
        q1.enqueue (38);
        cout << "q1.enqueue (56)" << endl;
        q1.enqueue (56);
        cout << "q1.enqueue (62)" << endl;
        q1.enqueue (62);
        cout << "q1.enqueue (71)" << endl;
        q1.enqueue (71);
        cout << "q1.enqueue (79)" << endl;
        q1.enqueue (79);
                
        cout << "TESTING IS_EMPTY ()" << endl;
        cout << "q1.is_empty () returns " << q1.is_empty () << endl;
        cout << "q1.size () returns " << q1.size () << endl;
        
        cout << "TESTING COPY CONSTRUCTOR" << endl;
        Queue <int> q2 (q1);
        cout << "Queue <int> q2 (q1)" << endl;
        cout << "q2.is_empty () returns " << q2.is_empty () << endl;
        cout << "q2.size () returns " << q2.size () << endl;
        print_vals (q2);
        // cout << "TESTING EXCEPTION HANDLING for DEQUEUE ()" << endl;
        // cout << "q2.dequeue returns " << q2.dequeue () << endl;
        
        cout << "q2.enqueue (76)" << endl;
        q2.enqueue (76);
        cout << "TESTING CLEAR ()" << endl;
        q2.clear ();
        cout << "q2.clear ()" << endl;
        print_vals (q2);
        
        cout << "TESTING OPERATOR =" << endl;
        Queue <int> q3;
        cout << "Queue <int> q3" << endl;
        q3 = q1;
        cout << "q3 = q1" << endl;
        print_vals (q3);
        
        cout << "q1.dequeue ()" << endl;
        q1.dequeue ();
        cout << "q1.enqueue (86)" << endl;
        q1.enqueue (86);
        cout << "q1.dequeue ()" << endl;
        q1.dequeue ();
        cout << "q1.dequeue ()" << endl;
        q1.dequeue ();
        cout << "q1.enqueue (96)" << endl;
        q1.enqueue (96);
        cout << "q1.enqueue (106)" << endl;
        q1.enqueue (106);
        cout << "q1.enqueue (116)" << endl;
        q1.enqueue (116);
        cout << "q1.enqueue (126)" << endl;
        q1.enqueue (126);
        cout << "q1.enqueue (136)" << endl;
        q1.enqueue (136);
        cout << "q1.enqueue (146)" << endl;
        q1.enqueue (146);
        cout << "q1.enqueue (156)" << endl;
        q1.enqueue (156);
        
        print_vals (q1);
    }
    
    catch (std::exception ee)
    {
        cout << "Queue is empty, sorry!" << endl;
    }
    
    
    
    cout << endl;
    return 0;
}
