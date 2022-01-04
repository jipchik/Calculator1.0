// -*- C++ -*-
// $Id: Stack.inl 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help on
// this assignment.

//
// size
// returns the current size of the stack
template <typename T>
inline
size_t Stack <T>::size (void) const
{
	return this->size_;
}

//
// top
// returns the current top element by using the getter from Array class
template <typename T>
inline
T Stack <T>::top (void) const
{
	return stack_.get(top_index_);
}

//
// is_empty
//returns true  if the top_index_ is -1 and false if it is anything else
template <typename T>
inline
bool Stack <T>::is_empty (void) const
{
	if(top_index_ == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
