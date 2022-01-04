//declaration of what a binary expression should do to evaluate two numbers
#ifndef _BIN_EX_COMMAND_H_
#define _BIN_EX_COMMAND_H_

#include "Expr_Command.h"


class Bin_Ex_Command : public Expr_Command
{
	public:
	
	Bin_Ex_Command(Stack <int> & s);	
	virtual int evaluate(int n1, int n2) const = 0;
	
	private: 	
	
	Stack<int> & s_;
 
};


#endif
