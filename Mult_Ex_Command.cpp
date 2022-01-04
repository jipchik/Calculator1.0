//implementing multiplication command



// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include "Mult_Ex_Command.h"

Mult_Ex_Command::Mult_Ex_Command(void)
: prec_(2)
{}

void Mult_Ex_Command::execute(Stack<int> & s)
{
	int n2 = s.pop();
	int n1 = s.pop();
	
	s.push(n2 * n1);
}

int Mult_Ex_Command::get_prec(void)
{
	return prec_;
}
