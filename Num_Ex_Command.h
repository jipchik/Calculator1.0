//declaration of num expression command
#ifndef _NUM_EX_COMMAND_H_
#define _NUM_EX_COMMAND_H_



// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include "Expr_Command.h"
#include "Stack.h"


class Num_Ex_Command : public Expr_Command
{
	public: 

	Num_Ex_Command(int n);
	virtual void execute(Stack<int> & s);
	int get_prec();
	private:  
	int n_;	
};

#endif
