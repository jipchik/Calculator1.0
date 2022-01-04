//implementing open command for handling parentheses


// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include "Open_Ex_Command.h"

Open_Ex_Command::Open_Ex_Command(void)
: prec_(-1)
{}

void Open_Ex_Command::execute(Stack<int> & s)
{
	std::cout << "This is a placeholder and will never make it to the phase of execution." << std::endl;
}

int Open_Ex_Command::get_prec(void)
{
	return prec_;
}
