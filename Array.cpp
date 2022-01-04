// $Id: Array.cpp 82
// 0 2011-01-17 15:30:41Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Basic_Array.h"
#include "Array.h"
#include <iostream>
#include <stdexcept>

template <typename T>
Array <T>::Array (void)
//using base member initialization
: Basic_Array <T>()
{}

template <typename T>
Array <T>::Array (size_t length)
//using base member initialization
: Basic_Array <T>(length)
{}

template <typename T>
Array <T>::Array (size_t length, T fill)
//using base member initialization
: Basic_Array <T>(length, fill)
{}

template <typename T>
Array <T>::Array (const Array & array)
//using base member initialization
: Basic_Array <T>(array)
{}

// base classes destructor runs due to it being virtual
template <typename T>
Array <T>::~Array (void)
{}

template <typename T>
const Array <T> & Array <T>::operator = (const Array & rhs)
{

//using base class assignment operator
	(Basic_Array<T>&) (*this) = rhs;
	return *this;
}

template <typename T>
void Array <T>::resize (size_t new_size)
{  
	//if the current size is larger than the passed in value for the new size, set current size to the new size, decreasing its size
	if(this->cur_size_ > new_size)
	{
		this->cur_size_ = new_size;
	}
	//else if the current size is smaller than the passed in value for the new size, set current and max size to the new size, increasing its size
	else if(this->cur_size_ < new_size)
	{
		T * temp = new T[new_size];
		for(int i = 0; i < this->cur_size_; i++)
		{
			temp[i] = this->data_[i];
		}
		delete [] this->data_;

		this->data_ = temp;
		this->cur_size_ = new_size;	
		this->max_size_  = new_size;
	}
}

template <typename T>
void Array <T>::shrink (void)
{
    
//	if the max size is larger than the current size of the array, set the max size to the current size to reclaim the unused space
	if(this->max_size_ > this->cur_size_)
 	{
		T * temp = new T[this->cur_size_];
		for(int i = 0; i < this->cur_size_; i++)
		{
			temp[i] = this->data_[i];
		}
		delete [] this->data_;
		this->data_ = temp;
		this->max_size_ = this->cur_size_;
	}
}


template <typename T>
Array <T> Array <T>::slice (size_t begin) const
{
	//create size for shallow copy
	size_t shallowSize = this->cur_size_ - begin;
	//create new array object from default constructor where data_ is set to a nullptr
	Array newArr;
	//set sizes for the new array
	newArr.cur_size_ = shallowSize;
	newArr.max_size_ = shallowSize;
	//set the new arrays data_ to point to the array being operated on plus the offset of begin so the new arrays data_ points 
	//an index in the already existing array
	newArr.data_ = this->data_ + begin;
	//return shallow copy
	return newArr; 
}

template <typename T>
Array <T> Array <T>::slice (size_t begin, size_t end) const
{
	////create size for the shallow copy
	size_t shallowSize = end - begin + 1;
	//create a new array object using default constructor where datA_ is set to a nullptr
	Array newArr;
	//set sizes for the new array
	newArr.cur_size_ = shallowSize;
	newArr.max_size_ = shallowSize;
	//set the new array to the array being operated on plus the offset of begin so the new arrays data_ points
	//to an index in the already existing array
	newArr.data_ = this->data_ + begin;
	//loop through the new array and set its characters from the passed in begin to end
	for(int i = begin; i < end; i++)
	{
		newArr.data_[i] =  newArr.data_[begin];
		begin++;	 
	}
	//return the new array
		return newArr;
}










