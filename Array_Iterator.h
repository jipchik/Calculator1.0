//declaration of an array iterator
#ifndef _ARRAY_ITERATOR_H_
#define _ARRAY_ITERATOR_H_


// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include"Basic_Array.h"


template <typename T>
class Array_Iterator
{
	public:

	Array_Iterator(Basic_Array<T> & a);
	~Array_Iterator(void);
	bool is_done(void);
	void advance(void);
	T & operator * (void);
	T * operator -> (void);
	
	private:

	Basic_Array<T> & a_;
	size_t curr_;

};

//include .cpp becuase it is templated
#include "Array_Iterator.cpp"

#endif
