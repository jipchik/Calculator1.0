//implementation of binary expression command execution

#include "Bin_Ex_Command.h"


Bin_Ex_Command(Stack<int> & s)
: s_(s)
{}

void Bin_Ex_Command::execute(void)
{
	int nl, n2;
	n2 = this->s_.pop();
	n1 = this->s_.pop();

	int result = this->evaluate(n1, n2);
	this->s_.push(result);
}

