// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Basic_Array.h"
#include <iostream>
#include <stdexcept>

template <typename T>
Basic_Array <T>::Basic_Array (void)
//using base member initialization
:
	data_ (nullptr),
	cur_size_(10),
	max_size_ (10)
{}

template <typename T>
Basic_Array <T>::Basic_Array (size_t length)
//using base member initialization
: data_(new T[length]),
	cur_size_ (length), 
	max_size_ (length)
{}

template <typename T>
Basic_Array <T>::Basic_Array (size_t length, T fill)
//using base member initialization
: data_(new T[length]), 
	cur_size_ (length), 
	max_size_ (length)
{
//once into the usage phase, assign all the values to the fill character
	for(int i = 0; i < cur_size_; i++)
	{
		data_[i] = fill;
	}
}

template <typename T>
Basic_Array <T>::Basic_Array (const Basic_Array & array)
//using base member initialization
: data_(new T[array.max_size_]), 
	cur_size_ (array.cur_size_), 
	max_size_ (array.max_size_)
{
//once into the usage phase, assign all the values from the referenced array to the newly initialized array 
	for(int i = 0; i < cur_size_; i++)
	{
		data_[i] = array.data_[i];
	}
}

template <typename T>
Basic_Array <T>::~Basic_Array (void)
{
	//delete the pointer to the array of characters if it is not a nullptr
	if(this->data_ != nullptr)
	{
 		delete [] this->data_;
  }  
}

template <typename T>
const Basic_Array <T> & Basic_Array <T>::operator = (const Basic_Array & rhs)
{
		if(this != &rhs)
		{
			//assign current and max size to the RHS values for current and max size respectively
			delete [] this->data_;
			cur_size_ = rhs.cur_size_;
			max_size_ = rhs.max_size_;
    	this->data_ = new T[rhs.cur_size_];
			//set the data pointer to a new character array with the current size of the passed in rhs
			//loop through each element in rhs and assign the new arrays values 
			for(int i = 0; i < rhs.size(); i++)
			{
				data_[i] = rhs.data_[i];
			}
		}	
	return (*this);	

}

template <typename T>
T & Basic_Array <T>::operator [] (size_t index)
{
	///if index request is larger than the current size of the array, throw OUT_OF_RANGE exception
	if(index >= cur_size_)
		{
			throw std::out_of_range("Index out of range.");
		}
	///otherwise return the value at the index requested
	return data_[index];	
}

template <typename T>
const T & Basic_Array <T>::operator [] (size_t index) const
{
	// if index is larger than the current size of the array, throw the out of range exception
	if(index >= cur_size_)
	{
		throw std::out_of_range("Index out of range.");
	}
	return data_[index];
}

template <typename T>
T Basic_Array <T>::get (size_t index) const
{
	//if index is larger than the current size of the array, throw the out of range exception
	if(index > cur_size_)
	{
		throw std::out_of_range("Index out of range.");
	}
	//return the value at the specified index
	return data_[index];
}

template <typename T>
void Basic_Array <T>::set (size_t index, T value)
{
	//if the index is larger than the current size of the array, throw the out of range exception
	if (index > cur_size_)
	{
		throw std::out_of_range("Index out of range.");
	}
	//else set the character at the passed in index to the passed in value character
	else
	{
 		data_[index] = value;
 	}
}


template <typename T>
int Basic_Array <T>::find (T element) const
{
	//loop through the array and if the character is present in the array, return its index
	//if the character is not present, -1 is returned
	for(int i = 0; i < cur_size_; i++)
	{
		if (data_[i] == element)
		{
			return i;
		}	
	}	
	return -1;	
}

template <typename T>
int Basic_Array <T>::find (T element, size_t start) const
{
	//if the passed in start value is larger or equal to the current size, throw out of range exception
	if(start >= cur_size_)
	{
		throw std::out_of_range("Index out of range.");
	}
	//else loop through the array and if the value is found, return its index
	//if the value is not in the array then -1 will be returned after the loop finishes
	else
	{
		for(int i = start; i < cur_size_; i++)
		{
			if(data_[i] == element)
			{
				return i;
			}
		}
		return -1;
	}
}

template <typename T>
bool Basic_Array <T>::operator == (const Basic_Array & rhs) const
{
	//declare boolean variable that will hold the outcome of the comparison and initialize it to false
	if(this == &rhs)
	{
		return true;
	}	
	//loop through each elements in the array, if one element is not the same, set testVal to false and break out of the loop and return testVal	
	//if all of the elements are the same, testVal will hold a true value and be returned at the finish of the loop	
	for(int i = 0; i < rhs.size(); i++)
	{
		if(data_[i] != rhs.get(i))
		{
			return false;
		}
	}
	return true;

}

template <typename T>
bool Basic_Array <T>::operator != (const Basic_Array & rhs) const
{
  //using == operator to see if the rhs passed in is unequal to the array in question, return true
  //else return false
	if(!(*this == rhs))
	{
		return true;
	}
	else
	{
		return false;
	}

}

template <typename T>
void Basic_Array <T>::fill (T element)
{
	//loop through the array and insert the passed in character into each index of the array
	for(int i = 0; i < cur_size_; i++)
	{
		data_[i] = element;
	}
}


template <typename T>
void Basic_Array <T>::reverse (void)
{
	//initialize integers that will coordinate the swap between the differing array indices
	int arrSize = cur_size_ - 1;;
	int count = 0; 
	//initialize boolean sentry variable for the while loop
	bool keepGoing = true;

	while(keepGoing)
	{
		//swap the characters at the count and arrSize index, at the start of the loop it will be the character at the zeroth and nth index					
		char temp = this->data_[count];
		this->data_[count] = this->data_[arrSize];
		this->data_[arrSize] = temp;
		//increment count and decrement arrSize to move inward one element from each end of the array
		count++;
		arrSize--;
		//if the array has an even number of elements, when the count value is higher than the arrSize value, terminate while loop
		if(count > arrSize)
		{
			keepGoing = false;
		}
		//else if the array has an odd number of elements, when the count value equals the arrSize value, terminate the while loop	
		else if(count == arrSize)
		{
			keepGoing = false;
		}
	}	
}










