//implementing subtraction command


// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include "Sub_Ex_Command.h"

Sub_Ex_Command::Sub_Ex_Command(void)
: prec_(1)
{}

void Sub_Ex_Command::execute(Stack<int> & s)
{
	int n2 = s.pop();
	int n1 = s.pop();
	
	s.push(n1 - n2);
}

int Sub_Ex_Command::get_prec(void)
{
	return prec_;
}
