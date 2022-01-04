//subtraction command declaration

#ifndef _SUB_EX_COMMAND_H_
#define _SUB_EX_COMMAND_H_


// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include "Expr_Command.h"
#include "Stack.h"

class Sub_Ex_Command : public Expr_Command
{
	public:
	Sub_Ex_Command(void);
	virtual void execute(Stack<int> & s);
	int get_prec();

	private:
	int prec_;
};


#endif
