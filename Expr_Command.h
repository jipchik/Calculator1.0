//declaration of expression interface for command pattern
#ifndef _EXPR_COMMAND_H_
#define _EXPR_COMMAND_H_



// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include "Stack.h"
class Expr_Command
{
	public:
	virtual void execute(Stack<int> & s) = 0;
	virtual int get_prec() = 0;
};




#endif
