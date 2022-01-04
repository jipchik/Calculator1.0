//implementing division command

#include "Div_Ex_Command.h"


// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.


Div_Ex_Command::Div_Ex_Command(void)
: prec_(2)
{}

void Div_Ex_Command::execute(Stack<int> & s)
{
    // COMMENT: Your code will crash if you have divide by 0.
    //
    // RESPONSE:: Implemented check in Calculator.cpp that does not allow an expression with a divide by zero to make it
    // to the postfix array, so the division command will never come into contact with a division by zero case.
    //

	int n2 = s.pop();
	int n1 = s.pop();

	s.push(n1 / n2);
}

int Div_Ex_Command::get_prec(void)
{
	return prec_;
}
