//implementation of num expression command 


// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include "Num_Ex_Command.h"


Num_Ex_Command::Num_Ex_Command(int n)
:	n_(n)
{}


void Num_Ex_Command::execute(Stack<int> & s)
{
	s.push(this->n_);
}

int Num_Ex_Command::get_prec(void)
{
	return 0;
}
