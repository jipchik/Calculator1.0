// -*- C++ -*-
// $Id: Array.h 819 2011-01-17 15:24:45Z hillj $

//==============================================================================
/**
 * @file       Array.h
 *
 * $Id: Array.h 819 2011-01-17 15:24:45Z hillj $
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <cstring>          // for size_t definition
#include "Basic_Array.h"
//#include "Array_Iterator.h"
/**
 * @class Array
 *
 * Array template class that is allowed to be resized
 */
template <typename T>
class Array : public Basic_Array <T>
{
public:
	/// Type definition of the element type.
	typedef T type;

  /// Default constructor.
  Array (void);

  /**
   * Initializing constructor.
   *
   * @param[in]      length        Initial size
   */
  Array (size_t length);

  /**
   * Initializing constructor.
   *
   * @param[in]      length        Initial size
   * @param[in]      fill          Initial value for each element
   */
  Array (size_t length, T fill);

  /**
   * Copy constructor
   *
   * @param[in]     arr         The source array.
   */
  Array (const Array & arr);

  /// Destructor.
 	~Array (void);

  /**
   * Assignment operation
   *
   * @param[in]       rhs      Right-hand side of equal sign
   * @return          Reference to self
   */
  const Array & operator = (const Array & rhs);


  /**
   * Set a new size for the array. If \a new_size is less than the current
   * size, then the array is truncated. If \a new_size if greater then the
   * current size, then the array is made larger and the new elements are
   * not initialized to anything. If \a new_size is the same as the current
   * size, then nothing happens.
   *
   * The array's original contents are preserved regardless of whether the 
   * array's size is either increased or decreased.
   *
   * @param[in]       new_size              New size of the array
   */
	void resize (size_t new_size);

  /// Shrink the array to reclaim unused space.
  void shrink ();
  
 
  Array slice (size_t begin) const;
  
  /**
   * @overload
   *
   * @param[in]       begin           The starting index
   * @param[in]       end             The ending index
   * @return          A new Array object
   */
  Array slice (size_t begin, size_t end) const;


//	friend class Array_Iterator<T>;
};

#include "Array.cpp"


#endif   // !defined _ARRAY_H_
