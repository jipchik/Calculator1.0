//implementing add command


// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include "Add_Ex_Command.h"


Add_Ex_Command::Add_Ex_Command(void)
: prec_(1)
{}

void Add_Ex_Command::execute(Stack<int> & s)
{
	int n2 = s.pop();
	int n1 = s.pop();
	
	s.push(n1 + n2);
}

int Add_Ex_Command::get_prec(void)
{
	return prec_;
}
