//implementing modulus command

#include "Mod_Ex_Command.h"


// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

Mod_Ex_Command::Mod_Ex_Command(void)
: prec_(2)
{}

void Mod_Ex_Command::execute(Stack<int> & s)
{
	int n2 = s.pop();
	int n1 = s.pop();
	
	s.push(n1 % n2);
}

int Mod_Ex_Command::get_prec(void)
{
	return prec_;
}
