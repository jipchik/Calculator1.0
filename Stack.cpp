// $Id: Stack.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include "Stack.h"
#include <iostream>

//
// Stack
//default constructor
//initializes the stack private members by calling the Array constructor for the stack_, and setting the top_index_ to -1 to indicate its empty
template <typename T>
Stack <T>::Stack (void) 
:	stack_(10),
	top_index_ (-1),
	size_(0)

{}

//
// Stack
//copy constructor
//uses Arrays class assignment operator to copy over the current stack_ values to the new stack_, top_index_ is set to the passed in stacks top_index_ value
template <typename T>
Stack <T>::Stack (const Stack & stack)
:	stack_(stack.stack_),
	top_index_(stack.top_index_),
	size_(stack.size_)
{}

//
// ~Stack
//
//destructor for stack class
template <typename T>
Stack <T>::~Stack (void)
{	
}

//
// push
//adds a new element to the top of the stack
template <typename T>
void Stack <T>::push (T element)
{
	//use temp to store the top_index_ in the case that the stack needs resized
	int temp = this->top_index_;
	//resize the stack if the top index ever becomes larger than the allocation size of the stack
	if(this->top_index_ >= this->stack_.size())
	{
		this->stack_.resize(this->stack_.size()*2);		
		this->top_index_ = temp;
	}
	//adds the passed in element to the top of the stack using the Array classes setter
	this->stack_.set(++top_index_, element);
	//increment the size property
	this->size_++;
}

//
// pop
//pops the top element off of the stack
template <typename T>
T Stack <T>::pop (void)
{
	//value that will be returned from popping the stack
	T retVal = this->top();

	//create exception object
	empty_exception e;
	//if the stack is empty, throw the empty_exception
	if(this->is_empty())
	{
		throw e;	
	}
	//else decrement the top_index_ and size_ properties to reflect the change in the stack
	else
	{
		--top_index_;
		--size_;
	}
	return retVal;
}


//
// operator =
//use the assignment operator of the Array class to assign the values of the new stack to the values from the rhs of the operator
template <typename T>
const Stack <T> & Stack <T>::operator = (const Stack & rhs)
{
	if(this != &rhs)
	{
		this->stack_ = rhs.stack_;
		this->top_index_ = rhs.top_index_;
	}
	return *this;
}


//
// clear
//clears the stack of its current values
template <typename T>
void Stack <T>::clear (void)
{
  //initialize a temporary stack and set the acted on stack to the temporary stack, effectively empties the stack
 	Stack<T> temp;
	*this = temp;	 
	
	
	
}

















